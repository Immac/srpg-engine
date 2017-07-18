#include "utilities.hpp"
using namespace SrpgEngine;
using namespace S2dge;
using namespace S2dgeUtil;



void S2dgeUtil::InitializeSprite(GameObject& game_object, TextureHandler& textures)
{
	Vocabulary v;
	const auto& graphics = game_object.Properties[v.graphics];
	graphics->Data[v.graphic] = new sf::Sprite();
	auto sf_sprite = static_cast<sf::Sprite *>(graphics->Data[v.graphic]);
	const auto& texture_path = graphics->Dictionary[v.texture];
	if(!textures.LoadTexture(texture_path)) {
		throw;
	}

	const auto& texture_ptr = textures[texture_path].get();
	sf_sprite->setTexture(*texture_ptr);
	graphics->Dictionary["texture_path"] = texture_path;
	graphics->Data["texture"] = texture_ptr;
}



void S2dgeUtil::UpdateSprite(GameObject& game_object, GameObject& system)
{
//	for(auto& stat : game_object.Statistics) {
//		system.Statistics[stat.first] = stat.second;
//	}
//	auto red = system.Statistics["red"];
//	auto green = system.Statistics["green"];
//	auto blue = system.Statistics["blue"];
//	auto alpha = system.Statistics["alpha"];
//	auto sprite = static_cast<sf::Sprite *>(
//					  game_object.Data["graphic"]);
//	auto different_color = ((sf::Sprite*)sprite)->getColor() != sf::Color(red,green,blue,alpha);
//	if(different_color){
//		sprite->setColor(sf::Color(red,green,blue,alpha));
//	}
//	sprite->setPosition(system.Statistics["display_x"] + system.Statistics["x-offset"]
//			, system.Statistics["display_y"] + system.Statistics["y-offset"]);
}
