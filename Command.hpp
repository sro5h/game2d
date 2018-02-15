#ifndef COMMAND_HPP_INCLUDED
#define COMMAND_HPP_INCLUDED

#include "Common.hpp"
#include <functional>

class Command final
{
public:
        Command();

public:
        std::function<void(Registry&)> action;
};

#endif // COMMAND_HPP_INCLUDED
