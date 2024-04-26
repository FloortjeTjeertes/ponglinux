#include <vector>
#include <string>
#include <unistd.h>
#include "ball.h"
#include "padle.h"
#include "screen.h"
#include "pongGame.h"

using std::string;



    int padle1Score = 0;

    int padle2Score = 0;

    int padle1Y = 0;
    int padle2Y = 0;

    int ballPositionY = 3;
    int ballPositionX = 4;
    bool adding;


     int scale = 2;
     int screen_Height = 9 * scale;
     int screen_Width = 16 * scale;
     int padle_Height = 2 + 1 * scale;


    bool FlipBallDirection = false;

    string BallDirection = "";

    PongGame::PongGame()
    {
        padle1Score = 0;
        padle2Score = 0;
        padle1Y = 0;
        padle2Y = 0;
        ballPositionY = 3;
        ballPositionX = 4;
        adding = true;
        FlipBallDirection = false;
        BallDirection = "";
    }

    void PongGame::play()
    {

        padle1Y = 1;
        padle2Y = 1;


        Screen newScreen(screen_Height, screen_Width, padle_Height);
        Ball ball(3,4);
        Padle padle1(1,2,padle_Height, screen_Height);
        Padle padle2(1,screen_Width-2,padle_Height, screen_Height);

        // game loop
        while (true)
        {

            newScreen.clearWindow();
            PongGame::setUpPlayfield(newScreen);

            usleep(10000 * 10);
            ball.ballAi(newScreen);
            padle1.padleAi(ball);
            padle2.padleAi(ball);
            newScreen.setPadle(padle1);
            newScreen.setPadle(padle2);

        
            if (checkWin(ballPositionX))
            {
                PongGame::setupGame(newScreen,ball,padle1,padle2);
            };

           newScreen.writeWindow(padle1Score, padle2Score, BallDirection);

          

            // if(padle1Y==screen_Height-padle_Height||padle1Y==0){
            //     adding=!adding;
            // }
            // if(adding){
            //     padle1Y++;
            //     padle2Y++;

            // }
            // else{
            //     padle1Y--;
            //     padle2Y--;

            // }
        }
    }

    void PongGame::setupGame(Screen sc,Ball ball,Padle player1, Padle player2)
    {
        sc.clearWindow();
        setUpPlayfield(sc);
        sc.setPadle(player1);
        sc.setPadle(player2);
        sc.setBall(ball);
    }

    // check if game is won
    bool PongGame::checkWin(int GotoPositionX)
    {

        if (GotoPositionX == screen_Width - 2)
        {
            padle2Score++;
            return true;
        }
        if (GotoPositionX == 0 + 1)
        {
            padle1Score++;
            return true;
        }
        return false;
    }

    void PongGame::setUpPlayfield(Screen screen)
    {

        for (int y = 0; y <= screen_Height; y++)
        {
            for (int x = 0; x <= screen_Width; x++)
            {
                if (y == 0 || y == screen_Height - 1)
                {
                    screen.getScreen(y, x) = "#";
                }
                else
                {
                    screen.getScreen(y, 0) = " ";
                    screen.getScreen(y, screen_Width - 1) = "#";

                }
            }
        }
    }
