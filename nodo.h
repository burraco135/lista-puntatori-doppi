#ifndef _NODO_H
#define _NODO_H

#include <iostream>
#include <stdlib.h>
using namespace std;

template<class T>
class Nodo {
	public:
		typedef T tipoelem;

		Nodo(); // costruttore
		Nodo(const T& elemento);

		// operatori
		void setElemento(tipoelem a);
		tipoelem getElemento() const;
		void setSucc(Nodo*);
		Nodo* getSucc();
		void setPrec(Nodo*);
		Nodo* getPrec();
		bool operator==(Nodo*);
	
	private:
		tipoelem elemento;
		Nodo* succ;
		Nodo* prec;
};

// ----- Implementazione classe Nodo | Costruttore ----- //
template<class T>
Nodo<T>::Nodo() { }

// ----- Implementazione classe Nodo | Costruttore copia ----- 
template<class T>
Nodo<T>::Nodo(const T& elemento) { this->elemento = elemento; }

// ----- Implementazione classe Nodo | Operatori ----- //
template<class T>
void Nodo<T>::setElemento(tipoelem a) { elemento = a; }

template<class T>
typename Nodo<T>::tipoelem Nodo<T>::getElemento() const { return elemento; }

template<class T>
void Nodo<T>::setSucc(Nodo* p) { succ = p; }

template<class T>
typename Nodo<T>::Nodo* Nodo<T>::getSucc() { return succ; }

template<class T>
void Nodo<T>::setPrec(Nodo* p) { prec = p; }

template<class T>
typename Nodo<T>::Nodo* Nodo<T>::getPrec() { return prec; }

template<class T>
bool Nodo<T>::operator==(Nodo* p) {
	return ( &getElemento == p->getElemento );
}

#endif //_NODO_H