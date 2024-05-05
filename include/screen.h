// screen.h
#ifndef SCREEN_H
#define SCREEN_H

#include <vector>
#include <string>
class Ball;
class Padle;

class Screen
{
private:
    std::vector<std::vector<std::string>> screen;
    int screen_height;
    int screen_width;
    int padleHeight;
    int growthFactor;
    int x = 0;
    int y = 0;

public:
    Screen(int pannelHeight, int pannelWidth, int padleHeight);
    void setPadle(Padle padle);
    void setBall(Ball ball);
    void clearWindow();
    std::string getScreen(int y, int x);
    int getScreenWidth();
    int getScreenHeight();
    void writeScore(int padle1Score, int padle2Score, std::string BallDirection);
    void writeWindow(int padle1Score, int padle2Score, std::string BallDirection);
    void setUpPlayfield();
    void clearTerminal();
};

#endif // SCREEN_H