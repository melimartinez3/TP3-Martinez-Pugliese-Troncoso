#include "cAvion.h"

cAvion::cAvion(int cant, string _patente) :cVehiculo(_patente) {
	this->cant_aviones = cant;
}

cAvion::~cAvion() {};