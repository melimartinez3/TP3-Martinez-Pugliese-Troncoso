#include "cFechayHora.h"
#include "cDonante.h"

// cosntructor de fecha y hora
cFechayHora::cFechayHora(time_t _hora, int anio, int mes, int dia) {
	this->hora = _hora;
	this->Anio = anio;
	this->Mes = mes;
	this->Dia = dia;
}

cFechayHora* cFechayHora:: ObtenerFechayHora(int hora, int min,int segundos, int dia, int mes,int anio)
{
	struct tm when = { 0 };
	when.tm_hour = hora;
	when.tm_min = min;
	when.tm_sec = segundos;

	time_t hora_t;
	hora_t = mktime(&when);//convertimos los datos de la hora pasada por parametros en int a time_t

	cFechayHora* fecha_hora=new cFechayHora(hora_t,anio,mes, dia); //inicializamos una variable de fecha y hora con los datos pasados como parametro
	return fecha_hora;
}

cFechayHora* cFechayHora::ObtenerFechayHora_Extraccion(cDonante* donante, int n) {
	time_t segundos_agregar = (time_t)n * 60;
	cFechayHora* aux = new cFechayHora(donante->FechaHoraApertura->get_hora()+segundos_agregar, donante->FechaHoraApertura->get_anio(), donante->FechaHoraApertura->get_mes(), donante->FechaHoraApertura->get_dia());
	return aux;
}

//destructor de fecha y hora
cFechayHora::~cFechayHora(){}
