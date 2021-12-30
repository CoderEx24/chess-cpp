#include <CppUTest/TestHarness.h>
#include "core/bishop.hpp"
#include "test_common.hpp"

// Bishop test case
// the bishop moves diagonally, as far as it can
//
// the moves are ordered starting with the northeast direction, going clockwise
//
//  \       /
//   \     /
//    4   1
//     \ /
//      B
//     / \
//    3   2
//   /     \
//  /       \
//

TEST_GROUP(TestBishop)
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

TEST(TestBishop, test_at_inital_position)
{
	// testing white bishop
	Bishop white_bishop(7, 2, WHITE);
	
	std::vector<Position> possible_moves(white_bishop.get_valid_positions(occupied_positions));
	CHECK_EQUAL(possible_moves.size(), 0);
	
	// testing black bishop	
	Bishop black_bishop(0, 2, BLACK);
	
	possible_moves = black_bishop.get_valid_positions(occupied_positions);
	CHECK_EQUAL(possible_moves.size(), 0);

}

TEST(TestBishop, test_case_1)
{
	// testing white bishop
	Bishop white_bishop(5, 4, WHITE);
	occupied_positions[5][4] = WHITE;

	std::vector<Position> possible_moves(white_bishop.get_valid_positions(occupied_positions));
	CHECK_EQUAL(possible_moves.size(), 7);

	CHECK_EQUAL(possible_moves[0], Position(4, 5));
	CHECK_EQUAL(possible_moves[1], Position(4, 3));
	CHECK_EQUAL(possible_moves[2], Position(3, 6));
	CHECK_EQUAL(possible_moves[3], Position(3, 2));
	CHECK_EQUAL(possible_moves[4], Position(2, 7));
	CHECK_EQUAL(possible_moves[5], Position(2, 1));
	CHECK_EQUAL(possible_moves[6], Position(1, 0));

	// testing black bishop
	Bishop black_bishop(2, 4, BLACK);
	occupied_positions[2][4] = BLACK;

	possible_moves = black_bishop.get_valid_positions(occupied_positions);
	CHECK_EQUAL(possible_moves.size(), 7);

	CHECK_EQUAL(possible_moves[0], Position(3, 5));
	CHECK_EQUAL(possible_moves[1], Position(3, 3));
	CHECK_EQUAL(possible_moves[2], Position(4, 6));
	CHECK_EQUAL(possible_moves[3], Position(4, 2));
	CHECK_EQUAL(possible_moves[4], Position(5, 7));
	CHECK_EQUAL(possible_moves[5], Position(5, 1));
	CHECK_EQUAL(possible_moves[6], Position(6, 0));
}

TEST(TestBishop, test_case_2)
{
	// testing white bishop
	Bishop white_bishop(4, 3, WHITE);
	occupied_positions[4][3] = WHITE;

	std::vector<Position> possible_moves(white_bishop.get_valid_positions(occupied_positions));
	CHECK_EQUAL(possible_moves.size(), 8);

	CHECK_EQUAL(possible_moves[0], Position(3, 4));
	CHECK_EQUAL(possible_moves[1], Position(5, 4));
	CHECK_EQUAL(possible_moves[2], Position(5, 2));
	CHECK_EQUAL(possible_moves[3], Position(3, 2));
	CHECK_EQUAL(possible_moves[4], Position(2, 5));
	CHECK_EQUAL(possible_moves[5], Position(2, 1));
	CHECK_EQUAL(possible_moves[6], Position(1, 6));
	CHECK_EQUAL(possible_moves[7], Position(1, 0));
	
	// testing black bishop
	Bishop black_bishop(3, 3, BLACK);
	occupied_positions[3][3] = BLACK;

	possible_moves = black_bishop.get_valid_positions(occupied_positions);
	CHECK_EQUAL(possible_moves.size(), 8);

	CHECK_EQUAL(possible_moves[9], Position(2, 4));
	CHECK_EQUAL(possible_moves[1], Position(4, 4));
	CHECK_EQUAL(possible_moves[2], Position(4, 2));
	CHECK_EQUAL(possible_moves[3], Position(2, 2));
	CHECK_EQUAL(possible_moves[4], Position(5, 5));
	CHECK_EQUAL(possible_moves[5], Position(5, 1));
	CHECK_EQUAL(possible_moves[6], Position(6, 6));
	CHECK_EQUAL(possible_moves[7], Position(6, 0));
}
