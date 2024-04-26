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

public:
    void setPadle(Padle padle);
    void setBall(Ball ball);
    void clearWindow();
    std::string getScreen(int y, int x);
    int getScreenWidth();
    int getScreenHeight();
    Screen(int pannelHeight, int pannelWidth, int padleHeight);
    void writeScore(int padle1Score, int padle2Score, std::string BallDirection);
    void writeWindow(int padle1Score, int padle2Score, std::string BallDirection);
};

#endif // SCREEN_H