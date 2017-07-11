#include <game-controller.hpp>
SrpgEngine::Game::GameController::GameController()
{
	this->DigitalInputs = {
		{"DigitalUp",false},
		{"DigitalDown",false},
		{"DigitalLeft",false},
		{"DigitalRight",false},
		{"ButtonA",false},
		{"ButtonB",false},
		{"ButtonX",false},
		{"ButtonY",false},
		{"ButtonLB",false},
		{"ButtonRB",false},
		{"ButtonLT",false},
		{"ButtonRT",false},
		{"ButtonLS",false},
		{"ButtonRS",false},
		{"ButtonStart",false},
		{"ButtonBack",false},
	};

	this->AnalogInputs = {
		{"X_AXIS",0},
		{"Y_AXIS",0},
		{"Z_AXIS",0},
		{"U_AXIS",0},
		{"V_AXIS",0},
		{"W_AXIS",0},
	};
}
