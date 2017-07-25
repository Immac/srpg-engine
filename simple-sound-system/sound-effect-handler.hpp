#ifndef SOUND_SOUND_EFFECT_HANDLER_HPP
#define SOUND_SOUND_EFFECT_HANDLER_HPP
#include <gameobject.hpp>
#include <SFML/Audio.hpp>
#include <memory>

namespace SrpgEngine {
namespace Audio {
using namespace SrpgEngine;
using namespace Framework;

class SoundEffectRepository : public Repository<UniquePtr<sf::SoundBuffer>>
{
private:
public:
	SoundEffectRepository() = default;
	~SoundEffectRepository() = default;
	bool LoadSoundEffect(const string& sound_effects_path);
};

}
}

#endif // SOUND_SOUND_EFFECT_HANDLER_HPP
