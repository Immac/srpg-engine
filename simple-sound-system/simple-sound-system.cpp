#include "simple-sound-system.hpp"

using namespace SrpgEngine;
using namespace Audio;

SimpleSoundSystem::SimpleSoundSystem(SrpgEngine::Game::Core& game_core)
	:game_core_(&game_core),game_state_("normal")
{
	game_state_.AddState("global");
	game_state_["global"]["selected_object"] = [this](auto& event) {
		auto& subject = event.Properties["subject"];
		auto sound_effect =
				static_cast<sf::Sound*>(
				subject->Properties["sound_effects"]->Data["select"]);
		sound_effect->play();
	};
}

void SimpleSoundSystem::Initialize(GameObject& settings)
{
	const auto& system_code = this->GetSystemCode();
	for(auto record : this->GameObjects) {
		auto game_object = record.second;
		auto system = game_object->Properties[system_code];
		auto& sound_effect_paths = game_object->Properties["sound_effects"]->Dictionary;
		for(const auto& record : sound_effect_paths) {

			const auto& path = record.second;
			sound_effects_.LoadSoundEffect(path);
			const auto& sound_buffer = *(sound_effects_[path]);

			const auto& sound_key = record.first;
			game_object->Properties["sound_effects"]->Data[sound_key]
					= new sf::Sound(sound_buffer);
		}
	}
}

void SimpleSoundSystem::Update()
{

}

string SimpleSoundSystem::GetSystemCode()
{
	return string("SSS");
}

Vector<string> SimpleSoundSystem::GetDependencies()
{
}

int SimpleSoundSystem::HandleEvent(GameObject& event)
{
	game_state_.HandleEvent(event);
	game_state_["global"].HandleEvent(event);
}
