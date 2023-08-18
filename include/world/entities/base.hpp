#pragma once

#include "entity.hpp"

namespace Nfloppy {

namespace World {

    namespace Entities {

        class Base final : public Entity {

        public:
            Base(EntityId id, Math::Vec2f const& pos, Math::Vec2f const& size);
            void update(double dt) final;

        private:
        };
    }

}

}
