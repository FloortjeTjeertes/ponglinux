class screen{

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
            ballPositionX = x;
            ballPositionY = y;
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