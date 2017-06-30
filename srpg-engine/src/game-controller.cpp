#include <game-controller.hpp>
SrpgEngine::Game::GameController::GameController()
{
	this->DigitalInputs.emplace("DigitalUp",0);
	this->DigitalInputs.emplace("DigitalDown",0);
	this->DigitalInputs.emplace("DigitalLeft",0);
	this->DigitalInputs.emplace("DigitalRight",0);
	this->DigitalInputs.emplace("ButtonA",0);
	this->DigitalInputs.emplace("ButtonB",0);
	this->DigitalInputs.emplace("ButtonX",0);
	this->DigitalInputs.emplace("ButtonY",0);
	this->DigitalInputs.emplace("ButtonLB",0);
	this->DigitalInputs.emplace("ButtonRB",0);
	this->DigitalInputs.emplace("ButtonLT",0);
	this->DigitalInputs.emplace("ButtonRT",0);
	this->DigitalInputs.emplace("ButtonLS",0);
	this->DigitalInputs.emplace("ButtonRS",0);
	this->DigitalInputs.emplace("ButtonStart",0);
	this->DigitalInputs.emplace("ButtonBack",0);
	this->AnalogInputs.emplace("X_AXIS",0);
	this->AnalogInputs.emplace("Y_AXIS",0);
	this->AnalogInputs.emplace("Z_AXIS",0);
	this->AnalogInputs.emplace("U_AXIS",0);
	this->AnalogInputs.emplace("V_AXIS",0);
	this->AnalogInputs.emplace("W_AXIS",0);
}