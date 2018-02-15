#ifndef POSITION_HPP_INCLUDED
#define POSITION_HPP_INCLUDED

#include <SFML/System/Vector2.hpp>

struct Position
{
        Position(float x, float y);

        sf::Vector2f position;
};

#endif // POSITION_HPP_INCLUDED
