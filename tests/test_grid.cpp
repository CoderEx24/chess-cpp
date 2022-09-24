#include <CppUTest/TestHarness.h>
#include <algorithm>
#include "core/grid.hpp"

class DummyGrid : public Grid
{
	public:
		DummyGrid(): Grid() {};
		DummyGrid(PlaceCommand *commands, int size): Grid(commands, size) {};

        PieceColor get_current_turn() { return this->current_turn; }

		friend const AbstractChessPiece* get_piece_at(const DummyGrid&, const Position&);
};

const AbstractChessPiece* get_piece_at(const DummyGrid& grid, const Position& pos)
{
	return const_cast<const AbstractChessPiece*>(grid.grid[pos.x][pos.y]);
}

TEST_GROUP(TestGrid)
{
	TEST_SETUP()    {}
	TEST_TEARDOWN() {}
};

TEST(TestGrid, test_at_initial_state)
{
	// testing initial grid state
	DummyGrid grid;

	// testing the first row
	CHECK_EQUAL(ROOK  , get_piece_at(grid, Position(0, 0))->get_type() );
	CHECK_EQUAL(BLACK , get_piece_at(grid, Position(0, 0))->get_color());

	CHECK_EQUAL(KNIGHT, get_piece_at(grid, Position(0, 1))->get_type() );
	CHECK_EQUAL(BLACK , get_piece_at(grid, Position(0, 1))->get_color());

	CHECK_EQUAL(BISHOP, get_piece_at(grid, Position(0, 2))->get_type() );
	CHECK_EQUAL(BLACK , get_piece_at(grid, Position(0, 2))->get_color());

	CHECK_EQUAL(QUEEN , get_piece_at(grid, Position(0, 3))->get_type() );
	CHECK_EQUAL(BLACK , get_piece_at(grid, Position(0, 3))->get_color());

	CHECK_EQUAL(KING  , get_piece_at(grid, Position(0, 4))->get_type() );
	CHECK_EQUAL(BLACK , get_piece_at(grid, Position(0, 4))->get_color());

	CHECK_EQUAL(BISHOP, get_piece_at(grid, Position(0, 5))->get_type() );
	CHECK_EQUAL(BLACK , get_piece_at(grid, Position(0, 5))->get_color());

	CHECK_EQUAL(KNIGHT, get_piece_at(grid, Position(0, 6))->get_type() );
	CHECK_EQUAL(BLACK , get_piece_at(grid, Position(0, 6))->get_color());

	CHECK_EQUAL(ROOK  , get_piece_at(grid, Position(0, 7))->get_type() );
	CHECK_EQUAL(BLACK , get_piece_at(grid, Position(0, 7))->get_color());

	// testing the second row

	CHECK_EQUAL(PAWN  , get_piece_at(grid, Position(1, 0))->get_type() );
	CHECK_EQUAL(BLACK , get_piece_at(grid, Position(1, 0))->get_color());

	CHECK_EQUAL(PAWN  , get_piece_at(grid, Position(1, 1))->get_type() );
	CHECK_EQUAL(BLACK , get_piece_at(grid, Position(1, 1))->get_color());

	CHECK_EQUAL(PAWN  , get_piece_at(grid, Position(1, 2))->get_type() );
	CHECK_EQUAL(BLACK , get_piece_at(grid, Position(1, 2))->get_color());

	CHECK_EQUAL(PAWN  , get_piece_at(grid, Position(1, 3))->get_type() );
	CHECK_EQUAL(BLACK , get_piece_at(grid, Position(1, 3))->get_color());

	CHECK_EQUAL(PAWN  , get_piece_at(grid, Position(1, 4))->get_type() );
	CHECK_EQUAL(BLACK , get_piece_at(grid, Position(1, 4))->get_color());

	CHECK_EQUAL(PAWN  , get_piece_at(grid, Position(1, 5))->get_type() );
	CHECK_EQUAL(BLACK , get_piece_at(grid, Position(1, 5))->get_color());

	CHECK_EQUAL(PAWN  , get_piece_at(grid, Position(1, 6))->get_type() );
	CHECK_EQUAL(BLACK , get_piece_at(grid, Position(1, 6))->get_color());

	CHECK_EQUAL(PAWN  , get_piece_at(grid, Position(1, 7))->get_type() );
	CHECK_EQUAL(BLACK , get_piece_at(grid, Position(1, 7))->get_color());

	// tesing second to last row

	CHECK_EQUAL(PAWN  , get_piece_at(grid, Position(6, 0))->get_type() );
	CHECK_EQUAL(WHITE , get_piece_at(grid, Position(6, 0))->get_color());

	CHECK_EQUAL(PAWN  , get_piece_at(grid, Position(6, 1))->get_type() );
	CHECK_EQUAL(WHITE , get_piece_at(grid, Position(6, 1))->get_color());

	CHECK_EQUAL(PAWN  , get_piece_at(grid, Position(6, 2))->get_type() );
	CHECK_EQUAL(WHITE , get_piece_at(grid, Position(6, 2))->get_color());

	CHECK_EQUAL(PAWN  , get_piece_at(grid, Position(6, 3))->get_type() );
	CHECK_EQUAL(WHITE , get_piece_at(grid, Position(6, 3))->get_color());

	CHECK_EQUAL(PAWN  , get_piece_at(grid, Position(6, 4))->get_type() );
	CHECK_EQUAL(WHITE , get_piece_at(grid, Position(6, 4))->get_color());

	CHECK_EQUAL(PAWN  , get_piece_at(grid, Position(6, 5))->get_type() );
	CHECK_EQUAL(WHITE , get_piece_at(grid, Position(6, 5))->get_color());

	CHECK_EQUAL(PAWN  , get_piece_at(grid, Position(6, 6))->get_type() );
	CHECK_EQUAL(WHITE , get_piece_at(grid, Position(6, 6))->get_color());

	CHECK_EQUAL(PAWN  , get_piece_at(grid, Position(6, 7))->get_type() );
	CHECK_EQUAL(WHITE , get_piece_at(grid, Position(6, 7))->get_color());


	// testing the last row
	CHECK_EQUAL(ROOK  , get_piece_at(grid, Position(7, 0))->get_type() );
	CHECK_EQUAL(WHITE , get_piece_at(grid, Position(7, 0))->get_color());

	CHECK_EQUAL(KNIGHT, get_piece_at(grid, Position(7, 1))->get_type() );
	CHECK_EQUAL(WHITE , get_piece_at(grid, Position(7, 1))->get_color());

	CHECK_EQUAL(BISHOP, get_piece_at(grid, Position(7, 2))->get_type() );
	CHECK_EQUAL(WHITE , get_piece_at(grid, Position(7, 2))->get_color());

	CHECK_EQUAL(QUEEN , get_piece_at(grid, Position(7, 3))->get_type() );
	CHECK_EQUAL(WHITE , get_piece_at(grid, Position(7, 3))->get_color());

	CHECK_EQUAL(KING  , get_piece_at(grid, Position(7, 4))->get_type() );
	CHECK_EQUAL(WHITE , get_piece_at(grid, Position(7, 4))->get_color());

	CHECK_EQUAL(BISHOP, get_piece_at(grid, Position(7, 5))->get_type() );
	CHECK_EQUAL(WHITE , get_piece_at(grid, Position(7, 5))->get_color());

	CHECK_EQUAL(KNIGHT, get_piece_at(grid, Position(7, 6))->get_type() );
	CHECK_EQUAL(WHITE , get_piece_at(grid, Position(7, 6))->get_color());

	CHECK_EQUAL(ROOK  , get_piece_at(grid, Position(7, 7))->get_type() );
	CHECK_EQUAL(WHITE , get_piece_at(grid, Position(7, 7))->get_color());

	// testing the middle 4 rows

	CHECK_EQUAL(nullptr, get_piece_at(grid, Position(2, 0)));
	CHECK_EQUAL(nullptr, get_piece_at(grid, Position(2, 1)));
	CHECK_EQUAL(nullptr, get_piece_at(grid, Position(2, 2)));
	CHECK_EQUAL(nullptr, get_piece_at(grid, Position(2, 3)));
	CHECK_EQUAL(nullptr, get_piece_at(grid, Position(2, 4)));
	CHECK_EQUAL(nullptr, get_piece_at(grid, Position(2, 5)));
	CHECK_EQUAL(nullptr, get_piece_at(grid, Position(2, 6)));
	CHECK_EQUAL(nullptr, get_piece_at(grid, Position(2, 7)));

	CHECK_EQUAL(nullptr, get_piece_at(grid, Position(3, 0)));
	CHECK_EQUAL(nullptr, get_piece_at(grid, Position(3, 1)));
	CHECK_EQUAL(nullptr, get_piece_at(grid, Position(3, 2)));
	CHECK_EQUAL(nullptr, get_piece_at(grid, Position(3, 3)));
	CHECK_EQUAL(nullptr, get_piece_at(grid, Position(3, 4)));
	CHECK_EQUAL(nullptr, get_piece_at(grid, Position(3, 5)));
	CHECK_EQUAL(nullptr, get_piece_at(grid, Position(3, 6)));
	CHECK_EQUAL(nullptr, get_piece_at(grid, Position(3, 7)));

	CHECK_EQUAL(nullptr, get_piece_at(grid, Position(4, 0)));
	CHECK_EQUAL(nullptr, get_piece_at(grid, Position(4, 1)));
	CHECK_EQUAL(nullptr, get_piece_at(grid, Position(4, 2)));
	CHECK_EQUAL(nullptr, get_piece_at(grid, Position(4, 3)));
	CHECK_EQUAL(nullptr, get_piece_at(grid, Position(4, 4)));
	CHECK_EQUAL(nullptr, get_piece_at(grid, Position(4, 5)));
	CHECK_EQUAL(nullptr, get_piece_at(grid, Position(4, 6)));
	CHECK_EQUAL(nullptr, get_piece_at(grid, Position(4, 7)));

	CHECK_EQUAL(nullptr, get_piece_at(grid, Position(5, 0)));
	CHECK_EQUAL(nullptr, get_piece_at(grid, Position(5, 1)));
	CHECK_EQUAL(nullptr, get_piece_at(grid, Position(5, 2)));
	CHECK_EQUAL(nullptr, get_piece_at(grid, Position(5, 3)));
	CHECK_EQUAL(nullptr, get_piece_at(grid, Position(5, 4)));
	CHECK_EQUAL(nullptr, get_piece_at(grid, Position(5, 5)));
	CHECK_EQUAL(nullptr, get_piece_at(grid, Position(5, 6)));
	CHECK_EQUAL(nullptr, get_piece_at(grid, Position(5, 7)));

}

