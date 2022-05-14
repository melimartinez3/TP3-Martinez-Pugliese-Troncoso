#pragma once
#include<stdio.h>
#include<string>
#include <stdlib.h>
#include"cFechayHora.h"
#include "cOrgano.h"
#include "cTemplate.h"

class cCentroSalud;

//enum Organo { Corazon = 1, Higado, Pancreas, Huesos, Rinion, Pulmones, Intestino, Piel, Corneas };
//typedef Organo eOrgano;

using namespace std;

class cPaciente
{
protected:
	string Nombre;
	string FechaNac;
	char Sexo;
	string Telefono;
	string TipoSangre;
	cCentroSalud* CentroSaludd;
	
public:
	cPaciente(string _nombre, string _fechanac, char _sexo, string _telefono, string _tiposangre);
	bool AsignacionCentroDeSalud(cPaciente* paciente, cCentroSalud* centrosalud);
	void DesasignacionCentroDeSalud(cPaciente* paciente);
	virtual ~cPaciente();

	string Get_TipoSangre()
	{
		return this->TipoSangre;
	}
};
