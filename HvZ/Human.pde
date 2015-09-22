//Class for my lovely zombies

class Human
{
  //varaibles
  PShape myHuman;
  
  PVector target;
  
  Fleer flee;
  
  ///////////////////////////////////////////////////////////////////////
  //---------------------------Constructor-------------------------------
  ///////////////////////////////////////////////////////////////////////
  Human(float x_, float y_)
  {    
    flee = new Fleer(x_, y_, 25, 2, 0.1);
    myHuman = createShape(RECT, 0, 0, 25, 25);
    myHuman.setTexture(humImgs.get(int(random(0,2))));
  }//end Constructor
  
  
  //////////////////////////////////////////////////////////////
  //------------------------Methods----------------------------
  //////////////////////////////////////////////////////////////
  void update()
  {    
    // Call the appropriate steering behaviors for our agents
    float dist = 75;
    PVector temp = new PVector(0,0);
    
    target = null;
    
    //check for nearby zombies
    for(Zombie zom : Zoms)
    {
      temp = zom.seek.position.copy();
      temp.sub(flee.position.copy());
      if(temp.mag() < dist)
      {
        //flee the closest zombie
        dist = temp.mag();
        target = zom.seek.position.copy();
      }
    }
    
    flee.setChaser(target);
    flee.update();
  }//end update
  
  
  void display()
  {
    noFill();
    myHuman.setStroke(0);
    
    flee.display(myHuman);
  }//end display
  
}//end class