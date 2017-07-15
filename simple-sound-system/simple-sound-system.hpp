#ifndef SOUNDSYSTEM_SIMPLE_SOUND_SYSTEM_HPP
#define SOUNDSYSTEM_SIMPLE_SOUND_SYSTEM_HPP
#include <gamesystem.hpp>
#include <gamecore.hpp>
#include "sound-effect-handler.hpp"

namespace SrpgEngine {
namespace Audio {

using namespace SrpgEngine;
using namespace Game;

class SimpleSoundSystem : public GameSystem
{
private:
	Core* game_core_;
	StateMachine game_state_;
	SoundEffectHandler sound_effects_;

public:
	SimpleSoundSystem(Core& game_core);
	void Initialize(GameObject& settings) override;
	void Update() override;
	string GetSystemCode() override;
	Vector<string> GetDependencies() override;
	int HandleEvent(GameObject& event) override;
};

}
}

#endif // SOUNDSYSTEM_SIMPLE_SOUND_SYSTEM_HPP
