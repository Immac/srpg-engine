#ifndef SRPG_OBSERVER_HPP
#define SRPG_OBSERVER_HPP

#include "gameobject.hpp"


namespace SrpgEngine {
namespace Framework {

using namespace SrpgEngine::Game;

class Observer
{
public:
  virtual ~Observer() {}
  virtual void OnNotify(const GameObject& entity, string event) = 0;
};

}
}

#endif // SRPG_OBSERVER_HPP
