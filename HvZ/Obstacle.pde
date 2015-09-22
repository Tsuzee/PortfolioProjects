//Obstacle Class to generate objects to avoid

class Obstacle
{
  //variables
  float radius;
  
  PVector pos;
  
  PShape obstacleShape;
  
  PImage obstacleImg;
  
  
  ////////////////////////////////////////////////////////////////////////
  //---------------------------Constructor-------------------------------
  ///////////////////////////////////////////////////////////////////////
  Obstacle(float x_, float y_, float radius_, PImage obstacleImg_)
  {
    pos = new PVector(x_, y_);
    radius = radius_;
    obstacleShape = createShape(RECT, pos.x, pos.y, radius, radius);
    //radius = radius / 8;
    obstacleImg = obstacleImg_;
    obstacleShape.setTexture(obstacleImg);
  }//end constructor
  
  
  //////////////////////////////////////////////////////////////
  //------------------------Methods----------------------------
  //////////////////////////////////////////////////////////////
  
  //display the obstacle to the screen
  void display()
  {
    fill(127);
    stroke(0);
    strokeWeight(1);
    noFill();
    obstacleShape.setStroke(0);
    
    shapeMode(CENTER);
 
    shape(obstacleShape);
  }//end display
  
}//end class