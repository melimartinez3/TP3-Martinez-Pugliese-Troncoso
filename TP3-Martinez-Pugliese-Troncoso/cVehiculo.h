#pragma once
#include<stdio.h>
#include<string>
#include <stdlib.h>
class cVehiculo
{
private:
	int cant_ambulancias;
	int cant_helicopteros;
	int cant_aviones;

public:
	cVehiculo(int cant_amb, int cant_heli, int cant_av);
	void AgregarAmbulancia();
	void SacarAmbulancia();
	void AgregarHelicoptero();
	void SacarHelicoptero();
	void AgregarAvion();
	void SacarAvion();
	~cVehiculo();
};

