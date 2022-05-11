#pragma once
#include "cTemplate.h"
#include "cOrgano.h"


class cListaReceptores :
    private cLista<int>
{
public:
    cListaReceptores(int tamtotal);
    cListaReceptores* FiltrarNuevaLista(string tiposangre, cLista<cOrgano>* _lista_organos);
    ~cListaReceptores();
};

