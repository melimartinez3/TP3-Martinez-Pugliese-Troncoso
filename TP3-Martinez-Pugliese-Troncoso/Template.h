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
	// constructor de la lista template
	cLista(int _tamtotal) {
		
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
	void Agregar(T* nuevo) {
		
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
	int Buscar(string busqueda) {

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
	/// Eliminamos un elemento de la lista
	/// </summary>
	void Eliminar() 
	{
		int pos = Buscar(busqueda);

		if (pos == -1) 
			return; //si no se encontro no lo borramos

		delete lista[pos]; //borramos el elemento de la lista
		CantActual--; //restamos 1 a la cantidad actual de la lista

		for (int k = pos; k < CantActual; k++) //hacemos un for a partir de la posicion del elemento eliminado
		{
			lista[k] = lista[k + 1]; //restamos en 1 la posicion de todos los elementos siguientes al elminado
		}
		lista[CantActual] = NULL; //ponemos en NULL la ultima posicion de la lista
		return;
	}

	/// <summary>
	/// Filtramos y retornamos la sublista
	/// </summary>
	/// <param name="parametro"></param>
	/// <returns></returns>
	T* Filtrar(string parametro)
	{
		T* sublista_aux = new T[TamTotal];
		int cont = 0;

		for (int i = 0; i < CantActual; i++) //recorremos toda la lista
		{
			if (*lista[i] == parametro) //si encontramos al elemento buscado
			{
				sublista_aux[i] = lista[i]; //igualamos el elemento[i] de la sublista auxiliar al elemento[i] de la lista original
				cont++; //sumamos 1 al contador 
			}

		}

		T* sublista = new T[cont]; //creamos una sublista del tama�o necesario
		for (int i = 0; i < cont; i++) 
		{
			sublista[i] = sublista_aux[i]; //copiamos los elementos de la sublista auxiliar a la sublista
		}

		return sublista; //retornamos la sublista

	}

	// destructor de la lista template
	~cLista() {
		if(lista!=NULL){
			for (int i = 0; i < CantActual; i++) {
				if (lista[i] != NULL) {
					delete lista[i];
				}
			}
			delete[] lista;
		}
	}
};