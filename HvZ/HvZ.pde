import ddf.minim.*;

//Darren Farr
//IMD TR 11:00
//Home Work #5

//Globals
Zombie myZom;
Human myHum;
Obstacle ob;
//SoundCipher sc;
Minim minim;
AudioPlayer player;

ArrayList<PImage> zomImgs;
ArrayList<Zombie> Zoms;
ArrayList<PImage> humImgs;
ArrayList<Human> Hums;
ArrayList<Obstacle> obs;
ArrayList<Human> eaten;

int imageNum;

float border;

PFont monoFont;

PShape backgroundImg;

boolean debug = false;
boolean debugObs = false;
boolean soundOn = true;
boolean playing = false;

/////////////////////////////////////////////////////////////////
//----------------------initial setup----------------------------
/////////////////////////////////////////////////////////////////
void setup()
{
  size(1000, 700, P2D);
  background(128);
  import arb.soundcipher.*;
  //sc = new SoundCipher(this);
  //sound
  minim = new Minim(this);
  player = minim.loadFile("yay.mp3");
    
  //load in assets
  loadAssets();
  
  //create the first zombie and add it to the list
  myZom = new Zombie(width/2, height/2);
  Zoms = new ArrayList<Zombie>();
  Zoms.add(myZom);
  
  //create list for deleating humans
  eaten = new ArrayList<Human>();
  
  //create 6 humans
  Hums = new ArrayList<Human>();
  
  myHum = new Human( (random(200, 500)), (random(200, 300)) );
  Hums.add(myHum);
  myHum = new Human( (random(200, 500)), (random(200, 300)) );
  Hums.add(myHum);
  myHum = new Human( (random(200, 500)), (random(200, 300)) );
  Hums.add(myHum);
  
  myHum = new Human( (random(200, 500)), (random(350, 600)) );
  Hums.add(myHum);
  myHum = new Human( (random(200, 500)), (random(350, 600)) );
  Hums.add(myHum);
  myHum = new Human( (random(200, 500)), (random(350, 600)) );
  Hums.add(myHum);
  
  //set variables
  border = 50;
  imageNum = 0;
  
  //setup text font
  monoFont = loadFont("AndaleMono-24.vlw");
  textFont(monoFont);
  textSize(17);
}//end setup

/////////////////////////////////////////////////////////////////
//---------------------------draw--------------------------------
/////////////////////////////////////////////////////////////////
void draw()
{
  background(128);
  
  if(soundOn && !playing)
  {
    //sc.playMidiFile("Music.mid", 220);
    playing = true;
    player.play();
  }
  else if(!soundOn && playing)
  {
    //sc.stop();
    playing = false;
    player.pause();
  }
  
  //display background image
  shape(backgroundImg);
  
  //display options
  stroke(0);
  strokeWeight(1);
  noFill();
  
  //draw humans and zombies
  
  for(Zombie zom : Zoms)
  {
    zom.update();
    zom.display();
  }
  
  for(Human hum : Hums)
  {
    hum.update();
    hum.display();
  }
  
  //display the obstacles
  for(Obstacle obsta : obs)
  {
    obsta.display();
  }
  
  for(Human hum : eaten)
  {
    myZom = new Zombie(hum.flee.position.x, hum.flee.position.y);
    Zoms.add(myZom);
    Hums.remove(hum);
  }
  eaten.clear();
  
  //draw game text
  fill(0);
  textSize(32);
  text("Humans vs. Zombies", width/2 - 175, 30);
  
  textSize(12);
  text("Press d to toggle debug mode.", 5, 15);
  text("Press o to toggle obstacle lines.", 5, 25);
  text("Press s to toggle sound.", 5, 35);
  
  if(Hums.isEmpty())
  {
    fill(255,0,0);
    textSize(72);
    text("Zombies Win", width/2 - 250, height/2);
  }
}//end draw

//////////////////////////////////////////////////////////////////
//----------------------load assets------------------------------
//////////////////////////////////////////////////////////////////
void loadAssets()
{
  //load the art assets
  //create 
  PImage Img;
  
  //zombie assets
  zomImgs = new ArrayList<PImage>();
  
  Img = loadImage("Zombie 0.png");
  zomImgs.add(Img);
  Img = loadImage("Zombie 1.png");
  zomImgs.add(Img);
  
  //human assets
  humImgs = new ArrayList<PImage>();
  
  Img = loadImage("Human 0.png");
  humImgs.add(Img);
  Img = loadImage("Human 1.png");
  humImgs.add(Img);
  
  //background assests
  Img = loadImage("Grass.png");
  backgroundImg = createShape(RECT, width/2, height/2, 900, 600);
  backgroundImg.setTexture(Img);
  backgroundImg.setStroke(0);
  

  //setup obstalce assets
  obs = new ArrayList<Obstacle>();
  
  //load trees
  Img = loadImage("Tree.png");
  
  ob = new Obstacle(175, 175, 75, Img);
  obs.add(ob);
  ob = new Obstacle(175, 525, 75, Img);
  obs.add(ob);
  ob = new Obstacle(825, 175, 75, Img);
  obs.add(ob);
  ob = new Obstacle(825, 525, 75, Img);
  obs.add(ob);
  ob = new Obstacle(463, 525, 75, Img);
  obs.add(ob);
  ob = new Obstacle(537, 525, 75, Img);
  obs.add(ob);
  ob = new Obstacle(463, 175, 75, Img);
  obs.add(ob);
  ob = new Obstacle(537, 175, 75, Img);
  obs.add(ob);
  
  //load fountains
  Img = loadImage("Fountain.png");
  ob = new Obstacle(333, 350, 75, Img);
  obs.add(ob);
  ob = new Obstacle(667, 350, 75, Img);
  obs.add(ob);
}//end loadAssets

////////////////////////////////////////////////////
//-----------------key listener---------------------
////////////////////////////////////////////////////
void keyPressed(){
  switch(key){
    case 'd': 
      {
       if(debug){debug = false;}
       else{debug = true;}
      }
      break;
    case 'o': 
      {
       if(debugObs){debugObs = false;}
       else{debugObs = true;}
      }
      break;
    case 's': 
      {
       if(soundOn){soundOn = false;}
       else{soundOn = true;}
      }
      break;
    default:
      break;
  }
}//end key pressed