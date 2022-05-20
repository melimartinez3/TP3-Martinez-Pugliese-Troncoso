#include "cReceptor.h"


cReceptor::cReceptor(eOrgano _organo, bool _prioridad, bool _estado, string _patologia, string _nombre, string _fechanac, char _sexo, string _telefono, string _tiposangre) :cPaciente(_nombre, _fechanac, _sexo, _telefono, _tiposangre) {
	this->Organo = _organo;
	this->FechaAgregado = NULL;
	this->Prioridad = _prioridad;
	this->Estado = _estado;
	this->Patologia = _patologia;
}

/// <summary>
/// Obtenemos la fecha y hora en la que se agrega al receptor a la lista
/// </summary>
/// <param name="receptor"></param>
/// <param name="hora"></param>
/// <param name="min"></param>
/// <param name="segundos"></param>
/// <param name="dia"></param>
/// <param name="mes"></param>
/// <param name="anio"></param>
void cReceptor::AsignacionFechaLLegda(cReceptor* receptor, int dia, int mes, int anio) {
	cFechayHora* fecha_hora_llegada = new cFechayHora(0, 0, 0, 0);// inicializamos la fecha y hora por defecto
	fecha_hora_llegada = fecha_hora_llegada->ObtenerFechayHora(dia, mes, anio);// obtenemos la fecha y hora 
	if (receptor->FechaAgregado == NULL)
		receptor->FechaAgregado = fecha_hora_llegada; //se lo asignamos al atributo del receptor

}

string cReceptor::PrioridadDelReceptor(cReceptor* receptor, cLista<cReceptor>* listadereceptores) {

	int n = listadereceptores->get_cant_actual();
	string prioridad;
	for (int i = 0; i < n; i++) {

		if (listadereceptores->lista[i] == receptor)
		{
			bool ok = receptor->get_Prioridad();
			if (ok)
			{
				prioridad = "Prioridad Absoluta";
				return prioridad;
			}
			else {
				prioridad = "Sin Prioridad";
					return prioridad;
			}
				
		}
	}
	prioridad = "Error";//no se encontro al receptor
	return prioridad;
	
}

string cReceptor::to_string() {
	
	string sexo;
	string organo;
	string prioridad;
	string estado;
	switch (Organo) {
	case 1: {organo = "Corazon";
		break; }
	case 2: {organo = "Higado";
		break; }
	case 3: { organo = "Pancreas";
		break; }
	case 4: { organo = "Huesos";
		break; }
	case 5: {organo = "Rinion";
		break; }
	case 6: {organo = "Pulmones";
		break; }
	case 7: {organo = "Intestino";
		break; }
	case 8: {organo = "Piel";
		break; }
	case 9: { organo = "Corneas";
		break; }
	}

	if (Prioridad)
		prioridad = "Absoluta";
	if (!Prioridad)
		prioridad = "Sin Prioridad";
	if (Estado)
			estado = "Estable";
	if (!Estado)
		estado = "Inestable";
	if (Sexo == 'M')
		sexo = "Masculino";
	if (Sexo == 'F')
		sexo = "Femenino";
	string dato;
	dato = "\nNombre: " + Nombre + " Fecha de Nacimineto: " + FechaNac + " Sexo: " + sexo + " Telefono: " + Telefono + " Tipo de Sangre: " + TipoSangre + " Organo: " + organo + " Prioridad " + prioridad + " Estado: " + estado;

	return dato;
}


cReceptor::~cReceptor() {};
