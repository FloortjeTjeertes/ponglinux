#include <string>
#include <screen.h>
#include <iostream>

using std::string;
using std::cout;

class Ball
{

private:
    int ballPositionY = 0;
    int ballPositionX = 0;
    int GoTox = 0;
    int GoToy = 0;
    string ballDirection = "";
    bool north = true;
    bool south = false;
    bool east = true;
    bool west = false;

public:
    Ball(int ballPositionY, int ballPositionX)
    {
        this->ballPositionY = ballPositionY;
        this->ballPositionX = ballPositionX;
    }

    int getBallPositionY()
    {
        return ballPositionY;
    }

    int getBallPositionX()
    {
        return ballPositionX;
    }

    void ballAi(Screen screen)
    {

        GoTox = ballPositionX;
        GoToy = ballPositionY;

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
            GoToy = ballPositionY;
            GoTox = ballPositionX;
        }
        ballPositionY = GoToy;
        ballPositionX = GoTox;

        ballDirection = NS + " " + EW;
    }

private:
    bool checkBounce(int GotoPositionY, int GotoPositionX, Screen screen)
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
};