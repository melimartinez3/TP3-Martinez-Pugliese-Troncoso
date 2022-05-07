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
	void Buscar() {

	}
	void Eliminar() {

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