TEST(TestGrid, test_custom_grids)
{
	// test 1
	// place 4 pawns the first row
	PlaceCommand grid1_commands [] {
		Grid::encode(Position(0, 0), PAWN, WHITE),
		Grid::encode(Position(0, 1), PAWN, BLACK),
		Grid::encode(Position(0, 2), PAWN, WHITE),
		Grid::encode(Position(0, 3), PAWN, BLACK)
	};

	DummyGrid grid1(grid1_commands, 4);

	CHECK_EQUAL(PAWN,  get_piece_at(grid1, Position(0, 0))->get_type());
	CHECK_EQUAL(WHITE, get_piece_at(grid1, Position(0, 0))->get_color());

	CHECK_EQUAL(PAWN,  get_piece_at(grid1, Position(0, 1))->get_type());
	CHECK_EQUAL(BLACK, get_piece_at(grid1, Position(0, 1))->get_color());

	CHECK_EQUAL(PAWN,  get_piece_at(grid1, Position(0, 2))->get_type());
	CHECK_EQUAL(WHITE, get_piece_at(grid1, Position(0, 2))->get_color());

	CHECK_EQUAL(PAWN,  get_piece_at(grid1, Position(0, 3))->get_type());
	CHECK_EQUAL(BLACK, get_piece_at(grid1, Position(0, 3))->get_color());


	CHECK_EQUAL(nullptr, get_piece_at(grid1, Position(0, 4)));
	CHECK_EQUAL(nullptr, get_piece_at(grid1, Position(0, 5)));
	CHECK_EQUAL(nullptr, get_piece_at(grid1, Position(0, 6)));
	CHECK_EQUAL(nullptr, get_piece_at(grid1, Position(0, 7)));
	CHECK_EQUAL(nullptr, get_piece_at(grid1, Position(1, 0)));
	CHECK_EQUAL(nullptr, get_piece_at(grid1, Position(1, 1)));
	CHECK_EQUAL(nullptr, get_piece_at(grid1, Position(1, 2)));
	CHECK_EQUAL(nullptr, get_piece_at(grid1, Position(1, 3)));
	CHECK_EQUAL(nullptr, get_piece_at(grid1, Position(1, 4)));
	CHECK_EQUAL(nullptr, get_piece_at(grid1, Position(1, 5)));
	CHECK_EQUAL(nullptr, get_piece_at(grid1, Position(1, 6)));
	CHECK_EQUAL(nullptr, get_piece_at(grid1, Position(1, 7)));
	CHECK_EQUAL(nullptr, get_piece_at(grid1, Position(2, 0)));
	CHECK_EQUAL(nullptr, get_piece_at(grid1, Position(2, 1)));
	CHECK_EQUAL(nullptr, get_piece_at(grid1, Position(2, 2)));
	CHECK_EQUAL(nullptr, get_piece_at(grid1, Position(2, 3)));
	CHECK_EQUAL(nullptr, get_piece_at(grid1, Position(2, 4)));
	CHECK_EQUAL(nullptr, get_piece_at(grid1, Position(2, 5)));
	CHECK_EQUAL(nullptr, get_piece_at(grid1, Position(2, 6)));
	CHECK_EQUAL(nullptr, get_piece_at(grid1, Position(2, 7)));
	CHECK_EQUAL(nullptr, get_piece_at(grid1, Position(3, 0)));
	CHECK_EQUAL(nullptr, get_piece_at(grid1, Position(3, 1)));
	CHECK_EQUAL(nullptr, get_piece_at(grid1, Position(3, 2)));
	CHECK_EQUAL(nullptr, get_piece_at(grid1, Position(3, 3)));
	CHECK_EQUAL(nullptr, get_piece_at(grid1, Position(3, 4)));
	CHECK_EQUAL(nullptr, get_piece_at(grid1, Position(3, 5)));
	CHECK_EQUAL(nullptr, get_piece_at(grid1, Position(3, 6)));
	CHECK_EQUAL(nullptr, get_piece_at(grid1, Position(3, 7)));
	CHECK_EQUAL(nullptr, get_piece_at(grid1, Position(4, 0)));
	CHECK_EQUAL(nullptr, get_piece_at(grid1, Position(4, 1)));
	CHECK_EQUAL(nullptr, get_piece_at(grid1, Position(4, 2)));
	CHECK_EQUAL(nullptr, get_piece_at(grid1, Position(4, 3)));
	CHECK_EQUAL(nullptr, get_piece_at(grid1, Position(4, 4)));
	CHECK_EQUAL(nullptr, get_piece_at(grid1, Position(4, 5)));
	CHECK_EQUAL(nullptr, get_piece_at(grid1, Position(4, 6)));
	CHECK_EQUAL(nullptr, get_piece_at(grid1, Position(4, 7)));
	CHECK_EQUAL(nullptr, get_piece_at(grid1, Position(5, 0)));
	CHECK_EQUAL(nullptr, get_piece_at(grid1, Position(5, 1)));
	CHECK_EQUAL(nullptr, get_piece_at(grid1, Position(5, 2)));
	CHECK_EQUAL(nullptr, get_piece_at(grid1, Position(5, 3)));
	CHECK_EQUAL(nullptr, get_piece_at(grid1, Position(5, 4)));
	CHECK_EQUAL(nullptr, get_piece_at(grid1, Position(5, 5)));
	CHECK_EQUAL(nullptr, get_piece_at(grid1, Position(5, 6)));
	CHECK_EQUAL(nullptr, get_piece_at(grid1, Position(5, 7)));
	CHECK_EQUAL(nullptr, get_piece_at(grid1, Position(6, 0)));
	CHECK_EQUAL(nullptr, get_piece_at(grid1, Position(6, 1)));
	CHECK_EQUAL(nullptr, get_piece_at(grid1, Position(6, 2)));
	CHECK_EQUAL(nullptr, get_piece_at(grid1, Position(6, 3)));
	CHECK_EQUAL(nullptr, get_piece_at(grid1, Position(6, 4)));
	CHECK_EQUAL(nullptr, get_piece_at(grid1, Position(6, 5)));
	CHECK_EQUAL(nullptr, get_piece_at(grid1, Position(6, 7)));
	CHECK_EQUAL(nullptr, get_piece_at(grid1, Position(6, 6)));
	CHECK_EQUAL(nullptr, get_piece_at(grid1, Position(7, 0)));
	CHECK_EQUAL(nullptr, get_piece_at(grid1, Position(7, 1)));
	CHECK_EQUAL(nullptr, get_piece_at(grid1, Position(7, 2)));
	CHECK_EQUAL(nullptr, get_piece_at(grid1, Position(7, 3)));
	CHECK_EQUAL(nullptr, get_piece_at(grid1, Position(7, 4)));
	CHECK_EQUAL(nullptr, get_piece_at(grid1, Position(7, 5)));
	CHECK_EQUAL(nullptr, get_piece_at(grid1, Position(7, 6)));
	CHECK_EQUAL(nullptr, get_piece_at(grid1, Position(7, 7)));

	// test 2
	// place a king in the middle of the board
	PlaceCommand grid2_commands[] { Grid::encode(Position(3, 3), KING, WHITE) };

	DummyGrid grid2(grid2_commands, 1);

	CHECK_EQUAL(KING,  get_piece_at(grid2, Position(3, 3))->get_type());
	CHECK_EQUAL(WHITE, get_piece_at(grid2, Position(3, 3))->get_color());

	CHECK_EQUAL(nullptr, get_piece_at(grid2, Position(0, 0)));
	CHECK_EQUAL(nullptr, get_piece_at(grid2, Position(0, 1)));
	CHECK_EQUAL(nullptr, get_piece_at(grid2, Position(0, 2)));
	CHECK_EQUAL(nullptr, get_piece_at(grid2, Position(0, 3)));
	CHECK_EQUAL(nullptr, get_piece_at(grid2, Position(0, 4)));
	CHECK_EQUAL(nullptr, get_piece_at(grid2, Position(0, 5)));
	CHECK_EQUAL(nullptr, get_piece_at(grid2, Position(0, 6)));
	CHECK_EQUAL(nullptr, get_piece_at(grid2, Position(0, 7)));
	CHECK_EQUAL(nullptr, get_piece_at(grid2, Position(1, 0)));
	CHECK_EQUAL(nullptr, get_piece_at(grid2, Position(1, 1)));
	CHECK_EQUAL(nullptr, get_piece_at(grid2, Position(1, 2)));
	CHECK_EQUAL(nullptr, get_piece_at(grid2, Position(1, 3)));
	CHECK_EQUAL(nullptr, get_piece_at(grid2, Position(1, 4)));
	CHECK_EQUAL(nullptr, get_piece_at(grid2, Position(1, 5)));
	CHECK_EQUAL(nullptr, get_piece_at(grid2, Position(1, 6)));
	CHECK_EQUAL(nullptr, get_piece_at(grid2, Position(1, 7)));
	CHECK_EQUAL(nullptr, get_piece_at(grid2, Position(2, 0)));
	CHECK_EQUAL(nullptr, get_piece_at(grid2, Position(2, 1)));
	CHECK_EQUAL(nullptr, get_piece_at(grid2, Position(2, 2)));
	CHECK_EQUAL(nullptr, get_piece_at(grid2, Position(2, 3)));
	CHECK_EQUAL(nullptr, get_piece_at(grid2, Position(2, 4)));
	CHECK_EQUAL(nullptr, get_piece_at(grid2, Position(2, 5)));
	CHECK_EQUAL(nullptr, get_piece_at(grid2, Position(2, 6)));
	CHECK_EQUAL(nullptr, get_piece_at(grid2, Position(2, 7)));
	CHECK_EQUAL(nullptr, get_piece_at(grid2, Position(3, 0)));
	CHECK_EQUAL(nullptr, get_piece_at(grid2, Position(3, 1)));
	CHECK_EQUAL(nullptr, get_piece_at(grid2, Position(3, 2)));
	CHECK_EQUAL(nullptr, get_piece_at(grid2, Position(3, 4)));
	CHECK_EQUAL(nullptr, get_piece_at(grid2, Position(3, 5)));
	CHECK_EQUAL(nullptr, get_piece_at(grid2, Position(3, 6)));
	CHECK_EQUAL(nullptr, get_piece_at(grid2, Position(3, 7)));
	CHECK_EQUAL(nullptr, get_piece_at(grid2, Position(4, 0)));
	CHECK_EQUAL(nullptr, get_piece_at(grid2, Position(4, 1)));
	CHECK_EQUAL(nullptr, get_piece_at(grid2, Position(4, 2)));
	CHECK_EQUAL(nullptr, get_piece_at(grid2, Position(4, 3)));
	CHECK_EQUAL(nullptr, get_piece_at(grid2, Position(4, 4)));
	CHECK_EQUAL(nullptr, get_piece_at(grid2, Position(4, 5)));
	CHECK_EQUAL(nullptr, get_piece_at(grid2, Position(4, 6)));
	CHECK_EQUAL(nullptr, get_piece_at(grid2, Position(4, 7)));
	CHECK_EQUAL(nullptr, get_piece_at(grid2, Position(5, 0)));
	CHECK_EQUAL(nullptr, get_piece_at(grid2, Position(5, 1)));
	CHECK_EQUAL(nullptr, get_piece_at(grid2, Position(5, 2)));
	CHECK_EQUAL(nullptr, get_piece_at(grid2, Position(5, 3)));
	CHECK_EQUAL(nullptr, get_piece_at(grid2, Position(5, 4)));
	CHECK_EQUAL(nullptr, get_piece_at(grid2, Position(5, 5)));
	CHECK_EQUAL(nullptr, get_piece_at(grid2, Position(5, 6)));
	CHECK_EQUAL(nullptr, get_piece_at(grid2, Position(5, 7)));
	CHECK_EQUAL(nullptr, get_piece_at(grid2, Position(6, 0)));
	CHECK_EQUAL(nullptr, get_piece_at(grid2, Position(6, 1)));
	CHECK_EQUAL(nullptr, get_piece_at(grid2, Position(6, 2)));
	CHECK_EQUAL(nullptr, get_piece_at(grid2, Position(6, 3)));
	CHECK_EQUAL(nullptr, get_piece_at(grid2, Position(6, 4)));
	CHECK_EQUAL(nullptr, get_piece_at(grid2, Position(6, 5)));
	CHECK_EQUAL(nullptr, get_piece_at(grid2, Position(6, 7)));
	CHECK_EQUAL(nullptr, get_piece_at(grid2, Position(6, 6)));
	CHECK_EQUAL(nullptr, get_piece_at(grid2, Position(7, 0)));
	CHECK_EQUAL(nullptr, get_piece_at(grid2, Position(7, 1)));
	CHECK_EQUAL(nullptr, get_piece_at(grid2, Position(7, 2)));
	CHECK_EQUAL(nullptr, get_piece_at(grid2, Position(7, 3)));
	CHECK_EQUAL(nullptr, get_piece_at(grid2, Position(7, 4)));
	CHECK_EQUAL(nullptr, get_piece_at(grid2, Position(7, 5)));
	CHECK_EQUAL(nullptr, get_piece_at(grid2, Position(7, 6)));
	CHECK_EQUAL(nullptr, get_piece_at(grid2, Position(7, 7)));

}

