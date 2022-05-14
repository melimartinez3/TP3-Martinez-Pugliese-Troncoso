#pragma once
#include "cPaciente.h"

class cReceptor :
    protected cPaciente
{
private:
    eOrgano Organo;
    cFechayHora* FechaAgregado;
    bool Prioridad;// absoluta=true no_ablsoluta=false
    bool Estado;// esta estable=true o inestable=false
    string Patologia;

public:

    friend class cCentroSalud;
    friend class cINCUCAI;
    //constructor de cReceptor
    cReceptor(eOrgano _organo, bool _prioridad, bool _estado, string _patologia, string _nombre, string _fechanac, char _sexo, string _telefono, string _tiposangre);
   

    void set_estado(bool nuevo) {
        this->Estado = nuevo;
    }

    void set_prioridad(bool prioridad) {
        this->Prioridad = prioridad;
    }
    eOrgano get_Organo() {
        return this->Organo;
    }
   
    void AsignacionFechaLLegda(cReceptor* receptor, int hora, int min, int segundos, int dia, int mes, int anio);
  
    time_t get_HoraAgregado()
    {
        return FechaAgregado->get_hora();
    }
    int get_DiaAgregado()
    {
        return FechaAgregado->get_dia();
    }
    int get_MesAgregado()
    {
        return FechaAgregado->get_mes();
    }
    int get_AnioAgregado()
    {
        return FechaAgregado->get_anio();
    }

    bool  get_Prioridad()
    {
        return this->Prioridad;
    }

    string Get_TipoSangre()
    {
        return this->TipoSangre;
    }

    
    // destructor de cReceptor
    ~cReceptor();

};

