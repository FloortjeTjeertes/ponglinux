// Ball.h
#ifndef BALL_H
#define BALL_H

#include <string>
#include "Screen.h"

class Ball
{
private:
    int ballPositionY;
    int ballPositionX;
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
};

#endif // BALL_H