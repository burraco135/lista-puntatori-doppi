#include <iostream>
#include "libro.h"
#include "lista.h"

using namespace std;

int main() {
	// creo un oggetto Libro
	Libro libro;
	// creo una lista di oggetti Libro
	Lista<Libro> lista_libro;
	// inizializzo la posizione sul primo elemento
	Lista<Libro>::posizione indice_libro = lista_libro.primoLista();
		cout << "Indice inizio: " << indice_libro << endl;
	
	// imposto i titoli di 6 libri nella lista
	libro.setTitolo("Libro 1");
	lista_libro.insLista(libro, indice_libro = lista_libro.succLista(indice_libro));
		cout << "Indice: " << indice_libro << endl;
	libro.setTitolo("Libro 2");
	lista_libro.insLista(libro, indice_libro = lista_libro.succLista(indice_libro));
		cout << "Indice: " << indice_libro << endl;
	libro.setTitolo("Libro 3");
	lista_libro.insLista(libro, indice_libro = lista_libro.succLista(indice_libro));
		cout << "Indice: " << indice_libro << endl;
	libro.setTitolo("Libro 4");
	lista_libro.insLista(libro, indice_libro = lista_libro.succLista(indice_libro));
		cout << "Indice: " << indice_libro << endl;
	libro.setTitolo("Libro 5");
	lista_libro.insLista(libro, indice_libro = lista_libro.succLista(indice_libro));
		cout << "Indice: " << indice_libro << endl;
	libro.setTitolo("Libro 6");
	lista_libro.insLista(libro, indice_libro = lista_libro.succLista(indice_libro));
		cout << "Indice: " << indice_libro << endl;

	// ----- Controllo dei puntatori ----- //

	// stampo lista_libro
	cout << "Lista di oggetti di tipo Libro:" << endl;
	lista_libro.stampaLista();

	// inserisco il titolo di un libro in posizione 2
	cout <<"\nInserimento nuovo elemento in seconda posizione...\n";
	libro.setTitolo("> Libro inserito");
	lista_libro.insLista(libro, indice_libro = lista_libro.succLista(lista_libro.primoLista()));

	// stampo lista_libro aggiornata
	lista_libro.stampaLista();

	cout << "\nLista di interi: " << endl;

	// creo una lista di interi
	Lista<int> lista_interi;
	// inizializzo la posizione sul primo elemento
	Lista<int>::posizione indice_interi = lista_interi.primoLista();

	// inserisco il valore di 5 elementi nella lista
	lista_interi.insLista(10, indice_interi = lista_interi.succLista(indice_interi));
	lista_interi.insLista(1, indice_interi = lista_interi.succLista(indice_interi));
	lista_interi.insLista(5, indice_interi = lista_interi.succLista(indice_interi));
	lista_interi.insLista(5, indice_interi = lista_interi.succLista(indice_interi));
	lista_interi.insLista(1, indice_interi = lista_interi.succLista(indice_interi));

	// stampo lista_interi
	lista_interi.stampaLista();

  cout << "bu0: " << lista_interi.leggiLista(indice_interi) << endl;

	// | ----- Inserire qui delle operazioni sulla lista di interi ----- | //
	// esempio - cancellare un elemento e stampare la lista aggiornata:
	// lista_interi.cancLista(indice_interi = lista_interi.succLista(primoLista));
	// lista_interi.stampa();

	return 0;
}