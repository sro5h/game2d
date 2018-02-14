#include "DebugRenderable.hpp"

DebugRenderable::DebugRenderable(float radius)
        : shape(radius)
{
        shape.setOrigin(radius, radius);
}
