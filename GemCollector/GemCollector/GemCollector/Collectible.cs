using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;

namespace GemCollector
{
    class Collectible : GameObject
    {
        public bool active { get; set; }


        public Collectible(Texture2D newTexture, int x, int y, int width, int height) : base(x, y, width, height)
        {
            active = true;
            this.texture = newTexture;
        }

        //check to see if an object is colliding with this object
        public bool CheckCollision(GameObject aObject)
        {
            if(!active)
            {
                return false;
            }

            if(aObject.positionRec.Intersects(this.positionRec))
            {
                return true;
            }
            else
            {
                return false;
            }
        }//end checkcollision

        //draw the collectible only if it is active
        public override void Draw(SpriteBatch sprite)
        {
            if(active)
            {
                base.Draw(sprite);
            }
        }//end draw

    }//end class
}
