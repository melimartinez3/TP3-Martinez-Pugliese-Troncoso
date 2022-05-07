#pragma once
#include "cPaciente.h"

enum Organo{Corazon=1, Higado, Pancreas, Huesos, Rinion, Pulmones, Intestino, Piel, Corneas};
typedef Organo eOrgano;

class cReceptor :
    protected cPaciente
{
private:
    eOrgano Organo;
    string FechaAgregado;
    bool Prioridad;// absoluta=true no_ablsoluta=false
    bool Estado;// esta estable=true o inestable=false
    string Patologia;
public:
    cReceptor(eOrgano _organo, string _fecha_agregado, bool _prioridad, bool _estado, string _patologia, string _nombre, string _fechanac, char _sexo, string _telefono, string _tiposangre);


};

