using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Audio;
using Microsoft.Xna.Framework.Content;
using Microsoft.Xna.Framework.GamerServices;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework.Input;
using Microsoft.Xna.Framework.Media;

namespace GemCollector
{
    //game States
    public enum GameState
    {
        Menu,
        Playing,
        Won,
        GameOver
    }

    /// <summary>
    /// This is the main type for your game
    /// </summary>
    public class Game1 : Microsoft.Xna.Framework.Game
    {   
        //variables
        GraphicsDeviceManager graphics;
        SpriteBatch spriteBatch;

        GameVariables gameVars;
        Player player;
        Collectible gem;
        List<Collectible> Gems = new List<Collectible>();

        double timer = 31;
        int timeLeft;
        int picNum = 0; //for cycling through char pictures
        int gemsRemaining;
        Random rand = new Random();

        //state whether or not keys are pressed
        KeyboardState keyState;
        KeyboardState previousKeyState;

        //game state
        GameState currentState;

        public Game1()
        {
            graphics = new GraphicsDeviceManager(this);
            graphics.PreferredBackBufferHeight = 768;
            graphics.PreferredBackBufferWidth = 1024;

            Content.RootDirectory = "Content";

            gameVars = new GameVariables(this.Content);
            player = new Player(200, 200, 100, 100);

            currentState = GameState.Menu;
            gemsRemaining = gameVars.numOfGems;
            timeLeft = (int)timer;
        }

        /// <summary>
        /// Allows the game to perform any initialization it needs to before starting to run.
        /// This is where it can query for any required services and load any non-graphic
        /// related content.  Calling base.Initialize will enumerate through any components
        /// and initialize them as well.
        /// </summary>
        protected override void Initialize()
        {
            // TODO: Add your initialization logic here
            base.Initialize();

            //items to initialize after LoadContent
            NextLevel();
        }

        /// <summary>
        /// LoadContent will be called once per game and is the place to load
        /// all of your content.
        /// </summary>
        protected override void LoadContent()
        {
            // Create a new SpriteBatch, which can be used to draw textures.
            spriteBatch = new SpriteBatch(GraphicsDevice);

            // TODO: use this.Content to load your game content here
            //Load Images
            gameVars.setBackground();
            gameVars.setPlayer();
            gameVars.setFont();
            gameVars.setGems();
        }

        /// <summary>
        /// UnloadContent will be called once per game and is the place to unload
        /// all content.
        /// </summary>
        protected override void UnloadContent()
        {
            // TODO: Unload any non ContentManager content here
        }

        /// <summary>
        /// Allows the game to run logic such as updating the world,
        /// checking for collisions, gathering input, and playing audio.
        /// </summary>
        /// <param name="gameTime">Provides a snapshot of timing values.</param>
        protected override void Update(GameTime gameTime)
        {
            // Allows the game to exit
            if (GamePad.GetState(PlayerIndex.One).Buttons.Back == ButtonState.Pressed)
                this.Exit();

            // TODO: Add your update logic here
            keyState = Keyboard.GetState();
            

            //update certian elements based on gamestate
            switch(currentState)
            {
                case GameState.Menu:
                    {
                        if (keyState.IsKeyDown(Keys.Enter))
                        {
                            if (SingleKeyPress(keyState, previousKeyState, Keys.Enter))
                            {
                                currentState = GameState.Playing;
                            }
                        }
                        if (keyState.IsKeyDown(Keys.Escape))
                        {
                            Exit();
                        }
                        break;
                    }
                case GameState.Playing:
                    {
                        //game count down till end of level
                        timer -= (float)gameTime.ElapsedGameTime.TotalSeconds;
                        //move the player on screen
                        MovePlayer(gameTime);
                        if (gemsRemaining == 0)
                        {
                            Thread.Sleep(3000);
                            NextLevel();
                        }
                        if(timeLeft == 0)
                        {
                            currentState = GameState.GameOver;
                        }
                        if (keyState.IsKeyDown(Keys.Escape))
                        {
                            Exit();
                        }
                        break;
                    }
                case GameState.Won:
                    {
                        player.totalScore = player.levelScore;
                        if (keyState.IsKeyDown(Keys.Enter))
                        {
                            if (SingleKeyPress(keyState, previousKeyState, Keys.Enter))
                            {
                                ResetGame();//clear game for new game
                                currentState = GameState.Menu;
                            }
                        }
                        if (keyState.IsKeyDown(Keys.Escape))
                        {
                            Exit();
                        }
                        break;
                    }
                case GameState.GameOver:
                    {
                        player.totalScore = player.levelScore;
                        if (keyState.IsKeyDown(Keys.Enter))
                        {
                            if (SingleKeyPress(keyState, previousKeyState, Keys.Enter))
                            {
                                ResetGame();//clear game for new game
                                currentState = GameState.Menu;
                            }
                        }
                        if (keyState.IsKeyDown(Keys.Escape))
                        {
                            Exit();
                        }
                        break;
                    }
                default:
                    {
                        break;
                    }
            }//end gamestate switch

            previousKeyState = keyState;//set previous state for next update
            base.Update(gameTime);
        }

