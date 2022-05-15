#include "cINCUCAI.h"
#include "cCentroSalud.h"


//constructor 
cINCUCAI::cINCUCAI(cLista<cDonante>* _cListaDonantes, cLista<cReceptor>* _cListaReceptores, cLista<cCentroSalud>* _cListaCentrosSalud)
{
	cListaDonantes = _cListaDonantes;
	cListaReceptor = _cListaReceptores;
	cListaCentrosSalud = _cListaCentrosSalud;
}




void cINCUCAI::RecibirPaciente(cPaciente* paciente, cLista<cDonante>* _cListaDonantes, cLista<cReceptor>* _cListaReceptores,string patente) //Pasarle por parametro las dos listas
{

	cDonante* donante_aux = dynamic_cast<cDonante*>(paciente);
	if (donante_aux == NULL)
	{

		//si es igual a NULL, nuestro paciente es un receptor
		cReceptor* receptor_aux = dynamic_cast<cReceptor*>(paciente);
		this->AgregarPaciente(paciente, 0, _cListaDonantes, _cListaReceptores);
		_cListaReceptores->setter_ca();
		return;
	}

	//si el paciente es un donante:
	donante_aux->ListaDeOrganosADonar(donante_aux);
	
	this->AgregarPaciente(paciente, 1, _cListaDonantes, _cListaReceptores);
	_cListaDonantes->setter_ca();
}

void cINCUCAI::EstudiosYBusquedaParaTrasplante(cPaciente* paciente, string patente) {

	cDonante* donante_aux = dynamic_cast<cDonante*>(paciente);
	
	if (donante_aux == NULL)
	{
		//si es igual a NULL, nuestro paciente es un receptor
		cReceptor* receptor_aux = dynamic_cast<cReceptor*>(paciente);
		cPaciente* paciente2 = this->BuscaPosibleDonante(receptor_aux);
		if (paciente2 == NULL)
			return;
		//ya tenemos al donante asignado para el receptor
		cDonante* donante_elegido = dynamic_cast<cDonante*>(paciente2);
		this->ProtocoloDeTransporte(donante_elegido, receptor_aux, receptor_aux->get_Organo(), patente, 15);
		return;
	}

	//si el paciente es un donante:
	this->Trasplante(donante_aux, patente);
}


