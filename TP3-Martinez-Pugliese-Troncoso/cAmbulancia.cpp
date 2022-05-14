#include "cAmbulancia.h"

cAmbulancia::cAmbulancia(int cant, string _patente) :cVehiculo(_patente) {
	this->cant_ambulancia = cant;
}


cAmbulancia::~cAmbulancia() {};