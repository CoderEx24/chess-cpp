#include "core/grid.hpp"
#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>

void Grid::init_grid()
{
    this->grid = new AbstractChessPiece**[8];
    this->fake_grid = new PieceColor*[8];

    for (int i = 0; i < 8; i ++)
    {
        this->grid[i] = new AbstractChessPiece*[8];
        this->fake_grid[i] = new PieceColor[8];

        std::fill(this->fake_grid[i], this->fake_grid[i] + 8, EMPTY);
        std::fill(this->grid[i], this->grid[i] + 8, nullptr);
    }

    for (int i = 0; i < 8; i ++)
    {
        this->grid[1][i] = new Pawn(1, i, BLACK);
        this->grid[6][i] = new Pawn(6, i, WHITE);

        this->fake_grid[0][i] = BLACK;
        this->fake_grid[1][i] = BLACK;
        this->fake_grid[6][i] = WHITE;
        this->fake_grid[7][i] = WHITE;

    }

    this->grid[0][0] = new Rook(0, 0, BLACK);
    this->grid[0][7] = new Rook(0, 7, BLACK);

    this->grid[0][1] = new Knight(0, 1, BLACK);
    this->grid[0][6] = new Knight(0, 6, BLACK);

    this->grid[0][2] = new Bishop(0, 2, BLACK);
    this->grid[0][5] = new Bishop(0, 5, BLACK);

    this->grid[0][3] = new Queen(0, 3, BLACK);
    this->grid[0][4] = this->black_king = new King(0, 4, BLACK);

    this->grid[7][0] = new Rook(7, 0, WHITE);
    this->grid[7][7] = new Rook(7, 7, WHITE);

    this->grid[7][1] = new Knight(7, 1, WHITE);
    this->grid[7][6] = new Knight(7, 6, WHITE);

    this->grid[7][2] = new Bishop(7, 2, WHITE);
    this->grid[7][5] = new Bishop(7, 5, WHITE);

    this->grid[7][3] = new Queen(7, 3, WHITE);
    this->grid[7][4] = this->white_king = new King(7, 4, WHITE);
}

Grid::Grid(PlaceCommand *commands, int size)
{
    this->grid = new AbstractChessPiece**[8];
    this->fake_grid = new PieceColor*[8];

    for (int i = 0; i < 8; i ++)
    {
        this->grid[i] = new AbstractChessPiece*[8];
        this->fake_grid[i] = new PieceColor[8];

        std::fill(this->grid[i], this->grid[i] + 8, nullptr);
        std::fill(this->fake_grid[i], this->fake_grid[i] + 8, EMPTY);
   }

    for (int i = 0; i < size; i ++)
    {
        PlaceCommand command = commands[i];
        PieceColor color = 1 + ((command & 0b1000000000) >> 9);
        Position   pos   = Position(command & 0b111, (command & 0b111000) >> 3);

        AbstractChessPiece *new_piece = nullptr;

        switch ((command & 0b111000000) >> 6)
        {
            case PAWN:
                new_piece = new Pawn(pos.x, pos.y, color);
                break;

            case ROOK:
                new_piece = new Rook(pos.x, pos.y, color);
                break;

            case KNIGHT:
                new_piece = new Knight(pos.x, pos.y, color);
                break;

            case BISHOP:
                new_piece = new Bishop(pos.x, pos.y, color);
                break;

            case QUEEN:
                new_piece = new Queen(pos.x, pos.y, color);
                break;

            case KING:
                new_piece = new King(pos.x, pos.y, color);
                break;
        }

        this->grid[pos.x][pos.y] = new_piece;
        this->fake_grid[pos.x][pos.y] = color;

        new_piece = nullptr;
    }
}

Grid::~Grid()
{
    for (int i = 0; i < 8; i ++)
    {
        for (int j = 0; j < 8; j ++)
        {
            if (this->grid[i][j]) delete this->grid[i][j];
            this->grid[i][j] = nullptr;
        }

        delete[] this->grid[i];
        delete[] this->fake_grid[i];

        this->grid[i]      = nullptr;
        this->fake_grid[i] = nullptr;
    }

    delete[] this->grid;
    delete[] this->fake_grid;

    this->grid       = nullptr;
    this->fake_grid  = nullptr;
    this->white_king = nullptr;
    this->black_king = nullptr;
}

bool Grid::move(const Position& piece, const Position& dest)
{
    if (!in_bounds(piece) || !in_bounds(dest))
        return false;

    AbstractChessPiece *selected_piece = this->grid[piece.x][piece.y];
    std::vector<Position> possible_moves(selected_piece->get_valid_positions(this->fake_grid));

    if (std::find(possible_moves.begin(), possible_moves.end(), dest) == possible_moves.end())
        return false;

    this->grid[piece.x][piece.y] = nullptr;
    this->fake_grid[piece.x][piece.y] = EMPTY;

    if (this->grid[dest.x][dest.y])
        delete this->grid[dest.x][dest.y];

    selected_piece->set_position(dest);
    this->grid[dest.x][dest.y] = selected_piece;
    this->fake_grid[dest.x][dest.y] = this->current_turn;

    this->current_turn = (this->current_turn == WHITE ? BLACK : WHITE);

    return true;
}

// TODO: potential of memory leak, use smart pointers instead of raw ones
const std::vector<Position>& Grid::get_possible_moves(const Position& piece)
{
    std::vector<Position> *pos_list = new std::vector<Position>(0);

    if (this->grid[piece.x][piece.y])
    {
        delete pos_list;
        pos_list = new std::vector<Position>(this->grid[piece.x][piece.y]->get_valid_positions(this->fake_grid));
    }

    return *pos_list;
}

/*PlaceCommand Grid::encode(Position, PieceType, PieceColor)
{
    return 0;
}
*/

