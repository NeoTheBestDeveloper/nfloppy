#pragma once

namespace Nfloppy {

namespace Math {

    class Vec2f {
    public:
        double x, y;

        Vec2f(double a);
        Vec2f(double t_x, double t_y);

        Vec2f operator+(Vec2f const& lhs);
        Vec2f operator-(Vec2f const& lhs);
        Vec2f operator*(Vec2f const& lhs);
        Vec2f operator/(Vec2f const& lhs);
    };

}

}
