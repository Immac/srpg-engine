#ifndef S2DGE_GAME_SYSTEM_HPP
#define S2DGE_GAME_SYSTEM_HPP
#include <gamesystem.hpp>
#include <state-machine.hpp>
#include <functional>
#include <memory>
#include "texture-handler.hpp"
#include <gamecore.hpp>

namespace SrpgEngine {
namespace S2dge {

class Sprite;
class TextureHandler;

using namespace SrpgEngine;
using namespace Framework;
using namespace Game;

class Simple2DGraphicsEngine : public Game::GameSystem {
private:
	static string SystemName;
	StateMachine game_state_;
	Core* game_core_;
	Vector<GameObject *> drawables_;
	TextureHandler textures_;
	void InitializeDefaults(GameObject& settings);
public:
	Simple2DGraphicsEngine(Core* core);
	void Initialize(GameObject& settings) override;
	void Update() override;
	int HandleEvent(GameObject& event) override;
	string GetSystemCode() override;
	Vector<string> GetDependencies() override;
	Vector<GameObject *> getDrawables() const;
	~Simple2DGraphicsEngine();
};

}
}

#endif // S2DGE_GAME_SYSTEM_HPP
