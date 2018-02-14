#ifndef DEBUG_RENDER_SYSTEM_HPP_INCLUDED
#define DEBUG_RENDER_SYSTEM_HPP_INCLUDED

#include "Common.hpp"
#include "System.hpp"
#include "DebugDraw.hpp"

class DebugRenderSystem : public System
{
public:
        DebugRenderSystem(Registry& registry, sf::RenderTarget& target);

        virtual void update();

private:
        Registry& mRegistry;
        DebugDraw mDebugDraw;
};

#endif // DEBUG_RENDER_SYSTEM_HPP_INCLUDED