TEST(TestGrid, test_turn_switch)
{
    DummyGrid grid;

    CHECK_EQUAL(WHITE, grid.get_current_turn());

    // moving a white pawn
    CHECK_TRUE(grid.move(Position(6, 0), Position(5, 0)));

    CHECK_EQUAL(BLACK, grid.get_current_turn());

    // moving a black pawn
    CHECK_TRUE(grid.move(Position(1, 0), Position(2, 0)));

    CHECK_EQUAL(WHITE, grid.get_current_turn());
}

TEST(TestGrid, test_move_pawn_one_step)
{
    DummyGrid grid;

    // checking white pawns
    CHECK_TRUE(grid.move(Position(6, 0), Position(5, 0)));

    CHECK_EQUAL(nullptr, get_piece_at(grid, Position(6, 0)));
    CHECK_EQUAL(PAWN,    get_piece_at(grid, Position(5, 0))->get_type());
    CHECK_EQUAL(WHITE,   get_piece_at(grid, Position(5, 0))->get_color());

    // checking black pawns
    CHECK_TRUE(grid.move(Position(1, 0), Position(2, 0)));

    CHECK_EQUAL(nullptr, get_piece_at(grid, Position(1, 0)));
    CHECK_EQUAL(PAWN,    get_piece_at(grid, Position(2, 0))->get_type());
    CHECK_EQUAL(BLACK,   get_piece_at(grid, Position(2, 0))->get_color());
}

