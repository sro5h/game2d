#ifndef COMMON_HPP_INCLUDED
#define COMMON_HPP_INCLUDED

#include "entt/entity/registry.hpp"
#include <cstdint>

using Entity = std::uint32_t;
using Registry = entt::Registry<Entity>;

namespace sf
{
class RenderTarget;
}

#endif // COMMON_HPP_INCLUDED