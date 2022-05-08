#pragma once
#include "cPaciente.h"
#include <time.h>
#include "cFechayHora.h"

class cDonante :
    protected cPaciente
{
private: 
    cFechayHora* FechaHoraFallecimiento;
    cFechayHora* FechaHoraAblacion;
    //puntero organos a donar

public:
    friend class cFechayHora;
    cDonante(string _nombre, string _fechanac, char _sexo, string _telefono, string _tiposangre);
    ~cDonante();
};

