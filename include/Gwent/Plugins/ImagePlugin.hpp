#pragma once

#include <R-Engine/Core/Backend.hpp>
#include <R-Engine/Core/Filepath.hpp>
#include <R-Engine/Core/Logger.hpp>
#include <R-Engine/Maths/Vec.hpp>
#include <R-Engine/Plugins/Plugin.hpp>

#include <string>
#include <unordered_map>

namespace r {

namespace gwent {

struct Background final {
};

struct Image final {
        std::string path;
};

class ImageManager final
{
    public:
        ImageManager() = default;

        ImageManager(const ImageManager &) = delete;
        ImageManager &operator=(const ImageManager &) = delete;
        ImageManager(ImageManager &&) noexcept = default;
        ImageManager &operator=(ImageManager &&) noexcept = default;

        const ::Texture2D *get(const std::string &path);
        void unload(void) noexcept;

    private:
        std::unordered_map<std::string, ::Texture2D> _texture_cache;
};

class ImagePlugin final : public Plugin
{
    public:
        void build(r::Application &app) override;
};

}// namespace gwent

}// namespace r
