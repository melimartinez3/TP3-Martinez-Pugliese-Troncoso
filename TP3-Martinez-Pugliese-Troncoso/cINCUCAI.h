#pragma once
#include "cDonante.h"
#include "cReceptor.h"
#include "cTemplate.h"
class cINCUCAI
{
private:

	cLista<cDonante>* cListaDonantes;
	cLista<cReceptor>* cListaReceptores;
	cLista<cCentroSalud>* cListaCentrosSalud;

public:

	cINCUCAI(cLista<cDonante>* _cListaDonantes, cLista<cReceptor>* _cListaReceptores, cLista<cCentroSalud>* _cListaCentrosSalud);
	~cINCUCAI();
	void RecibirPaciente(cPaciente* paciente, cLista<cDonante>* _cListaDonantes, cLista<cReceptor>* _cListaReceptores); 
	void AgregarPaciente(cPaciente* paciente, int m, cLista<cDonante>* _cListaDonantes, cLista<cReceptor>* _cListaReceptores);
	cLista<cReceptor>* BuscaPosiblesReceptores(cLista<cReceptor>* lista_receptores,cDonante* donante);
};

