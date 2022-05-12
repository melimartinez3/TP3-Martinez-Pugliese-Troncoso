#include "cListaReceptores.h"
#include "cReceptor.h"


cListaReceptores::cListaReceptores(int tamtotal):cLista<cReceptor>(tamtotal)
{
}

cListaReceptores* cListaReceptores::FiltrarNuevaLista(cLista<cOrgano>* _lista_organos) {

	cListaReceptores* sublista_aux = new cListaReceptores(TAM);
	int cont = 0;

	for (int i = 0; i < TAM; i++) //recorremos toda la lista
	{
		if ([i] == parametro) //si encontramos al elemento buscado
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