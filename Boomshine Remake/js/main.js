// main.js
// Dependencies: 
// Description: singleton object
// This object will be our main "controller" class and will contain references
// to most of the other objects in the game.

"use strict";

// if app exists use the existing copy
// else create a new object literal
var app = app || {};

/*
 .main is an object literal that is a property of the app global
 This object literal has its own properties and methods (functions)
 
 */
app.main = {
	//  properties
	paused: false,
	animationID: 0,
    WIDTH : 640, 
    HEIGHT: 640,
    canvas: undefined,
    ctx: undefined,
	array: undefined,
   	lastTime: 0, // used by calculateDeltaTime() 
    debug: false,
	gameState: undefined,
	level: undefined,
	levelMsg: "",
	roundScore: 0,
	neededScore: 0,
	totalScore: 0,
	currentLevel: 0,
	circSpeedMod: 1,
	circExplodeMod: 1,
	weapNum: 2,
	megaBomb: 2,
	scatterBomb: 2,
	finalLevel: undefined,
	sound: undefined,
	
		
	CIRCLE: Object.freeze({
		NUM_CIRCLES_START: 5,
		START_RADIUS: 10,
		MAX_RADIUS: 45,
		MIN_RADIUS: 2,
		MAX_LIFETIME: 2.5,
		MAX_SPEED: 80,
		EXPLOSION_SPEED: 60,
		IMPLOSION_SPEED: 84,
	}),
	
	CIRCLE_STATE: Object.freeze({
		NORMAL: 0,
		EXPLODING: 1,
		MAX_SIZE: 2,
		IMPOLODING: 3,
		DONE: 4
	}),
	
	GAME_STATE: Object.freeze({ // another fake enumeration 
		BEGIN : 0, 
		DEFAULT : 1, 
		EXPLODING : 2, 
		ROUND_OVER : 3, 
		REPEAT_LEVEL : 4, 
		END : 5 
	}),
	
	// original 8 fluorescent crayons: https://en.wikipedia.org/wiki/List_of_Crayola_crayon_colors#Fluorescent_crayons
	//  "Ultra Red", "Ultra Orange", "Ultra Yellow","Chartreuse","Ultra Green","Ultra Blue","Ultra Pink","Hot Magenta"
	colors: ["#FD5B78","#FF6037","#FF9966","#FFFF66","#66FF66","#50BFE6","#FF6EFF","#EE34D2"],
	
	circles : [],
	
	//init circle properties
	
	circleHitLeftRight: function (c){
		if(c.x < c.radius || c.x > this.WIDTH - c.radius){
			return true;
		}
	},
	
	circleHitTopBottom: function(c){
		if(c.y < c.radius || c.y > (this.HEIGHT - 160) - c.radius){
			return true;
		}
	},
    
    ///////////////////////////////////////////////////////////////////////
    //----------------------------methods----------------------------------
	///////////////////////////////////////////////////////////////////////
	
	//initialize function
	//setup game elements and start the game
	init : function() {
		console.log("app.main.init() called");
		// initialize properties
		this.canvas = document.querySelector('canvas');
		this.canvas.width = this.WIDTH;
		this.canvas.height = this.HEIGHT;
		this.ctx = this.canvas.getContext('2d');
		
		//number of game levels
		this.finalLevel = this.level.getNumOfLevels();
		
		//load level
		this.reset();
		
		//initialize the game state
		this.gameState = this.GAME_STATE.BEGIN;
		
		//hook events
		this.canvas.onmousedown = this.doMousedown.bind(this);
		
		// start the game loop
		this.update();
	},
	
	// creates a new level of circles 
	reset: function(){ 
		console.log("Reset Called");
		this.currentLevel++;
		var arrayData = this.level.getLevel(this.currentLevel);
		this.neededScore = arrayData.targetNum;
		this.numCircles = arrayData.numCircles;
		this.levelMsg = arrayData.levelMessage;
		this.circSpeedMod = arrayData.circleSpeedMod;
		this.circExplodeMod = arrayData.circleExRadiusMod;
		//this.numCircles += 5; 
		this.roundScore = 0; 
		//this.neededScore = Math.floor(this.numCircles / 3);
		this.circles = this.makeCircles(this.numCircles);
		this.sound.playBGAudio();
	},
	
	//update the game and draw all elements
	update: function(){
		// 1) LOOP
		// schedule a call to update()
	 	//requestAnimationFrame(function(){app.main.update()});
	 	this.animationID = requestAnimationFrame(this.update.bind(this));
		
	 	// 2) PAUSED?
	 	// if so, bail out of loop
		if(this.paused){
			this.drawPauseScreen(this.ctx);
			return;
		}
	 	
	 	// 3) HOW MUCH TIME HAS GONE BY?
	 	var dt = this.calculateDeltaTime();
	 	 
	 	// 4) UPDATE
	 	// move circles
		this.moveCircles(dt);
		
		//check collisions
		this.checkForCollisions();
	 	
		// 5) DRAW	
		// i) draw background
		this.ctx.fillStyle = "black"; 
		this.ctx.fillRect(0,0,this.WIDTH,this.HEIGHT);
			
		// ii) draw circles
		this.ctx.globalAlpha = 0.9;
		this.drawCircles(this.ctx);		
		
		// iii) draw HUD
		this.ctx.globalAlpha = 1.0;
		this.drawHUD(this.ctx);
		this.ctx.save();
		this.ctx.textAlign = "center";
		this.ctx.textBaseline = "middle";
		this.ctx.strokeStyle = "white";
		this.ctx.rect(0, 0, this.WIDTH, (this.HEIGHT - 160));
		this.ctx.rect(0, (this.HEIGHT - 160), 213, this.HEIGHT);
		this.ctx.rect(213, (this.HEIGHT - 160), 426, this.HEIGHT);
		this.ctx.rect(426, (this.HEIGHT - 160), 639, this.HEIGHT);
		this.ctx.rect(639, (this.HEIGHT - 160), this.WIDTH, this.HEIGHT);
		this.ctx.stroke();
		//weapon 1
		this.ctx.beginPath();
		this.ctx.arc(50, 580, this.CIRCLE.START_RADIUS*4, 0, Math.PI*2, true);
		this.ctx.closePath();
		this.ctx.fillStyle = "red";
		this.ctx.fill();
		this.fillText(this.ctx, "Mega Bomb", 108, 500, "17pt courier", "red");
		this.fillText(this.ctx, "x ", 125, 580, "20pt courier", "white");
		if(this.megaBomb > 0){this.fillText(this.ctx, this.megaBomb, 145, 580, "20pt courier", "white");}
		else {this.fillText(this.ctx, "0", 145, 580, "20pt courier", "white");}
		
		//weapon 2
		this.ctx.beginPath();
		this.ctx.arc(340, 540, this.CIRCLE.START_RADIUS/3, 0, Math.PI*2, true);
		this.ctx.closePath();
		this.ctx.fill();
		this.ctx.beginPath();
		this.ctx.arc(270, 560, this.CIRCLE.START_RADIUS/3, 0, Math.PI*2, true);
		this.ctx.closePath();
		this.ctx.fill();
		this.ctx.beginPath();
		this.ctx.arc(340, 600, this.CIRCLE.START_RADIUS/3, 0, Math.PI*2, true);
		this.ctx.closePath();
		this.ctx.fill();
		this.ctx.beginPath();
		this.ctx.arc(330, 580, this.CIRCLE.START_RADIUS/3, 0, Math.PI*2, true);
		this.ctx.closePath();
		this.ctx.fill();
		this.ctx.beginPath();
		this.ctx.arc(310, 610, this.CIRCLE.START_RADIUS/3, 0, Math.PI*2, true);
		this.ctx.closePath();
		this.ctx.fill();
		this.ctx.beginPath();
		this.ctx.arc(295, 575, this.CIRCLE.START_RADIUS/3, 0, Math.PI*2, true);
		this.ctx.closePath();
		this.ctx.fill();
		this.ctx.fillStyle = "red";
		this.ctx.fill();
		this.fillText(this.ctx, "Scatter Shot", 324, 500, "17pt courier", "red");
		this.fillText(this.ctx, "x ", 360, 580, "20pt courier", "white");
		if(this.scatterBomb > 0){this.fillText(this.ctx, this.scatterBomb, 375, 580, "20pt courier", "white");}
		else {this.fillText(this.ctx, "0", 375, 580, "20pt courier", "white");}
		
		//weapon 3 slot, no weapon
		this.fillText(this.ctx, "No Weapon", 534, 500, "17pt courier", "red");
		
		this.ctx.restore();
		this.drawWeapSelect();
		
		// iv) draw debug info
		if (this.debug){
			// draw dt in bottom right corner
			this.fillText(this.ctx, "dt: " + dt.toFixed(3), this.WIDTH - 150, (this.HEIGHT - 160) - 10, "18pt courier", "white");
		}
		
		// 6) CHECK FOR CHEATS
		//if start screen or round over screen
		if(this.gameState == this.GAME_STATE.BEGIN || this.gameState == this.GAME_STATE.ROUND_OVER){
			if(myKeys.keydown[myKeys.KEYBOARD.KEY_UP] && myKeys.keydown[myKeys.KEYBOARD.KEY_SHIFT]){
				this.totalScore++;
				this.sound.playEffect();
			}
			
		}
	},
	
	//create the circles
	makeCircles: function(num){
		//draw circles
		var circleDraw = function(ctx){
			ctx.save();
			ctx.beginPath();
			ctx.arc(this.x, this.y, this.radius, 0, Math.PI*2, false);
			ctx.closePath();
			ctx.fillStyle = this.fillStyle;
			ctx.fill();
			ctx.restore();
		};
		
		//move the circle
		var circleMove = function(dt){
			this.x += this.xSpeed * this.speed * dt;
			this.y += this.ySpeed * this.speed * dt;
		};
		
		this.array = [];
		//debugger;
		for(var i = 0; i < num; i++){
			//new object literal
			var c = {};
			
			//add x and y properties
			//getRandom() for utilities
			c.x = getRandom(this.CIRCLE.START_RADIUS * 2, this.WIDTH - this.CIRCLE.START_RADIUS * 2);
			c.y = getRandom(this.CIRCLE.START_RADIUS * 2, (this.HEIGHT - 160) - this.CIRCLE.START_RADIUS * 2);
			
			//add radius property
			c.radius = this.CIRCLE.START_RADIUS;
			
			//get random unit vector
			var randomVector = getRandomUnitVector();
			c.xSpeed = randomVector.x  * this.circSpeedMod;
			c.ySpeed = randomVector.y  * this.circSpeedMod;
			
			c.speed = this.CIRCLE.MAX_SPEED;
			c.fillStyle = this.colors[i % this.colors.length];
			c.state = this.CIRCLE_STATE.NORMAL;
			c.lifetime = 0;
			
			c.draw = circleDraw;
			c.move = circleMove;
			
			Object.seal(c);
			this.array.push(c);
		}
		return this.array;
	},
	
	//draw the circles to the canvas
	drawCircles: function(ctx){
		if(this.gameState === this.GAME_STATE.ROUND_OVER ||
			this.gameState === this.GAME_STATE.END || this.gameState === this.GAME_STATE.REPEAT_LEVEL){ 
			this.ctx.globalAlpha = 0.25;
		}
		for(var i = 0; i < this.circles.length; i++){
			var c = this.circles[i];
			if(c.state === this.CIRCLE_STATE.DONE) continue;
			c.draw(ctx);
		}
	},
	
	//circle movement
	moveCircles: function(dt){
		for(var i=0;i<this.circles.length; i++){
			var c = this.circles[i];
			if(c.state === this.CIRCLE_STATE.DONE) continue;
			if(c.state === this.CIRCLE_STATE.EXPLODING){
				c.radius += this.CIRCLE.EXPLOSION_SPEED  * dt;
				if(this.weapNum == 0 && this.megaBomb >= 0){
					
					if (c.radius >= (this.CIRCLE.MAX_RADIUS * 2 * this.circExplodeMod)){
						c.state = this.CIRCLE_STATE.MAX_SIZE;
						//console.log("circle #" + i + " hit CIRCLE.MAX_RADIUS");
					}
				}
				else{
					if (c.radius >= (this.CIRCLE.MAX_RADIUS * this.circExplodeMod)){
						c.state = this.CIRCLE_STATE.MAX_SIZE;
						//console.log("circle #" + i + " hit CIRCLE.MAX_RADIUS");
					}
				}
				continue;
			}
		
			if(c.state === this.CIRCLE_STATE.MAX_SIZE){
				c.lifetime += dt; // lifetime is in seconds
				if (c.lifetime >= this.CIRCLE.MAX_LIFETIME){
					c.state = this.CIRCLE_STATE.IMPLODING;
					//console.log("circle #" + i + " hit CIRCLE.MAX_LIFETIME");
				}
				continue;
			}
				
			if(c.state === this.CIRCLE_STATE.IMPLODING){
				c.radius -= this.CIRCLE.IMPLOSION_SPEED * dt;
				if (c.radius <= this.CIRCLE.MIN_RADIUS){
					//console.log("circle #" + i + " hit CIRCLE.MIN_RADIUS and is gone");
					c.state = this.CIRCLE_STATE.DONE;
					continue;
				}
			
			}
		
			// move circles
			c.move(dt);
		
			// did circles leave screen?
			if(this.circleHitLeftRight(c)){
				c.xSpeed *= -1;
				c.move(dt);
			}

			if(this.circleHitTopBottom(c)){
				c.ySpeed *= -1;
				c.move(dt);
			}
	
		} // end for loop
	},
	
	
	//check to see if a circle is clicked
	checkCircleClicked: function(mouse){
		//loop through array of circles
		for(var i = this.circles.length - 1; i >= 0; i--){
			var c = this.circles[i];
			if(pointInsideCircle(mouse.x, mouse.y, c)){
				this.sound.playEffect();
				c.xSpeed = c.ySpeed = 0;
				c.state = this.CIRCLE_STATE.EXPLODING;
				this.gameState = this.GAME_STATE.EXPLODING;
				this.roundScore ++;
				if(this.weapNum == 0 && this.megaBomb > -1){
					this.megaBomb--;
				}
				else if(this.weapNum == 1 && this.scatterBomb > 0){
					this.scatterBomb--;
					var numToEx = Math.floor(this.circles.length / 6);
					for(var j = 0; j < numToEx; j++){
						var cir = this.circles[j];
						cir.xSpeed = cir.ySpeed = 0;
						cir.state = this.CIRCLE_STATE.EXPLODING;
						this.roundScore += Math.floor(numToEx/3);
					}
				}
				break; //click only one circle
			}
		}
	},
	
	//check for circle collisions and round over conditions
	checkForCollisions: function(){
		if(this.gameState == this.GAME_STATE.EXPLODING){
			// check for collisions between circles
			for(var i=0;i<this.circles.length; i++){
				var c1 = this.circles[i];
				// only check for collisions if c1 is exploding
				if (c1.state === this.CIRCLE_STATE.NORMAL) continue;   
				if (c1.state === this.CIRCLE_STATE.DONE) continue;
				for(var j=0;j<this.circles.length; j++){
					var c2 = this.circles[j];
				// don't check for collisions if c2 is the same circle
					if (c1 === c2) continue; 
				// don't check for collisions if c2 is already exploding 
					if (c2.state != this.CIRCLE_STATE.NORMAL ) continue;  
					if (c2.state === this.CIRCLE_STATE.DONE) continue;
				
					// Now you finally can check for a collision
					if(circlesIntersect(c1,c2) ){
						this.sound.playEffect();
						c2.state = this.CIRCLE_STATE.EXPLODING;
						c2.xSpeed = c2.ySpeed = 0;
						this.roundScore ++;
					}
				}
			} // end for
			
			// round over?
			var isOver = true;
			for(var i=0;i<this.circles.length; i++){
				var c = this.circles[i];
				if(c.state != this.CIRCLE_STATE.NORMAL && c.state != this.CIRCLE_STATE.DONE){
				 isOver = false;
				 break;
				}
			} // end for
		
			if(isOver){
				if(this.roundScore < this.neededScore){
					this.gameState = this.GAME_STATE.REPEAT_LEVEL;
					this.sound.stopBGAudio();
				}
				else if(this.currentLevel == this.finalLevel)
				{
					this.gameState = this.GAME_STATE.END;
					this.totalScore += this.roundScore;
					this.sound.stopBGAudio();
				}
				else
				{
					this.gameState = this.GAME_STATE.ROUND_OVER;
					this.totalScore += this.roundScore;
					this.sound.stopBGAudio();
				}
			 }
				
		} // end if GAME_STATE_EXPLODING
	},
	
	//draw text to screen
	fillText: function(ctx, string, x, y, css, color) {
		ctx.save();
		// https://developer.mozilla.org/en-US/docs/Web/CSS/font
		ctx.font = css;
		ctx.fillStyle = color;
		ctx.fillText(string, x, y);
		ctx.restore();
	},
	
	//draw the HUD
	drawHUD: function(ctx){
		ctx.save(); // NEW
		// draw score
      	// fillText(string, x, y, css, color)
		this.fillText(ctx, "This Round: " + this.roundScore + "/" + this.neededScore + " of " + this.numCircles, 20, 20, "14pt courier", "#ddd");
		this.fillText(ctx, "Total Score: " + this.totalScore, this.WIDTH - 200, 20, "14pt courier", "#ddd");

		//FIGHT (begin game)
		if(this.gameState == this.GAME_STATE.BEGIN){
			ctx.textAlign = "center";
			ctx.textBaseline = "middle";
			this.fillText(this.ctx, "To begin, click a circle", this.WIDTH/2, this.HEIGHT/2, "30pt courier", "white");
			this.fillText(this.ctx, "Goal first round " + this.neededScore + " of " + (this.numCircles + 5) + 
				" circles", this.WIDTH/2 , this.HEIGHT/2 + 35, "20pt courier", "#ddd");
			this.fillText(this.ctx, "Click a weapon below to select it.", this.WIDTH/2, this.HEIGHT/2 + 70, "15pt courier", "red");
			this.fillText(this.ctx, "Use them wisely for they are not infinite.", this.WIDTH/2, this.HEIGHT/2 + 105, "15pt courier", "red");
		} // end if
	
		//ROUND OVER 
		if(this.gameState == this.GAME_STATE.ROUND_OVER){
			ctx.save();
			ctx.textAlign = "center";
			ctx.textBaseline = "middle";
			this.fillText(this.ctx, "Round Over", this.WIDTH/2, this.HEIGHT/2 - 40, "30pt courier", "red");
			this.fillText(this.ctx, "Click to continue", this.WIDTH/2, this.HEIGHT/2, "30pt courier", "white");
		} // end if
		
		//REPEAT LEVEL
		if(this.gameState == this.GAME_STATE.REPEAT_LEVEL){
			ctx.save();
			ctx.textAlign = "center";
			ctx.textBaseline = "middle";
			this.fillText(this.ctx, "You missed the goal of " + this.neededScore + " circles", this.WIDTH/2, this.HEIGHT/2 - 40, "20pt courier", "white");
			this.fillText(this.ctx, "Click to continue", this.WIDTH/2, this.HEIGHT/2, "30pt courier", "red");
			this.fillText(this.ctx, "Goal: " + this.neededScore + " of " + (this.numCircles) + 
				" circles", this.WIDTH/2 , this.HEIGHT/2 + 35, "20pt courier", "#ddd");
			this.fillText(this.ctx, this.levelMsg, this.WIDTH/2, this.HEIGHT/2 + 70, "20pt courier", "white");
		} // end if
		
		//END OF GAME
		if(this.gameState == this.GAME_STATE.END){
			ctx.save();
			ctx.textAlign = "center";
			ctx.textBaseline = "middle";
			this.fillText(this.ctx, "Game Over", this.WIDTH/2, this.HEIGHT/2 - 60, "50pt courier bold", "white");
			this.fillText(this.ctx, "Your final score was " + this.totalScore, this.WIDTH/2, this.HEIGHT/2, "30pt courier", "red");
			this.fillText(this.ctx, "Click to Start a New Game", this.WIDTH/2, this.HEIGHT/2 + 40, "20pt courier", "white");
		}
		
		ctx.restore(); // NEW
	},
	
	//pause the game
	pauseGame: function(){
		this.paused = true;
		
		//stop animation
		cancelAnimationFrame(this.animationID);
		this.sound.stopBGAudio();
		
		//update once
		this.update();
	},
	
	//draw the pause screen
	drawPauseScreen: function(ctx){
		ctx.save();
		ctx.fillStyle = "black";
		ctx.fillRect(0, 0, this.WIDTH, this.HEIGHT);
		ctx.textAlign = "center";
		ctx.textBaseline = "middle";
		this.fillText(ctx, "... PAUSED ...", this.WIDTH/2, this.HEIGHT/2, "40pt courier", "white");
		ctx.restore();
	},
	
	//resuem the game
	resumeGame: function(){
		//stop animation
		cancelAnimationFrame(this.animationID);
		
		this.paused = false;
		this.sound.playBGAudio();
		
		//restart
		this.update();
	},
	
	//toggle the debug mode on/off
	toggleDebug: function(){
		this.debug = !this.debug;
	},
	
	//do something on mouse down
	doMousedown: function(e){
		//var main = app.main;
		//insure not paused
		if(this.paused){
			this.paused = false;
			this.update();
			return;
		};
		
		if(this.gameState == this.GAME_STATE.EXPLODING) return;
		if(this.gameState == this.GAME_STATE.ROUND_OVER){
			this.gameState =  this.GAME_STATE.DEFAULT;
			this.reset();
			return;
		}
		if(this.gameState == this.GAME_STATE.REPEAT_LEVEL){
			this.gameState =  this.GAME_STATE.DEFAULT;
			this.currentLevel--;
			this.numCircles -= 5; 
			this.reset();
		}
		if(this.gameState == this.GAME_STATE.END){
			this.resetGame();
		}
		
		var mouse = getMouse(e); 
		app.main.checkCircleClicked(mouse);
		app.main.weaponSelect(mouse);
		this.sound.playBGAudio();
		
	},
	
	weaponSelect: function(mouse){
		if(mouse.x > 0 && mouse.x < 213 && mouse.y > 480){
			this.weapNum = 0;
		}
		else if(mouse.x > 213 && mouse.x < 426 && mouse.y > 480){
			this.weapNum = 1;
		}
		else if(mouse.x > 426 && mouse.x < 639 && mouse.y > 480){
			this.weapNum = 2;
		}
	},
	
	drawWeapSelect:function(){
		if(this.weapNum == 0){
			this.ctx.save();		
			this.ctx.rect(0, 481, 213, 159);
			this.ctx.stroke();
			this.ctx.fillStyle = '#8B0000';
			this.ctx.globalAlpha =0.5;
			this.ctx.fill();
			this.ctx.restore();
		}
		else if(this.weapNum == 1){
			this.ctx.save();
			this.ctx.rect(214, 481, 213, 159);
			this.ctx.stroke();
			this.ctx.fillStyle = '#8B0000';
			this.ctx.globalAlpha =0.5;
			this.ctx.fill();
			this.ctx.restore();
		}
		else if(this.weapNum == 2){
			this.ctx.save();
			this.ctx.rect(427, 481, 213, 159);
			this.ctx.stroke();
			this.ctx.fillStyle = '#8B0000';
			this.ctx.globalAlpha =0.5;
			this.ctx.fill();
			this.ctx.restore();
		}
	},
	
	//reset the game for a new game
	resetGame: function(){
		this.gameState = this.GAME_STATE.BEGIN;
		this.numCircles = this.CIRCLE.NUM_CIRCLES_START;
		this.circles = this.makeCircles(this.numCircles);
		this.neededScore = 0;
		this.totalScore = 0;
		this.currentLevel = 0;
		this.lastTime = 0;
		this.megaBomb = 2,
		this.scatterBomb = 2,
		this.weapNum = 2;
		this.reset();
	},
	
	//calculate the delta time
	calculateDeltaTime: function(){
		// what's with (+ new Date) below?
		// + calls Date.valueOf(), which converts it from an object to a 	
		// primitive (number of milliseconds since January 1, 1970 local time)
		var now,fps;
		now = (+new Date); 
		fps = 1000 / (now - this.lastTime);
		fps = clamp(fps, 12, 60);
		this.lastTime = now; 
		return 1/fps;
	}
    
}; // end app.main