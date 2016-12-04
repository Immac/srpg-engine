#ifndef PROPERTY_HPP
#define PROPERTY_HPP
#include "gameobject.hpp"

namespace SrpgEngine {
namespace Game {

using Framework::Vector;

class Property : public GameObject
{
public:
	Vector<string> systems;
};
}
}


#endif // PROPERTY_HPP