        /// <summary>
        /// This is called when the game should draw itself.
        /// </summary>
        /// <param name="gameTime">Provides a snapshot of timing values.</param>
        protected override void Draw(GameTime gameTime)
        {
            GraphicsDevice.Clear(Color.White);

            // TODO: Add your drawing code here
            spriteBatch.Begin();

            //draw certian elements based on gamestate
            switch (currentState)
            {
                case GameState.Menu:
                    {
                        //draw background
                        GraphicsDevice.Clear(Color.Black);

                        //draw gem graphic
                        spriteBatch.Draw(gameVars.GemImages[0], new Rectangle(100, 100, 50, 50), Color.White);
                        spriteBatch.Draw(gameVars.GemImages[1], new Rectangle(175, 100, 50, 50), Color.White);
                        spriteBatch.Draw(gameVars.GemImages[2], new Rectangle(250, 100, 50, 50), Color.White);
                        spriteBatch.Draw(gameVars.GemImages[3], new Rectangle(325, 100, 50, 50), Color.White);
                        spriteBatch.Draw(gameVars.GemImages[4], new Rectangle(400, 100, 50, 50), Color.White);
                        spriteBatch.Draw(gameVars.GemImages[5], new Rectangle(475, 100, 50, 50), Color.White);
                        spriteBatch.Draw(gameVars.GemImages[6], new Rectangle(550, 100, 50, 50), Color.White);
                        spriteBatch.Draw(gameVars.GemImages[7], new Rectangle(625, 100, 50, 50), Color.White);
                        spriteBatch.Draw(gameVars.GemImages[8], new Rectangle(700, 100, 50, 50), Color.White);
                        spriteBatch.Draw(gameVars.GemImages[9], new Rectangle(775, 100, 50, 50), Color.White);
                        spriteBatch.Draw(gameVars.GemImages[0], new Rectangle(850, 100, 50, 50), Color.White);

                        //draw text for user
                        spriteBatch.DrawString(gameVars.Font1Bold, "Gem Collector",
                            new Vector2((GraphicsDevice.Viewport.Width / 2) - 500, (GraphicsDevice.Viewport.Height / 2) - 150), Color.DarkRed, 0.0f, Vector2.Zero, 7.0f, SpriteEffects.None, 0.0f);

                        spriteBatch.DrawString(gameVars.Font1, "Press Enter to Play",
                            new Vector2((GraphicsDevice.Viewport.Width / 2) - 300, (GraphicsDevice.Viewport.Height / 2) + 50), Color.Red, 0.0f, Vector2.Zero, 2.75f, SpriteEffects.None, 0.0f);

                        spriteBatch.DrawString(gameVars.Font1, "Press Escape at any time to Exit",
                            new Vector2((GraphicsDevice.Viewport.Width / 2) - 200, (GraphicsDevice.Viewport.Height / 2) + 200), Color.Blue, 0.0f, Vector2.Zero, 1.0f, SpriteEffects.None, 0.0f);
                        break;
                    }
                case GameState.Playing:
                    {
                        //draw background
                        spriteBatch.Draw(gameVars.Background[gameVars.Level - 1], new Rectangle(0, 0, 1024, 768), Color.White);
                        
                        //draw collectibles
                        foreach( Collectible gem in Gems)
                        {
                            if(gem.CheckCollision(player))
                            {
                                gem.active = false;
                                player.levelScore += 100;
                                gemsRemaining -= 1;
                            }
                            gem.Draw(this.spriteBatch);
                        }

                        //draw player
                        player.Draw(this.spriteBatch);

                        //draw score, timer, and level
                        spriteBatch.DrawString(gameVars.Font1Bold, "Score " + player.levelScore.ToString(), new Vector2(10, 0), Color.DeepPink, 0.0f, Vector2.Zero, 3.0f, SpriteEffects.None, 0.0f);
                        timeLeft = (int)timer;
                        spriteBatch.DrawString(gameVars.Font1Bold, timeLeft.ToString(), new Vector2(465, 0), Color.DeepPink, 0.0f, Vector2.Zero, 3.0f, SpriteEffects.None, 0.0f);
                        spriteBatch.DrawString(gameVars.Font1Bold, "Level " + gameVars.Level, new Vector2(700, 0), Color.DeepPink, 0.0f, Vector2.Zero, 3.0f, SpriteEffects.None, 0.0f);
                        break;
                    }
                case GameState.Won:
                    {
                        //draw background with game over text plus final score
                        spriteBatch.Draw(gameVars.Background[gameVars.Level - 2], new Rectangle(0, 0, 1024, 768), Color.Gray);
                        spriteBatch.DrawString(gameVars.Font1Bold, "You Win!!",
                            new Vector2((GraphicsDevice.Viewport.Width / 2) - 270, (GraphicsDevice.Viewport.Height / 2) - 150), Color.DarkViolet, 0.0f, Vector2.Zero, 6.0f, SpriteEffects.None, 0.0f);

                        spriteBatch.DrawString(gameVars.Font1, "Total Score " + player.totalScore.ToString(),
                            new Vector2((GraphicsDevice.Viewport.Width / 2) - 230, (GraphicsDevice.Viewport.Height / 2) + 50), Color.DeepPink, 0.0f, Vector2.Zero, 3.0f, SpriteEffects.None, 0.0f);
                        break;
                    }
                case GameState.GameOver:
                    {
                        //draw background with game over text plus final score
                        spriteBatch.Draw(gameVars.Background[gameVars.Level - 1], new Rectangle(0, 0, 1024, 768), Color.Gray);
                        spriteBatch.DrawString(gameVars.Font1, "GAME OVER",
                            new Vector2((GraphicsDevice.Viewport.Width / 2) - 290, (GraphicsDevice.Viewport.Height / 2) - 150), Color.DarkViolet, 0.0f, Vector2.Zero, 6.0f, SpriteEffects.None, 0.0f);

                        spriteBatch.DrawString(gameVars.Font1, "Total Score " + player.totalScore.ToString(),
                            new Vector2((GraphicsDevice.Viewport.Width / 2) - 230, (GraphicsDevice.Viewport.Height / 2) + 50), Color.DeepPink, 0.0f, Vector2.Zero, 3.0f, SpriteEffects.None, 0.0f);

                        spriteBatch.DrawString(gameVars.Font1, "To TRY AGAIN press Enter",
                            new Vector2((GraphicsDevice.Viewport.Width / 2) - 265, (GraphicsDevice.Viewport.Height / 2) + 150), Color.DarkRed, 0.0f, Vector2.Zero, 2.0f, SpriteEffects.None, 1.0f);
                        break;
                    }
                default:
                    {
                        break;
                    }
            }//end gamestate switch

            spriteBatch.End();
            base.Draw(gameTime);
        }//end draw

