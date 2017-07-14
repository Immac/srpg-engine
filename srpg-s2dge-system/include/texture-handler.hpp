#ifndef S2DGE_TEXTURE_HANDLER_HPP
#define S2DGE_TEXTURE_HANDLER_HPP
#include <gameobject.hpp>
#include <SFML/Graphics.hpp>

namespace SrpgEngine {
namespace S2dge {

using namespace SrpgEngine::Framework;
using UniqueSfTexture = std::unique_ptr <sf::Texture>;

class TextureHandler : public Repository<UniqueSfTexture> {
public:
	TextureHandler() = default;
	bool LoadTexture(const string& texture_path);
};

}
}

#endif // S2DGE_TEXTURE_HANDLER_HPP

