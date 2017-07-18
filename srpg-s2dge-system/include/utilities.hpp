#ifndef S2DGE_UTIL_HPP
#define S2DGE_UTIL_HPP
#include <gameobject.hpp>
#include "texture-handler.hpp"

namespace SrpgEngine {
namespace S2dge {
namespace S2dgeUtil {
using namespace SrpgEngine::Game;

struct Vocabulary {
	string graphics = "graphics";
	string graphic = "graphic";
	string position = "position";
	string size = "size";
	string texture = "texture";
};

void InitializeSprite(GameObject& sprite_object, TextureHandler& textures);
void UpdateSprite(GameObject& game_object, GameObject& system);
}
}
}

#endif // S2DGE_UTIL_HPP
