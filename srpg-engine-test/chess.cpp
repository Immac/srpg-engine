//#include "chess.hpp"
//#include <sstream>

//using namespace SrpgEngine::Framework;
//using namespace SrpgEngine::Game;
//using namespace ChessExample;

//Vector<GameObject *> BoardFactory::CreateBoard()
//{
//	Vector<GameObject *> vec = Vector<GameObject *>();
////	auto isWhite = false;
////	std::stringstream ss;
////	auto leftOffset = 6;
////	auto topOffset = 1;
////	auto gridWidth =  8;
////	auto gridHeight = 8;
////	for(int i = topOffset; i < topOffset + gridHeight; i++)
////	{
////		for(int j = leftOffset; j < leftOffset + gridWidth ; j++) {
////			auto tile = new GameObject();
////			ss <<"tile" << j << i << std::endl;
////			tile->Name = ss.str();
////			tile->Systems.insert(_s2dge);
////			tile->Systems.insert(_tilepos);
////			tile->Properties[_s2dge] = new GameObject();
////			tile->Properties[_tilepos] = new GameObject();
////			tile->Properties[_s2dge]->Statistics["textured"] = 1;
////			tile->Properties[_s2dge]->Dictionary["texture"] = (isWhite)
////															  ? this->_texturePaths["WhiteTile"]
////															  : this->_texturePaths["BlackTile"];
////			tile->Propertie s[_tilepos]->Statistics["x"] = j;
////			tile->Properties[_tilepos]->Statistics["y"] = i;
////			tile->Properties[_tilepos]->Statistics["z"] = 1;
////			vec.push_back(tile);
////			ss.str(string());
////			ss.clear();
////			isWhite = !isWhite;
////		}
////		isWhite = !isWhite;
////	}
//	return vec;
//}
