#pragma once
#include<stdio.h>
#include<string>
#include <stdlib.h>
#include "cFechayHora.h"
class cOrgano
{
private: 
	string organo;
	cFechayHora* fechayhora_extraccion;
	string vehiculo;

public: 
	cOrgano(string _organo, cFechayHora* _fechayhora_extraccion);
	~cOrgano();
};

