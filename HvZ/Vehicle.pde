//Vehicle class
//Seekers and Fleers will extend this class
//Thus, every Seeker and Fleer will use this as their base

abstract class Vehicle 
{
  //vectors for moving vehicle
  PVector position;
  PVector velocity;
  PVector acceleration;

  float r;             //radius - not correct for this display
  float maxForce;      //Maximum steering force
  float maxSpeed;      //Maximum speed
  float mass = 1.0;    //arbitrary value will alter acceleration
  
  //orientation vectors provide local point of view for vehicle
  PVector fwd;
  PVector right;
  PVector temp;

  ///////////////////////////////////////////////////////////////////////
  //---------------------------Constructor-------------------------------
  ///////////////////////////////////////////////////////////////////////
  Vehicle(float x_, float y_, float r_, float maxSpeed_, float maxForce_) 
  {
    acceleration = new PVector(0, 0);
    velocity = new PVector(0, 0);
    position = new PVector(x_, y_);
    fwd = new PVector(0,0);
    right = new PVector(0,0);
    r = r_;
    maxSpeed = maxSpeed_;
    maxForce = maxForce_;
  }//end constructor
  
  //////////////////////////////////////////////////////////////
  //--------------------Abstract Methods------------------------
  //////////////////////////////////////////////////////////////

  //every sub-class Vehicle must use these functions
  abstract void calcSteeringForces();
  abstract void display(PShape myShape);
  
  //update position
  void update() 
  {
    //sum and apply steering forces
    calcSteeringForces();
    //update velocity
    velocity.add(acceleration);
    fwd = velocity.copy();
    //limit speed
    velocity.limit(maxSpeed);
    //change position
    position.add(velocity);
    //reset acceleration to 0 each cycle
    acceleration.mult(0);
    
    //fwd = velocity.get();
    fwd.normalize();
    //println("Fwd: " + fwd);
    right.x = fwd.y;
    right.mult(-1);
    right.y = fwd.x;
    
    //temp vector for debug mode
    temp = position.copy();
    temp.add(velocity);
    temp.setMag(50);
    temp.rotate(-PI/2);
  }//end update

  void applyForce(PVector force) 
  {
    acceleration.add(PVector.div(force, mass));
  }
  
}//end class