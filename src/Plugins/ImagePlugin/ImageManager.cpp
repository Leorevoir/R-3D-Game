#include <Gwent/Plugins/ImagePlugin.hpp>

#include <R-Engine/Core/Backend.hpp>

/**
* public
*/

void r::gwent::ImageManager::unload(void) noexcept
{
    for (auto const &[path, texture] : _texture_cache) {
        r::Logger::debug("Unloading texture: " + path);
        UnloadTexture(texture);
    }
}

const ::Texture2D *r::gwent::ImageManager::get(const std::string &path)
{
    const auto it = _texture_cache.find(path);

    if (it != _texture_cache.end()) {
        return &it->second;
    }

    if (!r::path::exists(path)) {
        r::Logger::error("Image file not found: " + path);
        return nullptr;
    }

    ::Texture2D texture = LoadTexture(path.c_str());
    if (texture.id <= 0) {
        r::Logger::error("Failed to load texture with Raylib: " + path);
        return nullptr;
    }

    r::Logger::debug("Successfully loaded texture: " + path);
    _texture_cache[path] = texture;
    return &_texture_cache.at(path);
}
