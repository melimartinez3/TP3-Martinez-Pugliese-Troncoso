#pragma once
#include "cDonante.h"
#define _CRT_SECURE_NOWARNINGS


using namespace std;

class cFechayHora {
   
private:
    int Hora;
    int Minutos;
    int Segundos;
    int Dia, Mes, Anio;
public:
    cFechayHora(int hora, int minuto, int segundo, int anio, int mes, int dia);
    ~cFechayHora();

    //declaramos los metodos
    void ObtenerFechayHora_Ablacion(cDonante* donante);

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


