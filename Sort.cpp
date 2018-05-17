#include "stdafx.h"
#include "Sort.h"

Sort::Sort():Casella(""){}
Casella* Sort::clonar() const {
	return new Sort(*this);
}

Sort::~Sort(){}
void Sort::llegir(ifstream & in_file) {}
void Sort::mostrar() const {
   cout << "Casella de Sort " <<_nom<< endl;
}
//virtual void processarJugada();