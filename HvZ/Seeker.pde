//Seeker class
//Creates an inherited Seeker object from the Vehicle class
//Due to the abstract nature of the vehicle class, the Seeker 
//  must implement the following methods: calcSteeringForces() and display()

class Seeker extends Vehicle {
  
  //---------------------------------------
  //Class fields
  //---------------------------------------
  //seeking target
  PVector target = null;
  
  //stage dimensions - the box the seeker stays in
  PVector center = new PVector(width/2, height/2);
  
  //weights for steering forces
  //right now, staying in the box is more important that chasing the target
  float stageWt = 100;
  float targetWt = 10;
  float totalWt = stageWt + targetWt;
  
  //This component implements steering forces
  //implements fleeing, seeking, avoidance behaviors
  //write one time by creating a class that can be re-used
  Steer steer;
  
  ///////////////////////////////////////////////////////////////////////
  //---------------------------Constructor-------------------------------
  ///////////////////////////////////////////////////////////////////////
  Seeker(float x_, float y_, float r_, float maxSpeed_, float maxForce) {
    //call the super class' constructor
    super(x_, y_, r_, maxSpeed_, maxForce);
    //create a Steer component
    steer = new Steer(this);
    velocity.add(new PVector(0.5,0));
  }//end constructor

  //////////////////////////////////////////////////////////////
  //------------------------Methods----------------------------
  //////////////////////////////////////////////////////////////
  
  //Calculate the Steering Forces
  void calcSteeringForces() {
    PVector force = new PVector(0, 0);


    if (target != null) 
    {
      //find distance to the target and determine whether to persue or seek
      PVector DtoT = target.copy();
      DtoT.sub(position.copy());
      
      if(DtoT.mag() < 2 * r)
      {
        force.add(PVector.mult(steer.pursue(target), targetWt));
      }
      else
      {
        force.add(PVector.mult(steer.seek(target), targetWt));
      }
    }
    else
    {
      force.add(PVector.mult(steer.wander(), 5));
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

  //setter for seek target
  void setTarget(PVector target_) {
    target = target_;
  }
  
  //test for outside stage border
  boolean offStage(float dist){
    boolean off = false;
    if (position.x < dist) off = true;
    else if (position.x > width - dist) off = true;
    else if (position.y < dist) off = true;
    else if (position.y > height - dist) off = true;
    return off;
  }

  //All Vehicles must implement display
  void display(PShape myShape) {
    //display options
    stroke(0);
    strokeWeight(1);
    noFill();
    
    // Draw rotated in the direction of velocity
    float theta = velocity.heading() + PI/2;
    fill(127);
    stroke(0);
    strokeWeight(1);
    shapeMode(CENTER);
   
    pushMatrix();
      translate(position.x, position.y);
      rotate(theta);
      shape(myShape);
      if(debug && temp != null)
      {
        line(0, 0, temp.x, temp.y);
      }
    popMatrix();
  }
}