        //setup next level
        protected void NextLevel()
        {
            gameVars.Level += 1; //set game level
            if(gameVars.Level == 26)
            {
                currentState = GameState.Won;
                return;
            }
            //set timer based on level
            if(gameVars.Level < 5)
            {
                timer = 31;            
            }
            else if(gameVars.Level > 4 && gameVars.Level <10)
            {
                timer = 33;
            }
            else if (gameVars.Level > 9 && gameVars.Level < 15)
            {
                timer = 36;
            }
            else if (gameVars.Level > 14 && gameVars.Level < 20)
            {
                timer = 41;
            }
            else if (gameVars.Level > 19 && gameVars.Level < 26)
            {
                timer = 46;
            }
            
            player.texture = gameVars.PlayerRight1;
            player.x = (GraphicsDevice.Viewport.Width / 2) - (player.positionRec.Width / 2);
            player.y = (GraphicsDevice.Viewport.Height / 2) - (player.positionRec.Height / 2);
            gameVars.numOfGems += gameVars.Level;
            gemsRemaining = gameVars.numOfGems;
            if (Gems != null)
            {
                Gems.Clear();
            }
            int k = 0;
            for(int i = 0; i < gameVars.numOfGems; i++)
            {
                
                if(k >= 10)
                {
                    k = 0;
                }
                gem = new Collectible(gameVars.GemImages[k], rand.Next(10,950), rand.Next(10, 700), 50, 50);
                if(k < 10)
                {
                    k++;
                }
                Gems.Add(gem);
            }//end for
        }//end nextlevel

        /// <summary>
        /// reset game variables for new game
        /// </summary>
        protected void ResetGame()
        {
            gameVars.Level = 1;
            gameVars.numOfGems = 5;
            player.levelScore = 0;
            player.totalScore = 0;
            timer = 31;
        }

