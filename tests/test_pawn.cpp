#include <CppUTest/TestHarness.h>
#include "core/pawn.hpp"
#include "test_common.hpp"

// Pawn test case
// The pawn only moves one cell "forwards". "forwards" is determined by
// the color of the pawn. The pawn can move 2 cells forward at the first
// move only. The pawn attack diagnoally. It can attack any piece to the
// northeast or northwest of the pawn (where north refers to the forward direction).
// There are aother special move the pawn can do (en passent).
// but it will be implemented in the Grid class.
//
//
//    (|)
//    _ _
//     |
//     WP
//
//
//     BP
//    _|_
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

	FakeGrid occupied_positions;


	void setup()
	{
		occupied_positions = init_grid();
	}

	void teardown()
	{
		for(int i = 0; i < 8; i ++)
			delete[] occupied_positions[i];
		delete[] occupied_positions;
	}
};

TEST(TestPawn, test_pawn_movement_before_first_move)
{
	// Testing white pawn
	DummyPawn white_pawn(6, 0);

	CHECK_TRUE(white_pawn.get_is_first_move());
	
	std::vector<Position> possible_moves(white_pawn.get_valid_positions(occupied_positions));
	CHECK_EQUAL(2, possible_moves.size());
	CHECK_EQUAL(Position(5, 0), possible_moves[0]);
	CHECK_EQUAL(Position(4, 0), possible_moves[1]);

	// Testing black pawn
	DummyPawn black_pawn(1, 0, BLACK);

	CHECK(black_pawn.get_is_first_move());

	possible_moves = black_pawn.get_valid_positions(occupied_positions);
	CHECK_EQUAL(2, possible_moves.size());
	CHECK_EQUAL(Position(2, 0), possible_moves[0]);
	CHECK_EQUAL(Position(3, 0), possible_moves[1]);
	
}

TEST(TestPawn, test_pawn_movement_after_first_move)
{
	// Testing white pawn
	DummyPawn pawn(6, 0);
	CHECK_TRUE(pawn.get_is_first_move());

	pawn.set_position(5, 0);
	CHECK_FALSE(pawn.get_is_first_move());
	
	std::vector<Position> possible_moves(pawn.get_valid_positions(occupied_positions));
	CHECK_EQUAL(1, possible_moves.size());
	CHECK_EQUAL(Position(4, 0), possible_moves[0]);

	// Testing black pawn
	DummyPawn black_pawn(1, 2, BLACK);
	CHECK_TRUE(black_pawn.get_is_first_move());

	black_pawn.set_position(2, 2);
	CHECK_FALSE(black_pawn.get_is_first_move());

	possible_moves = black_pawn.get_valid_positions(occupied_positions);
	CHECK_EQUAL(1, possible_moves.size());
	CHECK_EQUAL(Position(3, 2), possible_moves[0]);
}

TEST(TestPawn, test_case_enemy)
{
	// Testing white pawn
	DummyPawn white_pawn(3, 2);
	white_pawn.set_position(2, 2);
	occupied_positions[2][2] = WHITE;
	CHECK_FALSE(white_pawn.get_is_first_move());
	
	std::vector<Position> possible_moves(white_pawn.get_valid_positions(occupied_positions));
	CHECK_EQUAL(2, possible_moves.size());

	CHECK_EQUAL(Position(1, 3), possible_moves[0]);
	CHECK_EQUAL(Position(1, 1), possible_moves[1]);

	// Testing black pawn
	DummyPawn black_pawn(4, 2, BLACK);
	black_pawn.set_position(5, 2);
	occupied_positions[5][2] = BLACK;
	CHECK_FALSE(black_pawn.get_is_first_move());

	possible_moves = black_pawn.get_valid_positions(occupied_positions);
	CHECK_EQUAL(2, possible_moves.size());

	CHECK_EQUAL(Position(6, 3), possible_moves[0]);
	CHECK_EQUAL(Position(6, 1), possible_moves[1]);
}

