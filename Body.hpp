#ifndef BODY_HPP_INCLUDED
#define BODY_HPP_INCLUDED

#include "Collision.hpp"

struct Body
{
        Body();

        Shape::Ptr shape;
        bool dynamic;
};

#endif // BODY_HPP_INCLUDED
