#pragma once

#include "entity.hpp"

namespace Nfloppy {

namespace World {

    namespace Entities {

        class Bird final : public Entity {
        public:
            Bird(EntityId id, Math::Vec2f const& pos, Math::Vec2f const& size);
            void update(double dt) override;

        private:
        };

    }

}

}
