#include <CppUTest/TestHarness.h>
#include "core/queen.hpp"
#include "test_common.hpp"

// Queen test case
// The Queen can move in all 8 directions, as far as it can
// this means that the Queen can by modelled as a pawn and a bishop at the same time
//
// this test case provides 2 sets of tests.
// 
// The Normal Implementation tests
// -------------------------------
// these tests assume that the code generates the possible moves by itself
// the moves are ordered by starting from the north, going clockwise
//
//  \   |   /
//   \  |  /
//    8 1 2
//     \|/
// ---7-Q-3---
//     /|\
//    6 5 4
//   /  |  \
//  /   |   \
//
//  The Eazy Implementation tests
//  -----------------------------
//  these tests assume that the code reuses rook and bishop's code.
//  the moves of the rook are tested first, then the moves of the bishop.
//
//   \   |   /
//    \  |  /
//     8 1 5
//      \|/
//  ---4-Q-2---
//      /|\
//     7 3 6
//    /  |  \
//   /   |   \
//

TEST_GROUP(TestQueen)
{
	FakeGrid occupied_positions;


	void setup()
	{
		occupied_positions = (FakeGrid) new PieceColor [8][8] {
			{BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK},
			{BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK},
			{EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
			{EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
			{EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
			{EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
			{WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE},
			{WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE},
		};
	}

	void teardown()
	{
		for(int i = 0; i < 8; i ++)
			delete[] occupied_positions[i];
		delete[] occupied_positions;
	}

};


#ifdef QUEEN_EZ_IMP

IGNORE_TEST(TestQueen, test_case_1_normal_implementation) {}
IGNORE_TEST(TestQueen, test_case_2_normal_implementation) {}

#else

IGNORE_TEST(TestQueen, test_case_1_eazy_implementation) {}
IGNORE_TEST(TestQueen, test_case_2_eazy_implementation) {}


#endif


TEST(TestQueen, test_at_inital_position)
{
	// testing white queen
	Queen white_queen(7, 3, WHITE);
	
	std::vector<Position> possible_moves(white_queen.get_valid_positions(occupied_positions));
	CHECK_EQUAL(possible_moves.size(), 0);

	// testing black queen
	Queen black_queen(0, 3, BLACK);

	possible_moves = black_queen.get_valid_positions(occupied_positions);
	CHECK_EQUAL(possible_moves.size(), 0);
}

TEST(TestQueen, test_case_1_normal_implementation)
{
	// testing white queen
	Queen white_queen(5, 5, WHITE);
	occupied_positions[5][5] = WHITE;

	std::vector<Position> possible_moves(white_queen.get_valid_positions(occupied_positions));
	CHECK_EQUAL(possible_moves.size(), 17);

	CHECK_EQUAL(possible_moves[0],  Position(4, 5));
	CHECK_EQUAL(possible_moves[1],  Position(4, 6));
	CHECK_EQUAL(possible_moves[2],  Position(5, 6));
	CHECK_EQUAL(possible_moves[3],  Position(5, 4));
	CHECK_EQUAL(possible_moves[4],  Position(4, 4));
	CHECK_EQUAL(possible_moves[5],  Position(3, 5));
	CHECK_EQUAL(possible_moves[6],  Position(3, 7));
	CHECK_EQUAL(possible_moves[7],  Position(5, 7));
	CHECK_EQUAL(possible_moves[8],  Position(5, 3));
	CHECK_EQUAL(possible_moves[9],  Position(3, 3));
	CHECK_EQUAL(possible_moves[10], Position(2, 5));
	CHECK_EQUAL(possible_moves[11], Position(5, 2));
	CHECK_EQUAL(possible_moves[12], Position(2, 2));
	CHECK_EQUAL(possible_moves[13], Position(1, 5));
	CHECK_EQUAL(possible_moves[14], Position(5, 1));
	CHECK_EQUAL(possible_moves[15], Position(1, 1));
	CHECK_EQUAL(possible_moves[16], Position(5, 0));

	// testing black queen
	// there is a white queen in (5, 5)
	Queen black_queen(2, 5, BLACK);
	occupied_positions[2][5] = BLACK;

	possible_moves = black_queen.get_valid_positions(occupied_positions);
	CHECK_EQUAL(possible_moves.size(), 16);

	CHECK_EQUAL(possible_moves[0],  Position(2, 6));
	CHECK_EQUAL(possible_moves[1],  Position(3, 6));
	CHECK_EQUAL(possible_moves[2],  Position(3, 5));
	CHECK_EQUAL(possible_moves[3],  Position(3, 4));
	CHECK_EQUAL(possible_moves[4],  Position(2, 4));
	CHECK_EQUAL(possible_moves[5],  Position(2, 7));
	CHECK_EQUAL(possible_moves[6],  Position(4, 7));
	CHECK_EQUAL(possible_moves[7],  Position(4, 5));
	CHECK_EQUAL(possible_moves[8],  Position(4, 3));
	CHECK_EQUAL(possible_moves[9],  Position(2, 3));
	CHECK_EQUAL(possible_moves[10], Position(5, 5));
	CHECK_EQUAL(possible_moves[11], Position(5, 2));
	CHECK_EQUAL(possible_moves[12], Position(2, 2));
	CHECK_EQUAL(possible_moves[13], Position(6, 1));
	CHECK_EQUAL(possible_moves[14], Position(2, 1));
	CHECK_EQUAL(possible_moves[15], Position(2, 0));
}

TEST(TestQueen, test_case_2_normal_implementation)
{
	// testing white queen
	Queen white_queen(3, 3, WHITE);
	occupied_positions[3][3] = WHITE;

	std::vector<Position> possible_moves(white_queen.get_valid_positions(occupied_positions));
	CHECK_EQUAL(possible_moves.size(), 19);

	CHECK_EQUAL(possible_moves[0],  Position(2, 3));
	CHECK_EQUAL(possible_moves[1],  Position(2, 4));
	CHECK_EQUAL(possible_moves[2],  Position(3, 4));
	CHECK_EQUAL(possible_moves[3],  Position(4, 4));
	CHECK_EQUAL(possible_moves[4],  Position(4, 3));
	CHECK_EQUAL(possible_moves[5],  Position(4, 2));
	CHECK_EQUAL(possible_moves[6],  Position(3, 2));
	CHECK_EQUAL(possible_moves[7],  Position(2, 2));
	CHECK_EQUAL(possible_moves[8],  Position(1, 3));
	CHECK_EQUAL(possible_moves[9],  Position(1, 5));
	CHECK_EQUAL(possible_moves[10], Position(3, 5));
	CHECK_EQUAL(possible_moves[11], Position(5, 5));
	CHECK_EQUAL(possible_moves[12], Position(5, 3));
	CHECK_EQUAL(possible_moves[13], Position(5, 1));
	CHECK_EQUAL(possible_moves[14], Position(3, 1));
	CHECK_EQUAL(possible_moves[15], Position(1, 1));
	CHECK_EQUAL(possible_moves[16], Position(3, 6));
	CHECK_EQUAL(possible_moves[17], Position(3, 0));
	CHECK_EQUAL(possible_moves[18], Position(3, 7));

	// testing black queen
	// note that there is a white queen above that black queen
	Queen black_queen(4, 3, BLACK);
	occupied_positions[4][3] = BLACK;
	
	possible_moves = black_queen.get_valid_positions(occupied_positions);
	CHECK_EQUAL(possible_moves.size(), 18);	
	
	CHECK_EQUAL(possible_moves[0],  Position(3, 3));
	CHECK_EQUAL(possible_moves[1],  Position(3, 4));
	CHECK_EQUAL(possible_moves[2],  Position(4, 4));
	CHECK_EQUAL(possible_moves[3],  Position(5, 4));
	CHECK_EQUAL(possible_moves[4],  Position(5, 3));
	CHECK_EQUAL(possible_moves[5],  Position(5, 2));
	CHECK_EQUAL(possible_moves[6],  Position(4, 2));
	CHECK_EQUAL(possible_moves[7],  Position(3, 2));
	CHECK_EQUAL(possible_moves[8],  Position(2, 5));
	CHECK_EQUAL(possible_moves[9],  Position(4, 5));
	CHECK_EQUAL(possible_moves[10], Position(6, 5));
	CHECK_EQUAL(possible_moves[11], Position(6, 3));
	CHECK_EQUAL(possible_moves[12], Position(6, 1));
	CHECK_EQUAL(possible_moves[13], Position(4, 1));
	CHECK_EQUAL(possible_moves[14], Position(2, 1));
	CHECK_EQUAL(possible_moves[15], Position(4, 6));
	CHECK_EQUAL(possible_moves[16], Position(4, 0));
	CHECK_EQUAL(possible_moves[17], Position(4, 7));
}

TEST(TestQueen, test_case_1_easy_implementation)
{
	// testing white queen
	Queen white_queen(5, 5, WHITE);
	occupied_positions[5][5] = WHITE;

	std::vector<Position> possible_moves(white_queen.get_valid_positions(occupied_positions));
	CHECK_EQUAL(possible_moves.size(), 17);

	CHECK_EQUAL(possible_moves[0],  Position(4, 5));
	CHECK_EQUAL(possible_moves[1],  Position(5, 6));
	CHECK_EQUAL(possible_moves[2],  Position(5, 4));
	CHECK_EQUAL(possible_moves[3],  Position(3, 5));
	CHECK_EQUAL(possible_moves[4],  Position(5, 7));
	CHECK_EQUAL(possible_moves[5],  Position(5, 3));
	CHECK_EQUAL(possible_moves[6],  Position(2, 5));
	CHECK_EQUAL(possible_moves[7],  Position(5, 2));
	CHECK_EQUAL(possible_moves[8],  Position(1, 5));
	CHECK_EQUAL(possible_moves[9],  Position(5, 1));
	CHECK_EQUAL(possible_moves[10], Position(5, 0));
	CHECK_EQUAL(possible_moves[11], Position(4, 6));
	CHECK_EQUAL(possible_moves[12], Position(4, 4));
	CHECK_EQUAL(possible_moves[13], Position(3, 7));
	CHECK_EQUAL(possible_moves[14], Position(3, 3));
	CHECK_EQUAL(possible_moves[15], Position(2, 2));
	CHECK_EQUAL(possible_moves[16], Position(1, 1));

	// testing black queen
	// note that there is a white queen in (5, 5)
	Queen black_queen(2, 5, BLACK);
	occupied_positions[2][5] = BLACK;

	possible_moves = black_queen.get_valid_positions(occupied_positions);
	CHECK_EQUAL(possible_moves.size(), 16);

	CHECK_EQUAL(possible_moves[0],  Position(2, 6));
	CHECK_EQUAL(possible_moves[1],  Position(3, 5));
	CHECK_EQUAL(possible_moves[2],  Position(2, 4));
	CHECK_EQUAL(possible_moves[3],  Position(2, 7));
	CHECK_EQUAL(possible_moves[4],  Position(4, 5));
	CHECK_EQUAL(possible_moves[5],  Position(2, 3));
	CHECK_EQUAL(possible_moves[6],  Position(5, 5));
	CHECK_EQUAL(possible_moves[7],  Position(2, 2));
	CHECK_EQUAL(possible_moves[8],  Position(2, 1));
	CHECK_EQUAL(possible_moves[9],  Position(2, 0));
	CHECK_EQUAL(possible_moves[10], Position(3, 6));
	CHECK_EQUAL(possible_moves[11], Position(3, 4));
	CHECK_EQUAL(possible_moves[12], Position(4, 7));
	CHECK_EQUAL(possible_moves[13], Position(4, 3));
	CHECK_EQUAL(possible_moves[14], Position(5, 2));
	CHECK_EQUAL(possible_moves[15], Position(6, 1));
}

TEST(TestQueen, test_case_2_eazy_implementation)
{
	// testing white queen
	Queen white_queen(3, 3, WHITE);
	occupied_positions[3][3] = WHITE;

	std::vector<Position> possible_moves(white_queen.get_valid_positions(occupied_positions));
	CHECK_EQUAL(possible_moves.size(), 19);

	CHECK_EQUAL(possible_moves[0],  Position(2, 3));
	CHECK_EQUAL(possible_moves[1],  Position(3, 4));
	CHECK_EQUAL(possible_moves[2],  Position(4, 3));
	CHECK_EQUAL(possible_moves[3],  Position(3, 2));
	CHECK_EQUAL(possible_moves[4],  Position(1, 3));
	CHECK_EQUAL(possible_moves[5],  Position(3, 5));
	CHECK_EQUAL(possible_moves[6],  Position(5, 3));
	CHECK_EQUAL(possible_moves[7],  Position(3, 1));
	CHECK_EQUAL(possible_moves[8],  Position(3, 6));
	CHECK_EQUAL(possible_moves[9],  Position(3, 0));
	CHECK_EQUAL(possible_moves[10], Position(3, 7));
	CHECK_EQUAL(possible_moves[11], Position(2, 4));
	CHECK_EQUAL(possible_moves[12], Position(4, 4));
	CHECK_EQUAL(possible_moves[13], Position(4, 3));
	CHECK_EQUAL(possible_moves[14], Position(2, 2));
	CHECK_EQUAL(possible_moves[15], Position(1, 5));
	CHECK_EQUAL(possible_moves[16], Position(5, 5));
	CHECK_EQUAL(possible_moves[17], Position(5, 1));
	CHECK_EQUAL(possible_moves[18], Position(1, 1));

	// testing black queen
	// note that there is a white queen above it
	Queen black_queen(4, 3, BLACK);
	occupied_positions[4][3] = BLACK;

	possible_moves = black_queen.get_valid_positions(occupied_positions);
	CHECK_EQUAL(possible_moves.size(), 18);

	CHECK_EQUAL(possible_moves[0],  Position(3, 3));
	CHECK_EQUAL(possible_moves[1],  Position(4, 4));
	CHECK_EQUAL(possible_moves[2],  Position(5, 3));
	CHECK_EQUAL(possible_moves[3],  Position(4, 2));
	CHECK_EQUAL(possible_moves[4],  Position(4, 5));
	CHECK_EQUAL(possible_moves[5],  Position(6, 3));
	CHECK_EQUAL(possible_moves[6],  Position(4, 1));
	CHECK_EQUAL(possible_moves[7],  Position(4, 6));
	CHECK_EQUAL(possible_moves[8],  Position(4, 0));
	CHECK_EQUAL(possible_moves[9],  Position(4, 7));
	CHECK_EQUAL(possible_moves[10], Position(3, 4));
	CHECK_EQUAL(possible_moves[11], Position(5, 4));
	CHECK_EQUAL(possible_moves[12], Position(5, 2));
	CHECK_EQUAL(possible_moves[13], Position(3, 2));
	CHECK_EQUAL(possible_moves[14], Position(2, 5));
	CHECK_EQUAL(possible_moves[15], Position(6, 5));
	CHECK_EQUAL(possible_moves[16], Position(6, 1));
	CHECK_EQUAL(possible_moves[17], Position(2, 1));
}

