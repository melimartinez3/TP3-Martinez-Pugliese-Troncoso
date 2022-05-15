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
	friend class cCentroSalud;

	cINCUCAI(cLista<cDonante>* _cListaDonantes, cLista<cReceptor>* _cListaReceptores, cLista<cCentroSalud>* _cListaCentrosSalud);
	~cINCUCAI();
	void RecibirPaciente(cPaciente* paciente, cLista<cDonante>* _cListaDonantes, cLista<cReceptor>* _cListaReceptores,string patente); 
	void AgregarPaciente(cPaciente* paciente, int m, cLista<cDonante>* _cListaDonantes, cLista<cReceptor>* _cListaReceptores);
	cLista<cReceptor>* BuscaPosiblesReceptores(cDonante* donante);
	cReceptor* EleccionReceptor(cDonante* donante, eOrgano organo);
	cLista<cReceptor>* ReceptoresPorOrgano(eOrgano _organo, cLista<cReceptor>* lista_receptores);
	void OrdenarLista(cLista<cReceptor>* _lista_receptores);
	void OrdenamientoPorFecha(cLista<cReceptor>* lista, int n);
	cPaciente* BuscaPosibleDonante(cReceptor* receptor);
	void Trasplante(cDonante* donante,string patente);
	void ProtocoloDeTransporte(cDonante* donante, cReceptor* receptor, eOrgano organo, string patente, int n);
	void Transporte(cVehiculo* vehiculo);
	void EstudiosYBusquedaParaTrasplante(cPaciente* paciente, string patente);

};

