#include "libro.h"
#include <iostream>

using namespace std;

Libro::Libro() { titolo = ""; } // costruttore default

Libro::Libro(string t) { setTitolo(t); } // costruttore per utente

void Libro::setTitolo(string t) { titolo = t; }  // per inserire un titolo

string Libro::getTitolo() const { return(titolo); } // per stampare un titolo

bool Libro::operator==(Libro l) {
	return (getTitolo() == l.getTitolo());
} // sovraccarico == (per oggetti Libro)

// sovraccarico l'operatore << per permettere la stampa degli oggetti Libro
std::ostream& operator<<(std::ostream& stream, const Libro& l){
	stream << l.getTitolo();
	return stream;
}