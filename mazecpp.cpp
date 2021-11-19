#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>


using namespace std;

const int MazeSize = 2;
char Maze[MazeSize][MazeSize + 1] =
{
    "10",
    "01"};

const char Wall = '0';
const char Free = '1';
const char Path = '*';

class COORDINATE
{
public:
    int X;
    int Y;
    COORDINATE(int x = 0, int y = 0) { X = x, Y = y; }
    COORDINATE(const COORDINATE& COORDINATE) { X = COORDINATE.X; Y = COORDINATE.Y; }
};

COORDINATE StartingPoint(0, 0);
COORDINATE EndingPoint(MazeSize-1, MazeSize-1);


bool Solve(int X, int Y)
{
    // Make the move (if it's wrong, we will backtrack later.
    Maze[Y][X] = Path;

    // If you want progressive update, uncomment these lines...
    //PrintDaMaze();
    //Sleep(50);

    // Check if we have reached our goal.
    if (X == EndingPoint.X && Y == EndingPoint.Y)
    {
        return true;
    }

    // Recursively search for our goal.
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

    // If you want progressive update, uncomment these lines...
    //PrintDaMaze();


    return false;
}

void MazePrint()
{
    for (int Y = 0; Y < MazeSize; Y++)
    {
        printf("%s\n", Maze[Y]);
    }
    printf("\n");
}





int main(int argc, char* argv[])
{

    //char Maze[MazeSize][MazeSize];
    //cout << "Input size of Maze" << endl;
    //cin >> MazeSize;
    //(const int)MazeSize;

    


    MazePrint();

    cout << "Availability of path on your Maze:\n";
    cout << boolalpha << Solve(StartingPoint.X, StartingPoint.Y) <<endl;
    
    system("pause");
    return 0;
}