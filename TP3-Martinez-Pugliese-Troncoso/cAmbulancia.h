#pragma once
#include "cVehiculo.h"

class cAmbulancia :
    protected cVehiculo
{
private: 

    int cant_ambulancia;
public:
	cAmbulancia(int cant,string _patente);
	void AgregarAmbulancia()
	{
		this->cant_ambulancia = this->cant_ambulancia + 1;
	}

	void SacarAmbulancia()
	{
		if (cant_ambulancia > 0)
		{
			this->cant_ambulancia = this->cant_ambulancia - 1;
		}
	}
	int get_cant_ambulancias() {
		return this->cant_ambulancia;
	}
	~cAmbulancia();
};

