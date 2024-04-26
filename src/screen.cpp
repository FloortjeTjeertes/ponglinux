
#include <vector>
#include <stdio.h>
#include <iostream>
#include <screen.h>
#include <string>

using std::string;


class screen
{

    std::vector<std::vector<std::string>> screen = std::vector<std::vector<std::string>>(pannelHeight, std::vector<std::string>(pannelWidth));
    const int growthFactor = 2;
    const int pannelHeight = 9 * growthFactor;
    const int pannelWidth = 16 * growthFactor;
    const int padleHeight = 2 + 1 * growthFactor;
    int ballPositionY = 3;
    int ballPositionX = 4;

    

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

    void SetBall(int y, int x)
    {

        if (y >= 0 && y < pannelHeight && x >= 0 && x < pannelWidth)
        {
            int ballPositionX = x;
            int ballPositionY = y;
            screen[ballPositionY][ballPositionX] = "○";
        }
        else
        {
            cout << "Error: Attempted to set ball outside screen bounds." << endl;
        }
    }
    void SetPadle(int Y1, int Y2)
    {
        for (int i = 0; i < padleHeight; i++)
        {
            screen[Y1 + i][1] = '|';
        }
        for (int i = 0; i < padleHeight; i++)
        {
            screen[Y2 + i][pannelWidth - 2] = '|';
        }
    }

    void writeScore(){
        int padle1Score;
        int padle2Score;
        int BallDirection;
        cout << "Padle1=" << padle1Score << " padle2=" << padle2Score << " ball direction= " << BallDirection << " X=" << ballPositionX << " Y=" << ballPositionY << endl;

    }

    void writeWindow()
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

        cout << "Padle1=" << padle1Score << " padle2=" << padle2Score << " ball direction= " << BallDirection << " X=" << ballPositionX << " Y=" << ballPositionY << endl;
    }
}