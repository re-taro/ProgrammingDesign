#pragma once
#include <string>
#include <unordered_map>
#include <SFML/Graphics.hpp>

class TextureManager {
  std::unordered_map<std::string, sf::Texture> textures;
  TextureManager();
  ~TextureManager();
public:
  sf::Texture* get(const std::string& filename);
  static TextureManager* getInstance();
  TextureManager(const TextureManager&) = delete;
  TextureManager& operator=(const TextureManager&) = delete;
  TextureManager(const TextureManager&&) = delete;
  TextureManager& operator=(const TextureManager&&) = delete;
};
