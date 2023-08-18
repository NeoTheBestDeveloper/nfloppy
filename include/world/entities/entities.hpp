#pragma once

#include <memory>
#include <vector>

#include "background.hpp"
#include "base.hpp"
#include "bird.hpp"
#include "entity.hpp"
#include "entity_id.hpp"
#include "pipe.hpp"

namespace Nfloppy {

namespace World {

    namespace Entities {

        class Entities {
        public:
            using EntityPtr = std::unique_ptr<Entity>;

            explicit Entities(uint64_t entities_count);

            EntityPtr& operator[](EntityId id)
            {
                return m_entities[static_cast<size_t>(id)];
            }
            auto begin() { return m_entities.begin(); }
            auto begin() const { return m_entities.cbegin(); }
            auto end() { return m_entities.end(); }
            auto end() const { return m_entities.cend(); }

        private:
            std::vector<EntityPtr> m_entities;
        };

    }

}

}
