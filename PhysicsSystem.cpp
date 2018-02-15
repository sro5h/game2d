#include "PhysicsSystem.hpp"
#include "Body.hpp"
#include "Position.hpp"
#include <iostream>

PhysicsSystem::PhysicsSystem(Registry& registry)
        : mRegistry(registry)
{
}

void PhysicsSystem::update()
{
        auto view = mRegistry.view<Position, Body>();

        for (auto itA = view.begin(); itA != view.end(); ++itA)
        {
                for (auto itB = itA; itB != view.end(); ++itB)
                {
                        if (itA == itB)
                                continue;

                        Position& positionA = view.get<Position>(*itA);
                        Position& positionB = view.get<Position>(*itB);
                        const Body& bodyA = view.get<Body>(*itA);
                        const Body& bodyB = view.get<Body>(*itB);

                        if (!bodyA.shape || !bodyB.shape)
                                continue;

                        collide(bodyA, positionA, bodyB, positionB);
                }
        }
}

void PhysicsSystem::collide(const Body& bodyA, Position& positionA,
                const Body& bodyB, Position& positionB)
{
        sf::Transform transformA;
        transformA.translate(positionA.position);
        sf::Transform transformB;
        transformB.translate(positionB.position);

        Manifold m;
        m.solve(*(bodyA.shape), transformA, *(bodyB.shape), transformB);

        if (m.colliding)
        {
                if (bodyA.dynamic && !bodyB.dynamic)
                {
                        positionA.position -= m.normal * m.depth;
                }
                else if (!bodyA.dynamic && bodyB.dynamic)
                {
                        positionB.position += m.normal * m.depth;
                }
                else if (bodyA.dynamic && bodyB.dynamic)
                {
                        positionA.position -= m.normal * m.depth * 0.5f;
                        positionB.position += m.normal * m.depth * 0.5f;
                }
        }
}
