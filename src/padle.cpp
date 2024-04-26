#include "ball.h"
#include "padle.h"


    int padleY = 0;
    int padleX = 0;
    int height =0;
    int pannelHeight = 0;




    Padle::Padle(int yPostition,int xPosition,int height, int pannelHeight)
    {
        this->padleY = yPostition;
        this->padleX = xPosition;
        this->height = height;
        this->pannelHeight = pannelHeight;
    }


    int  Padle::getPadleY()
    {
        return padleY;
    }

    int  Padle::getPadleX()
    {
        return padleX;
    }

 


    void  Padle::padleAi(Ball ball)
    {
         if (ball.getBallPositionY() + height / 2 > pannelHeight - height / 2)
            {
                padleY = pannelHeight - height - 1;
            }
            else if (ball.getBallPositionY() < height / 2)
            {
                padleY = 1;
            }
            else
            {
                padleY = ball.getBallPositionY() - height / 2;
            }
    }
