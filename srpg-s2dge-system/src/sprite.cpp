#include "sprite.hpp"
using namespace SrpgEngine::S2dge;

Sprite::Sprite(GameObject& system_object)
	:_system_object(system_object)
{

}

const string& Sprite::GetTexturePath()
{
	return _system_object.Dictionary["texture"];
}

void Sprite::SetTexture(sf::Texture& texture)
{
	this->setTexture(texture);
}

