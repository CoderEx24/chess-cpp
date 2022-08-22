#include "core/abstract_chess_piece.hpp"

std::size_t std::hash<Position>::operator()(const Position& pos) const
{
    return pos.x | (pos.y << 3);
}

std::string Position::to_string() const
{
    return "(" + std::to_string(this->x) + ", " + std::to_string(this->y) + ")";
}

std::ostream& operator<<(std::ostream& output, const Position& pos)
{
    output << pos.to_string();
    return output;
}

