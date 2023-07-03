#pragma once

namespace Nfloppy {

namespace Math {

    class Vec2f {
    public:
        double x, y;

        Vec2f(double a);
        Vec2f(double x_, double y_);

        Vec2f operator+(Vec2f const& lhs);
        Vec2f operator-(Vec2f const& lhs);
        Vec2f operator*(Vec2f const& lhs);
        Vec2f operator/(Vec2f const& lhs);
        bool operator==(Vec2f const& lhs);
    };

}

}
