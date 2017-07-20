#include "texture-handler.hpp"
#include <iostream>

using namespace SrpgEngine::S2dge;

bool TextureHandler::LoadTexture(const string& texture_path)
{
	auto& textures = (*this);
	if(!textures.HasKey(texture_path))
	{
		textures[texture_path] = std::make_unique<sf::Texture>();

		if(!textures[texture_path]->loadFromFile(texture_path))
		{
			//TODO: proper debugging, not using cout
			std::cout << "Texture not found at: " << texture_path;
			return false;
		}
	}
	return true;
}
