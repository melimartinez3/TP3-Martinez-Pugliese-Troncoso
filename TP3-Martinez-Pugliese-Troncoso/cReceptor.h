#pragma once
#include "cPaciente.h"

class cReceptor :
    public cPaciente
{
private:
    eOrgano Organo;
    bool Prioridad;// absoluta=true no_ablsoluta=false
    bool Estado;// esta estable=true o inestable=false
    string Patologia;

public:

    cFechayHora* FechaAgregado;

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

    string PrioridadDelReceptor(cReceptor* receptor, cLista<cReceptor>* listadereceptores);

     /*friend ostream& operator<<(ostream& out, cPaciente* paciente) {

        cReceptor* receptor = dynamic_cast<cReceptor*>(paciente);
        string prioridad;
        string estado;

        if (receptor->Prioridad == true)
            prioridad = "Si";
        else 
            prioridad = "No";

        if (receptor->Estado == true)
            estado = "Si";
        else
            estado = "No";

        out << "\nNombre: " << receptor->Nombre << "Fecha de nacimiento: " << receptor->FechaNac << "Sexo: " << receptor->Sexo << "Telefono: " << receptor->Telefono << "Tipo de Sangre: " << receptor->TipoSangre << "Organo a Recibir: " << receptor->Organo <<"Prioridad: " << prioridad << "Estado: " << estado << "Patologia: " << receptor->Patologia<< endl;
        return out;


        friend ostream& operator<<(ostream& out, const cPaciente& paciente) {

        cout << paciente;
        string prioridad;
        string estado;

        if (this->Prioridad == true)
            prioridad = "Si";
        else
            prioridad = "No";

        if (this->Estado == true)
            estado = "Si";
        else
            estado = "No";

        out << "\nOrgano a Recibir: " << receptor->Organo << "Prioridad: " << prioridad << "Estado: " << estado << "Patologia: " << receptor->Patologia << endl;
        return out;
    }
      
    };*/

    
   
    // destructor de cReceptor
    ~cReceptor();

};

