#include "stdafx.h"
#include "Propietat.h"

Propietat::Propietat():Casella("")
{
	_preu = 0;
	_preu_casa = 0;
}
Casella* Propietat::clonar() const {
	return new Propietat(*this);
 }


Propietat::~Propietat()
{
}
void Propietat::llegir(ifstream& in_file) {
	in_file.ignore();
	getline(in_file, _nom);
	in_file >> _preu;
	in_file >> _preu_casa;
}
void Propietat::mostrar() const {
	cout << "Propietat: " << _nom << " : " << _preu <<" \u20AC"<< endl;
}
void Propietat::processarJugada()const {

}