#include "cReceptor.h"


cReceptor::cReceptor(eOrgano _organo, string _fecha_agregado, bool _prioridad, bool _estado, string _patologia, string _nombre, string _fechanac, char _sexo, string _telefono, string _tiposangre) :cPaciente(_nombre, _fechanac, _sexo, _telefono, _tiposangre) {
	this->Organo = _organo;
	this->FechaAgregado = _fecha_agregado;
	this->Prioridad = _prioridad;
	this->Estado = _estado;
	this->Patologia = _patologia;
}
