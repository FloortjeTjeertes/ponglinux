#ifndef screen
#define screen

#include <vector>
#include <stdio.h>
#include <iostream>
namespace pong
{
    class screen
    {
        public:

            void clearWindow();
            void writeWindow();
            void SetBall(int y ,int x);
            void SetPadle(int Y1, int Y2);
            void writeWindow()
        private:
            std::vector<std::vector<std::string>> screen;
    
    };
}
#endif 
