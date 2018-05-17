#include "stdafx.h"
#include "Casella.h"

Casella::Casella(string nom){
	_nom = nom;
}
Casella* Casella::clonar()const {
	return new Casella(*this);
}
Casella::~Casella(){}
void Casella::mostrar() const {}
void Casella::llegir(ifstream &i_file) {};