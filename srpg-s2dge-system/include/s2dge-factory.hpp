#ifndef S2DGE_FACTORY_HPP
#define S2DGE_FACTORY_HPP

#include <gameobject.hpp>
#include <random>

namespace SrpgEngine {
namespace S2dge {

class DrawableTestObjectFactory{
public:
	DrawableTestObjectFactory();
	~DrawableTestObjectFactory();
	Game::GameObject Create();
private:
	std::mt19937_64 *_randomEngine;
};

}
}

#endif // S2DGE_FACTORY_HPP
