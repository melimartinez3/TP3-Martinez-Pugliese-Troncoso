#include "cHelicoptero.h"

cHelicoptero::cHelicoptero(int cant, string _patente) :cVehiculo(_patente) {
	this->cant_helicopteros = cant;
}

cHelicoptero::~cHelicoptero() {};