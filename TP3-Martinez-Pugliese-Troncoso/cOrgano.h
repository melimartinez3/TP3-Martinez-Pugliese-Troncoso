#pragma once
#include<stdio.h>
#include<string>
#include <stdlib.h>
#include "cFechayHora.h"
#include "cVehiculo.h"


enum Organo { Corazon = 1, Higado, Pancreas, Huesos, Rinion, Pulmones, Intestino, Piel, Corneas };
typedef Organo eOrgano;

class cOrgano
{
private: 
	eOrgano organo;
	cFechayHora* fechayhora_extraccion;
	cVehiculo* vehiculo;

public: 
	friend class cDonante;
	friend class cTemplate;
	friend class cCentroSalud;
	friend class cINCUCAI;
	cOrgano(eOrgano _organo, cFechayHora* _fechayhora_extraccion);
	eOrgano get_Organo();
	
	~cOrgano();
};

