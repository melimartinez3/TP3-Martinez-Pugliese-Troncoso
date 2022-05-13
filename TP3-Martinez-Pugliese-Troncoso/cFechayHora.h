#pragma once
class cDonante;
#include <time.h>
#define _CRT_SECURE_NOWARNINGS


using namespace std;

class cFechayHora {
   
private:
    time_t hora;
    int Dia, Mes, Anio;
public:
    cFechayHora(time_t _hora, int anio, int mes, int dia);
    ~cFechayHora();

    //declaramos los metodos
    void ObtenerFechayHora_Apertura(cDonante* donante, int hora, int min, int segundos, int dia, int mes, int anio);
    cFechayHora* ObtenerFechayHora_Extraccion(cDonante* donante, int n);

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
    time_t get_hora() {
        return this->hora;
    };
};


