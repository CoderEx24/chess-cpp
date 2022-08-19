#include "core/grid.hpp"

void Grid::init_grid()
{
    this->grid = new AbstractChessPiece**[8];
    this->fake_grid = new PieceColor*[8];

    for (int i = 0; i < 8; i ++)
    {
        this->grid[i] = new AbstractChessPiece*[8];
        this->fake_grid[i] = new PieceColor[8];
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
    this->grid[0][4] = new King(0, 4, BLACK);

    this->grid[7][0] = new Rook(7, 0, WHITE);
    this->grid[7][7] = new Rook(7, 7, WHITE);

    this->grid[7][1] = new Knight(7, 1, WHITE);
    this->grid[7][6] = new Knight(7, 6, WHITE);

    this->grid[7][2] = new Bishop(7, 2, WHITE);
    this->grid[7][5] = new Bishop(7, 5, WHITE);

    this->grid[7][3] = new Queen(7, 3, WHITE);
    this->grid[7][4] = new King(7, 4, WHITE);
}

Grid::Grid(PlaceCommand *commands, int size)
{
    for (int i = 0; i < size; i ++)
    {
        PlaceCommand command = commands[i];
        PieceColor color = command & 0x200;
        Position   pos   = Position(command & 0x7, command & 0x38);

        AbstractChessPiece *new_piece = nullptr;

        switch (command & 0x070)
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
    }
}

void Grid::move(const Position& piece, const Position& dest)
{
}

const std::vector<Position>& Grid::get_possible_moves(const Position& piece)
{

}

/*PlaceCommand Grid::encode(Position, PieceType, PieceColor)
{
    return 0;
}
*/

