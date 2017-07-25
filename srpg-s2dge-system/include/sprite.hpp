#ifndef S2DGE_SPRITE_HPP
#define S2DGE_SPRITE_HPP
#include <SFML/Graphics.hpp>
#include <gameobject.hpp>
#include <texture-handler.hpp>

namespace SrpgEngine {
namespace S2dge {

using namespace SrpgEngine::Game;

class Sprite : public sf::Sprite {
private:
	GameObject& _system_object;
	std::unique_ptr<Sprite> _under_sprite;
	std::unique_ptr<Sprite> _over_sprite;
public:
	Sprite(GameObject& system_object);
	const string& GetTexturePath();
	void SetTexture(sf::Texture& texture);
};


}
}
#endif // S2DGE_SPRITE_HPP
