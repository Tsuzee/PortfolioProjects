//Darren Farr
//Asteroids Remake
//IMD 11:00am TR

//globals
boolean turnRight = false;
boolean turnLeft = false;
boolean move = false;
boolean firstRun = true;
boolean bulletReady = true;
boolean canFire = true;
boolean safe = false;

int bulletsOut;
int bulletShot;
int asteroidNum;
int highScore;
int numOfLives;
int numOfAst;
int delay;

float distance = 0;

PFont monoFont;

PShape life;



ArrayList<Asteroid> asteroidList;
ArrayList<PShape> lives;

Ship spaceShip;
Asteroid asteroid;
Bullet shipBullet1;
Bullet shipBullet2;
Bullet shipBullet3;
Bullet shipBullet4;

////////////////////////////////////////////////
//-----------------setup------------------------
////////////////////////////////////////////////
void setup()
{
  //classic web size ratio 1.18, 714x600
  size(800, 800, P2D);
  
  asteroidList = new ArrayList<Asteroid>();
  lives = new ArrayList<PShape>();
  
  //setup text font
  monoFont = loadFont("AndaleMono-24.vlw");
  textFont(monoFont);
  textSize(17);
 
  bulletsOut = 0;
  highScore = 0;
  numOfLives = 3;
  numOfAst = 5;
  delay = 0;
 
  spaceShip = new Ship(0);
  shipBullet1 = new Bullet();
  shipBullet2 = new Bullet();
  shipBullet3 = new Bullet();
  shipBullet4 = new Bullet();
 
  asteroidSetup(numOfAst);
 
  //create the lives ship shape 
  for(int i = 0; i < 3; i++)
  {
    life = createShape();
      life.beginShape();
      life.vertex(10, 0);
      life.vertex(20, 30);
      life.vertex(10, 20);
      life.vertex(0, 30);
   life.endShape(CLOSE);
   life.setFill(0);
 
   lives.add(life);
  }
 }//end setup

////////////////////////////////////////////////
//------------------drawer----------------------
////////////////////////////////////////////////
void draw()
{
  background(0);
  
  if(frameCount - bulletShot > 15)
  {
    bulletReady = true;
  }
  
  
  //draw ship
  spaceShip.updatePosition();
  spaceShip.display();
  
  //draw bullets
  shipBullet1.updatePosition();
  shipBullet1.display();
  shipBullet2.updatePosition();
  shipBullet2.display();
  shipBullet3.updatePosition();
  shipBullet3.display();
  shipBullet4.updatePosition();
  shipBullet4.display();
  
  //draw asteroids
  for(Asteroid ast : asteroidList)
  {
    ast.updatePosition();
    ast.display();
  }
  
  checkCollisions();
  
  if(!spaceShip.shipActive && numOfLives > 0)
  {
    spaceShip.position.x = width/2;
    spaceShip.position.y = height/2;
    
    for(Asteroid ast : asteroidList)
    {
      safe = false;
      distance = PVector.dist(ast.getPos(), spaceShip.position.copy() );
       if(distance > 50.0 && !spaceShip.shipActive)
      {
        safe = true;
      }
    }
    if(safe)
    {
      spaceShip.shipActive = true;
      spaceShip.showShip = true;
      canFire = true;
    }
  }
  
  //draw game text
  textSize(17);
  text("High Score: " + highScore, 20, 20);
  strokeWeight(2);
  pushMatrix();
      shapeMode(CENTER);
      translate(700, 27);
      for(PShape life : lives)
      {
        shape(life);
        translate(30, 0);
      }
  popMatrix();
  
  //check for game over
  if(numOfLives < 1)
  {
    textSize(25);
    text("Game Over", width/2 - 30, height/2 - 5);
  }
  
  //move to next level
  if(asteroidList.isEmpty())
  {
    if(frameCount + delay > frameCount + 180)
    {
      delay = 0;
      numOfAst++;
      asteroidSetup(numOfAst);
    }
    else
    {
      delay++;
    }
  }
  println(numOfLives);
}//end draw

