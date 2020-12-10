#ifndef _LIBRO_H
#define _LIBRO_H

#include <string>
#include <iostream>

using namespace std;

class Libro {
	public:
		Libro(); // costruttore default
		Libro(string); // costruttore copia

		void setTitolo(string);
		string getTitolo() const;
		bool operator==(Libro);
		
	private:
		string titolo; // ogni oggetto libro ha un titolo
};

// sovraccarico output <<
std::ostream& operator<<(std::ostream&, const Libro&);

#endif //_LIBRO_H