#pragma once
#include "cVehiculo.h"
class cAvion :
    protected cVehiculo
{
private:

    int cant_aviones;
public:
	cAvion(int cant, string _patente);
	void AgregarAvion()
	{
		this->cant_aviones = this->cant_aviones + 1;
	}

	void SacarAvion()
	{
		if (cant_aviones > 0)
		{
			this->cant_aviones = this->cant_aviones - 1;
		}
	}

	int get_cant_aviones() {
		return this->cant_aviones;
	}
	~cAvion();
};

