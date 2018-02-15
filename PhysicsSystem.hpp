#ifndef PHYSICS_SYSTEM_HPP_INCLUDED
#define PHYSICS_SYSTEM_HPP_INCLUDED

#include "Common.hpp"
#include "System.hpp"

class PhysicsSystem : public System
{
public:
        PhysicsSystem(Registry& registry);

        virtual void update();

private:
        void collide(const Body& bodyA, Position& positionA, const Body& bodyB,
                        Position& positionB);

private:
        Registry& mRegistry;
};

#endif // PHYSICS_SYSTEM_HPP_INCLUDED
