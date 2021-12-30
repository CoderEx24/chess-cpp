#include <CppUTest/TestHarness.h>
#include "core/pawn.hpp"
#include "test_common.hpp"

// Pawn test case
// The pawn only moves one cell "forwards". "forwards" is determined by
// the color of the pawn. The pawn can move 2 cells forward at the first
// move only. There are aother special move the pawn can do (en passent).
// but it will be implemented in the Grid class.
//
//
//    (|)
//     |
//     WP
//
//
//     BP
//     |
//    (|)

class DummyPawn : public Pawn
{
	public: 
		DummyPawn(): Pawn() {}
		DummyPawn(int x, int y, PieceColor c = WHITE): Pawn(x, y, c) {}
		bool get_is_first_move() const { return is_first_move; }
};

TEST_GROUP(TestPawn)
{
	PieceColor occupied_positions[8][8] {
		{BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK},
		{BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK},
		{EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
		{EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
		{EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
		{EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
		{WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE},
		{WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE},
	};

};

TEST(TestPawn, test_pawn_movement_before_first_move)
{
	// Testing white pawn
	DummyPawn white_pawn(6, 0);

	CHECK(white_pawn.get_is_first_move());
	
	std::vector<Position> possible_moves(white_pawn.get_valid_positions((FakeGrid) occupied_positions));
	CHECK_EQUAL(possible_moves.size(), 2);
	CHECK_EQUAL(possible_moves[0], Position(5, 0));
	CHECK_EQUAL(possible_moves[1], Position(4, 0));

	// Testing black pawn
	DummyPawn black_pawn(1, 0, BLACK);

	CHECK(black_pawn.get_is_first_move());

	possible_moves = black_pawn.get_valid_positions((FakeGrid) occupied_positions);
	CHECK_EQUAL(possible_moves.size(), 2);
	CHECK_EQUAL(possible_moves[0], Position(2, 0));
	CHECK_EQUAL(possible_moves[1], Position(3, 0));

}

TEST(TestPawn, test_pawn_movement_after_first_move)
{
	// Testing white pawn
	DummyPawn pawn(6, 0);
	CHECK(pawn.get_is_first_move());

	pawn.set_position(5, 0);
	CHECK(!pawn.get_is_first_move());
	
	std::vector<Position> possible_moves(pawn.get_valid_positions((FakeGrid) occupied_positions));
	CHECK_EQUAL(possible_moves.size(), 1);
	CHECK_EQUAL(possible_moves[0], Position(4, 0));

	// Testing black pawn
	DummyPawn black_pawn(1, 2, BLACK);
	CHECK(black_pawn.get_is_first_move());

	black_pawn.set_position(2, 2);
	CHECK(!black_pawn.get_is_first_move());

	possible_moves = black_pawn.get_valid_positions((FakeGrid) occupied_positions);
	CHECK_EQUAL(possible_moves.size(), 1);
	CHECK_EQUAL(possible_moves[0], Position(2, 2));
}

