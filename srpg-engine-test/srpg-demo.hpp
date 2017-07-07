#ifndef SRPG_DEMO_HPP
#define SRPG_DEMO_HPP
#include <SFML/System.hpp>

namespace SrpgDemo {
namespace Util {

class Synchronizer
{
private:
	sf::Time _step;
	sf::Clock _clock;
	sf::Time _lag = sf::Time::Zero;
public:
	Synchronizer(sf::Time step);
	void Reset();
	bool TryStep();
	void FinishStep();
};

}
}

#endif // SRPG_DEMO_HPP
