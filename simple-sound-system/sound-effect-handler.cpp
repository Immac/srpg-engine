#include "sound-effect-handler.hpp"
#include <iostream>

using namespace SrpgEngine;
using namespace Framework;
using namespace Audio;

bool SoundEffectRepository::LoadSoundEffect(const string& sound_effects_path)
{
	auto &sfx_repo = (*this);
	const auto& path = sound_effects_path;
	if(!sfx_repo.HasKey(path))
	{
		sfx_repo[path] = std::make_unique<sf::SoundBuffer>();
		if(!sfx_repo[path]->loadFromFile(path))
		{
			std::cout << "Sound effect not found at: "
					  << path
					  << std::endl;
			return false;
		}
	}
	return true;
}
