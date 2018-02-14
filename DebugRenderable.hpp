#ifndef DEBUG_RENDERABLE_HPP_INCLUDED
#define DEBUG_RENDERABLE_HPP_INCLUDED

#include <SFML/Graphics/CircleShape.hpp>

struct DebugRenderable
{
        DebugRenderable(float radius = 20.0f);

        sf::CircleShape shape;
};

#endif // DEBUG_RENDERABLE_HPP_INCLUDED
