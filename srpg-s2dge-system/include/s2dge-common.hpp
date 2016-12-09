#ifndef S2DGE_COMMON_HPP
#define S2DGE_COMMON_HPP
#include "common.hpp"

namespace SrpgEngine {
namespace S2dge {
using Framework::string;
static string SystemName = "S2DGE";

static std::pair<string,int> xCoordinateDefault = {"x",0};
static std::pair<string,int> yCoordinateDefault = {"y",0};
static std::pair<string,int> heightDefault = {"height",0};
static std::pair<string,int> widthDefault = {"width",0};
static std::pair<string,int> colorDefault = {"argb", 0x00000000};
static std::pair<string,string> textureName = {"texture","default.png"};

}
}

#endif // S2DGE_COMMON_HPP
