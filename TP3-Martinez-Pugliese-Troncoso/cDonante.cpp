#include "cDonante.h"
//#include "cOrgano.h"

cDonante::cDonante(string _nombre, string _fechanac, char _sexo, string _telefono, string _tiposangre) :cPaciente(_nombre, _fechanac, _sexo, _telefono, _tiposangre)
{
	FechaHoraFallecimiento = NULL;
	FechaHoraApertura = NULL;
    listadeorganos = NULL;
}

cDonante::~cDonante() {
	
	if(FechaHoraFallecimiento != NULL)
		delete FechaHoraFallecimiento;
	
	if(FechaHoraApertura != NULL)
		delete FechaHoraApertura;
};
