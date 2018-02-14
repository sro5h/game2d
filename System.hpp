#ifndef SYSTEM_HPP_INCLUDED
#define SYSTEM_HPP_INCLUDED

#include <memory>

class System
{
public:
        typedef std::unique_ptr<System> Ptr;

public:
        virtual ~System() = default;
        virtual void update() = 0;
};

#endif // SYSTEM_HPP_INCLUDED
