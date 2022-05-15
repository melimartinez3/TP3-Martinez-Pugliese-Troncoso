#pragma once
#include<stdio.h>
#include<string>
#include <stdlib.h>
#include "cFechayHora.h"
#include "cDonante.h"

class cOrgano
{
private: 
	eOrgano organo;
	cFechayHora* fechayhora_extraccion;
	string vehiculo;

public: 
	friend class cDonante;
	friend class cTemplate;
	cOrgano(eOrgano _organo, cFechayHora* _fechayhora_extraccion);
	eOrgano get_Organo() {
		return this->organo;
	};
	~cOrgano();
};