TEST(TestGrid, test_move_pawn_two_steps)
{
    DummyGrid grid;

    // checking white pawns
    CHECK_TRUE(grid.move(Position(6, 0), Position(4, 0)));

    CHECK_EQUAL(nullptr, get_piece_at(grid, Position(6, 0)));
    CHECK_EQUAL(PAWN,    get_piece_at(grid, Position(4, 0))->get_type());
    CHECK_EQUAL(WHITE,   get_piece_at(grid, Position(4, 0))->get_color());

    // checking black pawns
    CHECK_TRUE(grid.move(Position(1, 1), Position(3, 1)));

    CHECK_EQUAL(nullptr, get_piece_at(grid, Position(1, 1)));
    CHECK_EQUAL(PAWN,    get_piece_at(grid, Position(3, 1))->get_type());
    CHECK_EQUAL(BLACK,   get_piece_at(grid, Position(3, 1))->get_color());
}

TEST(TestGrid, test_move_rook)
{
    DummyGrid grid;

    // clear a path for the rooks
    CHECK_TRUE(grid.move(Position(6, 0), Position(4, 0)));
    CHECK_TRUE(grid.move(Position(1, 0), Position(3, 0)));

    // move white rook
    CHECK_TRUE(grid.move(Position(7, 0), Position(5, 0)));

    CHECK_EQUAL(nullptr, get_piece_at(grid, Position(7, 0)));
    CHECK_EQUAL(ROOK,    get_piece_at(grid, Position(5, 0))->get_type());
    CHECK_EQUAL(WHITE,   get_piece_at(grid, Position(5, 0))->get_color());

    // move black rook
    CHECK_TRUE(grid.move(Position(0, 0), Position(2, 0)));

    CHECK_EQUAL(nullptr, get_piece_at(grid, Position(0, 0)));
    CHECK_EQUAL(ROOK,    get_piece_at(grid, Position(2, 0))->get_type());
    CHECK_EQUAL(BLACK,   get_piece_at(grid, Position(2, 0))->get_color());

    // moving the white rook to an open position
    CHECK_TRUE(grid.move(Position(5, 0), Position(5, 4)));

    CHECK_EQUAL(nullptr, get_piece_at(grid, Position(5, 0)));
    CHECK_EQUAL(ROOK,    get_piece_at(grid, Position(5, 4))->get_type());
    CHECK_EQUAL(WHITE,   get_piece_at(grid, Position(5, 4))->get_color());

    // moving the black rook to the same column
    CHECK_TRUE(grid.move(Position(2, 0), Position(2, 4)));

    CHECK_EQUAL(nullptr, get_piece_at(grid, Position(2, 0)));
    CHECK_EQUAL(ROOK,    get_piece_at(grid, Position(2, 4))->get_type());
    CHECK_EQUAL(BLACK,   get_piece_at(grid, Position(2, 4))->get_color());

    // capturing the black rook
    CHECK_TRUE(grid.move(Position(5, 4), Position(2, 4)));

    CHECK_EQUAL(nullptr, get_piece_at(grid, Position(5, 4)));
    CHECK_EQUAL(ROOK,    get_piece_at(grid, Position(2, 4))->get_type());
    CHECK_EQUAL(WHITE,   get_piece_at(grid, Position(2, 4))->get_color());
}

