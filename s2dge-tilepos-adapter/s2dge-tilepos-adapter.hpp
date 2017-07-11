#ifndef S2DGE_TILEPOS_ADAPTER_HPP
#define S2DGE_TILEPOS_ADAPTER_HPP

#include <gamesystem.hpp>

namespace SrpgEngine {
namespace SimplePositionSystem {
using namespace Game;
using namespace Framework;
class S2dgeTilePosAdapter : public GameSystem {
private:
	string _systemName;
	Vector<string> _dependencies;
	int _tileSize;
	// GameSystem interface
public:
	S2dgeTilePosAdapter();
	void Initialize(GameObject &settings) override;
	void Update() override;
	int HandleEvent(GameObject &event) override;
	string GetSystemCode() override;
	Vector<string> GetDependencies() override;
};

}
}

#endif // S2DGE_TILEPOS_ADAPTER_HPP
