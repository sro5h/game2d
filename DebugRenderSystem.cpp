#include "DebugRenderSystem.hpp"
#include "Body.hpp"
#include "Position.hpp"
#include <SFML/Graphics/RenderTarget.hpp>

DebugRenderSystem::DebugRenderSystem(Registry& registry, sf::RenderTarget& target)
        : mRegistry(registry)
        , mDebugDraw(target)
{
}

void DebugRenderSystem::update()
{
        auto view = mRegistry.view<Position, Body>();

        for (Entity entity: view)
        {
                Position& position = view.get<Position>(entity);
                Body& body = view.get<Body>(entity);

                if (!body.shape)
                        continue;

                sf::Transform transform;
                transform.translate(position.position);

                mDebugDraw.draw(*body.shape, transform);
        }
}
