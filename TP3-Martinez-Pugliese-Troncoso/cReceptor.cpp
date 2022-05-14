#include "cReceptor.h"


cReceptor::cReceptor(eOrgano _organo, bool _prioridad, bool _estado, string _patologia, string _nombre, string _fechanac, char _sexo, string _telefono, string _tiposangre) :cPaciente(_nombre, _fechanac, _sexo, _telefono, _tiposangre) {
	this->Organo = _organo;
	this->FechaAgregado = NULL;
	this->Prioridad = _prioridad;
	this->Estado = _estado;
	this->Patologia = _patologia;
	CentroSalud = NULL;
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
void cReceptor::AsignacionFechaLLegda(cReceptor* receptor,int hora,int min, int segundos, int dia, int mes, int anio) {
	cFechayHora* fecha_hora_llegada = new cFechayHora(0, 0, 0, 0);// inicializamos la fecha y hora por defecto
	fecha_hora_llegada = fecha_hora_llegada->ObtenerFechayHora(hora, min, segundos, dia, mes, anio);// obtenemos la fecha y hora 
	if (receptor->FechaAgregado == NULL)
		receptor->FechaAgregado = fecha_hora_llegada; //se lo asignamos al atributo del receptor

}



cReceptor::~cReceptor() {};
