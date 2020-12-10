#include <iostream>
#include "nodo.h"
#include "lista.h"

using namespace std;

int main() {
  // creo una lista di interi
	cout << "\nLista di interi: " << endl;

	// creo una lista di interi
	Lista<int> lista_interi;
	// inizializzo la posizione sul primo elemento
	Lista<int>::posizione indice_interi = lista_interi.primoLista();

	// inserisco il valore di 5 elementi nella lista
	cout << &indice_interi << endl;
	lista_interi.insLista(10, indice_interi = lista_interi.succLista(indice_interi));
	/*lista_interi.insLista(1, indice_interi = lista_interi.succLista(indice_interi));
	lista_interi.insLista(5, indice_interi = lista_interi.succLista(indice_interi));
	lista_interi.insLista(5, indice_interi = lista_interi.succLista(indice_interi));
	lista_interi.insLista(1, indice_interi = lista_interi.succLista(indice_interi));*/

	lista_interi.stampaLista();
}