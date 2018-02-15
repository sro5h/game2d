#ifndef COMMAND_QUEUE_HPP_INCLUDED
#define COMMAND_QUEUE_HPP_INCLUDED

#include "Command.hpp"
#include <queue>

class CommandQueue
{
public:
        void push(const Command& command);
        Command pop();
        bool isEmpty() const;

private:
        std::queue<Command> mQueue;
};

#endif // COMMAND_QUEUE_HPP_INCLUDED
