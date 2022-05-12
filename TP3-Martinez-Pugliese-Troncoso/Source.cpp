#include <iostream>
#include "cDonante.h"
#include "cReceptor.h"
#include "cTemplate.h"
#include "cINCUCAI.h"

#define TAM 50

int main() {
	srand(time(NULL));
	// declaramos las variables dinamicas
	cPaciente* paciente1 = new cPaciente("Pepe Argento", "20/10/1986", 'M', "1124861020", "B+");
	cCentroSalud* centrodesalud1 = new cCentroSalud("centrito4", "Juramento 2556", "Buenos Aires", "Buenos Aires", "46583226");
	/*cLista<cDonante>* cListaDonante = new cLista<cDonante>(TAM);
	cLista<cReceptor> cListaReceptor(TAM);
	cLista<cCentroSalud> cListaCentroSalud(TAM);
	cINCUCAI* incucai = new cINCUCAI(cListaDonante, cListaReceptor, cListaCentroSalud);*/
		
	// asignamos y desasignamos el centro de salud del paciente 1
	bool ok=paciente1->AsignacionCentroDeSalud(paciente1, centrodesalud1);
	if (!ok) {
		cout << "El paciente ya tenia un centro asignado" << endl;
	}
	paciente1->DesasignacionCentroDeSalud(paciente1);
	
	
	cLista<cDonante> cLista(TAM);

	



	// eliminamos la memoria dinamica del main
	delete paciente1;
	delete centrodesalud1;
}