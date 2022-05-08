#pragma once
#include "cDonante.h"
#include "cReceptor.h"
#include "Template.h"
class cINCUCAI
{
private:

	cLista<cDonante>* cListaDonantes;
	cLista<cReceptor>* cListaReceptores;
	cLista<cCentroSalud>* cListaCentrosSalud;

public:
	cINCUCAI(cLista<cDonante>* _cListaDonantes, cLista<cReceptor>* _cListaReceptores, cLista<cCentroSalud>* _cListaCentrosSalud);
	~cINCUCAI();
	void RecibirPaciente(cPaciente* paciente);
	void AgregarPaciente(cPaciente* paciente, int m); //m va a ser 0 si es un receptor, 1 si es un donante
	cLista<cReceptor>* BuscaPosiblesReceptores(cLista<cReceptor>* lista_receptores,cDonante* donante);
};

