#pragma once

#include "entity.hpp"

namespace Nfloppy {

namespace World {

    namespace Entities {

        class Pipe final : public Entity {
        public:
            Pipe(EntityId id, Math::Vec2f const& pos, Math::Vec2f const& size);
            void update(double dt) final;

        private:
        };
    }

}

}
