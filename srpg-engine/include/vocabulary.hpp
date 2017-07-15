#ifndef SRPG_VOCABULARY_HPP
#define SRPG_VOCABULARY_HPP
#include <gamecommon.hpp>

namespace SrpgEngine {
namespace Util {
using namespace Framework;

template <class TEnum> class Thesaurus
{
protected:
	Map<TEnum,string> map_;
public:
	Thesaurus() = default;
	string operator[] (TEnum key)
	{
		return map_[key];
	}

	string operator[] (TEnum key) const
	{
		return map_[key];
	}
};

}
}


#endif // SRPG_VOCABULARY_HPP