////////////////////////////////////////////////////////////////////
//-------------------collision dectection---------------------------
////////////////////////////////////////////////////////////////////
void checkCollisions()
{
  asteroidNum = 0;
  
  //ship collision
  for(Asteroid ast : asteroidList)
  {
    distance = PVector.dist(ast.getPos(), spaceShip.position.copy());
    if(distance < 30.0 && spaceShip.shipActive)
    {
      spaceShip.shipActive = false;
      spaceShip.showShip = false;
      canFire = false;
      lives.remove(numOfLives - 1);
      numOfLives--;
      break;
    }
    
    //bullet collisions
    if(shipBullet1.isActive())
    {
      distance = PVector.dist(ast.getPos(), shipBullet1.bulletPos());
      if(distance < 23.0)
      {
        shipBullet1.active = false;
        splitAsteroid(asteroidNum);
        bulletsOut--;
        break;
      }
    }
    if(shipBullet2.isActive())
    {
      distance = PVector.dist(ast.getPos(), shipBullet2.bulletPos());
      if(distance < 23.0)
      {
        shipBullet2.active = false;
        splitAsteroid(asteroidNum);
        bulletsOut--;
        break;
      }
    }
    if(shipBullet3.isActive())
    {
      distance = PVector.dist(ast.getPos(), shipBullet3.bulletPos());
      if(distance < 23.0)
      {
        shipBullet3.active = false;
        splitAsteroid(asteroidNum);
        bulletsOut--;
        break;
      }
    }
    if(shipBullet4.isActive())
    {
      distance = PVector.dist(ast.getPos(), shipBullet4.bulletPos());
      if(distance < 23.0)
      {
        shipBullet4.active = false;
        splitAsteroid(asteroidNum);
        bulletsOut--;
        break;
      }
    }
      asteroidNum++;
  }
}//end check for collisions

//////////////////////////////////////////////////////////////////////
//-------------------------key listeners------------------------------
//////////////////////////////////////////////////////////////////////
void keyPressed()
{
  switch(keyCode)
  {
    case RIGHT: 
      turnRight = true;
      break;
    case LEFT: 
      turnLeft = true;
      break;
    case UP:
      move = true;
      break;
  }
  if(key == ' ' && canFire)
  {
  if(bulletsOut < 4)
  {
  
    if(bulletReady)
    {
      if(!(shipBullet1.isActive()))
      {
        shipBullet1.fire(spaceShip.getPos(), spaceShip.getDir());
        bulletsOut++;
        bulletReady = false;
        bulletShot = frameCount;
      }
      else if(!(shipBullet2.isActive()))
      {
        shipBullet2.fire(spaceShip.getPos(), spaceShip.getDir());
        bulletsOut++;
        bulletReady = false;
        bulletShot = frameCount;
      }
      else if(!(shipBullet3.isActive()))
      {
        shipBullet3.fire(spaceShip.getPos(), spaceShip.getDir());
        bulletsOut++;
        bulletReady = false;
        bulletShot = frameCount;
      }
      else if(!(shipBullet4.isActive()))
      {
        shipBullet4.fire(spaceShip.getPos(), spaceShip.getDir());
        bulletsOut++;
        bulletReady = false;
        bulletShot = frameCount;
      }
    }//end if ready
  }//end if bulletsout
  }//end if space
}//end keypressed

void keyReleased()
{
  switch(keyCode)
  {
    case RIGHT: 
      turnRight = false;
      break;
    case LEFT: 
      turnLeft = false;
      break;
    case UP:
      move = false;
      break;
  }
}//end keyreleased


//////////////////////////////////////////////////////////////////////////
//----------------------create asteroids----------------------------------
//////////////////////////////////////////////////////////////////////////
void asteroidSetup(int num)
{
  for(int i = 0; i < num; i++)
  {
    asteroid = new Asteroid(1.5, int(random(0,3)), 1.0);
    asteroidList.add(asteroid);
  }
}//end create asteroids


///////////////////////////////////////////////////////////////////////////////////////////
//-----------------------------split asteroids into pieces---------------------------------
///////////////////////////////////////////////////////////////////////////////////////////
void splitAsteroid(int astNum)
{
  if(!(asteroidList.get(astNum).beenHit))
  {
   
   asteroid = new Asteroid(1.5, 1, 1.0);
   asteroid.setPosDir(asteroidList.get(astNum).getPos(), asteroidList.get(astNum).getDir() );
   asteroid.reScale(0.5);
   asteroid.changeDirection(22);
   asteroid.beenHit = true;
   asteroidList.add(asteroid);
   
   asteroid = new Asteroid(1.5, asteroidList.get(astNum).getImageNum(), 1.0);
   asteroid = asteroidList.get(astNum);
   asteroid.beenHit = true;
   asteroidList.remove(astNum);
   asteroid.reScale(0.75);
   asteroid.changeDirection(-22);
   asteroidList.add(asteroid);
  }
  else
  {
    highScore += 1000;
    asteroidList.remove(astNum);
  }
}//end splitAsteroid