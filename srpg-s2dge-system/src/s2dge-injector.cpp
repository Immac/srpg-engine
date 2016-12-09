#include "s2dge-injector.hpp"
#include "s2dge-common.hpp"


int SrpgEngine::S2dge::Injector::InjectSystem(SrpgEngine::Game::GameObject target)
{
	if(Util::Find(target.Systems,S2dge::SystemName))
	{
		return 1;
	}
	target.Systems.insert(S2dge::SystemName);
	target.Dictionary.Add(S2dge::textureName.first,S2dge::textureName.second);
	target.Statistics.Add(S2dge::colorDefault.first,S2dge::colorDefault.second);
	target.Statistics.Add(S2dge::xCoordinateDefault.first,S2dge::xCoordinateDefault.second);
	target.Statistics.Add(S2dge::yCoordinateDefault.first,S2dge::yCoordinateDefault.second);
	target.Statistics.Add(S2dge::widthDefault.first,S2dge::widthDefault.second);
	target.Statistics.Add(S2dge::heightDefault.first,S2dge::heightDefault.second);

	return 0;
}
