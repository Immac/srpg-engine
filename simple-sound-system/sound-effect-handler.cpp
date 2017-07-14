#include "sound-effect-handler.hpp"
#include <iostream>

using namespace SrpgEngine;
using namespace Framework;
using namespace Audio;

bool SoundEffectHandler::LoadSoundEffect(const string& sound_effects_path)
{
	auto &sound_effects = (*this);
	if(!sound_effects.HasAny(sound_effects_path))
	{
		sound_effects[sound_effects_path] = std::make_unique<sf::SoundBuffer>();
		if(!sound_effects[sound_effects_path]->loadFromFile(sound_effects_path))
		{
			std::cout << "Sound effect not found at: "
					  << sound_effects_path << std::endl;
			return false;
		}
	}
	return true;
}
