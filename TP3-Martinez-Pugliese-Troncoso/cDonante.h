#pragma once
#include "cPaciente.h"
#include "cFechayHora.h"
#include "cTemplate.h"
class cOrgano;

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
    friend class cCentroSalud;
    cDonante(string _nombre, string _fechanac, char _sexo, string _telefono, string _tiposangre);
    ~cDonante();
};

