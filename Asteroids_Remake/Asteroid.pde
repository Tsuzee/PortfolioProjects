//Asteroid class

class Asteroid
{
  //variables
  PVector position;
  PVector velocity;
  PVector direction;
  
  PShape asteroid1;
  PShape asteroid2;
  PShape asteroid3;
  
  PShape[] asteroids;
  
  float speed;
  float scale;
  
  int asteroidNum;
  int startX;
  int startY;
  
  boolean beenHit = false;
  
  //////////////////////////////////////////////////////////////////
  //-----------------------Constructor------------------------------
  //////////////////////////////////////////////////////////////////
  Asteroid(float s, int num, float scale_)
  {
    //position = new PVector(width/3, height/3);
    startX = int(random(0, width));
    startY = int(random(0, height));
    if(startX > (width/2 - 25) && startX < (width/2 + 25) && startY > (height/2 - 25) && startY < (height/2 + 25) )
    {
      startX -= 50;
      startY += 50;
    }
    position = new PVector(startX, startY);
    
    velocity = new PVector(0, 0);
    direction = new PVector(random(-1,1), random(-1,1));
    speed = s;
    asteroidNum = num;
    scale = scale_;
    strokeWeight(2);
    stroke(255);
    
    asteroid1 = createShape();
    asteroid1.beginShape();
      asteroid1.vertex(0, 5);
      asteroid1.vertex(10, 15);
      asteroid1.vertex(0, 20);
      asteroid1.vertex(5, 30);
      asteroid1.vertex(10, 22);
      asteroid1.vertex(15, 30);
      asteroid1.vertex(40, 22);
      asteroid1.vertex(25, 17);
      asteroid1.vertex(40, 10);
      asteroid1.vertex(25, 0);
      asteroid1.vertex(20,5);
      asteroid1.vertex(18,0);
    asteroid1.endShape(CLOSE);
    asteroid1.setFill(0);
    asteroid1.setStroke(#FFFFFF);
    asteroid1.setStrokeWeight(2);
    
    
    asteroid2 = createShape();
    asteroid2.beginShape();
      asteroid2.vertex(0, 10);
      asteroid2.vertex(0, 20);
      asteroid2.vertex(10, 30);
      asteroid2.vertex(20, 30);
      asteroid2.vertex(25, 35);
      asteroid2.vertex(32, 28);
      asteroid2.vertex(25, 20);
      asteroid2.vertex(35, 17);
      asteroid2.vertex(35, 10);
      asteroid2.vertex(25, 0);
      asteroid2.vertex(10,0);
    asteroid2.endShape(CLOSE); 
    asteroid2.setFill(0);
    asteroid2.setStroke(#FFFFFF);
    asteroid2.setStrokeWeight(2);
    
    
    asteroid3 = createShape();
    asteroid3.beginShape();
      asteroid3.vertex(10, 0);
      asteroid3.vertex(0, 10);
      asteroid3.vertex(0, 20);
      asteroid3.vertex(10, 30);
      asteroid3.vertex(20, 30);
      asteroid3.vertex(40, 20);
      asteroid3.vertex(35, 15);
      asteroid3.vertex(40, 10);
      asteroid3.vertex(25, 0);
      asteroid3.vertex(20, 10);
    asteroid3.endShape(CLOSE);
    asteroid3.setFill(0);
    asteroid3.setStroke(#FFFFFF);
    asteroid3.setStrokeWeight(2);
    
    asteroids = new PShape[3];
    asteroids[0] = asteroid1;
    asteroids[1] = asteroid2;
    asteroids[2] = asteroid3;
  }
  
  
  //////////////////////////////////////////////////////////////
  //------------------------Methods----------------------------
  //////////////////////////////////////////////////////////////
  void updatePosition()
  {    
    velocity = PVector.mult(direction, speed);
    position.add(velocity);
    
    if(position.x > width)
    {
      position.x = 0;
    }
    if(position.x < 0)
    {
      position.x = width;
    }
    
    if(position.y > height)
    {
      position.y = 0;
    }
    if(position.y < 0)
    {
      position.y = height;
    }
  }
  
  void display()
  {
    pushMatrix();
    shapeMode(CENTER);
    translate(position.x, position.y);
    scale(scale);
    shape(asteroids[asteroidNum]);
    popMatrix();
  }
  
  void changeDirection(int direct)
  {
    direction.rotate(radians(direct));
  }//end change direction
  
  void setPosDir(PVector pos, PVector dir)
  {
    position = pos.copy();
    direction = dir.copy();
  }
  
  PVector getPos()
  {
    return position.copy();
  }
  
  PVector getDir()
  {
    return direction.copy();
  }
  
  void reScale(float newScale)
  {
    scale = newScale;
  }//end rescale
  
  int getImageNum()
  {
    return asteroidNum;
  }
}//end class