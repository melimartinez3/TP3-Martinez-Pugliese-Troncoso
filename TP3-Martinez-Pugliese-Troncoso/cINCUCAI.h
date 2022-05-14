#pragma once
#include "cDonante.h"
#include "cReceptor.h"

class cINCUCAI
{
private:

	cLista<cDonante>* cListaDonantes;
	cLista<cReceptor>* cListaReceptor;
	cLista<cCentroSalud>* cListaCentrosSalud;

public: 

	cINCUCAI(cLista<cDonante>* _cListaDonantes, cLista<cReceptor>* _cListaReceptores, cLista<cCentroSalud>* _cListaCentrosSalud);
	~cINCUCAI();
	void RecibirPaciente(cPaciente* paciente, cLista<cDonante>* _cListaDonantes, cLista<cReceptor>* _cListaReceptores); 
	void AgregarPaciente(cPaciente* paciente, int m, cLista<cDonante>* _cListaDonantes, cLista<cReceptor>* _cListaReceptores);
	cLista<cReceptor>* BuscaPosiblesReceptores(cDonante* donante);
	int EleccionReceptor(cDonante* donante, eOrgano organo);
	cLista<cReceptor>* ReceptoresPorOrgano(eOrgano _organo, cLista<cReceptor>* lista_receptores);
	void OrdenarLista(cLista<cReceptor>* _lista_receptores);
	void OrdenamientoPorFecha(cLista<cReceptor>* lista, int n);



};

