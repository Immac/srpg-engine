#ifndef SRPG_MENU_SYSTEM_HPP
#define SRPG_MENU_SYSTEM_HPP
#include "cursor.hpp"
#include <gamecore.hpp>
#include <gamesystem.hpp>
#include <state-machine.hpp>

namespace SrpgEngine {
namespace SimpleMenuSystem {

using namespace Game;

class MenuSystem : public GameSystem
{
private:
	Core * core_;
public:
	MenuSystem(Core &core);
	void Initialize(GameObject& settings) override;
	void Update() override;
	string GetSystemCode() override;
	Vector<string> GetDependencies() override;
	int HandleEvent(GameObject& event) override;
};

}
}

#endif // SRPG_MENU_SYSTEM_HPP