TEST(TestGrid, test_move_knight)
{
    DummyGrid grid;

    // moving white knight
    CHECK_TRUE(grid.move(Position(7, 1), Position(5, 2)));

    CHECK_EQUAL(nullptr, get_piece_at(grid, Position(7, 1)));
    CHECK_EQUAL(KNIGHT,  get_piece_at(grid, Position(5, 2))->get_type());
    CHECK_EQUAL(WHITE,   get_piece_at(grid, Position(5, 2))->get_color());

    // moving black knight
    CHECK_TRUE(grid.move(Position(0, 1), Position(2, 0)));

    CHECK_EQUAL(nullptr, get_piece_at(grid, Position(0, 1)));
    CHECK_EQUAL(KNIGHT,  get_piece_at(grid, Position(2, 0))->get_type());
    CHECK_EQUAL(BLACK,   get_piece_at(grid, Position(2, 0))->get_color());

    // moving white knight
    CHECK_TRUE(grid.move(Position(5, 2), Position(4, 0)));

    CHECK_EQUAL(nullptr, get_piece_at(grid, Position(5, 2)));
    CHECK_EQUAL(KNIGHT,  get_piece_at(grid, Position(4, 0))->get_type());
    CHECK_EQUAL(WHITE,   get_piece_at(grid, Position(4, 0))->get_color());

    // moving black knight
    CHECK_TRUE(grid.move(Position(2, 0), Position(3, 2)));

    CHECK_EQUAL(nullptr, get_piece_at(grid, Position(2, 0)));
    CHECK_EQUAL(KNIGHT,  get_piece_at(grid, Position(3, 2))->get_type());
    CHECK_EQUAL(BLACK,   get_piece_at(grid, Position(3, 2))->get_color());

    // moving white knight
    CHECK_TRUE(grid.move(Position(4, 0), Position(3, 2)));

    CHECK_EQUAL(nullptr, get_piece_at(grid, Position(2, 0)));
    CHECK_EQUAL(KNIGHT,  get_piece_at(grid, Position(3, 2))->get_type());
    CHECK_EQUAL(WHITE,   get_piece_at(grid, Position(3, 2))->get_color());
}

