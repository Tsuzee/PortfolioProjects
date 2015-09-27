using System;
using System.Collections.Generic;
using System.Linq;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Audio;
using Microsoft.Xna.Framework.Content;
using Microsoft.Xna.Framework.GamerServices;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework.Input;
using Microsoft.Xna.Framework.Media;
using System.Text;

namespace GemCollector
{
    class GameVariables
    {
        private ContentManager myContent;

        public int Level = 0;
        public int numOfGems = 5;
        public float playerSpeed = 100;

        public SpriteFont Font1;
        public SpriteFont Font1Bold;

        //textures
        public Texture2D[] Background;
        public Texture2D[] GemImages;
        public Texture2D PlayerDown1;
        public Texture2D PlayerDown2;
        public Texture2D PlayerDown3;
        public Texture2D PlayerUp1;
        public Texture2D PlayerUp2;
        public Texture2D PlayerUp3;
        public Texture2D PlayerRight1;
        public Texture2D PlayerRight2;
        public Texture2D PlayerRight3;
        public Texture2D PlayerLeft1;
        public Texture2D PlayerLeft2;
        public Texture2D PlayerLeft3;

        public GameVariables(ContentManager content)
        {
            myContent = content;
        }

        //set background images
        public void setBackground()
        {
            Background = new Texture2D[25];
            Background[0] = myContent.Load<Texture2D>("ft2_01");
            Background[1] = myContent.Load<Texture2D>("ft2_02");
            Background[2] = myContent.Load<Texture2D>("ft2_03");
            Background[3] = myContent.Load<Texture2D>("ft2_04");
            Background[4] = myContent.Load<Texture2D>("ft2_05");
            Background[5] = myContent.Load<Texture2D>("ft2_06");
            Background[6] = myContent.Load<Texture2D>("ft2_07");
            Background[7] = myContent.Load<Texture2D>("ft2_08");
            Background[8] = myContent.Load<Texture2D>("ft2_09");
            Background[9] = myContent.Load<Texture2D>("ft2_10");
            Background[10] = myContent.Load<Texture2D>("ft2_11");
            Background[11] = myContent.Load<Texture2D>("ft2_12");
            Background[12] = myContent.Load<Texture2D>("ft2_13");
            Background[13] = myContent.Load<Texture2D>("ft2_14");
            Background[14] = myContent.Load<Texture2D>("ft2_15");
            Background[15] = myContent.Load<Texture2D>("ft2_16");
            Background[16] = myContent.Load<Texture2D>("ft2_17");
            Background[17] = myContent.Load<Texture2D>("ft2_18");
            Background[18] = myContent.Load<Texture2D>("ft2_19");
            Background[19] = myContent.Load<Texture2D>("ft2_20");
            Background[20] = myContent.Load<Texture2D>("ft2_21");
            Background[21] = myContent.Load<Texture2D>("ft2_22");
            Background[22] = myContent.Load<Texture2D>("ft2_23");
            Background[23] = myContent.Load<Texture2D>("ft2_24");
            Background[24] = myContent.Load<Texture2D>("ft2_25");
        }

        //set player images
        public void setPlayer()
        {
            PlayerDown1 = myContent.Load<Texture2D>("Down1");
            PlayerDown2 = myContent.Load<Texture2D>("Down2");
            PlayerDown3 = myContent.Load<Texture2D>("Down3");
            PlayerUp1 = myContent.Load<Texture2D>("Up1");
            PlayerUp2 = myContent.Load<Texture2D>("Up2");
            PlayerUp3 = myContent.Load<Texture2D>("Up3");
            PlayerRight1 = myContent.Load<Texture2D>("Right1");
            PlayerRight2 = myContent.Load<Texture2D>("Right2");
            PlayerRight3 = myContent.Load<Texture2D>("Right3");
            PlayerLeft1 = myContent.Load<Texture2D>("Left1");
            PlayerLeft2 = myContent.Load<Texture2D>("Left2");
            PlayerLeft3 = myContent.Load<Texture2D>("Left3");
        }

        //set gem images
        public void setGems()
        {
            GemImages = new Texture2D[10];
            GemImages[0] = myContent.Load<Texture2D>("Gem1");
            GemImages[1] = myContent.Load<Texture2D>("Gem2");
            GemImages[2] = myContent.Load<Texture2D>("Gem3");
            GemImages[3] = myContent.Load<Texture2D>("Gem4");
            GemImages[4] = myContent.Load<Texture2D>("Gem5");
            GemImages[5] = myContent.Load<Texture2D>("Gem6");
            GemImages[6] = myContent.Load<Texture2D>("Gem7");
            GemImages[7] = myContent.Load<Texture2D>("Gem8");
            GemImages[8] = myContent.Load<Texture2D>("Gem9");
            GemImages[9] = myContent.Load<Texture2D>("Gem10");
        }

        //set font
        public void setFont()
        {
            Font1 = myContent.Load<SpriteFont>("Font1");
            Font1Bold = myContent.Load<SpriteFont>("Font1Bold");
        }
    }//end class
}
