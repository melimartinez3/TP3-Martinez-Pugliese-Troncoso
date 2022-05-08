#pragma once
#include<stdio.h>
#include<string>
#include <stdlib.h>
#include "cCentroSalud.h"

using namespace std;

class cPaciente
{
protected:
	string Nombre;
	string FechaNac;
	char Sexo;
	string Telefono;
	string TipoSangre;
	cCentroSalud* CentroSalud;
	
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
