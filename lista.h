#ifndef _LISTA_H
#define _LISTA_H

#include "nodo.h"
#include <iostream>
#include <stdlib.h>

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
		bool listaVuota() const;
		typename Nodo<T>::tipoelem leggiLista(posizione) const;
		void scriviLista(typename Nodo<T>::tipoelem, posizione);
		posizione primoLista() const;
		bool fineLista(posizione) const;
		posizione succLista(posizione) const;
		posizione precLista(posizione) const;
		void insLista(typename Nodo<T>::tipoelem, posizione);
		void cancLista(posizione);

		void stampaLista() const;

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
	typename Nodo<T>::tipoelem ElementoNullo;
	lista = new class Nodo<T>::Nodo;
	lista->setElemento(ElementoNullo); // inserisce l'elemento
	lista->setSucc(lista); // il nodo precedente del corrente è se stesso
	lista->setPrec(lista); // il nodo precedente del corrente è se stesso
}

template <class T>
bool Lista<T>::listaVuota() const {
	return ( lista->getSucc() == lista && lista->getPrec() == lista );
}

template <class T>
typename Nodo<T>::tipoelem Lista<T>::leggiLista(posizione p) const {
	return ( p->getElemento() );
}

template <class T>
void Lista<T>::scriviLista(typename Nodo<T>::tipoelem a, posizione p) {
	p->setElemento(a);
}

template <class T>
typename Lista<T>::posizione Lista<T>::primoLista() const {
	return ( lista->getSucc() );
}

template <class T>
bool Lista<T>::fineLista(posizione p) const {
	return ( p == lista );
}

template <class T>
typename Lista<T>::posizione Lista<T>::succLista(posizione p) const {
	return ( p->getSucc() );
}

template <class T>
typename Lista<T>::posizione Lista<T>::precLista(posizione p) const {
	return ( p->getPrec() );
}

template <class T>
void Lista<T>::insLista(typename Nodo<T>::tipoelem a, posizione p) {
	
  Nodo<T>* nuovo_nodo;
	nuovo_nodo = new Nodo<T>; // creo il nodo per l'elemento da inserire
	nuovo_nodo->setElemento(a); // inserisco il valore nel nodo

	nuovo_nodo->setPrec(p->getPrec()); // collega il nuovo nodo
	nuovo_nodo->setSucc(p);	// a quello precedente e a quello puntato da p

	( p->getPrec() )->setSucc(nuovo_nodo); // collega il nodo puntato da p
	p->setPrec(nuovo_nodo); // e quello successivo a nuovo_nodo

	p = nuovo_nodo; // aggiorna p
}

/*

1) creo un nuovo nodo
2) imposto l'elemento da inserire nel nuovo nodo
3) collego il nuovo nodo al precedente di p 		nuovo_nodo->setPrec(p->getPrec())
4) collego il nuovo nodo al successivo p 				nuovo_nodo->setSucc(p)

if p == lista 
	while !fineLista


[nuovo_nodo] [succ] -> 
						 [prec] -> 
						 [elemento] -> elemento nuovo_nodo

[nodo_in_posizione_p-1] [succ] -> puntatore a p
												[prec] -> puntatore a p-2
												[elemento] -> elemento_p-1

[nuovo_nodo] [succ] -> p
						 [prec] -> p-1
						 [elemento] -> elemento nuovo_nodo

[nodo_in_posizione_(ex p)p+1] [succ] -> nodo_in_posizione_p+1 -----
											[prec] -> nodo_in_posizione_p-1 -----	
											[elemento] -> elemento_p				----- elemento nuovo_nodo

[nodo_in_posizione_p+2] [succ] -> nodo in posizione p+2 
												[prec] -> nodo in posizione p+1 (ex p)
												[elemento] -> elemento_p+2
*/

template <class T>
void Lista<T>::cancLista(posizione p) {
	Lista<T>::posizione temp_posizione;
 	temp_posizione = p;
 	
 	(p->getSucc())->setPrec(p->getPrec()); // collega il nodo successivo a p a quello precedente a p
 	
 	(p->getPrec())->setSucc(p->getSucc()); // collega il nodo precedente a p a quello successivo a p
  
 	p = p->getSucc(); // dealloca l'area di memoria puntata da temp
 	
 	delete temp_posizione;
}

template <class T>
void Lista<T>::stampaLista() const {
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