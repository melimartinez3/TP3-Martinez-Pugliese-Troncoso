#include "cINCUCAI.h"

//constructor 
cINCUCAI::cINCUCAI(cLista<cDonante>* _cListaDonantes, cLista<cReceptor>* _cListaReceptores, cLista<cCentroSalud>* _cListaCentrosSalud) 
{
	cListaDonantes = _cListaDonantes;
	cListaReceptores = _cListaReceptores;
	cListaCentrosSalud = _cListaCentrosSalud;
}

void cINCUCAI::RecibirPaciente(cPaciente* paciente, cLista<cDonante>* _cListaDonantes, cLista<cReceptor>* _cListaReceptores) //Pasarle por parametro las dos listas
{
	cDonante* donante_aux = dynamic_cast<cDonante*>(paciente);
	if (donante_aux == NULL)
	{
		//si es igual a NULL, nuestro paciente es un receptor
		this->AgregarPaciente(paciente, 0, _cListaDonantes, _cListaReceptores);
		return;
	}

	//si el paciente es un donante:
	this->AgregarPaciente(paciente, 1, _cListaDonantes, _cListaReceptores);
	
}

void cINCUCAI::AgregarPaciente(cPaciente* paciente, int m, cLista<cDonante>* _cListaDonantes, cLista<cReceptor>* _cListaReceptores)
{
	//si m es 0 es un receptor y si me es 1 es un donante
	if (m == 0)
	{
		cReceptor* receptor_aux = dynamic_cast<cReceptor*>(paciente);

		int ca = _cListaReceptores->get_cant_actual();
		int tamtotal = _cListaReceptores->get_tamaño_total();
		if (ca < tamtotal) {
			if (_cListaReceptores->lista[ca] == NULL)
				_cListaReceptores->lista[ca] = receptor_aux;
		}
		return; 

	}
	else if (m == 1)
	{
		//agregar a la lista de donantes
		cDonante* donante_aux = dynamic_cast<cDonante*>(paciente);
		int ca = _cListaDonantes->get_cant_actual();
		int tamtotal = _cListaDonantes->get_tamaño_total();
		if (ca < tamtotal) {
			if (_cListaDonantes->lista[ca] == NULL)
				_cListaDonantes->lista[ca] = donante_aux;
		}
		return;
	}
	else
		throw new exception("\nNo se pudo agregar a ninguna de las dos listas (Donantes y Receptores)");
	
}

cLista<cReceptor>* cINCUCAI::BuscaPosiblesReceptores(cLista<cReceptor>* lista_receptores, cDonante* donante)
{
	cLista<cReceptor>* aux1;
	int i = 0;
	string TipoSangreBuscar = donante->Get_TipoSangre();
	aux1=lista_receptores->Filtrar(TipoSangreBuscar);
	//int n = 
	//for(int i=0;i<)
	if (aux1->lista[i]->get_Organo()==)

	
}



cINCUCAI::~cINCUCAI()
{
	if(cListaDonantes != NULL)
		delete cListaDonantes;

	if (cListaReceptores != NULL)
		delete cListaReceptores;

	if (cListaCentrosSalud != NULL)
		delete cListaCentrosSalud;
}
