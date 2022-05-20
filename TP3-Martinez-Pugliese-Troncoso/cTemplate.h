#pragma once
#include<stdio.h>
#include<string>
#include <stdlib.h>

using namespace std;

template <class T>
class cLista {
private:

	int CantActual;
	int TamTotal;

public:
	T** lista;
	friend class cINCUCAI;
	friend class cDonante;
	friend class cReceptor;
	friend class cCentroSalud;


	cLista(int _tamtotal);
	void operator+(T* nuevo);
	int	Buscar(string busqueda);
	T* operator-(T* aeliminar);
	cLista<T>* Filtrar(string parametro);
	//friend ostream& operator<< (ostream &out,  T &objeto);
	friend ostream& operator<< <>(ostream& out, const cLista<T>&);
	T* operator[](string busqueda);



	~cLista();

	void setter_ca();// setter de cant actual +1

	void setter_ca_menos1() {
		this->CantActual = this->CantActual - 1;
	}

	int get_cant_actual() {
		return this->CantActual;
	}
	int get_tamanio_total() {
		return this->TamTotal;
	}

	void set_CantActual(int cantactual) {
		this->CantActual = cantactual;
	}

};

template <class T>
void cLista<T>::setter_ca() {
	this->CantActual = this->CantActual + 1;
}

// constructor de la lista template
template <class T>
cLista<T>::cLista(int _tamtotal) {

	this->CantActual = 0;
	this->TamTotal = _tamtotal;
	lista = new T * [TamTotal];
	for (int i = 0; i < TamTotal; i++) {
		lista[i] = NULL;
	}
}




/// <summary>
/// Agregamos a la lista un nuevo elemento
/// </summary>
/// <param name="nuevo"></param>
template <class T>
void cLista<T>::operator+(T* nuevo) {

	if (CantActual < TamTotal) {// verificamos que la cantidad actual sea menor a la maxima
		lista[CantActual++] = nuevo;// lo agregamos a la lista
	}

}

/// <summary>
/// Buscamos un elemento de la lista y retornamos su posicion
/// </summary>
/// <param name="busqueda"></param>
/// <returns></returns>
template <class T>
int	cLista<T>::Buscar(string busqueda) {

	int i;

	for (i = 0; i < CantActual; i++) //recorremos toda la lista
	{
		if (*lista[i] == busqueda) //si encontramos al elemento buscado
			return i; //devolvemos su posicion
	}

	if (i == CantActual)
	{
		return -1; //si no lo encontramos retornamos -1
	}
}

/// <summary>
/// Operator []
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="busqueda"></param>
/// <returns></returns>
template <class T>
T* cLista<T>::operator[](string busqueda)
{
	return Buscar(busqueda);
}

/// <summary>
/// esta funcion quita de la lista un elemento
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="aeliminar"></param>
/// <returns></returns>
template <class T>
T* cLista<T>::operator-(T* aeliminar) {
	T* aux = NULL;
	int pos = -1;

	for (int i = 0; i < CantActual; i++) {
		if (lista[i] == aeliminar)
		{
			aux = lista[i];
			pos = i;
		}
	}

	if (pos == -1)
		return NULL;

	this->setter_ca_menos1();
	for (int j = pos; j < CantActual; j++)
	{
		lista[j] = lista[j + 1];
	}

	lista[CantActual] = NULL;

	return aux;
}


/// <summary>
/// Filtramos y retornamos la sublista
/// </summary>
/// <param name="parametro"></param>
/// <returns></returns>
template <class T>
cLista<T>* cLista<T>::Filtrar(string parametro)
{
	cLista<T>* sublista_aux = new T[TamTotal];
	int cont = 0;

	for (int i = 0; i < CantActual; i++) //recorremos toda la lista
	{
		if (*lista[i] == parametro) //si encontramos al elemento buscado
		{
			sublista_aux[i] = lista[i]; //igualamos el elemento[i] de la sublista auxiliar al elemento[i] de la lista original
			cont++; //sumamos 1 al contador 
		}

	}

	T* sublista = new T[cont]; //creamos una sublista del tamaño necesario
	for (int i = 0; i < cont; i++)
	{
		sublista[i] = sublista_aux[i]; //copiamos los elementos de la sublista auxiliar a la sublista
	}

	return sublista; //retornamos la sublista

}

/// <summary>
/// operador de flujo
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="out"></param>
/// <param name="clase"></param>
/// <returns></returns>
template <class T>
ostream& operator<< <>(ostream& out, const cLista<T>& List) {

	for (int i = 0; i < List.CantActual; i++)
	{
		out << List.lista[i]->to_string() << endl;
	}

	return out;
}


// destructor de la lista template
template <class T>
cLista<T>::~cLista() {
	if (lista != NULL) {
		for (int i = 0; i < CantActual; i++) {
			if (lista[i] != NULL) {
				delete lista[i];
			}
		}
		delete[] lista;
	}
}
