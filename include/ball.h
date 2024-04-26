// Ball.h
#ifndef BALL_H
#define BALL_H

#include <string>
#include "Screen.h"

class Ball
{
private:
    int Y;
    int X;
    std::string ballDirection;
    bool north;
    bool south;
    bool east;
    bool west;

public:
    Ball(int ballPositionY, int ballPositionX);
    int getBallPositionY();
    int getBallPositionX();
    void ballAi(Screen screen);
    bool checkBounce(int GotoPositionY, int GotoPositionX, Screen screen);
};

#endif // BALL_H