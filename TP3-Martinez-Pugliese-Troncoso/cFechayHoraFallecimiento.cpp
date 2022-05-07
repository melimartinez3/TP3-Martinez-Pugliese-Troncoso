#include "cFechayHoraFallecimiento.h"
// cosntructor de fecha y hora
cFechayHoraFallecimiento::cFechayHoraFallecimiento(int hora, int minuto, int segundo, int anio, int mes, int dia) {
	this->Hora = hora;
	this->Minutos = minuto;
	this->Segundos = segundo;
	this->Anio = anio;
	this->Mes = mes;
	this->Dia = dia;

}

//destructor de fecha y hora
cFechayHoraFallecimiento::~cFechayHoraFallecimiento(){}
