#include "cFechayHora.h"

// cosntructor de fecha y hora
cFechayHora::cFechayHora(int hora, int minuto, int segundo, int anio, int mes, int dia) {
	this->Hora = hora;
	this->Minutos = minuto;
	this->Segundos = segundo;
	this->Anio = anio;
	this->Mes = mes;
	this->Dia = dia;

}

void cFechayHora:: ObtenerFechayHora_Ablacion(cDonante* donante)
{
	time_t rawtime;
	struct tm timeinfo;
	time(&rawtime);
	localtime_s(&timeinfo, &rawtime);
	//obtenemos la fecha y hora deablacion y la inicializamos en una variable auxiliar con los datos sacados de la fecha y hora del momento                                              
	cFechayHora* fecha_hora_ablacion = new cFechayHora(timeinfo.tm_hour, timeinfo.tm_min, timeinfo.tm_sec, timeinfo.tm_year - 100, timeinfo.tm_mon, timeinfo.tm_mday);

	donante->FechaHoraAblacion = fecha_hora_ablacion; //se lo asignamos al atributo del donante 
}

//destructor de fecha y hora
cFechayHora::~cFechayHora(){}
