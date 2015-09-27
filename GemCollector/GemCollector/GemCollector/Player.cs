using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;

namespace GemCollector
{
    class Player : GameObject
    {
        public int levelScore;
        public int totalScore;

        public Player(int x, int y, int width, int height) : base(x, y, width, height)
        {
            levelScore = 0;
            totalScore = 0;
        }

        //sets the players current texture
        public void setTexture(Texture2D newTexture)
        {
            texture = newTexture;
        }//end setTexture

        public override void Draw(SpriteBatch sprite)
        {
            base.Draw(sprite);
        }
    }//end class
}
