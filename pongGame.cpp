class pongGame(){
    int padle1Score = 0;
    int padle2Score = 0;

    int padle1Y = 0;
    int padle2Y = 0;

    int ballPositionY = 3;
    int ballPositionX = 4;
    bool adding;
    bool north = true;
    bool south = false;
    bool east = true;
    bool west = false;

    const int growthFactor = 2;
    const int pannelHeight = 9 * growthFactor;
    const int pannelWidth = 16 * growthFactor;
    const int padleHeight = 2 + 1 * growthFactor;
    // string screen[pannelHeight][pannelWidth];
    std::vector<std::vector<string>> screen = std::vector<std::vector<string>>(pannelHeight, std::vector<string>(pannelWidth));


    bool FlipBallDirection = false;

    string BallDirection = "";




    void play(){

        padle1Y = 1;
        padle2Y = 1;
        bool adding = true;
        // game loop
        while (true)
        {

            this.clearWindow();
            setUpPlayfield();

            usleep(10000 * 10);
            SetPadle(padle1Y, padle2Y);

            BallAi();
            if (CheckWin(ballPositionX))
            {
                SetupGame();
            };

            writeWindow();

            if (ballPositionY + padleHeight / 2 > pannelHeight - padleHeight / 2)
            {
                padle1Y = pannelHeight - padleHeight - 1;
            }
            else if (ballPositionY < padleHeight / 2)
            {
                padle1Y = 1;
            }
            else
            {
                padle1Y = ballPositionY - padleHeight / 2;
            }
            padle2Y = padle1Y;

            // if(padle1Y==pannelHeight-padleHeight||padle1Y==0){
            //     adding=!adding;
            // }
            // if(adding){
            //     padle1Y++;
            //     padle2Y++;

            // }
            // else{
            //     padle1Y--;
            //     padle2Y--;

            // }
        }
    }

  void SetupGame()
    {
        clearWindow();
        setUpPlayfield();
        SetBall(4, 4);
        SetPadle(4, 4);
    }

   

 
    // check if game is won 
    bool CheckWin(int GotoPositionX)
    {

        if (GotoPositionX == pannelWidth - 2)
        {
            padle2Score++;
            return true;
        }
        if (GotoPositionX == 0 + 1)
        {
            padle1Score++;
            return true;
        }
        return false;
    }

   

    void setUpPlayfield()
    {

        for (int y = 0; y <= pannelHeight; y++)
        {
            for (int x = 0; x <= pannelWidth; x++)
            {
                if (y == 0 || y == pannelHeight - 1)
                {
                    screen[y][x] = "#";
                }
                else
                {
                    screen[y][0] = "#";
                    screen[y][pannelWidth - 1] = "#";
                }
            }
        }
    }



   

  

}