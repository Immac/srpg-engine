#ifndef SRPG_ACTION_SYSTEM_HPP
#define SRPG_ACTION_SYSTEM_HPP

#include <gamesystem.hpp>
#include <functional>

namespace SrpgEngine {
namespace SimplePositionSystem {
using namespace Game;

class TilePositionSystem : public GameSystem {
private:
	Map<string, std::function<void()>> _eventMap;
	// GameSystem interface
public:
	void Initialize(GameObject &settings) override;
	void Update() override;
	int HandleEvent(string eventKey);
	string GetSystemCode() override;
	Vector<string> GetDependencies() override;
};

}
}



#endif // SRPG_ACTION_SYSTEM_HPP
