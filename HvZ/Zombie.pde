//Class for my lovely zombies

class Zombie
{
  //varaibles
  PShape myZombie;
  
  PVector target;
  
  Seeker seek;
  
  ///////////////////////////////////////////////////////////////////////
  //---------------------------Constructor-------------------------------
  ///////////////////////////////////////////////////////////////////////
  Zombie(float x_, float y_)
  {    
    seek = new Seeker(x_, y_, 25, 1, 0.1);
    myZombie = createShape(RECT, 0, 0, 25, 25);
    myZombie.setTexture( zomImgs.get(int(random(0,2))) );
  }//end Constructor
  
  
  //////////////////////////////////////////////////////////////
  //------------------------Methods----------------------------
  //////////////////////////////////////////////////////////////
  
  void update()
  {    
    // Call the appropriate steering behaviors for our agents
    float dist = 100;
    PVector temp = new PVector(0,0);
    
    target = null;
    
    //check for nearby humans
    for(Human hum : Hums)
    {
      temp = hum.flee.position.copy();
      temp.sub(seek.position.copy());
      
      //check to see if zombie has caught the human
      if(temp.mag() < (seek.r + hum.flee.r) - ((seek.r + hum.flee.r)/4) )
      {
        eaten.add(hum);
      }
      
      else if(temp.mag() < dist)
      {
        //persue nearest human
        dist = temp.mag();
        target = hum.flee.position.copy();
      }
    }
    
    seek.setTarget(target);
    seek.update();
  }//end update
  
  void display()
  {
    noFill();
    myZombie.setStroke(0);
    
    seek.display(myZombie);
  }//end display
  
}//end class