TEST(TestGrid, test_move_bishop)
{
    DummyGrid grid;

    // clearing the path for the bishops
    CHECK_TRUE(grid.move(Position(6, 4), Position(4, 4)));
    CHECK_TRUE(grid.move(Position(1, 1), Position(3, 1)));

    // moving white bishop
    CHECK_TRUE(grid.move(Position(7, 5), Position(3, 1)));

    CHECK_EQUAL(nullptr, get_piece_at(grid, Position(7, 5)));
    CHECK_EQUAL(BISHOP,  get_piece_at(grid, Position(3, 1))->get_type());
    CHECK_EQUAL(WHITE,   get_piece_at(grid, Position(3, 1))->get_color());

    // moving black bishop
    CHECK_TRUE(grid.move(Position(0, 2), Position(2, 0)));

    CHECK_EQUAL(nullptr, get_piece_at(grid, Position(0, 2)));
    CHECK_EQUAL(BISHOP,  get_piece_at(grid, Position(2, 0))->get_type());
    CHECK_EQUAL(BLACK,   get_piece_at(grid, Position(2, 0))->get_color());

    // capturing black bishop

    CHECK_TRUE(grid.move(Position(3, 1), Position(2, 0)));

    CHECK_EQUAL(nullptr, get_piece_at(grid, Position(3, 1)));
    CHECK_EQUAL(BISHOP,  get_piece_at(grid, Position(2, 0))->get_type());
    CHECK_EQUAL(WHITE,   get_piece_at(grid, Position(2, 0))->get_color());
}

