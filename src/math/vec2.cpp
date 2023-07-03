#include "math/vec2.hpp"

using Nfloppy::Math::Vec2f;

Vec2f::Vec2f(double a)
    : x(a)
    , y(a)
{
}

Vec2f::Vec2f(double x_, double y_)
    : x(x_)
    , y(y_)
{
}

Vec2f Vec2f::operator+(Vec2f const& lhs)
{
    x += lhs.x;
    y += lhs.y;
    return *this;
}

Vec2f Vec2f::operator-(Vec2f const& lhs)
{
    x -= lhs.x;
    y -= lhs.y;
    return *this;
}

Vec2f Vec2f::operator/(Vec2f const& lhs)
{
    x /= lhs.x;
    y /= lhs.y;
    return *this;
}

Vec2f Vec2f::operator*(Vec2f const& lhs)
{
    x *= lhs.x;
    y *= lhs.y;
    return *this;
}

bool Vec2f::operator==(Vec2f const& lhs) { return x == lhs.x and y == lhs.y; }
