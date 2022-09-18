#include "core/grid.hpp"
#include <algorithm>
#include <iostream>

void Grid::init_grid()
{

    /* std::cout << "hash of (1, 2) = " << std::hash<Position>()(Position(1, 2)) << '\n'; */

    this->grid = new AbstractChessPiece**[8];
    this->fake_grid = new PieceColor*[8];
    this->white_pieces = new std::vector<AbstractChessPiece*>(16);
    this->black_pieces = new std::vector<AbstractChessPiece*>(16);

    for (int i = 0; i < 8; i ++)
    {
        this->grid[i] = new AbstractChessPiece*[8];
        this->fake_grid[i] = new PieceColor[8];

        std::fill(this->fake_grid[i], this->fake_grid[i] + 8, EMPTY);
        std::fill(this->grid[i], this->grid[i] + 8, nullptr);
    }

    std::fill(this->fake_grid[0], this->fake_grid[0] + 8, BLACK);
    std::fill(this->fake_grid[1], this->fake_grid[1] + 8, BLACK);
    std::fill(this->fake_grid[6], this->fake_grid[6] + 8, WHITE);
    std::fill(this->fake_grid[7], this->fake_grid[7] + 8, WHITE);

    for (int i = 0; i < 8; i ++)
    {
        this->grid[1][i] = new Pawn(1, i, BLACK);
        this->grid[6][i] = new Pawn(6, i, WHITE);
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

    std::copy(this->grid[0], this->grid[0] + 8, this->black_pieces->begin());
    std::copy(this->grid[1], this->grid[1] + 8, this->black_pieces->begin() + 8);

    std::copy(this->grid[6], this->grid[6] + 8, this->white_pieces->begin());
    std::copy(this->grid[7], this->grid[7] + 8, this->white_pieces->begin() + 8);
}

Grid::Grid(PlaceCommand *commands, int size)
{
    this->grid = new AbstractChessPiece**[8];
    this->fake_grid = new PieceColor*[8];

    this->white_pieces = new std::vector<AbstractChessPiece*>(16);
    this->black_pieces = new std::vector<AbstractChessPiece*>(16);

    for (int i = 0; i < 8; i ++)
    {
        this->grid[i] = new AbstractChessPiece*[8];
        this->fake_grid[i] = new PieceColor[8];

        std::fill(this->grid[i], this->grid[i] + 8, nullptr);
        std::fill(this->fake_grid[i], this->fake_grid[i] + 8, EMPTY);
   }

    for (int i = 0; i < size; i ++)
    {
        Position pos;
        PieceType type;
        PieceColor color;
        Grid::decode(commands[i], pos, type, color);

        AbstractChessPiece *new_piece = nullptr;

        switch (type)
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

        std::vector<AbstractChessPiece*> *pieces_set = (color == WHITE) ? this->white_pieces : this->black_pieces;
        pieces_set->push_back(new_piece);

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
    delete   this->white_pieces;
    delete   this->black_pieces;

    this->grid       = nullptr;
    this->fake_grid  = nullptr;
    this->white_king = nullptr;
    this->black_king = nullptr;
    this->white_pieces = nullptr;
    this->black_pieces = nullptr;
}

bool Grid::move(const Position& piece, const Position& dest)
{
    if (!in_bounds(piece) || !in_bounds(dest))
        return false;

    // making a regular move
    AbstractChessPiece *selected_piece = this->grid[piece.x][piece.y];
    std::vector<AbstractChessPiece*> *opponent_pieces_set = (this->current_turn == WHITE) ? this->black_pieces : this->white_pieces ;
    std::vector<Position> possible_moves(selected_piece->get_valid_positions(this->fake_grid));

    if (std::find(possible_moves.begin(), possible_moves.end(), dest) == possible_moves.end())
        return false;

    this->grid[piece.x][piece.y] = nullptr;
    this->fake_grid[piece.x][piece.y] = EMPTY;

    AbstractChessPiece *target = this->grid[dest.x][dest.y];
    if (target)
    {
        auto it = std::find(opponent_pieces_set->begin(), opponent_pieces_set->end(), target);
        opponent_pieces_set->erase(it);
        delete target;
    }

    selected_piece->set_position(dest);
    this->grid[dest.x][dest.y] = selected_piece;
    this->fake_grid[dest.x][dest.y] = this->current_turn;

    this->current_turn = (this->current_turn == WHITE ? BLACK : WHITE);

    return true;
}

// TODO: potential of memory leak, use smart pointers instead of raw ones
const std::vector<Position>* Grid::get_possible_moves(const Position& piece)
{
    std::vector<Position> *pos_list = new std::vector<Position>(0);

    if (this->grid[piece.x][piece.y])
    {
        delete pos_list;

        AbstractChessPiece *the_piece = this->grid[piece.x][piece.y];

        pos_list = new std::vector<Position>(the_piece->get_valid_positions(this->fake_grid));

        if (the_piece->get_type() == KING)
            this->filter_king_moves(*pos_list, the_piece->get_color());

    }

    return pos_list;
}

void Grid::filter_king_moves(std::vector<Position>& king_moves, PieceColor color)
{
    King *the_king = (color == WHITE) ? this->white_king : this->black_king;
    std::vector<AbstractChessPiece*> *opponent_piece_set = (color == WHITE) ? this->black_pieces : this->white_pieces;

    auto pred = [=](Position pos) {
        for (auto piece : *opponent_piece_set)
        {
            std::vector<Position> pos_list = piece->get_valid_positions(this->fake_grid);

            for (auto king_pos : king_moves)
                if (pos_list.end() != std::find(pos_list.begin(), pos_list.end(), king_pos))
                    return true;
        }
        return false;
    };

    king_moves.erase(std::remove_if(king_moves.begin(), king_moves.end(), pred), king_moves.end());
}

void Grid::analyse_king_position()
{
    King *the_king = (this->current_turn == WHITE) ? this->white_king : this->black_king;
    std::vector<AbstractChessPiece*> *current_piece_set = (this->current_turn == WHITE) ? this->white_pieces : this->black_pieces;
    std::vector<AbstractChessPiece*> *opponent_piece_set = (this->current_turn == BLACK) ? this->white_pieces : this->black_pieces;

    std::vector<AbstractChessPiece*> attacking_pieces(opponent_piece_set->size());

    // now, check every possible position that the king can be attacked from
    // this is done by looping through all the opponent pieces, and checking
    // whether there is an opponent piece that can attack the king.

    for (auto piece : *opponent_piece_set)
    {
        std::vector<Position> pos_list = piece->get_valid_positions(this->fake_grid);
        if (pos_list.end() != std::find(pos_list.begin(), pos_list.end(), the_king->get_position()))
            attacking_pieces.push_back(piece);
    }

    // if there is no attacking pieces, then the king is safe and
    // no further analysis is required
    if (attacking_pieces.size() == 0)
        return;
    this->current_possible_moves.clear();

    // the king is threathened, now we need to figure out the possible moves
    // that can save him
    //
    // there are two possible ways with which the king can be saved,
    // moving the king or blocking the attacking piece.


    // the first saving method, moving the king, is quite easy
    // generate the king's valid positions and remove from them
    // and other compromising positions (because the king cannot move to a check)
    std::vector<Position> king_moves = the_king->get_valid_positions(this->fake_grid);
    this->filter_king_moves(king_moves, this->current_turn);

    {
        std::vector<Position> &temp = this->current_possible_moves[the_king->get_position()];
        std::copy(king_moves.begin(), king_moves.end(), temp.begin());
    }

}

/*PlaceCommand Grid::encode(Position, PieceType, PieceColor)
{
    return 0;
}
*/
