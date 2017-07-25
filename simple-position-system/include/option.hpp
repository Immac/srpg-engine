#ifndef OPTION_HPP
#define OPTION_HPP
#include <gamecommon.hpp>

namespace SrpgEngine {
namespace SimplePositionSystem {
using namespace Util;

enum class OptionType {
	Exclude,
	Include
};

class Option {
public:
	OptionType Type;
	Vector<string> Tags;
};

}
}
#endif // OPTION_HPP
