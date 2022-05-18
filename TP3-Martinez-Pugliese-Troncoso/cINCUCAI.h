#pragma once
#include "cDonante.h"
#include "cReceptor.h"
# define TAM 50
class cINCUCAI
{
private:

	cLista<cDonante>* cListaDonantes;
	cLista<cReceptor>* cListaReceptores;
	cLista<cCentroSalud>* cListaCentrosSalud;

public: 
	friend class cCentroSalud;

	cINCUCAI();
	~cINCUCAI();
	void RecibirPaciente(cPaciente* paciente,string patente); 
	void AgregarPaciente(cPaciente* paciente, int m);
	cLista<cReceptor>* BuscaPosiblesReceptores(cDonante* donante);
	cReceptor* EleccionReceptor(cDonante* donante, eOrgano organo);
	cLista<cReceptor>* ReceptoresPorOrgano(eOrgano _organo);
	void OrdenarLista();
	void OrdenamientoPorFecha(cLista<cReceptor>* lista_aux, int n);
	cPaciente* BuscaPosibleDonante(cReceptor* receptor);
	void Trasplante(cDonante* donante,string patente);
	void ProtocoloDeTransporte(cDonante* donante, cReceptor* receptor, eOrgano organo, string patente, int n);
		void Transporte(cVehiculo* vehiculo);
	void EstudiosYBusquedaParaTrasplante(cPaciente* paciente, string patente);

};

