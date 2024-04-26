#ifndef pong
#define pong
namespace pong
{
    class pong
    {
        public:

            void clearWindow();
            void BallAi(int GotoPositionX,int GotoPositionY);
            void SetBall(int y,int x);
            void SetPadle(int Y1,int Y2);
            void writeWindow();
    
    };
}
#endif 