void cINCUCAI::AgregarPaciente(cPaciente* paciente, int m, cLista<cDonante>* _cListaDonantes, cLista<cReceptor>* _cListaReceptores)
{
	//si m es 0 es un receptor y si me es 1 es un donante
	if (m == 0)
	{
		cReceptor* receptor_aux = dynamic_cast<cReceptor*>(paciente);

		int ca = cListaReceptor->get_cant_actual();
		int tamtotal = cListaReceptor->get_tamanio_total();
		if (ca < tamtotal) {
			if (cListaReceptor->lista[ca] == NULL)
				cListaReceptor->lista[ca] = receptor_aux;
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
	cLista<cReceptor>* sublista_aux = new cLista<cReceptor>(50);// ponemos 50 porque es la cantidad maxima de pacientes que puede tener (define del main)
	int cont;
	int n = cListaReceptor->get_cant_actual();
	int k = donante->listadeorganos->get_cant_actual();
    int j;
	int p = 0;
	for (int i = 0; i < n; i++) //recorremos toda la lista
	{
		cont = 0;
		for (j = 0; j < k; j++) {
			eOrgano organoreceptor = cListaReceptor->lista[i]->get_Organo();
			eOrgano organodonante = donante->listadeorganos->lista[j]->get_Organo();
			if (organoreceptor == organodonante) //si encontramos al elemento buscado
			{
				sublista_aux->lista[p] = cListaReceptor->lista[i]; //igualamos el elemento[i] de la sublista auxiliar al elemento[i] de la lista original
				sublista_aux->setter_ca();
				p++; //sumamos 1

			}
		}

	}
	if (p == 0)
		return NULL;

	sublista_aux = sublista_aux->Resize(sublista_aux, p);
	return sublista_aux;
	
}

void cINCUCAI::Trasplante(cDonante* donante,string patente) {
	cReceptor* receptor_elegido = NULL;
	int j = donante->listadeorganos->get_cant_actual();
	eOrgano organo;
	int n = 5;
	for (int i = 1; i < j+1; i++) {
		organo = donante->switchOrganos(i);
		 receptor_elegido = this->EleccionReceptor(donante, organo);
		 if (receptor_elegido != NULL) {
			 this->ProtocoloDeTransporte(donante, receptor_elegido, organo, patente, n);
			 n = n + 5;
		 }

	}
}

cLista<cReceptor>* cINCUCAI::ReceptoresPorOrgano(eOrgano _organo, cLista<cReceptor>* lista_receptores)
{
	int n = lista_receptores->get_cant_actual();
	cLista<cReceptor>* aux = new cLista<cReceptor>(n);
	int p = 0;
	for (int i = 0; i < n; i++)
	{
		if (lista_receptores->lista[i]->get_Organo() == _organo)
		{
			aux->lista[p] = lista_receptores->lista[i];
		
			p++;
		}
	}
	OrdenarLista(aux);
	aux->set_CantActual(p);
	aux = aux->Resize(aux, p);
	return aux;
}

void cINCUCAI::OrdenarLista(cLista<cReceptor>* _lista_receptores)
{
	int n = _lista_receptores->get_cant_actual();
	int i, p, k, cont;

	p = 0;

	cLista<cReceptor>* aux_prioridad = new cLista<cReceptor>(n);
	cLista<cReceptor>* aux_sinprioridad = new cLista<cReceptor>(n);

	for (i = 0; i < n; i++)
	{
		if (_lista_receptores->lista[i]->get_Prioridad())
		{
			aux_prioridad->lista[p] = _lista_receptores->lista[i];
			p++;
		}
	}

	aux_prioridad = aux_prioridad->Resize(aux_prioridad, p);
	OrdenamientoPorFecha(aux_prioridad, p);

	k = 0;

	for (i = 0; i < n; i++)
	{
		if (!_lista_receptores->lista[i]->get_Prioridad())
		{
			aux_sinprioridad->lista[p] = _lista_receptores->lista[i];
			p++;
		}
	}
	aux_sinprioridad = aux_sinprioridad->Resize(aux_sinprioridad, p);
	OrdenamientoPorFecha(aux_sinprioridad, p);

	cLista<cReceptor>* aux_total = new cLista<cReceptor>(n);

	for (i = 0; i < p; i++)
	{
		aux_total->lista[i] = aux_prioridad->lista[i];
	}
	cont = 0;
	for (i = p; i < n; i++)
	{
		aux_total->lista[i] = aux_sinprioridad->lista[cont];
		cont++;
	}

}

void cINCUCAI::OrdenamientoPorFecha(cLista<cReceptor>* lista, int n)
{
	int i, j, cont;
	cReceptor* aux = new cReceptor(Corazon, true, true, " "," ", " ", ' '," ", " "); //inicializamos con valores cualquiera para luego igualarlo

	for (i = 0; i < n - 1; i++)
	{
		cont = 0;
		for (j = 0; j < n - 1; j++)
		{
			int primero = lista->lista[j]->get_AnioAgregado() * 10000 + lista->lista[j]->get_MesAgregado() * 1000 + lista->lista[j]->get_DiaAgregado() * 100;
			int segundo = lista->lista[j + 1]->get_AnioAgregado() * 10000 + lista->lista[j + 1]->get_MesAgregado() * 1000 + lista->lista[j + 1]->get_DiaAgregado() * 100;

			if (primero > segundo)
			{
				aux = lista->lista[j];
				lista->lista[j] = lista->lista[j + 1];
				lista->lista[j + 1] = aux;
				cont++;
				
			}
		}

		if (cont == 0)
		{
			break;
		}
	}
}


cReceptor* cINCUCAI::EleccionReceptor(cDonante* donante, eOrgano organo) {
	cLista<cReceptor>* listareceptores = BuscaPosiblesReceptores(donante);
	if (listareceptores == NULL)
		return NULL;
	listareceptores = this->ReceptoresPorOrgano(organo, listareceptores);
	int n = listareceptores->get_cant_actual();
	int pos=0;

	string sangre = donante->Get_TipoSangre();

	for (int i = 0; i < n; i++) {
		
		if (sangre == listareceptores->lista[i]->Get_TipoSangre())
		return listareceptores->lista[i];
	}

	return NULL;
}

void cINCUCAI::ProtocoloDeTransporte(cDonante* donante,cReceptor*receptor,eOrgano organo,string patente,int n) {
	//asignamos vehiculo
	bool ok = donante->CentroSaludd->AsignacionVehiculo(donante, organo, receptor, patente);
	if (!ok)
		return;
	//obtenemos la fecha y hora de extraccion de ese organo a donar
	cOrgano* organo_donar=NULL;
	int j = donante->listadeorganos->get_cant_actual();
	for (int i = 0; i < j; i++) {
		if (donante->listadeorganos->lista[i]->get_Organo() == organo)
		{
			donante->listadeorganos->lista[i]->fechayhora_extraccion->ObtenerFechayHora_Extraccion(donante, n);
			organo_donar = donante->listadeorganos->lista[i];
			break;
		}
	}
	
	organo_donar=donante->listadeorganos->operator-(organo_donar);//quitamos el organo a donar de la lista
	this->Transporte(organo_donar->vehiculo);
	receptor->CentroSaludd->RealizacionDelTrasplante(organo_donar, this, receptor);

}
cPaciente* cINCUCAI::BuscaPosibleDonante(cReceptor* receptor)
{
	cPaciente* paciente = NULL;
	int cont;
	eOrgano organo_buscado = receptor->get_Organo();
	int n = cListaDonantes->get_cant_actual();
	int j;
	int k;


	for (int i = 0; i < n; i++) //recorremos toda la lista
	{
		cont = 0;
		k = cListaDonantes->lista[i]->listadeorganos->get_cant_actual();
		for (j = 0; j < k; j++)
			if (organo_buscado == cListaDonantes->lista[i]->listadeorganos->lista[j]->get_Organo() && cListaDonantes->lista[i]->Get_TipoSangre() == receptor->Get_TipoSangre()) //si encontramos al donante
			{
				paciente = cListaDonantes->lista[i];
				return paciente;
			}

	}

	return paciente;

}

void cINCUCAI::Transporte(cVehiculo* vehiculo) {

	cAmbulancia* ambulancia = dynamic_cast<cAmbulancia*>(vehiculo);
	if (ambulancia != NULL)
	{
		cout << "\nIUIUIUI" << endl;
		cout << "\nLa ambulancia llego a destino" << endl;
	}
	cAvion* avion = dynamic_cast<cAvion*>(vehiculo);
	if (avion != NULL)
	{
		cout << "\nZHOOOOOM" << endl;
		cout << "\nEl avion llego a destino" << endl;
	}
	cHelicoptero* helicoptero = dynamic_cast<cHelicoptero*>(vehiculo);
	if (helicoptero != NULL)
	{
		cout << "\nTACA-TACA-TACA-TACA" << endl;
		cout << "\nEl helicoptero llego a destino" << endl;
	}


}

cINCUCAI::~cINCUCAI()
{
	if (cListaDonantes != NULL)
		delete cListaDonantes;

	if (cListaReceptor != NULL)
		delete cListaReceptor;

	if (cListaCentrosSalud != NULL)
		delete cListaCentrosSalud;
}
