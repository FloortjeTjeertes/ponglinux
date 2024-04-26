// PongGame.h

#ifndef PONGGAME_H
#define PONGGAME_H

#include <string>
namespace pong
{
class PongGame
{
    
public:
    void SetupGame();
    void play();
    // Add other public methods here

private:
    int padle2Y = 0;
    int ballPositionY = 3;
    int ballPositionX = 4;
    bool adding;
    bool north = true;
    bool south = false;
    bool east = true;
    bool west = false;

    // Add other private variables and methods here
};
}
#endif // PONGGAME_H