//Ship class

class Ship
{
  //variables
  PVector position;
  PVector velocity;
  PVector direction;
  PVector driftDirection;
  PVector drift;
  
  float speed;
  float accel;
  float terminalVel;
  float friction;
  
  boolean showShip = true;
  boolean shipActive = true;
  
  PShape ship;
  PShape shipFlame;
  
  
  //////////////////////////////////////////////////////////////////
  //-----------------------Constructor------------------------------
  //////////////////////////////////////////////////////////////////
  Ship(float s)
  {
    position = new PVector(width/2, height/2);
    velocity = new PVector(0, 0);
    direction = new PVector(0, 0);
    driftDirection = new PVector(0,0);
    drift = new PVector(0,0);
    terminalVel = 6.0;
    speed = s;
    
    PVector.fromAngle(radians(-90), direction);
    accel = .1;
    terminalVel = 6.0;
    friction = 0.95;
    
    ship = createShape();
    ship.beginShape();
      ship.vertex(15, 10);
      ship.vertex(10, 0);
      ship.vertex(30, 10);
      ship.vertex(10, 20);
    ship.endShape(CLOSE);
  }
  
  

  //////////////////////////////////////////////////////////////
  //------------------------Methods----------------------------
  //////////////////////////////////////////////////////////////
  void updatePosition()
  {
    driftDirection.mult(0);
    if(turnRight)
    {
      direction.rotate(radians(3));
      driftDirection = direction.copy();
      driftDirection.rotate(-1.5);
    }
    if(turnLeft)
    {
      direction.rotate(radians(-3));
      driftDirection = direction.copy();
      driftDirection.rotate(1.5);
    }
    if(move)
    {
      speed += accel;
    }
    if(!move)
    {
      if(speed > 0)
      {
        speed *= friction;
      }
      if(speed < 0.001)
      {
        speed = 0;
      }
    }
      
    drift = PVector.mult(driftDirection, speed * .6);
    drift.limit(terminalVel-2);
    position.add(drift);
    velocity = PVector.mult(direction, speed);
    velocity.limit(terminalVel);
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
    if(showShip)
    {
      strokeWeight(2);
      pushMatrix();
      shapeMode(CENTER);
      translate(position.x, position.y);
      rotate(direction.heading());
      shape(ship); 
      popMatrix();
    }
  }
  
  PVector getPos()
  {
    return position.copy();
  }
  
  PVector getDir()
  {
    return direction.copy();
  }
  
  float getSpeed()
  {
    return speed;
  }
  
}//end class