#include "cINCUCAI.h"

//constructor 
cINCUCAI::cINCUCAI(cLista<cDonante>* _cListaDonantes, cLista<cReceptor>* _cListaReceptores, cLista<cCentroSalud>* _cListaCentrosSalud)
{
	cListaDonantes = _cListaDonantes;
	cListaReceptor = _cListaReceptores;
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
		int tamtotal = _cListaReceptores->get_tamanio_total();
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
		int tamtotal = _cListaDonantes->get_tamanio_total();
		if (ca < tamtotal) {
			if (_cListaDonantes->lista[ca] == NULL)
				_cListaDonantes->lista[ca] = donante_aux;
		}
		return;
	}
	else
		throw new exception("\nNo se pudo agregar a ninguna de las dos listas (Donantes y Receptores)");
	
}

cLista<cReceptor>* cINCUCAI::BuscaPosiblesReceptores(cDonante* donante)
{
	cLista<cReceptor>* aux1;
	string TipoSangreBuscar = donante->Get_TipoSangre();
	aux1=cListaReceptor->Filtrar(TipoSangreBuscar);
	
	cLista<cReceptor>* sublista_aux = new cLista<cReceptor>(50);// ponemos 50 porque es la cantidad maxima de pacientes que puede tener (define del main)
	int cont;
	int n = cListaReceptor->get_cant_actual();
	int k = donante->listadeorganos->get_cant_actual();
    int j;
	int p = 0;
	for (int i = 0; i < n; i++) //recorremos toda la lista
	{
		cont = 0;
		for(j=0; j<k; j++)
		if (aux1->lista[i]->get_Organo() == donante->listadeorganos->lista[k]->get_Organo()) //si encontramos al elemento buscado
		{
		
				sublista_aux->lista[p] = aux1->lista[i]; //igualamos el elemento[i] de la sublista auxiliar al elemento[i] de la lista original
				p++; //sumamos 1
			
		}

	}

	cLista<cReceptor>* sublista = new cLista<cReceptor>(p); //creamos una sublista del tamaño necesario
	for (int i = 0; i < cont; i++)
	{
		sublista[i] = sublista_aux[i]; //copiamos los elementos de la sublista auxiliar a la sublista
	}

	return sublista;
	
}

void cINCUCAI::EleccionReceptor(cDonante* donante) {
	cLista<cReceptor>* listareceptores = BuscaPosiblesReceptores(donante);
	int n=donante->listadeorganos->get_cant_actual();
	for (int i = 0; i < n; i++) {
		

	}
}



cINCUCAI::~cINCUCAI()
{
	if(cListaDonantes != NULL)
		delete cListaDonantes;

	if (cListaReceptor != NULL)
		delete cListaReceptor;

	if (cListaCentrosSalud != NULL)
		delete cListaCentrosSalud;
}
