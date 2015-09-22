//Darren Farr
//Cave Falling: Perlin noise and collesion dection test

//globals, a necessary evil
PFont monoFont;

float foreVal;
float backVal;
float foreGroundTime = 0.0;
float difficulty = 0.005;
float speed;

int highScore = 0;
int startX = 0;

boolean moveRight = false;
boolean moveLeft = false;
boolean noMove = true;
boolean startGame = false;
boolean firstRun = true;
boolean gameOver = false;

Ship spaceShip;

////////////////////////////////////////////////
//------------------setup-----------------------
////////////////////////////////////////////////
void setup()
{
  //window size
  size(800, 800);
  smooth();
  
  ellipseMode(CENTER);
  
  //setup text font
  monoFont = loadFont("AndaleMono-24.vlw");
  textFont(monoFont);
  textSize(17);
}//end setup

////////////////////////////////////////////////
//-------------------draw-----------------------
////////////////////////////////////////////////
void draw()
{
  background(128);
  
  //draw foreground
  foreVal = foreGroundTime;
  for (int i = 0; i < height; i++) 
  {
    stroke(0);
    strokeWeight(2);
    
    // Get current and "next" noise value
    float x1 = noise(foreVal)*500;
    float x2 = noise(foreVal+0.001)*500;
    
    // Draw line
    float lineX1 = 100 + x1;
    float lineX2 = 200 + x2;
    
    line(lineX1, i, lineX2, i+1);
    if(firstRun && i == (height/2) )
    {
      startX = int(100 + x1 + ((x2-x1)/2));
      spaceShip = new Ship(startX);
      firstRun = false;
    }
    stroke(255);
    foreVal += 0.003;   
   if(i == height/2)
   {
     checkCollisions(lineX1, lineX2);
   }
  }
  if(startGame)
  {
    foreGroundTime+= difficulty;
  }
  spaceShip.updatePosition();
  spaceShip.display();
  
  //track high score
  //increase the game and ship speed at set intervals to increase difficulty
  if(frameCount % 60 == 0 && startGame && !gameOver)
  {
    highScore += 100;
    if(highScore % 2000 == 0)
    {
      difficulty += 0.002;
      speed +=1;
      highScore += 500;
    }
  }
  
  fill(255);
  text("Press Enter to Start", 10, 20);
  text("Use left/right arrow keys to move", 10, 50);
  text("HIGH SCORE: " + highScore, 600, 20);
  
  if(gameOver)
  {
    textSize(30);
    text("GAME OVER", width/2 - 75, height/2 + 5);
    textSize(17);
  }
}//end of draw

///////////////////////////////////////////////////////////////////////////////////////
//------------------------------collision dectection-----------------------------------
//take in the left and right bounderies and check if ship is at or over the bounderies
///////////////////////////////////////////////////////////////////////////////////////
void checkCollisions(float leftB, float rightB)
{
  if((spaceShip.getXPos() - (spaceShip.shipRadius/2)) < leftB || 
     (spaceShip.getXPos() + (spaceShip.shipRadius/2)) > rightB)
  {
    startGame = false;
    gameOver = true;
  }
  
  
}//end check for collisions

///////////////////////////////////////////////////////
//------------------key listeners----------------------
///////////////////////////////////////////////////////
void keyPressed(){
  switch(keyCode){
    case RIGHT: 
      moveRight = true;
      break;
    case LEFT: 
      moveLeft = true;
      break;
    case ENTER:
      startGame = true;
      break;
    default:
      noMove = true;
      break;
  }
  noMove = false;
}

//look for released keys
void keyReleased(){
  switch(keyCode){
    case RIGHT: 
      moveRight = false;
      break;
    case LEFT: 
      moveLeft = false;
      break;
    case UP:
      //moveUp = false;
      //move = false;
      break;
  }
  noMove = true;
}