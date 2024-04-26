// screen.h
#ifndef SCREEN_H
#define SCREEN_H

#include <vector>
#include <string>
#include "ball.h"
#include "padle.h"

class Screen
{
private:
    std::vector<std::vector<std::string>> screen;
    const int growthFactor;
    int pannelHeight;
    int pannelWidth;
    int padleHeight;

public:
    Screen(int pannelHeight, int pannelWidth, int padleHeight);
    int getScreenHeight();
    int getScreenWidth();
    std::string getScreen(int y, int x);
    void clearWindow();
    void setBall(Ball ball);
    void setPadle(Padle padle);
    void writeScore();
    void writeWindow();
};

#endif // SCREEN_H