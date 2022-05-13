#include "cCentroSalud.h"
//constructor de cCentroSalud
cCentroSalud::cCentroSalud(string _nombre, string _direcc, string _partido, string _provincia, string _telefono) {
	this->Nombre = _nombre;
	this->Direccion = _direcc;
	this->Partido = _partido;
	this->Provincia = _provincia;
	this->Telefono = _telefono;
	
	listavehiculos = NULL;

}
bool cCentroSalud::AsignacionVehiculo(cDonante* donante, eOrgano organo, eVehiculos vehiculo) {
	int cont = 0;
	while (cont < 10) {
		//if(donante->listadeorganos-> == organo) CONSULTAR
	}

}

eVehiculos cCentroSalud::CalculoDistancia(cDonante* donante,cReceptor* receptor) {

   



}




// destructor de cCentroSalud
cCentroSalud::~cCentroSalud() {
	
	if (listavehiculos != NULL)
		delete listavehiculos;
}