#ifndef S2DGE_GAME_SYSTEM_HPP
#define S2DGE_GAME_SYSTEM_HPP
#include <gamesystem.hpp>
#include <state-machine.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <functional>
#include <memory>

namespace SrpgEngine {
namespace S2dge {

using namespace SrpgEngine::Framework;
using Game::GameObject;
using UniqueSfTexture = std::unique_ptr <sf::Texture>;

class Simple2DGraphicsEngine : public Game::GameSystem {
private:
	static string SystemName;
	StateMachine _game_state;
	Vector<GameObject *> _drawables;
	Repository<UniqueSfTexture> _textures;
	void InitializeDefaults(GameObject &settings);
public:
	Simple2DGraphicsEngine();
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
