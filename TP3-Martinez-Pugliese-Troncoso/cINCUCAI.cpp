#include "cINCUCAI.h"

//constructor 
cINCUCAI::cINCUCAI(cLista<cDonante>* _cListaDonantes, cLista<cReceptor>* _cListaReceptores, cLista<cCentroSalud>* _cListaCentrosSalud) 
{
	cListaDonantes = _cListaDonantes;
	cListaReceptores = _cListaReceptores;
	cListaCentrosSalud = _cListaCentrosSalud;
}

void cINCUCAI::RecibirPaciente(cPaciente* paciente) //Pasarle por parametro las dos listas
{
	cDonante* donante_aux = dynamic_cast<cDonante*>(paciente);
	if (donante_aux == NULL)
	{
		//si es igual a NULL, nuestro paciente es un receptor
		this->AgregarPaciente(paciente, 0); 
		return;
	}

	//si el paciente es un donante:
	this->AgregarPaciente(paciente, 1); 
	
}

void cINCUCAI::AgregarPaciente(cPaciente* paciente, int m)
{
	if (m == 0)
	{
		//tenemos que agregar a la lista de receptores
		return;
	}

	//agregar a la lista de donantes
	
}

cLista<cReceptor>* cINCUCAI::BuscaPosiblesReceptores(cLista<cReceptor>* lista_receptores, cDonante* donante)
{
	cLista<cReceptor>* aux1;
	string TipoSangreBuscar = donante->
	lista_receptores->Filtrar();
}

cINCUCAI::~cINCUCAI()
{
	//HACER LOS DELETES DE LOS PUNTEROS
}
