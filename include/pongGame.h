// PongGame.h
#ifndef PONGGAME_H
#define PONGGAME_H

#include <vector>
#include <string>
#include "screen.h"
#include "ball.h"
#include "padle.h"

class PongGame
{
private:
    int padle1Score;
    int padle2Score;
    int padle1Y;
    int padle2Y;
    int ballPositionY;
    int ballPositionX;
    bool adding;
    int growthFactor;
    int pannelHeight;
    int pannelWidth;
    int padleHeight;
    bool FlipBallDirection;
    std::string BallDirection;

public:
    PongGame();
    void play();
    void setupGame(Screen sc,Ball ball,Padle player1, Padle player2);
    bool checkWin(int GotoPositionX);
    void setUpPlayfield(Screen screen);
};

#endif // PONGGAME_H