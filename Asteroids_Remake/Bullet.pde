//Bullet Class

class Bullet
{
  //variables
  PVector position;
  PVector velocity;
  PVector direction;
  
  boolean active;
  float speed;
  float shipSpeed;
  int pixelsMoved;
  
  
  //////////////////////////////////////////////////////////////////
  //-----------------------Constructor------------------------------
  //////////////////////////////////////////////////////////////////
  Bullet()
  {
    position = new PVector(width/2, height/2);
    velocity = new PVector(0, 0);
    direction = new PVector(0, 0);
    speed = 8;
    active = false;
    pixelsMoved = 0;
    
  }//end constructor
  
  
  //////////////////////////////////////////////////////////////
  //------------------------Methods----------------------------
  //////////////////////////////////////////////////////////////
  void fire(PVector currentP, PVector currentD)
  {
    position = currentP.copy();
    direction = currentD.copy();
    active = true;
  }//end fire
  
  boolean isActive()
  {
    return active;
  }
  
  void updatePosition()
  {
    if(active)
    {
      velocity = PVector.mult(direction, speed);
      position.add(velocity);
      pixelsMoved++;
    
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
      
      if(pixelsMoved > 75)
      {
        active = false;
        pixelsMoved = 0;
        bulletsOut--;
      }
    }
  }//end update
  
 //draw bullet
  void display()
  {     
    if(active)
    {
      fill(255);
      stroke(255);
      ellipseMode(CENTER);
      ellipse(position.x, position.y, 3, 3);
    }
  
  }//end display
  
  PVector bulletPos()
  {
    return position.copy();
  }
  
}//end class