TEST(TestGrid, test_move_queen)
{
    DummyGrid grid;

    // clearing the path for the queens
    CHECK_TRUE(grid.move(Position(6, 3), Position(4, 3)));
    CHECK_TRUE(grid.move(Position(1, 3), Position(3, 3)));

    // moving white queen
    CHECK_TRUE(grid.move(Position(7, 3), Position(5, 3)));

    CHECK_EQUAL(nullptr, get_piece_at(grid, Position(7, 3)));
    CHECK_EQUAL(QUEEN,   get_piece_at(grid, Position(5, 3))->get_type());
    CHECK_EQUAL(WHITE,   get_piece_at(grid, Position(5, 3))->get_color());

    // moving black queen
    CHECK_TRUE(grid.move(Position(0, 3), Position(2, 3)));

    CHECK_EQUAL(nullptr, get_piece_at(grid, Position(0, 3)));
    CHECK_EQUAL(QUEEN,   get_piece_at(grid, Position(2, 3))->get_type());
    CHECK_EQUAL(BLACK,   get_piece_at(grid, Position(2, 3))->get_color());

    // moving white queen
    CHECK_TRUE(grid.move(Position(5, 3), Position(5, 0)));

    CHECK_EQUAL(nullptr, get_piece_at(grid, Position(5, 3)));
    CHECK_EQUAL(QUEEN,   get_piece_at(grid, Position(5, 0))->get_type());
    CHECK_EQUAL(WHITE,   get_piece_at(grid, Position(5, 0))->get_color());

    // capturing white queen
    CHECK_TRUE(grid.move(Position(2, 3), Position(5, 0)));

    CHECK_EQUAL(nullptr, get_piece_at(grid, Position(2, 3)));
    CHECK_EQUAL(QUEEN,   get_piece_at(grid, Position(5, 0))->get_type());
    CHECK_EQUAL(BLACK,   get_piece_at(grid, Position(5, 0))->get_color());
}

TEST(TestGrid, test_move_king)
{
    DummyGrid grid;

    // clearing the path for the kings
    CHECK_TRUE(grid.move(Position(6, 4), Position(4, 4)));
    CHECK_TRUE(grid.move(Position(1, 4), Position(3, 4)));

    // moving white king
    CHECK_TRUE(grid.move(Position(7, 4), Position(6, 4)));

    CHECK_EQUAL(nullptr, get_piece_at(grid, Position(7, 4)));
    CHECK_EQUAL(KING,    get_piece_at(grid, Position(6, 4))->get_type());
    CHECK_EQUAL(WHITE,   get_piece_at(grid, Position(6, 4))->get_color());

    // moving the black king
    CHECK_TRUE(grid.move(Position(0, 4), Position(1, 4)));

    CHECK_EQUAL(nullptr, get_piece_at(grid, Position(0, 4)));
    CHECK_EQUAL(KING,    get_piece_at(grid, Position(1, 4))->get_type());
    CHECK_EQUAL(BLACK,   get_piece_at(grid, Position(1, 4))->get_color());

    // moving the white king
    CHECK_TRUE(grid.move(Position(6, 4), Position(5, 5)));

    CHECK_EQUAL(nullptr, get_piece_at(grid, Position(6, 4)));
    CHECK_EQUAL(KING,    get_piece_at(grid, Position(5, 5))->get_type());
    CHECK_EQUAL(WHITE,   get_piece_at(grid, Position(5, 5))->get_color());

    // moving the black king
    CHECK_TRUE(grid.move(Position(1, 4), Position(2, 5)));

    CHECK_EQUAL(nullptr, get_piece_at(grid, Position(1, 4)));
    CHECK_EQUAL(KING,    get_piece_at(grid, Position(2, 5))->get_type());
    CHECK_EQUAL(BLACK,   get_piece_at(grid, Position(2, 5))->get_color());
}

