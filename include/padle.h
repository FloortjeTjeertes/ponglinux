// Padle.h
#ifndef PADLE_H
#define PADLE_H

class Ball;

class Padle
{
private:
    int padleY;
    int padleX;
    int height;
    int pannelHeight;

public:
    Padle(int yPostition, int xPosition, int padleHeight, int pannelHeight);
    int getPadleY();
    int getPadleX();
    void padleAi(Ball ball);
};

#endif // PADLE_H