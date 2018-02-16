#include "MoveCommand.hpp"
#include "Position.hpp"

MoveCommand::MoveCommand(Entity entity, float x, float y)
        : entity(entity)
        , velocity(x, y)
{
}

void MoveCommand::operator()(Registry& registry) const
{
        Position& position = registry.get<Position>(entity);
        position.position += velocity;
}
