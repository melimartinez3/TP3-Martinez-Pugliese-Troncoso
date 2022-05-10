#pragma once
#include "cPaciente.h"
#include "cFechayHora.h"
#include "cOrgano.h"
#include "Template.h"

class cDonante :
    protected cPaciente
{
private: 
    cFechayHora* FechaHoraFallecimiento;
    cFechayHora* FechaHoraApertura;//hora en el q se abre el cuerpo
    cLista<cOrgano>* listadeorganos;

public:
    friend class cFechayHora;
    friend class cINCUCAI;
    cDonante(string _nombre, string _fechanac, char _sexo, string _telefono, string _tiposangre);
    ~cDonante();
};

