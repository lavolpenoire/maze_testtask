#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>


using namespace std;

int MazeSize = 9;
//vector<vector<int>> Maze(MazeSize, vector<int>(MazeSize));

vector< vector<int> > Maze;

/*
{
    {1,1,0,0,0,0,0,0,0},
    {0,1,0,0,0,0,0,0,0},
    {0,1,1,1,0,0,0,0,0},
    {0,0,0,1,1,1,1,0,0},
    {0,0,0,0,0,0,1,0,0},
    {0,0,0,0,1,1,1,0,0},
    {0,0,0,0,1,0,0,0,0},
    {0,0,0,0,1,1,1,1,0},
    {0,0,0,0,0,0,0,1,1}
};
*/
const int Wall = 0;
const int Free = 1;
const int Path = 8;



void MazeInit(); 
bool Result();
void MazePrint();
bool Restriction();
bool Solve(int X, int Y);




class COORDINATE
{
public:
    int X;
    int Y;
    COORDINATE(int x = 0, int y = 0) { X = x, Y = y; }
    COORDINATE(const COORDINATE& COORDINATE) { X = COORDINATE.X; Y = COORDINATE.Y; }
};

COORDINATE StartingPoint(0, 0);
COORDINATE EndingPoint(MazeSize - 1, MazeSize - 1);




int main(int argc, char* argv[])
{
    MazeInit();
    Result();
}




bool Solve(int X, int Y)
{

    // Make the move (if it's wrong, we will backtrack later.
    Maze[Y][X] = Path;


    // Check if goal reached
    if (X == EndingPoint.X && Y == EndingPoint.Y)
    {
        return true;
    }

    // Recursively search for goal
    if (X > 0 && Maze[Y][X - 1] == Free && Solve(X - 1, Y))
    {
        return true;
    }
    if (X < MazeSize && Maze[Y][X + 1] == Free && Solve(X + 1, Y))
    {
        return true;
    }
    if (Y > 0 && Maze[Y - 1][X] == Free && Solve(X, Y - 1))
    {
        return true;
    }
    if (Y < MazeSize && Maze[Y + 1][X] == Free && Solve(X, Y + 1))
    {
        return true;
    }

    // Otherwise we need to backtrack and find another solution.
    Maze[Y][X] = Free;
    
    return false;

}

void MazePrint()
{
    for (const auto& row : Maze)
    {
        for (const auto& s : row) std::cout << s << ' ';
        std::cout << std::endl;
    }
  
}


//Check if  Maze fits the requirements: size, avialability of trting endd endding points
bool Restriction()
{

    if ((Maze[StartingPoint.Y][StartingPoint.X] != Wall) || (Maze[EndingPoint.Y][EndingPoint.X] != Wall) || (MazeSize >= 2) || (MazeSize <= 50))
    {
        return true;
    }
    else return false;
}

bool Result()
{
    if (Restriction())
    {
        if ( Solve(StartingPoint.X, StartingPoint.Y) )
        {
            MazePrint();
            cout << "Availability of path on your Maze:\n";
            cout << boolalpha << Solve(StartingPoint.X, StartingPoint.Y) << endl;
        }
        else
        {
            MazePrint();
            cout << "Availability of path on your Maze:\n";
            cout << boolalpha << Solve(StartingPoint.X, StartingPoint.Y) << endl;
        }

    }
    else
    {
        cout << "False: wrong Maze\n";
    }
    system("pause");
    return 0;
}

void MazeInit()
{
    Maze.resize(MazeSize, vector<int>(MazeSize));
    Maze = 
    {   {1,1,0,0,0,0,0,0,0},
        {0,1,0,0,0,0,0,0,0},
        {0,1,1,1,0,0,0,0,0},
        {0,0,0,1,1,1,1,0,0},
        {0,0,0,0,0,0,1,0,0},
        {0,0,0,0,1,1,1,0,0},
        {0,0,0,0,1,0,0,0,0},
        {0,0,0,0,1,1,1,1,0},
        {0,0,0,0,0,0,0,1,1}     };
}