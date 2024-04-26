#include "padle.h"
#include "ball.h"

class Padle
{
private:
    int padleY = 0;
    int padleX = 0;
    int padleHeight =0;
    int pannelHeight = 0;


public:


    Padle(int yPostition,int xPosition,int padleHeight, int pannelHeight)
    {
        this->padleY = yPostition;
        this->padleX = xPosition;
        this->padleHeight = padleHeight;
        this->pannelHeight = pannelHeight;
    }


    int getPadleY()
    {
        return padleY;
    }

    int getPadleX()
    {
        return padleX;
    }

 


    void padleAi(Ball ball)
    {
         if (ball.getBallPositionY() + padleHeight / 2 > pannelHeight - padleHeight / 2)
            {
                padleY = pannelHeight - padleHeight - 1;
            }
            else if (ball.getBallPositionY() < padleHeight / 2)
            {
                padleY = 1;
            }
            else
            {
                padleY = ball.getBallPositionY() - padleHeight / 2;
            }
    }
};