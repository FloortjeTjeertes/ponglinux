#include <stdio.h>
#include <iostream>
#include <unistd.h>

// #include "pong.h"
// #include <X11/Xlib.h>
using namespace std;
// using namespace pong;

class PongGame
{
    int padle1Score = 0;
    int padle2Score = 0;

    int padle1Y = 0;
    int padle2Y = 0;

    int ballPositionY = 3;
    int ballPositionX = 4;
    bool adding;
    bool north = true;
    bool south = false;
    bool east = true;
    bool west = false;

    const int growthFactor = 2;
    const int pannelHeight = 9 * growthFactor;
    const int pannelWidth = 16 * growthFactor;
    const int padleHeight = 2 + 1 * growthFactor;
    string screen[pannelHeight][pannelWidth];

    bool FlipBallDirection = false;

    string BallDirection = "";

    void clearWindow()
    {
        for (int y = 0; y < pannelHeight; y++)
        {
            for (int x = 0; x < pannelWidth; x++)
            {
                screen[y][x] = " ";
            }
        }
    }

    void SetBall(int y, int x)
    {

        if (y >= 0 && y < pannelHeight && x >= 0 && x < pannelWidth)
        {
            ballPositionX = x;
            ballPositionY = y;
            screen[ballPositionY][ballPositionX] = "○";
        }
        else
        {
            cout << "Error: Attempted to set ball outside screen bounds." << endl;
        }
    }

    bool checkBounce(int GotoPositionY, int GotoPositionX)
    {
        bool bounce = false;
        if (screen[GotoPositionY][GotoPositionX] == "#" || screen[GotoPositionY][GotoPositionX] == "|")
        {
            bounce = true;
            cout << '\a';
        }

        BallDirection += " " + screen[GotoPositionY][GotoPositionX];

        return bounce;
    }

    bool CheckWin(int GotoPositionX)
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

    void BallAi()
    {

        int GoTox = ballPositionX;
        int GoToy = ballPositionY;

        string NS;
        string EW;

        if (east)
        {
            GoTox++;
            EW = "east";
        }
        if (west)
        {
            GoTox--;
            EW = "west";
        }
        if (north)
        {
            GoToy--;
            NS = "north";
        }
        if (south)
        {
            GoToy++;
            NS = "south";
        }

        if (checkBounce(GoToy, GoTox))
        {

            if (GoToy >= pannelHeight - 1 || GoToy <= 0)
            {
                north = !north;
                south = !south;
            }
            else
            {
                east = !east;
                west = !west;
            }
            GoToy = ballPositionY;
            GoTox = ballPositionX;
        }

        SetBall(GoToy, GoTox);

        BallDirection = NS + " " + EW;
    }

    void setUpPlayfield()
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

    void SetPadle(int Y1, int Y2)
    {
        for (int i = 0; i < padleHeight; i++)
        {
            screen[Y1 + i][1] = '|';
        }
        for (int i = 0; i < padleHeight; i++)
        {
            screen[Y2 + i][pannelWidth - 2] = '|';
        }
    }

    void writeWindow()
    {

        cout << "\x1B[2J\x1B[H";

        for (int y = 0; y < pannelHeight; y++)
        {
            string row = "";

            for (int x = 0; x < pannelWidth; x++)
            {

                row += screen[y][x] + " ";
            }

            cout << row << "" << y << endl
                 << flush;
        }

        cout << "Padle1=" << padle1Score << " padle2=" << padle2Score << " ball direction= " << BallDirection << " X=" << ballPositionX << " Y=" << ballPositionY << endl;
    }

    void SetupGame()
    {
        clearWindow();
        setUpPlayfield();
        SetBall(4, 4);
        SetPadle(4, 4);
    }

    int main(void)
    {
        SetupGame();

        padle1Y = 1;
        padle2Y = 1;
        bool adding = true;
        // game loop
        while (true)
        {

            clearWindow();
            setUpPlayfield();

            usleep(10000 * 10);
            SetPadle(padle1Y, padle2Y);

            BallAi();
            if (CheckWin(ballPositionX))
            {
                SetupGame();
            };

            writeWindow();

            if (ballPositionY + padleHeight / 2 > pannelHeight - padleHeight / 2)
            {
                padle1Y = pannelHeight - padleHeight - 1;
            }
            else if (ballPositionY < padleHeight / 2)
            {
                padle1Y = 1;
            }
            else
            {
                padle1Y = ballPositionY - padleHeight / 2;
            }
            padle2Y = padle1Y;

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

        return 0;
    }
}