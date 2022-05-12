#pragma once
#include "cTemplate.h"
#include "cOrgano.h"
#define TAM 50

class cListaReceptores :
    private cLista<cReceptor>
{
public:
    cListaReceptores(int tamtotal);
    cListaReceptores* FiltrarNuevaLista(cLista<cOrgano>* _lista_organos);
    ~cListaReceptores();
};

