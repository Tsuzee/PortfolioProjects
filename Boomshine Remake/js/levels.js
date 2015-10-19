//This is a level file for Boomshine
//The first level details what info each level has

"use strict";

var app = app || {};

//define the level module and immediately invoke it in an IIFE
app.level = (function(){
	
		var numOfLevels = 30;
		//array of level data
		var levels = [
		//level 1
		{
			targetNum:			1, 		//level score required to continue to next level
			numCircles:			5, 		//number of circles in the level
			levelMessage: 		"",		//message to user if any (displays on REPEAT LEVEL screen) expect level 1
			powerUp:			2,		//which power the level gives if any  (didn't get to using this :(  )
			powerUpTarget:		0,		//target number of circles for user to gain a power up.(didn't get to using this :(  )
			circleSpeedMod: 	0.5,		//modification to the circles speed
			circleExRadiusMod: 	1.3,		//modification to the circle explosion size
		},
		
		//level 2
		{
			targetNum:			2,
			numCircles:			10,
			levelMessage: 		"",
			powerUp:			2,
			powerUpTarget:		0,
			circleSpeedMod: 	0.75,
			circleExRadiusMod: 	1.2,
		},
		
		//level 3
		{
			targetNum:			3,
			numCircles:			12,
			levelMessage: 		"",
			powerUp:			2,
			powerUpTarget:		0,
			circleSpeedMod: 	1,
			circleExRadiusMod: 	1.1,
		},
		
		//level 4
		{
			targetNum:			4,
			numCircles:			14,
			levelMessage: 		"",
			powerUp:			2,
			powerUpTarget:		0,
			circleSpeedMod: 	1,
			circleExRadiusMod: 	1,
		},
		
		//level 5
		{
			targetNum:			5,
			numCircles:			16,
			levelMessage: 		"",
			powerUp:			2,
			powerUpTarget:		0,
			circleSpeedMod: 	1,
			circleExRadiusMod: 	1,
		},
		
		//level 6
		{
			targetNum:			6,
			numCircles:			16,
			levelMessage: 		"",
			powerUp:			2,
			powerUpTarget:		0,
			circleSpeedMod: 	1,
			circleExRadiusMod: 	1,
		},
		
		//level 7
		{
			targetNum:			7,
			numCircles:			18,
			levelMessage: 		"",
			powerUp:			2,
			powerUpTarget:		0,
			circleSpeedMod: 	1,
			circleExRadiusMod: 	1,
		},
		
		//level 8
		{
			targetNum:			8,
			numCircles:			18,
			levelMessage: 		"",
			powerUp:			2,
			powerUpTarget:		0,
			circleSpeedMod: 	1,
			circleExRadiusMod: 	1,
		},
		
		//level 9
		{
			targetNum:			9,
			numCircles:			20,
			levelMessage: 		"",
			powerUp:			2,
			powerUpTarget:		0,
			circleSpeedMod: 	1,
			circleExRadiusMod: 	1,
		},
		
		//level 10
		{
			targetNum:			10,
			numCircles:			20,
			levelMessage: 		"",
			powerUp:			2,
			powerUpTarget:		0,
			circleSpeedMod: 	1,
			circleExRadiusMod: 	1,
		},
		
		//level 11
		{
			targetNum:			11,
			numCircles:			22,
			levelMessage: 		"",
			powerUp:			2,
			powerUpTarget:		0,
			circleSpeedMod: 	1,
			circleExRadiusMod: 	1,
		},
		
		//level 12
		{
			targetNum:			12,
			numCircles:			24,
			levelMessage: 		"",
			powerUp:			2,
			powerUpTarget:		0,
			circleSpeedMod: 	1,
			circleExRadiusMod: 	1,
		},
		
		//level 13
		{
			targetNum:			13,
			numCircles:			26,
			levelMessage: 		"",
			powerUp:			2,
			powerUpTarget:		0,
			circleSpeedMod: 	1,
			circleExRadiusMod: 	1,
		},
		
		//level 14
		{
			targetNum:			14,
			numCircles:			28,
			levelMessage: 		"",
			powerUp:			2,
			powerUpTarget:		0,
			circleSpeedMod: 	1,
			circleExRadiusMod: 	1,
		},
		
		//level 15
		{
			targetNum:			15,
			numCircles:			30,
			levelMessage: 		"Your halfway there!",
			powerUp:			2,
			powerUpTarget:		0,
			circleSpeedMod: 	1,
			circleExRadiusMod: 	1,
		},
		
		//level 16
		{
			targetNum:			20,
			numCircles:			32,
			levelMessage: 		"",
			powerUp:			2,
			powerUpTarget:		0,
			circleSpeedMod: 	1,
			circleExRadiusMod: 	1,
		},
		
		//level 17
		{
			targetNum:			24,
			numCircles:			34,
			levelMessage: 		"",
			powerUp:			2,
			powerUpTarget:		0,
			circleSpeedMod: 	1,
			circleExRadiusMod: 	1,
		},
		
		//level 18
		{
			targetNum:			26,
			numCircles:			36,
			levelMessage: 		"",
			powerUp:			2,
			powerUpTarget:		0,
			circleSpeedMod: 	1,
			circleExRadiusMod: 	1,
		},
		
		//level 19
		{
			targetNum:			28,
			numCircles:			38,
			levelMessage: 		"",
			powerUp:			2,
			powerUpTarget:		0,
			circleSpeedMod: 	1,
			circleExRadiusMod: 	1,
		},
		
		//level 20
		{
			targetNum:			30,
			numCircles:			40,
			levelMessage: 		"Keep going!",
			powerUp:			2,
			powerUpTarget:		0,
			circleSpeedMod: 	1,
			circleExRadiusMod: 	1,
		},
		
		//level 21
		{
			targetNum:			32,
			numCircles:			42,
			levelMessage: 		"",
			powerUp:			2,
			powerUpTarget:		0,
			circleSpeedMod: 	3,
			circleExRadiusMod: 	0.3,
		},
		
		//level 22
		{
			targetNum:			34,
			numCircles:			44,
			levelMessage: 		"",
			powerUp:			2,
			powerUpTarget:		0,
			circleSpeedMod: 	1,
			circleExRadiusMod: 	1,
		},
		
		//level 23
		{
			targetNum:			36,
			numCircles:			46,
			levelMessage: 		"",
			powerUp:			2,
			powerUpTarget:		0,
			circleSpeedMod: 	0.3,
			circleExRadiusMod: 	1.5,
		},
		
		//level 24
		{
			targetNum:			38,
			numCircles:			48,
			levelMessage: 		"",
			powerUp:			2,
			powerUpTarget:		0,
			circleSpeedMod: 	1,
			circleExRadiusMod: 	1,
		},
		
		//level 25
		{
			targetNum:			40,
			numCircles:			50,
			levelMessage: 		"Getting close, don't give up now!!",
			powerUp:			2,
			powerUpTarget:		0,
			circleSpeedMod: 	1,
			circleExRadiusMod: 	1,
		},
		
		//level 26
		{
			targetNum:			44,
			numCircles:			52,
			levelMessage: 		"",
			powerUp:			2,
			powerUpTarget:		0,
			circleSpeedMod: 	1,
			circleExRadiusMod: 	1,
		},
		
		//level 27
		{
			targetNum:			48,
			numCircles:			54,
			levelMessage: 		"",
			powerUp:			2,
			powerUpTarget:		0,
			circleSpeedMod: 	2,
			circleExRadiusMod: 	0.5,
		},
		
		//level 28
		{
			targetNum:			51,
			numCircles:			56,
			levelMessage: 		"Almost Done!!",
			powerUp:			2,
			powerUpTarget:		0,
			circleSpeedMod: 	1,
			circleExRadiusMod: 	1,
		},
		
		//level 29
		{
			targetNum:			53,
			numCircles:			58,
			levelMessage: 		"So close",
			powerUp:			2,
			powerUpTarget:		0,
			circleSpeedMod: 	1,
			circleExRadiusMod: 	1,
		},
		
		//level 30
		{
			targetNum:			55,
			numCircles:			60,
			levelMessage: 		"This is it!!!!",
			powerUp:			2,
			powerUpTarget:		0,
			circleSpeedMod: 	0.75,
			circleExRadiusMod: 	1.25,
		}
		]; //end of array	
	
	//return the number of levels
	function getNumOfLevels(){
		return numOfLevels;
	}
	
	//returns the needed level information based on the paramater
	function getLevel(levelNum){
		return levels[levelNum - 1];
	}//end of getLevel
	
	//return the function
	return{
		getLevel: getLevel,
		getNumOfLevels: getNumOfLevels
	};
	
}());