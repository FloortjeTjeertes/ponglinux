#include <vector>
#include <string>
#include <unistd.h>
#include "ball.h"
#include "padle.h"
#include "screen.h"
#include "pongGame.h"

using std::string;

class PongGame
{

    int padle1Score = 0;

    int padle2Score = 0;

    int padle1Y = 0;
    int padle2Y = 0;

    int ballPositionY = 3;
    int ballPositionX = 4;
    bool adding;


    const int growthFactor = 2;
    const int pannelHeight = 9 * growthFactor;
    const int pannelWidth = 16 * growthFactor;
    const int padleHeight = 2 + 1 * growthFactor;


    bool FlipBallDirection = false;

    string BallDirection = "";


    void play()
    {

        padle1Y = 1;
        padle2Y = 1;
        bool adding = true;


        Screen newScreen(pannelHeight, pannelWidth, padleHeight);
        Ball ball(3,4);
        Padle padle1(1,2,padleHeight, pannelHeight);
        Padle padle2(1,pannelWidth-2,padleHeight, pannelHeight);

        // game loop
        while (true)
        {

            newScreen.clearWindow();
            setUpPlayfield(newScreen);

            usleep(10000 * 10);
            ball.ballAi(newScreen);
            padle1.padleAi(ball);
            padle2.padleAi(ball);
            newScreen.setPadle(padle1);
            newScreen.setPadle(padle2);

        
            if (checkWin(ballPositionX))
            {
                setupGame(screen);
            };

            writeWindow();

          

            // if(padle1Y==pannelHeight-padleHeight||padle1Y==0){
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

    void setupGame(Screen sc,Ball ball,Padle player1, Padle player2)
    {
        sc.clearWindow();
        this->setUpPlayfield(sc);
        sc.SetPadle(player1);
        sc.SetPadle(player2);
        sc.SetBall(ball);
    }

    // check if game is won
    bool checkWin(int GotoPositionX)
    {

        if (GotoPositionX == pannelWidth - 2)
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

    void setUpPlayfield(Screen screen)
    {

        for (int y = 0; y <= pannelHeight; y++)
        {
            for (int x = 0; x <= pannelWidth; x++)
            {
                if (y == 0 || y == pannelHeight - 1)
                {
                    screen[y][x] = "#";
                }
                else
                {
                    screen[y][0] = "#";
                    screen[y][pannelWidth - 1] = "#";
                }
            }
        }
    }
}