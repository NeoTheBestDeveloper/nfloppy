#pragma once

#include <filesystem>
#include <unordered_map>
#include <vector>

#include "world/entities/entity_id.hpp"

using Nfloppy::World::Entities::EntityId;
using std::filesystem::path;

namespace Nfloppy {

namespace ui {

    namespace Texture {

        class TexturePathes {
        public:
            static const TexturePathes& instance()
            {
                static const TexturePathes pathes;
                return pathes;
            }

            TexturePathes(const TexturePathes&) = delete;

            const std::vector<path>& operator[](EntityId id) const;

        private:
            TexturePathes();

            std::unordered_map<EntityId, std::vector<path>> m_pathes;
        };

    }

}

}
