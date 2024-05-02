// Ball.h
#ifndef BALL_H
#define BALL_H

#include <string>
#include "screen.h"

class Ball
{
private:
    int Y;
    int X;
    std::string ballDirection;
    bool north = true;
    bool south = false;
    bool east = true;
    bool west = false;
    int GoTox = 0;
    int GoToy = 0;

public:
    Ball(int ballPositionY, int ballPositionX);
    int getBallPositionY();
    int getBallPositionX();
    void ballAi(Screen screen);
    bool checkBounce(int GotoPositionY, int GotoPositionX, Screen screen);
};

#endif // BALL_H