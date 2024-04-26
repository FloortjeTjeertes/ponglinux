#include <stdio.h>
#include <iostream>
#include <unistd.h>
#include <vector>

// #include "pong.h"
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




