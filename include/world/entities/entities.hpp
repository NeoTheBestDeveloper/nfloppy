#pragma once

#include <utility>
#include <vector>

#include "entity.hpp"
#include "entity_id.hpp"

namespace Nfloppy {

namespace World {

    namespace Entities {

        class Entities {
        public:
            explicit Entities(uint64_t entities_count);

            EntityPtr& operator[](EntityId id)
            {
                return m_entities[static_cast<size_t>(id)];
            }

            /* Get Entity by id and specific sample number. For example,
             we have several entities with id "EntityId::PIPE" you can use it
             like "entities[{EntityId::PIPE, tube_num}]" */
            EntityPtr& operator[](std::pair<EntityId, uint64_t> id)
            {
                return m_entities[static_cast<size_t>(id.first) + id.second];
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
