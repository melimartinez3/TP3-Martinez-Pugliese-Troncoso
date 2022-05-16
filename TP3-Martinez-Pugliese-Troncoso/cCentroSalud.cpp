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

bool cCentroSalud::AsignacionVehiculo(cDonante* donante, eOrgano organo, cReceptor* receptor, string patente, cCentroSalud* centrosaluddonante, cCentroSalud* centrosaludreceptor) {

	cVehiculo* aux = NULL;

	eVehiculos vehiculo_asignar = CalculoDistancia(donante, receptor,centrosaluddonante,centrosaludreceptor);

	
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


eVehiculos cCentroSalud::CalculoDistancia(cDonante* donante, cReceptor* receptor, cCentroSalud* centrosaluddonante, cCentroSalud* centrosaludreceptor) {

	eVehiculos vehiculo;
	if (receptor == NULL) {
		vehiculo = SinReceptor; //como no hay receptor devolvemos esto
		return vehiculo;
	}
	if (centrosaluddonante->get_partido() == centrosaludreceptor->get_partido() && centrosaluddonante->get_provincia() == centrosaludreceptor->get_provincia())
		vehiculo = Ambulancia;
	
	else if (centrosaluddonante->get_provincia() == centrosaludreceptor->get_provincia() && centrosaluddonante->get_partido() != centrosaludreceptor->get_partido())
		vehiculo = Helicoptero;

	else
		vehiculo = Avion;

	return vehiculo;
}


void cCentroSalud::RealizacionDelTrasplante(cOrgano* organo, cINCUCAI* incucai,cReceptor* receptor, cDonante* donante) {

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
	eOrgano organo_aux = organo->organo;
	bool vehiculo = DesasignacionVehiculo(donante, organo_aux);

}

cLista<cReceptor>* cCentroSalud::ReceptoresPorCentroSalud(cCentroSalud* centro, cLista<cReceptor>* lista_receptores)
{
	int n = lista_receptores->get_cant_actual();
	cLista<cReceptor>* aux = new cLista<cReceptor>(n);
	int p = 0;

	for (int i = 0; i < n; i++)
	{
		if (lista_receptores->lista[i]->CentroSaludd == centro)
		{
			aux->lista[p] = lista_receptores->lista[i];
			p++;
		}
	}

	aux->set_CantActual(p);
	aux = aux->Resize(aux, p);

	return aux;
}

/// <summary>
/// en esta funcion chequeamos los organos donados en esa provincia (sin importar en que provincia esta el receptor)
/// </summary>
/// <param name="centrosalud"></param>
/// <param name="donante"></param>
/// <param name="receptor"></param>
/// <returns></returns>
int cCentroSalud::ListadeDonacionesPorProvincias(cCentroSalud* centrosalud, cLista<cDonante>* listadonantes, cINCUCAI* incucai, int mes) {
	
	string provincia=this->get_provincia();
	int n = incucai->cListaDonantes->get_cant_actual();
	int cont = 0;
	// recorremos la lista de donantes
	for (int i = 0; i < n; i++) {                              // corroboramos solo el primer organo ya que una vez que comienza la ablacion se quitan todos en ese mismo momento
		if (provincia == listadonantes->lista[i]->CentroSaludd->get_provincia() && listadonantes->lista[i]->listadeorganos->lista[0]->fechayhora_extraccion->get_mes() == mes) {
			cont++;
		}
	}
	return cont;
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