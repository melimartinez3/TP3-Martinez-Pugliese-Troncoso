#include "cDonante.h"
#include "cOrgano.h"

cDonante::cDonante(string _nombre, string _fechanac, char _sexo, string _telefono, string _tiposangre) :cPaciente(_nombre, _fechanac, _sexo, _telefono, _tiposangre)
{
	FechaHoraFallecimiento = NULL;
	FechaHoraApertura = NULL;
    listadeorganos = NULL;
}

void cDonante::ListaDeOrganosADonar(cDonante* donante) {

	int cant_organos = rand() % 10;
	cLista<cOrgano>* listaorganos = new cLista<cOrgano>(cant_organos);
	eOrgano n = Corazon;
	int masminutos = 0;
	cFechayHora* aux=new cFechayHora(0,0,0,0);

	for (int i = 0; i < cant_organos; i++) {
		aux = aux->ObtenerFechayHora_Extraccion(donante, masminutos);
		masminutos = masminutos + 5;
		cOrgano* organoaux= new cOrgano(n, aux);
		listaorganos->lista[i] = organoaux;
		//sumarle uno a corazon, al enum, para pasarele dif organos 
	}

}

cDonante::~cDonante() {
	
	if(FechaHoraFallecimiento != NULL)
		delete FechaHoraFallecimiento;
	
	if(FechaHoraApertura != NULL)
		delete FechaHoraApertura;
};
