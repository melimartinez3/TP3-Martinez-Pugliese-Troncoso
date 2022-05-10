#include "cFechayHora.h"
#include "cDonante.h"
// cosntructor de fecha y hora
cFechayHora::cFechayHora(time_t _hora, int anio, int mes, int dia) {
	this->hora = _hora;
	this->Anio = anio;
	this->Mes = mes;
	this->Dia = dia;
}

void cFechayHora:: ObtenerFechayHora_Apertura(cDonante* donante,int hora, int min,int segundos, int dia, int mes,int anio)
{
	struct tm when = { 0 };
	when.tm_hour = hora;
	when.tm_min = min;
	when.tm_sec = segundos;

	time_t hora_t;
	hora_t = mktime(&when);//convertimos los datos de la hora pasada por parametros en int a time_t

	cFechayHora* fecha_hora_apertura=new cFechayHora(hora_t,dia,mes,anio); //inicializamos una variable de fecha y hora con los datos pasados como parametro
	donante->FechaHoraApertura = fecha_hora_apertura; //se lo asignamos al atributo del donante 
}

//destructor de fecha y hora
cFechayHora::~cFechayHora(){}
