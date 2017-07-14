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
	StateMachine _game_state;
	Core* _game_core;
	Vector<GameObject *> _drawables;
	TextureHandler _textures;
	void InitializeDefaults(GameObject &settings);
public:

	Simple2DGraphicsEngine(Core *core);
	void Initialize(GameObject &settings) override;
	void Update() override;
	int HandleEvent(GameObject &event) override;
	string GetSystemCode();
	Vector<string> GetDependencies();
	~Simple2DGraphicsEngine();

	Vector<GameObject *> getDrawables() const;
};

}
}

#endif // S2DGE_GAME_SYSTEM_HPP
