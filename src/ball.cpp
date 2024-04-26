#include <string>
#include <screen.h>
#include <iostream>

#include "ball.h"

using std::string;
using std::cout;


    int Y = 0;
    int X = 0;
    int GoTox = 0;
    int GoToy = 0;
    string ballDirection = "";
    bool north = true;
    bool south = false;
    bool east = true;
    bool west = false;

    Ball::Ball(int ballPositionY, int ballPositionX)
    {
        this->Y = ballPositionY;
        this->X = ballPositionX;
    }

    int  Ball::getBallPositionY()
    {
        return Y;
    }

    int  Ball::getBallPositionX()
    {
        return X;
    }

    void  Ball::ballAi(Screen screen)
    {

        GoTox = X;
        GoToy = Y;

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

        if (checkBounce(GoToy, GoTox, screen))
        {

            if (GoToy >= screen.getScreenHeight() - 1 || GoToy <= 0)
            {
                north = !north;
                south = !south;
            }
            else
            {
                east = !east;
                west = !west;
            }
            GoToy = Y;
            GoTox = X;
        }
        Y = GoToy;
        X = GoTox;

        ballDirection = NS + " " + EW;
    }

    bool  Ball::checkBounce(int GotoPositionY, int GotoPositionX, Screen screen)
    {
        bool bounce = false;
        if (screen.getScreen(GotoPositionY,GotoPositionX)  == "#" || screen.getScreen(GotoPositionY,GotoPositionX) == "|")
        {
            bounce = true;
            cout << '\a';
        }

        ballDirection += " " + screen.getScreen(GotoPositionY,GotoPositionX);

        return bounce;
    }
