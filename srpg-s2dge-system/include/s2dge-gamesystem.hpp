#ifndef S2DGE_GAME_SYSTEM_HPP
#define S2DGE_GAME_SYSTEM_HPP
#include <gamesystem.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <functional>

namespace SrpgEngine {
namespace S2dge {

using namespace SrpgEngine::Framework;
using Game::GameObject;
using UniqueTexture_t = std::unique_ptr<sf::Texture>;

class Simple2DGraphicsEngine : public Game::GameSystem {
private:
	static string SystemName;
	Vector<GameObject *> _drawables;
	Repository<UniqueTexture_t> _textures;
	void InitializeDefaults(GameObject &settings);
	Map<string, std::function<void(GameObject *)>> _eventMap;
public:
	Simple2DGraphicsEngine();
	void Initialize(GameObject &settings) override;
	void Update() override;
	int HandleEvent(GameObject *event) override;
	string GetSystemCode();
	Vector<string> GetDependencies();
	~Simple2DGraphicsEngine();

	Vector<GameObject *> getDrawables() const;
};

}
}

#endif // S2DGE_GAME_SYSTEM_HPP
