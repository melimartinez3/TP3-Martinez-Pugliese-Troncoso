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
/// <summary>
/// asignamos al organo un vehiculo para que sea trasladado de un centro a otro
/// </summary>
/// <param name="donante"></param>
/// <param name="organo"></param>
/// <param name="receptor"></param>
/// <param name="patente"></param>
/// <returns></returns>
bool cCentroSalud::AsignacionVehiculo(cDonante* donante, eOrgano organo, cReceptor* receptor, string patente) {

	int pos = 0;
	eVehiculos vehiculo_asignar = CalculoDistancia(donante, receptor);

	int n = donante->listadeorganos->get_cant_actual();
	for (int i = 0; i < n; i++) {
		if (donante->listadeorganos->lista[i]->get_Organo() == organo)
		{
			pos = i;
			break;
		}
	}
	switch (vehiculo_asignar)
	{
	case -1: //no hay receptor asiq devuelvo false
	      {
		      return false;
	      }

	case 1: 
	{  if (donante->listadeorganos->lista[pos]->vehiculo == NULL) {
		donante->listadeorganos->lista[pos]->vehiculo = new cAmbulancia(patente);
		return true;
	  }
	}
		
	case 2:
	    {
		if (donante->listadeorganos->lista[pos]->vehiculo == NULL) {
			donante->listadeorganos->lista[pos]->vehiculo = new cAvion(patente);
			return true;
		}

	    }

	case 3:
	{
		if (donante->listadeorganos->lista[pos]->vehiculo == NULL) {
			donante->listadeorganos->lista[pos]->vehiculo = new cHelicoptero(patente);
			return true;
		}
	
	}
		
	}
	return false;
}
 /// <summary>
 /// una vez que llega a destino desasignamos el vehiculo del organo
 /// </summary>
 /// <param name="donante"></param>
 /// <param name="organo"></param>
 /// <returns></returns>
 bool cCentroSalud::DesasignacionVehiculo(cDonante* donante, eOrgano organo) {

	int n = donante->listadeorganos->get_cant_actual();
	for (int i = 0; i < n; i++) {
		if (donante->listadeorganos->lista[i]->get_Organo() == organo)
		{
			donante->listadeorganos->lista[i]->vehiculo = NULL;
			return true;// se desasigno el vehiculo  
		}
	}
	return false;
}

/// <summary>
/// calculamos la distancia entre los centro de salud y determinamos en que vehiculo viaja
/// </summary>
/// <param name="donante"></param>
/// <param name="receptor"></param>
/// <returns></returns>
eVehiculos cCentroSalud::CalculoDistancia(cDonante* donante, cReceptor* receptor) {
	
	eVehiculos vehiculo;
	if (receptor == NULL) {
		vehiculo = SinReceptor; //como no hay receptor devolvemos esto
		return vehiculo;
	}
	if (donante->CentroSaludd->get_partido()== receptor->CentroSaludd->get_partido() && donante->CentroSaludd->get_provincia() == receptor->CentroSaludd->get_provincia())
		vehiculo = Ambulancia;
	
	else if (donante->CentroSaludd->get_provincia() == receptor->CentroSaludd->get_provincia() && donante->CentroSaludd->get_partido() != receptor->CentroSaludd->get_partido())
		vehiculo = Helicoptero;

	else
		vehiculo = Avion;

	return vehiculo;
}

/// <summary>
/// se realiza el trasplante del organo
/// </summary>
/// <param name="organo"></param>
/// <param name="incucai"></param>
/// <param name="receptor"></param>
/// <param name="donante"></param>
void cCentroSalud::RealizacionDelTrasplante(cOrgano* organo, cINCUCAI* incucai,cReceptor* receptor, cDonante* donante) {

	time_t hora_de_extraccion=organo->fechayhora_extraccion->get_hora();

	time_t hora_de_diferencia_max = 20 *60*60; //segundos que hay en 20 horas

	time_t tiempo_ahora;
	tiempo_ahora = time(NULL);
	ctime(&tiempo_ahora);
	

	time_t diferencia_de_horas = difftime(tiempo_ahora, hora_de_extraccion);

	int exitoso = rand() % 2; //exitoso es 0 y no exitoso es 1

	if (diferencia_de_horas < hora_de_diferencia_max) { 
		//se puede realizar el trasplante porque pasaron menos de 20 horas
		if (exitoso == 0) {
			incucai->cListaReceptores->operator-(receptor);
		}
		else {
			receptor->set_estado(false);
			receptor->set_prioridad(true);
		}
	}
	eOrgano organo_aux = organo->organo;
	bool vehiculo = DesasignacionVehiculo(donante, organo_aux);

}
/// <summary>
/// devolvemos una lista de receptores de un centro de salud
/// </summary>
/// <param name="centro"></param>
/// <param name="incucai"></param>
/// <returns></returns>
cLista<cReceptor>* cCentroSalud::ReceptoresPorCentroSalud(cCentroSalud* centro, cINCUCAI* incucai)
{
	int n = incucai->cListaReceptores->get_cant_actual();
	cLista<cReceptor>* aux = new cLista<cReceptor>(n);
	int p = 0;

	for (int i = 0; i < n; i++)
	{
		if (incucai->cListaReceptores->lista[i]->CentroSaludd == centro)
		{
			aux->lista[p] = incucai->cListaReceptores->lista[i];
			p++;
		}
	}

	aux->set_CantActual(p);
	//aux = aux->Resize(aux, p);

	return aux;
}

string cCentroSalud::to_string() {
	string dato;
	dato = "\n Nombre: " + Nombre + " Direccion: " + Direccion + " Partido: " + Partido + " Provincia: " + Provincia + " Telefono: " + Telefono;
	return dato;
}

void cCentroSalud::Imprimir() {
	string dato = to_string();
	cout << dato;
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