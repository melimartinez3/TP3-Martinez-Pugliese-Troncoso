#pragma once
#include<stdio.h>
#include<string>
#include <stdlib.h>



using namespace std;
class cVehiculo
{

public:
	friend class cOrgano;

	string patente;
	cVehiculo(string patente_);

	virtual ~cVehiculo();
};

