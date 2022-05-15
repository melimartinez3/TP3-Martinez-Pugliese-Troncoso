#pragma once
#include<stdio.h>
#include<string>
#include <stdlib.h>

using namespace std;

template <class T>
class cLista {
private:
	T** lista;
	int CantActual;
	int TamTotal;

public:
	friend class cINCUCAI;
	friend class cDonante;
	friend class cReceptor;
	friend class cCentroSalud;
	

	cLista(int _tamtotal);
	void operator+(T* nuevo);
	int	Buscar(string busqueda);
	T* operator-(T* aeliminar);
	cLista<T>* Filtrar(string parametro);	
	cLista<T>* Resize(cLista<T>* array, int n);

	~cLista();

	void setter_ca();

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
	this->CantActual = this->CantActual+1;
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
		else
			throw new exception("\nNo se puede agregar a la lista");
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
			return - 1; //si no lo encontramos retornamos -1
		}

	}

	/// <summary>
	/// quitamos un elemento de la lista
	/// </summary>
	/*template <class T>
	T* cLista<T>::operator-(string busqueda){
		T* aux = NULL;
		int pos = Buscar(busqueda);

		if (pos == -1) 
			return aux; //si no se encontro no lo borramos

		
		aux = lista[pos];
		CantActual--;
		for (unsigned int j = pos; j < CantActual; j++)
		{
			lista[j] = lista[j + 1];
		}
		lista[CantActual] = NULL;
		return aux;
	}*/

	template <class T>
	T* cLista<T>::operator-(T* aeliminar) {
		T* aux = NULL;
		int pos=-1;

		for (int i = 0; i < CantActual; i++) {
			if (lista[i] == aeliminar)
			{
				aux = lista[i];
				pos = i;
			}
		}

		if (pos == -1)
			return NULL;

		CantActual--;
		for ( int j = pos; j < CantActual; j++)
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

	template <class T>
	cLista<T>* cLista<T>::Resize(cLista<T>* array, int n)
	{
		cLista<T>* nuevo = new cLista<T>(n);
		for (int i = 0; i < n; i++)
		{
			nuevo[i] = array[i];
		}
		return nuevo;
	}
	
	// destructor de la lista template
	template <class T>
	cLista<T>::~cLista() {
		if(lista!=NULL){
			for (int i = 0; i < CantActual; i++) {
				if (lista[i] != NULL) {
					delete lista[i];
				}
			}
			delete[] lista;
		}
	}
