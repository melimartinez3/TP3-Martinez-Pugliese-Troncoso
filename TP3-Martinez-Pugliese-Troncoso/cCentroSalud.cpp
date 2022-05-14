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
bool cCentroSalud::AsignacionVehiculo(cDonante* donante, eOrgano organo, eVehiculos vehiculoo) {

	switch()
	int n=donante->listadeorganos->get_cant_actual();
	for(int i=0;i<n;i++){
		if (donante->listadeorganos->lista[i]->get_Organo() == organo)
		{
			donante->listadeorganos->lista[i]->vehiculo=new cVehiculo()
			return true;
		}
	}
	return false;
}


eVehiculos cCentroSalud::CalculoDistancia(cDonante* donante, cReceptor* receptor) {


   if(donante->CentroSaludd->get_partido()==receptor->CentroSaludd->get_partido())


}




// destructor de cCentroSalud
cCentroSalud::~cCentroSalud() {
	
	if (listavehiculos != NULL)
		delete listavehiculos;

}