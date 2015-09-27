using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;


namespace GemCollector
{
    public class GameObject
    {
        public Texture2D texture;
        public Rectangle positionRec;
        public float x { get; set; }
        public float y { get; set; }

        public GameObject(int x, int y, int width, int height)
        {
            this.x = x;
            this.y = y;
            positionRec = new Rectangle(x, y, width, height);
        }

        //draw object
        public virtual void Draw(SpriteBatch sprite)
        {
            positionRec.X = (int)x;
            positionRec.Y = (int)y;
            sprite.Draw(texture, positionRec, Color.White);
        }
    }//end class
}
