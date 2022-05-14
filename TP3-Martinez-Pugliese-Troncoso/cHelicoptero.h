#pragma once
#include "cVehiculo.h"
class cHelicoptero :
    protected cVehiculo
{
private: 
    int cant_helicopteros;

public:
	cHelicoptero(int cant, string _patente);
	void AgregarHelicoptero()
	{
		this->cant_helicopteros = this->cant_helicopteros + 1;
	}
	void SacarHelicoptero()
	{
		if (cant_helicopteros > 0)
		{
			this->cant_helicopteros = this->cant_helicopteros - 1;
		}
	}

	int get_cant_helicopteros() {
		return this->cant_helicopteros;
	}
	~cHelicoptero();
};

