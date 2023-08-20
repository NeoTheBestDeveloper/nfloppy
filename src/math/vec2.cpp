#include "math/vec2.hpp"

using Nfloppy::Math::Vec2f;

Vec2f::Vec2f(double a)
    : x(a)
    , y(a)
{
}

Vec2f::Vec2f(double t_x, double t_y)
    : x(t_x)
    , y(t_y)
{
}

Vec2f Vec2f::operator+(Vec2f const& lhs) { return { x + lhs.x, y + lhs.y }; }
Vec2f Vec2f::operator-(Vec2f const& lhs) { return { x - lhs.x, y - lhs.y }; }
Vec2f Vec2f::operator*(Vec2f const& lhs) { return { x * lhs.x, y * lhs.y }; }
Vec2f Vec2f::operator/(Vec2f const& lhs) { return { x / lhs.x, y / lhs.y }; }
