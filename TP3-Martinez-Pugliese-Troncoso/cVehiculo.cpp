#include "cVehiculo.h"

void cVehiculo::AgregarAmbulancia()
{
	this->cant_ambulancias = this->cant_ambulancias + 1;
}

void cVehiculo::SacarAmbulancia()
{
	if (cant_ambulancias > 0)
	{
		this->cant_ambulancias = this->cant_ambulancias - 1;
	}
	
	//throw new exception ("\nNo hay mas ambulancias disponibles");
}

void cVehiculo::AgregarHelicoptero()
{
	this->cant_helicopteros = this->cant_helicopteros + 1;
}
void cVehiculo::SacarHelicoptero()
{
	if (cant_helicopteros > 0)
	{
		this->cant_helicopteros = this->cant_helicopteros - 1;
	}

	//throw new exception("\nNo hay mas helicopteros disponibles");
}
void cVehiculo::AgregarAvion()
{
	this->cant_aviones = this->cant_aviones + 1;
}

void cVehiculo::SacarAvion()
{
	if (cant_aviones > 0)
	{
		this->cant_aviones = this->cant_aviones - 1;
	}

	//throw new exception("\nNo hay mas aviones disponibles");
}

