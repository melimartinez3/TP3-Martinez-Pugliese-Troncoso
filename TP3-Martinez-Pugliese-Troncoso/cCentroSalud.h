#pragma once
#include<stdio.h>
#include<string>
#include <stdlib.h>
#include "cVehiculo.h"
#include "cReceptor.h"
#include "cDonante.h"

using namespace std;

enum Vehiculos { Ambulancia = 1, Helicoptero, Avion};
typedef Vehiculos eVehiculos;

class cCentroSalud
{
private:
	string Nombre;
	string Direccion;
	string Partido;
	string Provincia;
	string Telefono;
	cLista<cVehiculo>* listavehiculos;
	
public:
	friend class cReceptor;
	friend class cDonante;
	cCentroSalud(string _nombre, string _direcc, string _partido, string _provincia, string _telefono);
	bool AsignacionVehiculo(cDonante* donante, eOrgano organo, eVehiculos vehiculoo);
	eVehiculos CalculoDistancia(cDonante* donante, cReceptor* receptor);
	bool DesasignacionVehiculo();
	string get_partido() {
		return this->Partido;
	}
	string get_provincia() {
		return this->Provincia;
	}
	~cCentroSalud();
};

