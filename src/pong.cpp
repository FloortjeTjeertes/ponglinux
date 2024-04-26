#include <stdio.h>
#include <pongGame.h>

// #include <X11/Xlib.h>
using namespace std;
// using namespace pong;

int main()
{
    PongGame pongGame;
    pongGame.SetupGame();
    pongGame.play();

    return 0;
}
