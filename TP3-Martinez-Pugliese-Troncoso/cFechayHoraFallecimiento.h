#pragma once
#include "cDonante.h"
#define _CRT_SECURE_NOWARNINGS


using namespace std;

class cFechayHoraFallecimiento {
   
private:
    int Hora;
    int Minutos;
    int Segundos;
    int Dia, Mes, Anio;
public:
    cFechayHoraFallecimiento(int hora, int minuto, int segundo, int anio, int mes, int dia);
    ~cFechayHoraFallecimiento();

    //declaramos los metodos
    void obtenerFechayHora_Fallecimiento(cDonante* donante);

    //declaramos e implemnetamos los gets
    int get_dia() {
        return this->Dia;
    };
    int get_mes() {
        return this->Mes;
    };
    int get_anio() {
        return this->Anio;
    };
    int get_hora() {
        return this->Hora;
    };
    int get_min() {
        return this->Minutos;
    };
    int get_segundos() {
        return this->Segundos;
    };
};


