#include "stdafx.h"
#include "Jugador.h"


Jugador::Jugador()
{
	_nom = " ";
	_penalitzacio = 0;
	_diner = 0;
	_posicio = 0;
}

void Jugador::llegir(int capital_inicial) {
	cin >> _nom;
	_diner = capital_inicial;
}
void Jugador::mostrar() const {
	if (_penalitzacio > 0)
		cout << _nom << ": " << _diner << ": Casella:" << _posicio << ": Penalitzat amb " << _penalitzacio << " torns" << endl;
	else
	cout << _nom << ": " << _diner << ": Casella:" << _posicio << endl;
}
Jugador::~Jugador()
{
}
