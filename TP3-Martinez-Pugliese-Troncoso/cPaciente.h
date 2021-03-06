#pragma once
#include<stdio.h>
#include<string>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include"cFechayHora.h"
#include "cOrgano.h"
#include "cTemplate.h"

using namespace std;

class cCentroSalud;


using namespace std;

class cPaciente
{
protected:
	string Nombre;
	string FechaNac;
	char Sexo;
	string Telefono;
	string TipoSangre;
	
public:
	cCentroSalud* CentroSaludd;
	friend class cCentroSalud;
	cPaciente(string _nombre, string _fechanac, char _sexo, string _telefono, string _tiposangre);
	bool AsignacionCentroDeSalud(cPaciente* paciente, cCentroSalud* centrosalud);
	void DesasignacionCentroDeSalud(cPaciente* paciente);
	friend bool operator==(const string& sangre1, const string& sangre2)
	{
		if (sangre1 == sangre2)
			return true;

		return false;
	}


	virtual string Get_TipoSangre()
	{
		return this->TipoSangre;
	}
	virtual string to_string() = 0;
	//virtual void Imprimir() = 0;
	
	virtual ~cPaciente();
};
