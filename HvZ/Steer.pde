//Steer class
//Implements a steering component for this vehicle
//providing frequently used steering functions
//each of which returns a vector steering force

class Steer 
{
  Vehicle vehicle;

  ///////////////////////////////////////////////////////////////////////
  //---------------------------Constructor-------------------------------
  ///////////////////////////////////////////////////////////////////////
  Steer (Vehicle vehicle_) {
    vehicle = vehicle_;
  }

  //////////////////////////////////////////////////////////////
  //------------------------Methods----------------------------
  //////////////////////////////////////////////////////////////

  // steering force towards a target
  PVector seek(PVector target) 
  {
    PVector desired = PVector.sub(target, vehicle.position);  
    desired.normalize();
    desired.mult(vehicle.maxSpeed);
    PVector steer = PVector.sub(desired, vehicle.velocity); 
    return steer;
  }
  
  // steering force away a target
  PVector flee(PVector target) 
  {
    PVector desired = PVector.sub(target, vehicle.position);  
    desired.mult(-1);
    desired.normalize();
    desired.mult(vehicle.maxSpeed);
    PVector steer = PVector.sub(desired, vehicle.velocity); 
    return steer;
  }
  
  // steering force towards a target with greater urgency
  PVector pursue(PVector target) 
  {
    PVector desired = PVector.sub(target, vehicle.position);  
    desired.normalize();
    desired.mult((vehicle.maxSpeed) * 1.5);
    PVector steer = PVector.sub(desired, vehicle.velocity); 
    return steer;
  }
  
  // steering force away from a target with greater urgency
  PVector evade(PVector target) 
  {
    PVector desired = PVector.sub(target, vehicle.position);  
    desired.mult(-1);
    desired.normalize();
    desired.mult((vehicle.maxSpeed) * 2);
    PVector steer = PVector.sub(desired, vehicle.velocity); 
    return steer;
  }
  
  //wander steering forces in a random direction
  //basic code taken from Explanation of Wander method in content resources
  PVector wander()
  {
    //set a circleCenter in front of the vehicle
    PVector circleCenter = vehicle.velocity.copy();
    
    //take a arbritry vector with length 1 and give it the length of the vehicle
    PVector displacement = new PVector( int(random(-1,2)), int(random(-1,2)) );
    displacement.mult(vehicle.r);
    
    //rotate it by a random angle and add it to the center of our circle and return
    //it as our wandering force
    displacement.rotate(random(-7, 7));
    circleCenter.add(displacement);
    
    return circleCenter;
  }
  
  //Obstacle Avoidence
  PVector avoidObstacle (Obstacle obst, float safeDistance) 
  {
    PVector steer = new PVector(0, 0);
    float fwdDot;
    float rightDot;
    
    // Create vecToCenter - a vector from the character to the center of the obstacle
    PVector VtoC = new PVector(0,0);
    VtoC = obst.pos.copy();
    VtoC.sub(vehicle.position.copy());
    
    fwdDot = vehicle.fwd.dot(VtoC);
    rightDot = vehicle.right.dot(VtoC);
    //line(vehicle.position.x, vehicle.position.y, obst.pos.x, obst.pos.y);
    
    //Find the distance to the obstacle and Return a zero vector if the obstacle is too far to concern us
    if( (obst.radius/2 + vehicle.r + safeDistance) < VtoC.mag() )
    {
      return steer;
    }
        
    if(debugObs)
    {
      pushMatrix();
      translate(vehicle.position.x, vehicle.position.y);
      line(0, 0, VtoC.x, VtoC.y);
      popMatrix();
    }
    
    // Return a zero vector if the obstacle is behind us
    // (dot product of vecToCenter and forward is negative)
    if( fwdDot < 0 )
    {
      return steer;
    }
    
    // Use the dot product of the vector to obstacle center (vecToCenter) and the unit vector
    // to the right (right) of the vehicle to find the distance between the centers
    // of the vehicle and the obstacle
    // Compare this to the sum of the radii and return a zero vector if we can pass safely
    if( rightDot > (obst.radius/2 + vehicle.r + safeDistance) )
    {
      return steer;
    }
    
    // If we get this far we are on a collision course and must steer
    // Use the sign of the dot product between the vector to center (vecToCenter) and the
    // vector to the right (right) to determine whether to steer left or right
    if(rightDot > 0)
    {
      steer = PVector.mult(vehicle.right, -vehicle.maxSpeed);
    }
    else
    {
      steer = PVector.mult(vehicle.right, vehicle.maxSpeed);
    }
    
    steer.mult(safeDistance / VtoC.mag());
    // For each case calculate desired velocity using the right vector and maxSpeed
    // Compute the force required to change current velocity to desired velocity
    // Consider multiplying this force by safeDistance/dist to increase the relative weight
    // of the steering force when obstacles are closer.
    
    return steer;
  }//end avoid obstacle
  
}//end class