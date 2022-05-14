#include "cCentroSalud.h"
//constructor de cCentroSalud
cCentroSalud::cCentroSalud(string _nombre, string _direcc, string _partido, string _provincia, string _telefono) {
	this->Nombre = _nombre;
	this->Direccion = _direcc;
	this->Partido = _partido;
	this->Provincia = _provincia;
	this->Telefono = _telefono;
	
	lista_ambulancias = NULL;
	lista_aviones = NULL;
	lista_helicopteros = NULL;

}

bool cCentroSalud::AsignacionVehiculo(cDonante* donante, eOrgano organo, cReceptor* receptor, string patente) {

	cVehiculo* aux = NULL;

	eVehiculos vehiculo_asignar = CalculoDistancia(donante, receptor);
	
	switch (vehiculo_asignar)
	{
	case 1: 
		{
			aux = new cAmbulancia(patente);
			break;
		}
		
	case 2:
	    {
		    aux = new cAvion(patente);
		    break;

	    }

	case 3:
	{
		aux = new cHelicoptero(patente);
		break;

	}
		
	}

	int n = donante->listadeorganos->get_cant_actual();
	for (int i = 0; i < n; i++) {
		if (donante->listadeorganos->lista[i]->get_Organo() == organo)
		{
			donante->listadeorganos->lista[i]->vehiculo = aux;
			return true;
		}
	}

	return false;
}


eVehiculos cCentroSalud::CalculoDistancia(cDonante* donante, cReceptor* receptor) {

	eVehiculos vehiculo;

	if (donante->CentroSaludd->get_partido() == receptor->CentroSaludd->get_partido() && donante->CentroSaludd->get_provincia() == receptor->CentroSaludd->get_provincia())
		vehiculo = Ambulancia;

	else if (donante->CentroSaludd->get_provincia() == receptor->CentroSaludd->get_provincia() && donante->CentroSaludd->get_partido() != receptor->CentroSaludd->get_partido())
		vehiculo = Helicoptero;

	else
		vehiculo = Avion;

	return vehiculo;
}



// destructor de cCentroSalud
cCentroSalud::~cCentroSalud() {
	
	if (lista_ambulancias != NULL)
		delete lista_ambulancias;

	if (lista_aviones != NULL)
		delete lista_aviones;

	if (lista_helicopteros != NULL)
		delete lista_helicopteros;

}