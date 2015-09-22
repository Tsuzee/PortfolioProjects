//Mover class

class Ship
{
  //variables
  PVector position;
  PVector velocity;
  PVector direction;
  
  int shipRadius;
  
  ///////////////////////////////////////////////////////////////////////
  //--------------------------Constructor-------------------------------
  //Purpose:  Instantiates vectors, sets position to center of window
  ///////////////////////////////////////////////////////////////////////
  Ship(int start)
  {
    shipRadius = 15;
    position = new PVector(start + shipRadius, height/2);
    velocity = new PVector(0, 0);
    direction = new PVector(0, 0);
    PVector.fromAngle(0, direction);
    speed = 2;
    
  }
  
  /////////////////////////////////////////////////////////////////////
  //----------------------------Methods--------------------------------
  /////////////////////////////////////////////////////////////////////
  void updatePosition()
  {
    
    //SET THE DIRECTION VECTOR VALUES FOR MOVELEFT, MOVERIGHT
    if(moveRight)
    {
      direction.x = 1;
      direction.y = 0;
    }
    if(moveLeft)
    {
      direction.x = -1;
      direction.y = 0;
    }
    if(noMove)
    {
      direction.x = 0;
      direction.y = 0;
    }
    
    //calculate new velocity and change the ships position
    velocity = PVector.mult(direction, speed);
    position.add(velocity);
  }//end updatePosition
  
  
  //draw the ship to the screen
  void display()
  {
    fill(0,0,255);
    stroke(0);
    strokeWeight(2);
    ellipseMode(CENTER);
    ellipse(position.x, position.y, shipRadius, shipRadius);

  }//end display
  
  //return x coordinate of position
  float getXPos()
  {
    return position.x;
  }
  
}  //end class