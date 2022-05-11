#include "cPaciente.h"
#include "cCentroSalud.h"

using namespace std;
// constructor de cPaciente
cPaciente::cPaciente(string _nombre, string _fechanac, char _sexo, string _telefono, string _tiposangre) {
	
	this->Nombre = _nombre;
	this->FechaNac = _fechanac;
	this->Sexo = _sexo;
	this->Telefono = _telefono;
	this->TipoSangre = _tiposangre;
	CentroSalud = NULL;
}
/// <summary>
/// en esta funcion le asignamos a un paciente su centro de salud correspondiente
/// </summary>
/// <param name="paciente"></param>
/// <param name="centrosalud"></param>
/// <returns></returns>
bool cPaciente::AsignacionCentroDeSalud(cPaciente* paciente, cCentroSalud* centrosalud) {
	if (paciente->CentroSalud == NULL) {// vemos si el paciente no tiene un centro de slaud ya asignado
		paciente->CentroSalud = centrosalud;// le asignamos el centro de salud correspondiente
		return true;
	}
	return false;// no se lo pudimos asignar
}
/// <summary>
/// desasignamos el centro de salud del paciente
/// </summary>
/// <param name="paciente"></param>
/// <returns></returns>
void cPaciente::DesasignacionCentroDeSalud(cPaciente* paciente) {
	if (paciente->CentroSalud != NULL) {// vemos que el paciente tenga un centro de salud asignado
		paciente->CentroSalud = NULL;// lo desasignamos
	}
}

// destructor de cPaciente
cPaciente::~cPaciente() {
	
	if(CentroSalud !=NULL)
		delete CentroSalud;
};
