#ifndef S2DGE_UTIL_HPP
#define S2DGE_UTIL_HPP
#include <gameobject.hpp>
#include "texture-handler.hpp"

namespace SrpgEngine {
namespace S2dge {
namespace S2dgeUtil {
using namespace SrpgEngine::Game;
void InitializeSprite(GameObject& sprite_object, GameObject& system, TextureHandler& textures);
void UpdateSprite(GameObject& game_object, GameObject& system);
}
}
}

#endif // S2DGE_UTIL_HPP
