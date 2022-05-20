#include "cDonante.h"


cDonante::cDonante(string _nombre, string _fechanac, char _sexo, string _telefono, string _tiposangre) :cPaciente(_nombre, _fechanac, _sexo, _telefono, _tiposangre)
{
	FechaHoraFallecimiento = NULL;
	FechaHoraApertura = NULL;
    listadeorganos = NULL;
}

/// <summary>
/// Le asignamos al donante la fecha y hora de apertura del cuerpo
/// </summary>
/// <param name="donante"></param>
/// <param name="hora"></param>
/// <param name="min"></param>
/// <param name="segundos"></param>
/// <param name="dia"></param>
/// <param name="mes"></param>
/// <param name="anio"></param>
void cDonante::AsignacionFechadeApertura(cDonante* donante, int hora, int min, int segundos, int dia, int mes, int anio) {

	cFechayHora* fecha_hora_apertura= new cFechayHora(0, 0, 0, 0);
	fecha_hora_apertura = fecha_hora_apertura->ObtenerFechayHora(hora, min, segundos, dia, mes, anio);
	if(donante->FechaHoraApertura==NULL)
	donante->FechaHoraApertura = fecha_hora_apertura; //se lo asignamos al atributo del donante
	 

}
/// <summary>
/// Armamos una lista de organos posibles a donar
/// </summary>
/// <param name="donante"></param>
void cDonante::ListaDeOrganosADonar(cDonante* donante) {

	int cant_organos = (rand() %9)+1;// determinamos la cantidad de organos a donar
	cLista<cOrgano>* listaorganos = new cLista<cOrgano>(cant_organos);
	eOrgano n = Corazon;// primer organo a donar
	int cont = 1;// empieza en 1 pq es el valor minimo del enum
	int masminutos = 0;
	cFechayHora* aux=new cFechayHora(0,0,0,0);// creamos la fecha de extraccion

	for (int i = 0; i < cant_organos; i++) {// recorremos la lista de organos para ir llenandola
		aux = aux->ObtenerFechayHora_Extraccion(donante, masminutos);// obtenemos la fecha de extraccion del organo y la guardamos en un auxiliar
		masminutos = masminutos + 5;
		cOrgano* organoaux= new cOrgano(n, aux);// inicializamos el organo 
		listaorganos->lista[i] = organoaux;// asociamos el organo inicializado en la lista de organos del donante
		listaorganos->setter_ca();
		cont++;
		n = switchOrganos(cont);// vamos modificando el valor de cont, que determina los organos a donar
	}
	donante->listadeorganos=listaorganos;
}
/// <summary>
/// switch para seleccionar el n asociado al eOrgano(enum)
/// </summary>
/// <param name="n"></param>
/// <returns></returns>
eOrgano cDonante::switchOrganos(int n) {
	switch (n) {
	case 1: return Corazon;
	case 2: return Higado;
	case 3: return Pancreas;
	case 4: return Huesos;
	case 5: return Rinion;
	case 6: return Pulmones;
	case 7: return Intestino;
	case 8: return Piel;
	case 9: return Corneas;
	}
}
string cDonante::to_string() {

	string sexo;
	if (Sexo == 'M')
		sexo = "Masculino";
	if(Sexo=='F')
		sexo="Femenino";

	string dato;
	dato = "\nNombre: " + Nombre + " Fecha de Nacimineto: " + FechaNac + " Sexo: " + sexo + " Telefono: " + Telefono + " Tipo de Sangre: " + TipoSangre;
	return dato;
}


cDonante::~cDonante() {
	
	if(FechaHoraFallecimiento != NULL)
		delete FechaHoraFallecimiento;
	
	if(FechaHoraApertura != NULL)
		delete FechaHoraApertura;

	if (listadeorganos != NULL)
		delete listadeorganos;
};
