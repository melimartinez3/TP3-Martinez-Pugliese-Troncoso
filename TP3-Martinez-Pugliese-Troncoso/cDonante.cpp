#include "cDonante.h"
//#include "cOrgano.h"

cDonante::cDonante(string _nombre, string _fechanac, char _sexo, string _telefono, string _tiposangre) :cPaciente(_nombre, _fechanac, _sexo, _telefono, _tiposangre)
{
	FechaHoraFallecimiento = NULL;
	FechaHoraApertura = NULL;
    listadeorganos = NULL;
}

void cDonante::ListaDeOrganosADonar() {

	int cant_organos = rand() % 10;
	cLista<cOrgano>* listaorganos = new cLista<cOrgano>(cant_organos);
	int n = 0;
	for (int i = 0; i < cant_organos; i++) {
		
		listaorganos->lista[i]=new cOrgano()
	}

}

cDonante::~cDonante() {
	
	if(FechaHoraFallecimiento != NULL)
		delete FechaHoraFallecimiento;
	
	if(FechaHoraApertura != NULL)
		delete FechaHoraApertura;
};
