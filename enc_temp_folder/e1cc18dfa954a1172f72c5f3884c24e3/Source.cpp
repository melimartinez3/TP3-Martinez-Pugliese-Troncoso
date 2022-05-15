#include <iostream>
#include "cTemplate.h"
#include "cCentroSalud.h"

#define TAM 50

int main() {
	srand(time(NULL));

	// declaramos las variables dinamicas
	cPaciente* paciente1 = NULL;
	cDonante* donante1=new cDonante("Pepe Argento", "20/10/1973", 'M', "1124861020", "B+");
	paciente1 = donante1;

	cPaciente* paciente2=NULL;
	cReceptor*receptor1 = new cReceptor(Corazon,true,true,"Ataque Cardiaco","Moni Argento", "8 / 1 / 1978", 'F', "1194961088", "B+");
	paciente2 = receptor1;

	cPaciente* paciente3 = NULL;
	cDonante* donante2 = new cDonante("Coqui Argento", "7/6/2002", 'M', "1124868907", "A+");
	paciente3 = donante2;

	cPaciente* paciente4 = NULL;
	cReceptor* receptor2 = new cReceptor(Rinion, true, false, "Rinionitis", "Paola Argento", "22 / 10 / 2000", 'F', "1194967654", "A+");
	paciente4 = receptor2;

	cCentroSalud* centrodesalud1 = new cCentroSalud("centrito4", "Juramento 2556", "Buenos Aires", "Buenos Aires", "46583226");
	cCentroSalud* centrodesalud2 = new cCentroSalud("centrito5", "Cabildo 2856", "Buenos Aires", "Buenos Aires", "46583226");

	cLista<cDonante>* cListaDonante = new cLista<cDonante>(TAM);
	cLista<cReceptor>* cListaReceptor = new cLista<cReceptor>(TAM);
	cLista<cCentroSalud>* cListaCentroSalud = new cLista<cCentroSalud>(TAM);

	cINCUCAI* incucai = new cINCUCAI(cListaDonante, cListaReceptor, cListaCentroSalud);

	//obtenemos la fecha y hora de falleciicmiento
	donante1->FechaHoraFallecimiento=donante1->FechaHoraFallecimiento->ObtenerFechayHora(13, 18, 13, 14, 5, 2022);
	donante2->FechaHoraFallecimiento=donante2->FechaHoraFallecimiento->ObtenerFechayHora(19, 16, 20, 14, 5, 2002);

	//obtenemos la fecha y hora de apertura del cuerpo
	donante1->FechaHoraApertura = donante1->FechaHoraApertura->ObtenerFechayHora(13, 27, 45, 14, 5, 2022);
	donante2->FechaHoraApertura = donante1->FechaHoraApertura->ObtenerFechayHora(19, 56, 12, 14, 5, 2022);

	// asignamos y desasignamos el centro de salud del paciente 1
	bool ok=paciente1->AsignacionCentroDeSalud(paciente1, centrodesalud1);
	if (!ok) {
		cout << "El paciente ya tenia un centro asignado" << endl;
	}
	 ok = paciente2->AsignacionCentroDeSalud(paciente2, centrodesalud2);
	if (!ok) {
		cout << "El paciente ya tenia un centro asignado" << endl;
	}
	ok = paciente3->AsignacionCentroDeSalud(paciente3, centrodesalud1);
	if (!ok) {
		cout << "El paciente ya tenia un centro asignado" << endl;
	}
	ok = paciente4->AsignacionCentroDeSalud(paciente4, centrodesalud2);
	if (!ok) {
		cout << "El paciente ya tenia un centro asignado" << endl;
	}

	//agregamos los pacientes a las listas
	incucai->RecibirPaciente(paciente1, cListaDonante, cListaReceptor, "AEI789");
	incucai->RecibirPaciente(paciente2, cListaDonante, cListaReceptor, "ARE986");
	incucai->RecibirPaciente(paciente3, cListaDonante, cListaReceptor, "ABC907");
	incucai->RecibirPaciente(paciente4, cListaDonante, cListaReceptor, "AKL996");
	//hacer el trasplante 
	//incucai->EstudiosYBusquedaParaTrasplante(paciente1, "AEI789");
	incucai->EstudiosYBusquedaParaTrasplante(paciente3, "ABC907");


	paciente1->DesasignacionCentroDeSalud(paciente1);
	paciente2->DesasignacionCentroDeSalud(paciente2);
	

	



	// eliminamos la memoria dinamica del main
	delete paciente1;
	delete paciente2;
	delete paciente3;
	delete paciente4;
	delete centrodesalud1;
	delete centrodesalud2;
	delete cListaCentroSalud;
	delete cListaDonante;
	delete cListaReceptor;
	delete incucai;
}