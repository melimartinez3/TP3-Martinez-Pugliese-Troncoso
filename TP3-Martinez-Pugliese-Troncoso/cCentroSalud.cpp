#include "cCentroSalud.h"
//constructor de cCentroSalud
cCentroSalud::cCentroSalud(string _nombre, string _direcc, string _partido, string _provincia, string _telefono) {
	this->Nombre = _nombre;
	this->Direccion = _direcc;
	this->Partido = _partido;
	this->Provincia = _provincia;
	this->Telefono = _telefono;
    // inicializar en null a la lista vehiculos
}

// destructor de cCentroSalud
cCentroSalud::~cCentroSalud() {
	//delete lista vehiculos
}