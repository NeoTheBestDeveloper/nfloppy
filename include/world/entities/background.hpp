#pragma once

#include "entity.hpp"

namespace Nfloppy {

namespace World {

    namespace Entities {

        class Background final : public Entity {

        public:
            Background(EntityId id, Math::Vec2f const& pos,
                       Math::Vec2f const& size);

        private:
        };
    }

}

}