        /// <summary>
        /// check to see if a key has been pressed only once
        /// </summary>
        /// <param name="current"></param>
        /// <param name="previous"></param>
        /// <param name="key"></param>
        /// <returns></returns>
        protected bool SingleKeyPress(KeyboardState current, KeyboardState previous, Keys key)
        {
            if (current.IsKeyDown(key) && previousKeyState.IsKeyUp(key))
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        /// <summary>
        /// move the character to the other side of the screen if it walks off one side
        /// </summary>
        protected void ScreenWrap()
        {
            if(player.x < (0 - player.positionRec.Width))
            {
                player.x = graphics.PreferredBackBufferWidth - 1;
            }

            if(player.y < (0 - player.positionRec.Height))
            {
                player.y = graphics.PreferredBackBufferHeight - 1;
            }

            if(player.x > graphics.PreferredBackBufferWidth)
            {
                player.x = 1 - player.positionRec.Width;
            }

            if(player.y > graphics.PreferredBackBufferHeight)
            {
                player.y = 1 - player.positionRec.Height;
            }
        }//end screenwrap


        /// <summary>
        /// Move the player around the game with animation done by changing textures
        /// </summary>
        /// <param name="gameTime"></param>
        protected void MovePlayer(GameTime gameTime)
        {
            //check key input and move character accordingly, also change texture to simulate walking
            if (keyState.IsKeyDown(Keys.W) || keyState.IsKeyDown(Keys.Up))//up
            {
                if ((!keyState.IsKeyDown(Keys.A) && !keyState.IsKeyDown(Keys.D)) && 
                    (!keyState.IsKeyDown(Keys.Right) && !keyState.IsKeyDown(Keys.Left)))
                {
                    if (picNum == 0)
                    {
                        player.texture = gameVars.PlayerUp1;
                    }
                    else if (picNum == 15)
                    {
                        player.texture = gameVars.PlayerUp2;
                    }
                    else if (picNum == 30)
                    {
                        player.texture = gameVars.PlayerUp3;
                    }
                    if (picNum < 30)
                    {
                        picNum += 1;
                    }
                    else if (picNum == 30)
                    {
                        picNum = 0;
                    }
                }
                player.y -= (float)gameVars.playerSpeed * (float)gameTime.ElapsedGameTime.TotalSeconds;
            }//end W/up key

            if (keyState.IsKeyDown(Keys.S) || keyState.IsKeyDown(Keys.Down))//down
            {
                if ((!keyState.IsKeyDown(Keys.A) && !keyState.IsKeyDown(Keys.D)) &&
                    (!keyState.IsKeyDown(Keys.Right) && !keyState.IsKeyDown(Keys.Left)))
                {
                    if (picNum == 0)
                    {
                        player.texture = gameVars.PlayerDown1;
                    }
                    else if (picNum == 15)
                    {
                        player.texture = gameVars.PlayerDown2;
                    }
                    else if (picNum == 30)
                    {
                        player.texture = gameVars.PlayerDown3;
                    }
                    if (picNum < 30)
                    {
                        picNum += 1;
                    }
                    else if (picNum == 30)
                    {
                        picNum = 0;
                    }
                }
                player.y += (float)gameVars.playerSpeed * (float)gameTime.ElapsedGameTime.TotalSeconds;
            }//end S/down key

            if (keyState.IsKeyDown(Keys.A) || keyState.IsKeyDown(Keys.Left))//left
            {
                if (picNum == 0)
                {
                    player.texture = gameVars.PlayerLeft1;
                }
                else if (picNum == 15)
                {
                    player.texture = gameVars.PlayerLeft2;
                }
                else if (picNum == 30)
                {
                    player.texture = gameVars.PlayerLeft3;
                }
                player.x -= (float)gameVars.playerSpeed * (float)gameTime.ElapsedGameTime.TotalSeconds;
                if (picNum < 30)
                {
                    picNum += 1;
                }
                else if (picNum == 30)
                {
                    picNum = 0;
                }
            }//end A/left key

            if (keyState.IsKeyDown(Keys.D) || keyState.IsKeyDown(Keys.Right))//right
            {
                if (picNum == 0)
                {
                    player.texture = gameVars.PlayerRight1;
                }
                else if (picNum == 15)
                {
                    player.texture = gameVars.PlayerRight2;
                }
                else if (picNum == 30)
                {
                    player.texture = gameVars.PlayerRight3;
                }
                player.x += (float)gameVars.playerSpeed * (float)gameTime.ElapsedGameTime.TotalSeconds;
                if (picNum < 30)
                {
                    picNum += 1;
                }
                else if (picNum == 30)
                {
                    picNum = 0;
                }
            }//end D/right key

            //exit key
            if (keyState.IsKeyDown(Keys.Escape))
            {
                Exit();
            }

            //check for screenwrap
            ScreenWrap();
        }//end move player
    }//end Game
}
