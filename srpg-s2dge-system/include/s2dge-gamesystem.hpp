#ifndef S2DGE_GAME_SYSTEM_HPP
#define S2DGE_GAME_SYSTEM_HPP
#include <gamesystem.hpp>
#include "s2dge-common.hpp"
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

namespace SrpgEngine {
namespace S2dge {

class Simple2DGraphicsEngine : public Game::GameSystem{
private:
	sf::RenderWindow *window;
public:
	void Initialize();
	void Update(Framework::Vector<Game::GameObject *> object);
	Framework::string GetSystemCode();
};

}
}

#endif // S2DGE_GAME_SYSTEM_HPP
