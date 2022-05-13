#pragma once
#include "cTemplate.h"
#include "cOrgano.h"
#define TAM 50

class cListaReceptores :
    private cLista<cReceptor>
{
public:
    friend class cINCUCAI;
    cListaReceptores(int tamtotal);
    cLista<cReceptor>* FiltrarNuevaLista(cLista<cOrgano>* _lista_organos, cLista<cReceptor>* listareceptores);
    ~cListaReceptores();
};

