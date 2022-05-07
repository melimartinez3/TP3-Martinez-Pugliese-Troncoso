#pragma once
#include<stdio.h>
#include<string>
#include <stdlib.h>

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
	//lista  vehiculos disponibles
public:
	cCentroSalud(string _nombre, string _direcc, string _partido, string _provincia, string _telefono);
	bool AsignacionVehiculo();
	eVehiculos CalculoDistancia();
	bool DesasignacionVehiculo();




	~cCentroSalud();
};

