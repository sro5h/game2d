#ifndef MOVE_COMMAND_HPP_INCLUDED
#define MOVE_COMMAND_HPP_INCLUDED

#include "Common.hpp"
#include <SFML/System/Vector2.hpp>

struct MoveCommand
{
        MoveCommand(Entity entity, float x, float y);

        void operator()(Registry& registry) const;

        const Entity entity;
        const sf::Vector2f velocity;
};

#endif // MOVE_COMMAND_HPP_INCLUDED
