//Fleer class
//Creates an inherited Fleer object from the Vehicle class
//Due to the abstract nature of the vehicle class, the Fleer 
//must implement the following methods: calcSteeringForces() and display()

class Fleer extends Vehicle 
{
  //fleer chaser
  PVector chaser = null;
  
  //stage dimensions - the box the seeker stays in
  PVector center = new PVector(width/2, height/2);
  //float border = 200;
  
  //weights for steering forces
  //right now, staying in the box is more important that chasing the chaser
  float stageWt = 50;
  float chaserWt = 10;
  float totalWt = stageWt + chaserWt;
  
  //This component implements steering forces
  //implements fleeing, seeking, avoidance behaviors
  //write one time by creating a class that can be re-used
  Steer steer;
  
  ///////////////////////////////////////////////////////////////////////
  //---------------------------Constructor-------------------------------
  ///////////////////////////////////////////////////////////////////////
  Fleer(float x_, float y_, float r_, float maxSpeed_, float maxForce) {
    //call the super class' constructor
    super(x_, y_, r_, maxSpeed_, maxForce);
    //create a Steer component
    steer = new Steer(this);
    velocity.add(new PVector(1,0));
  }//end constructor


  
  //////////////////////////////////////////////////////////////
  //------------------------Methods----------------------------
  //////////////////////////////////////////////////////////////
  
  //Calculate the Steering Forces
  void calcSteeringForces() {
    PVector force = new PVector(0, 0);

    if (chaser != null) 
    {
      //find distance to the target and determine whether to flee or evade
      PVector DtoT = chaser.copy();
      DtoT.sub(position.copy());
      
      if(DtoT.mag() < 2 * r)
      {
        force.add(PVector.mult(steer.evade(chaser), chaserWt));
      }
      else
      {
        force.add(PVector.mult(steer.flee(chaser), chaserWt));
      }
    }
    else
    {
      force.add(PVector.mult(steer.wander(), chaserWt));
    }
    
    if (offStage(border)){
      force.add(PVector.mult(steer.seek(center), stageWt));
    }
    
    force.limit(maxForce);
    //could add other steering forces here
    for(Obstacle obsta : obs)
    {
      force.add(steer.avoidObstacle(obsta, 5));
    }
    force.limit(maxForce); // this second limitation smoothed out the motion mostly
    
    applyForce(force);
  }//end calcsteering
  
  //setter for seek chaser
  void setChaser(PVector chaser_) 
  {
    chaser = chaser_;
  }//end set chaser
  
  //test for outside stage border
  boolean offStage(float dist){
    boolean off = false;
    if (position.x < dist) off = true;
    else if (position.x > width - dist) off = true;
    else if (position.y < dist) off = true;
    else if (position.y > height - dist) off = true;
    return off;
  }//end off stage

  //display
  void display(PShape myShape) {
    //display options
    
    stroke(100);
    strokeWeight(1);
    noFill();
    
    // Draw a triangle rotated in the direction of velocity
    float theta = velocity.heading() + PI/2;
    fill(127);
    stroke(0);
    strokeWeight(1);
    pushMatrix();
      translate(position.x, position.y);
      rotate(theta);
      shape(myShape);
      //draw a debug line
      if(debug && temp != null)
      {
        line(0, 0, temp.x, temp.y);
      }
    popMatrix();
  }
}//end display