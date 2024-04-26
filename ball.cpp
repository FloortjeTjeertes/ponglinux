class ball{
 void BallAi()
    {

        int GoTox = ballPositionX;
        int GoToy = ballPositionY;

        string NS;
        string EW;

        if (east)
        {
            GoTox++;
            EW = "east";
        }
        if (west)
        {
            GoTox--;
            EW = "west";
        }
        if (north)
        {
            GoToy--;
            NS = "north";
        }
        if (south)
        {
            GoToy++;
            NS = "south";
        }

        if (checkBounce(GoToy, GoTox))
        {

            if (GoToy >= pannelHeight - 1 || GoToy <= 0)
            {
                north = !north;
                south = !south;
            }
            else
            {
                east = !east;
                west = !west;
            }
            GoToy = ballPositionY;
            GoTox = ballPositionX;
        }

        SetBall(GoToy, GoTox);

        BallDirection = NS + " " + EW;
    }
       bool checkBounce(int GotoPositionY, int GotoPositionX)
    {
        bool bounce = false;
        if (screen[GotoPositionY][GotoPositionX] == "#" || screen[GotoPositionY][GotoPositionX] == "|")
        {
            bounce = true;
            cout << '\a';
        }

        BallDirection += " " + screen[GotoPositionY][GotoPositionX];

        return bounce;
    }
}