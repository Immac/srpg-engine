#ifndef GAMECOMMON_HPP
#define GAMECOMMON_HPP

#include "repository.hpp"

namespace SrpgEngine {
namespace Game {
using Framework::string;
using Framework::Repository;
using Statistic = std::pair<string,int>;
using StatRepository = Repository<int>;

}
}

#endif // GAMECOMMON_HPP
