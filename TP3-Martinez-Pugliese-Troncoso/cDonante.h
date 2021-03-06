#pragma once
#include "cPaciente.h"
class cOrgano;


class cDonante :
    public cPaciente
{
private: 
    cLista<cOrgano>* listadeorganos;

public:
    friend class cFechayHora;
    friend class cINCUCAI;
    friend class cCentroSalud;

    cFechayHora* FechaHoraFallecimiento;
    cFechayHora* FechaHoraApertura;//hora en el q se abre el cuerpo
   
    cDonante(string _nombre, string _fechanac, char _sexo, string _telefono, string _tiposangre);
    void ListaDeOrganosADonar(cDonante* donante);
     eOrgano switchOrganos(int n);
    void AsignacionFechadeApertura(cDonante* donante, int dia, int mes, int anio);
    ~cDonante();

    string Get_TipoSangre()
    {
        return this->TipoSangre;
    }

    string to_string();
    
};

