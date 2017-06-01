#ifndef S2DGE_GAME_SYSTEM_HPP
#define S2DGE_GAME_SYSTEM_HPP
#include <gamesystem.hpp>
#include "s2dge-common.hpp"
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <functional>

namespace SrpgEngine {
namespace S2dge {

using namespace SrpgEngine::Framework;
using Game::GameObject;

class Simple2DGraphicsEngine : public Game::GameSystem {
private:
	static string SystemName;
	Vector<GameObject *> _drawables;
	void InitializeDefaults(GameObject &settings);
	Map<string, std::function<void()>> _eventMap;
public:
	Simple2DGraphicsEngine();
	void Initialize(GameObject &settings) override;
	void Update() override;
	int HandleEvent(string eventKey) override;
	string GetSystemCode();
	Vector<string> GetDependencies();
	~Simple2DGraphicsEngine();

	Vector<GameObject *> getDrawables() const;
};

}
}

#endif // S2DGE_GAME_SYSTEM_HPP
