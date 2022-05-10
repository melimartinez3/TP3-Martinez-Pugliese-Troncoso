#include "cDonante.h"

cDonante::cDonante(string _nombre, string _fechanac, char _sexo, string _telefono, string _tiposangre) :cPaciente(_nombre, _fechanac, _sexo, _telefono, _tiposangre)
{
	FechaHoraFallecimiento = NULL;
	FechaHoraApertura = NULL;
    listadeorganos = NULL;
}

cDonante::~cDonante() {
	delete FechaHoraFallecimiento;
	delete FechaHoraApertura;
};
