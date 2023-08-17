#pragma once

#include <filesystem>
#include <unordered_map>

#include "world/entities/entity_id.hpp"

using Nfloppy::World::Entities::EntityId;

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

            const std::filesystem::path& operator[](EntityId id) const;

        private:
            TexturePathes();

            std::unordered_map<EntityId, std::filesystem::path> m_pathes;
        };

    }

}

}
