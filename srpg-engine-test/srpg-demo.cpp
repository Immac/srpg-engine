#include "srpg-demo.hpp"
#include <iostream>

using namespace SrpgDemo::Util;

Synchronizer::Synchronizer(sf::Time step)
	:_step(step)
{
}

void Synchronizer::Reset()
{
	this->_clock.restart();
}

bool Synchronizer::TryStep()
{
	this->_lag += this->_clock.getElapsedTime();
	return this->_lag >= this->_step;
}

void Synchronizer::FinishStep()
{
	this->_lag -= this->_step;
	this->_clock.restart();
}
