#ifndef _LISTA_H
#define _LISTA_H

#include "nodo.h"
#include <iostream>

using namespace std;

template<class T>
class Lista {
	public:
		Lista(); // costruttore
		Lista(const Lista<T>&); // costruttore copia
		~Lista(); // distruttore

		// posizione
		typedef Nodo<T>* posizione;

		// operatori
		void creaLista();
		bool listaVuota();
		tipoelem leggiLista(posizione);
		void scriviLista(tipoelem, posizione);
		posizione primoLista();
		bool fineLista(posizione);
		posizione succLista(posizione);
		posizione precLista(posizione);
		void insLista(tipoelem, posizione);
		void cancLista(posizione);

		void stampaLista();

	private:
		// lista è una struttura di puntatori agli oggetti Nodo
		posizione lista;
};

// ----- Implementazione classe Lista | Costruttore ----- //
template <class T>
Lista<T>::Lista() { creaLista(); }

// ----- Implementazione classe Lista | Costruttore copia ----- //
template <class T>
Lista<T>::Lista(const Lista<T>& l) { } //FIXME

// ----- Implementazione classe Lista | Distruttore ----- //
template <class T>
Lista<T>::~Lista() {
	while (lista->getSucc() != lista->getPrec()) {
		cancLista(lista->getSucc());
	}

	delete lista;
}

// ----- Implementazione classe Lista | Operatori ----- //
template <class T>
void Lista<T>::creaLista() {
	tipoelem ElementoNullo;
	lista = new Nodo;
	lista->setElemento(ElementoNullo); // inserisce l'elemento
	lista->setSucc(lista); // il nodo precedente del corrente è se stesso
	lista->setPrec(lista); // il nodo precedente del corrente è se stesso
}

template <class T>
bool Lista<T>::listaVuota() {
	return ( lista->getSucc() == lista && lista->getPrec() == lista );
}

template <class T>
typename Lista<T>::tipoelem Lista<T>::leggiLista(posizione p) {
	return ( p->getElemento() );
}

template <class T>
void Lista<T>::scriviLista(tipoelem a, posizione p) {
	p->setElemento(a);
}

template <class T>
typename Lista<T>::posizione Lista<T>::primoLista() {
	return ( lista->getSucc() );
}

template <class T>
bool Lista<T>::fineLista(posizione p) {
	return ( p == lista; );
}

template <class T>
typename Lista<T>::posizione Lista<T>::succLista(posizione p) {
	return ( p->getSucc() );
}

template <class T>
typename Lista<T>::posizione Lista<T>::precLista(posizione p) {
	return ( p->getPrec() );
}

template <class T>
void Lista<T>::insLista(tipoelem a, posizione p) {
	temp = new Nodo; // creo il nodo per l'elemento da inserire
	temp->setElemento(a); // inserisco il valore nel nodo

	temp->setPrec(p->getPrec()); // collega il nuovo nodo
	temp->setSucc(p);	// a quello precedente e a quello puntato da p

	( p->getPrec() )->setSucc(temp); // collega il nodo puntato da p
	p->setPrec(temp); // e quello successivo a temp

	p = temp; // aggiorna p
}

template <class T>
void Lista<T>::cancLista(posizione p) {
	Lista<T>::posizione temp;
 	temp = p;
 	
 	(p->getSucc())->setPrec(p->getPrec()); // collega il nodo successivo a p a quello precedente a p
 	
 	(p->getPrec())->setSucc(p->getSucc()); // collega il nodo precedente a p a quello successivo a p

 	p = p->getSucc(); // dealloca l'area di memoria puntata da temp
 	
 	delete temp;
}

template <class T>
void Lista<T>::stampaLista() {
	Nodo<T>* indice = primoLista();

	while ( !fineLista(indice) ) {
		cout << leggiLista(indice);

		if ( !fineLista(succLista(indice)) ) {
			cout << endl;
		}

		indice = succLista(indice);
	}

	cout << endl;
}

#endif //_LISTA_H