TEST(TestGrid, test_attacking_king_positions)
{
    PlaceCommand grid_build[] {
        Grid::encode(Position(4, 3), KING, WHITE),
        Grid::encode(Position(2, 5), ROOK, BLACK),
    };

    DummyGrid grid(grid_build, 2);

    CHECK_TRUE(grid.move(Position(4, 3), Position(4, 2)));
    CHECK_TRUE(grid.move(Position(2, 5), Position(2, 3)));

    const std::vector<Position> *king_possible_moves = grid.get_possible_moves(Position(4, 2));

    auto start_it = king_possible_moves->cbegin();
    auto end_it = king_possible_moves->cend();

    CHECK_EQUAL(5, king_possible_moves->size());

    CHECK(end_it != std::find(start_it, end_it, Position(3, 2)));
    CHECK(end_it != std::find(start_it, end_it, Position(3, 1)));
    CHECK(end_it != std::find(start_it, end_it, Position(4, 1)));
    CHECK(end_it != std::find(start_it, end_it, Position(5, 1)));
    CHECK(end_it != std::find(start_it, end_it, Position(5, 2)));

    delete king_possible_moves;
}

TEST(TestGrid, test_winning_condition)
{
    DummyGrid grid;

    // making the 3 move checkmate
    CHECK_TRUE(grid.move(Position(6, 4), Position(4, 4)));
    CHECK_TRUE(grid.move(Position(1, 2), Position(3, 2)));
    CHECK_TRUE(grid.move(Position(4, 4), Position(3, 2)));
    CHECK_TRUE(grid.move(Position(0, 3), Position(3, 0)));

    CHECK_EQUAL(BLACK, grid.get_winner());
}

TEST(TestGrid, test_en_passant)
{
    DummyGrid grid;

    CHECK_TRUE(grid.move(Position(6, 0), Position(4, 0)));
    CHECK_TRUE(grid.move(Position(1, 1), Position(3, 1)));
    CHECK_TRUE(grid.move(Position(4, 0), Position(3, 0)));
    CHECK_TRUE(grid.move(Position(3, 1), Position(4, 1)));
    CHECK_TRUE(grid.move(Position(6, 2), Position(4, 2)));
    CHECK_TRUE(grid.move(Position(4, 1), Position(5, 2)));

    CHECK_EQUAL(nullptr, get_piece_at(grid, Position(4, 2)));
    CHECK_EQUAL(PAWN,    get_piece_at(grid, Position(5, 2))->get_type());
    CHECK_EQUAL(BLACK,   get_piece_at(grid, Position(5, 2))->get_color());
}

TEST(TestGrid, test_caslting)
{
    DummyGrid grid;

    // castling kingside
    CHECK_TRUE(grid.move(Position(7, 6), Position(5, 7)));
    CHECK_TRUE(grid.move(Position(1, 0), Position(2, 0)));
    CHECK_TRUE(grid.move(Position(6, 6), Position(4, 6)));
    CHECK_TRUE(grid.move(Position(2, 0), Position(3, 0)));
    CHECK_TRUE(grid.move(Position(7, 5), Position(6, 6)));
    CHECK_TRUE(grid.move(Position(3, 0), Position(4, 0)));
    CHECK_TRUE(grid.move(Position(7, 4), Position(7, 6)));

    CHECK_EQUAL(nullptr, get_piece_at(grid, Position(7, 4)));
    CHECK_EQUAL(nullptr, get_piece_at(grid, Position(7, 7)));

    CHECK_EQUAL(KING,    get_piece_at(grid, Position(7, 6))->get_type());
    CHECK_EQUAL(WHITE,   get_piece_at(grid, Position(7, 6))->get_color());

    CHECK_EQUAL(ROOK,    get_piece_at(grid, Position(7, 5))->get_type());
    CHECK_EQUAL(WHITE,   get_piece_at(grid, Position(7, 5))->get_color());

    DummyGrid grid2;

    // castling queenside
    CHECK_TRUE(grid.move(Position(6, 3), Position(4, 3)));
    CHECK_TRUE(grid.move(Position(1, 1), Position(2, 1)));
    CHECK_TRUE(grid.move(Position(7, 3), Position(5, 3)));
    CHECK_TRUE(grid.move(Position(2, 1), Position(3, 1)));
    CHECK_TRUE(grid.move(Position(7, 2), Position(5, 4)));
    CHECK_TRUE(grid.move(Position(3, 1), Position(4, 1)));
    CHECK_TRUE(grid.move(Position(7, 1), Position(5, 0)));
    CHECK_TRUE(grid.move(Position(4, 1), Position(5, 1)));
    CHECK_TRUE(grid.move(Position(7, 4), Position(7, 2)));

    CHECK_EQUAL(nullptr, get_piece_at(grid, Position(7, 4)));
    CHECK_EQUAL(nullptr, get_piece_at(grid, Position(7, 0)));

    CHECK_EQUAL(KING,    get_piece_at(grid, Position(7, 2))->get_type());
    CHECK_EQUAL(WHITE,   get_piece_at(grid, Position(7, 2))->get_color());

    CHECK_EQUAL(ROOK,    get_piece_at(grid, Position(7, 3))->get_type());
    CHECK_EQUAL(WHITE,   get_piece_at(grid, Position(7, 3))->get_color());
}
