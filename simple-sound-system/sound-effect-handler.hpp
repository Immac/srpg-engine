#ifndef SOUND_SOUND_EFFECT_HANDLER_HPP
#define SOUND_SOUND_EFFECT_HANDLER_HPP
#include <gameobject.hpp>
#include <SFML/Audio.hpp>
#include <memory>

namespace SrpgEngine {
namespace Audio {
using namespace SrpgEngine;
using namespace Framework;


class SoundEffectHandler : public Repository<UniquePtr<sf::SoundBuffer>>
{
private:
public:
	SoundEffectHandler() = default;
	bool LoadSoundEffect(const string& sound_effects_path);
};

}
}

#endif // SOUND_SOUND_EFFECT_HANDLER_HPP
