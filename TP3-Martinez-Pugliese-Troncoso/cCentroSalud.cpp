#include "cCentroSalud.h"

#define _CRT_SECURE_NO_WARNINGS

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
	case -1: //no hay receptor asiq devuelvo false
	      {
		      return false;
		      break;
	      }

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
	if (receptor == NULL) {
		vehiculo = SinReceptor; //como no hay receptor devolvemos esto
		return vehiculo;
	}
	if (donante->CentroSaludd->get_partido() == receptor->CentroSaludd->get_partido() && donante->CentroSaludd->get_provincia() == receptor->CentroSaludd->get_provincia())
		vehiculo = Ambulancia;

	else if (donante->CentroSaludd->get_provincia() == receptor->CentroSaludd->get_provincia() && donante->CentroSaludd->get_partido() != receptor->CentroSaludd->get_partido())
		vehiculo = Helicoptero;

	else
		vehiculo = Avion;

	return vehiculo;
}


void cCentroSalud::RealizacionDelTrasplante(cOrgano* organo, cINCUCAI* incucai,cReceptor* receptor) {

	time_t hora_de_extraccion=organo->fechayhora_extraccion->get_hora();

	time_t hora_de_diferencia_max = 20 *60*60; //segundos que hay en 20 horas

	time_t tiempo_ahora;
	tiempo_ahora = time(NULL);
	//ctime(&tiempo_ahora);
	

	time_t diferencia_de_horas = difftime(tiempo_ahora, hora_de_extraccion);

	int exitoso = rand() % 2; //exitoso es 0 y no exitoso es 1

	if (diferencia_de_horas < hora_de_diferencia_max) { 
		//se puede realizar el trasplante porque pasaron menos de 20 horas
		if (exitoso == 0) {
			incucai->cListaReceptor->operator-(receptor);
		}
		else {
			receptor->set_estado(false);
			receptor->set_prioridad(true);
		}
	}
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