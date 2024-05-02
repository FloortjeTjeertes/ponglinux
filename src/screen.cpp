
#include <vector>
#include <stdio.h>
#include <iostream>
#include <string>
#include "ball.h"
#include "padle.h"

#include "screen.h"

using std::string;
using namespace std;




Screen::Screen(int pannelHeight, int pannelWidth, int padleHeight)
{
    this->screen_height = pannelHeight;
    this->screen_width = pannelWidth;
    this->padleHeight = padleHeight;
    this->screen = std::vector<std::vector<std::string>>(pannelHeight, std::vector<std::string>(pannelWidth));
}

int Screen::getScreenHeight()
{
    return screen_height;
}

int Screen::getScreenWidth()
{
    return screen_width;
}

string Screen::getScreen(int y, int x)
{
    return screen[y][x];
}

void Screen::setUpPlayfield()
{

    for (int y = 0; y < screen_height; y++)
    {
        for (int x = 0; x < screen_width; x++)
        {
            if (y == 0 || y == screen_height - 1)
            {
                this->screen[y][x] = "#";
            }
            else
            {   
                this->screen[y][0] = "#";
                this->screen[y][x] = " ";
                this->screen[y][screen_width - 1] = "#";
            }
        }
    }
}

void Screen::clearWindow()
{
    for (int y = 0; y < screen_height; y++)
    {
        for (int x = 0; x < screen_width; x++)
        {
            screen[y][x] = " ";
        }
    }
}

void Screen::setBall(Ball ball)
{

    if (ball.getBallPositionY() >= 0 && ball.getBallPositionY() < screen_height && ball.getBallPositionX() >= 0 && ball.getBallPositionX() < screen_width)
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
void Screen::setPadle(Padle padle)
{
    for (int i = 0; i < padleHeight; i++)
    {
        screen[padle.getPadleY() + i][1] = '|';
    }
}

void Screen::writeWindow(int padle1Score, int padle2Score, string BallDirection)
{
    cout << "\x1B[2J\x1B[H";

    for (int y = 0; y < screen_height; y++)
    {
        string row = "";

        for (int x = 0; x < screen_width; x++)
        {

            row += screen[y][x] + " ";
        }

        cout << row << "" << y + 1 << endl
             << flush;
    }
    writeScore(padle1Score, padle2Score, BallDirection);
}

void Screen::writeScore(int padle1Score, int padle2Score, string BallDirection)
{

    cout << "Padle1=" << padle1Score << " padle2=" << padle2Score << " ball direction= " << BallDirection << endl
         << "screen-height= " << screen_height << " screen-width= " << screen_width << " padle height= " << padleHeight << endl
         << "X=" << x << " Y=" << y
         << endl;
}