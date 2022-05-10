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
		/*//CONSULTAR NO SABEMOS COMO SACAR LOS DTAOS DEL RECEPTOR QUE ESTA IGUALADO A PACIENTE DESDE EL MAIN
		//cReceptor*receptor=new cReceptor()
		//tenemos que agregar a la lista de receptores
		int ca = _cListaReceptores->get_cant_actual();
		int tamtotal = _cListaReceptores->get_tamaño_total();
		if (ca < tamtotal) {
			if (_cListaReceptores->lista[ca] == NULL)
				//_cListaReceptores->lista[ca] = 
		}
		return; */
		
	}

	//agregar a la lista de donantes
	
}

cLista<cReceptor>* cINCUCAI::BuscaPosiblesReceptores(cLista<cReceptor>* lista_receptores, cDonante* donante)
{
	/*cLista<cReceptor>* aux1;
	
	string TipoSangreBuscar = donante->Get_TipoSangre();
	aux1=lista_receptores->Filtrar(TipoSangreBuscar);
	int n = 
	for(int i=0;i<)*/
	
}

cINCUCAI::~cINCUCAI()
{
	delete cListaDonantes;
	delete cListaReceptores;
	delete cListaCentrosSalud;
}
