#include "pch.h"
#include "../mazecpp.h"

TEST(Positive_yes) {
	MazeSize = 9;
	vector< vector<int> > MazeExample =
	{		{1,1,0,0,0,0,0,0,0},
			{0,1,0,0,0,0,0,0,0},
			{0,1,1,1,0,0,0,0,0},
			{0,0,0,1,1,1,1,0,0},
			{0,0,0,0,0,0,1,0,0},
			{0,0,0,0,1,0,1,0,0},
			{0,0,0,0,1,0,0,0,0},
			{0,0,0,0,1,1,1,1,0},
			{0,0,0,0,0,0,0,1,1} };
	Maze.resize(MazeSize, vector<int>(MazeSize));
	Maze = MazeExample;

	ASSERT_EQ(Solve, true);
}


TEST(Positive_no) {
	MazeSize = 9;
	vector< vector<int> > MazeExample =
	{		{1,1,0,0,0,0,0,0,0},
			{0,1,0,0,0,0,0,0,0},
			{0,1,1,1,0,0,0,0,0},
			{0,0,0,1,1,1,1,0,0},
			{0,0,0,0,0,0,1,0,0},
			{0,0,0,0,1,0,1,0,0},
			{0,0,0,0,1,0,0,0,0},
			{0,0,0,0,0,1,1,1,0},
			{0,0,0,0,0,0,0,1,1} };
	Maze.resize(MazeSize, vector<int>(MazeSize));
	Maze = MazeExample;

	ASSERT_EQ(Solve, false);
}





int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}