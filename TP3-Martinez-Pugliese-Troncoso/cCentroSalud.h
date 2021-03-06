#pragma once
#include<stdio.h>
#include<string>
#include <stdlib.h>
#include "cINCUCAI.h"
#include "cAmbulancia.h"
#include "cAvion.h"
#include "cHelicoptero.h"



using namespace std;

enum Vehiculos { Ambulancia = 1, Avion, Helicoptero,SinReceptor=-1};
typedef Vehiculos eVehiculos;

class cCentroSalud
{
private:
	string Nombre;
	string Direccion;
	string Partido;
	string Provincia;
	string Telefono;
	cLista<cAmbulancia>* lista_ambulancias;
	cLista<cAvion>* lista_aviones;
	cLista<cHelicoptero>* lista_helicopteros;
	
public:
	friend class cReceptor;
	friend class cDonante;
	
	cCentroSalud(string _nombre, string _direcc, string _partido, string _provincia, string _telefono);
	bool AsignacionVehiculo(cDonante* donante, eOrgano organo, cReceptor* receptor, string patente);
	eVehiculos CalculoDistancia(cDonante* donante, cReceptor* receptor);
	bool DesasignacionVehiculo(cDonante* donante, eOrgano organo);
	void RealizacionDelTrasplante(cOrgano* organo, cINCUCAI* incucai, cReceptor* receptor, cDonante* donante);
	cLista<cReceptor>* ReceptoresPorCentroSalud(cCentroSalud* centro, cINCUCAI* incucai);
	

	string get_partido() {
		return this->Partido;
	}
	string get_provincia() {
		return this->Provincia;
	}
	string to_string();
	void Imprimir();

	~cCentroSalud();
};

