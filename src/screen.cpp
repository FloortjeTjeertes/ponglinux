
#include <vector>
#include <stdio.h>
#include <iostream>
#include <string>
#include "screen.h"

using std::string;
using namespace std;

class Screen
{

private:
    std::vector<std::vector<std::string>> screen = std::vector<std::vector<std::string>>(pannelHeight, std::vector<std::string>(pannelWidth));
    const int growthFactor = 0;
    const int pannelHeight = 0;
    const int pannelWidth = 0;
    const int padleHeight = 0;
public:
    Screen(int pannelHeight, int pannelWidth, int padleHeight)
    {
        pannelHeight = pannelHeight;
        pannelWidth = pannelWidth;
        padleHeight = padleHeight;
    }

    int getScreenHeight()
    {
        return pannelHeight;
    }

    int getScreenWidth()
    {
        return pannelWidth;
    }

    string getScreen(int y, int x)
    {
        return screen[y][x];

    }

    

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

    void setBall(Ball ball)
    {

        if (ball.getBallPositionY() >= 0 && ball.getBallPositionY() < pannelHeight && ball.getBallPositionX() >= 0 && ball.getBallPositionX() < pannelWidth)
        {
            int ballPositionX = ball.getBallPositionX();
            int ballPositionY = ball.getBallPositionY();
            screen[ballPositionY][ballPositionX] = "○";
        }
        else
        {
            cout << "Error: Attempted to set ball outside screen bounds." << endl;
        }
    }
    void setPadle(Padle padle)
    {
        for (int i = 0; i < padleHeight; i++)
        {
            screen[padle.getPadleY() + i][1] = '|';
        }
    
    }

    void writeScore( int padle1Score, int padle2Score, int BallDirection){
        
        int BallDirection=0;
        cout << "Padle1=" << padle1Score << " padle2=" << padle2Score << " ball direction= " << BallDirection << " X=" << ballPositionX << " Y=" << ballPositionY << endl;

    }

    void writeWindow(int padle1Score, int padle2Score, int BallDirection)
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
        writeScore( padle1Score,  padle2Score,  BallDirection);
    }
}