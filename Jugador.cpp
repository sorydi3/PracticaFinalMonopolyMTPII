#include "stdafx.h"
#include "Jugador.h"
#include<cmath>


Jugador::Jugador()
{ 
	_nom = " ";
	_penalitzacio = 0;
	_diner = 0;
	_posicio = 0;
	_id = 0;
}

void Jugador::llegir(int capital_inicial) {
	cin >> _nom;
	_diner = capital_inicial;
}
void Jugador::mostrar(char opcio) const {
	if (_diner >= 0) {

	if (opcio == 'l') {
		if (_penalitzacio > 0)
			cout << "Jugador " << _id + 1 << ": " << _nom << ": " << _diner << ": Casella:" << _posicio << ": Penalitzat amb " << _penalitzacio << " torns" << endl;
		else
			cout <<"Jugador "<< _id + 1 <<": "<< _nom << ": " << _diner << ": Casella:" << _posicio << endl;
	}
	else if (opcio=='p') {
		cout << "En/La " << _nom << " estx penalitza" << endl;
	}
	else {
		cout << "En/La " << _nom << " Ha tret un " <<_posicio<< endl;
	}
	}
	else {
		cout << "Jugador " << _id + 1 << ": " << _nom << ": - ELIMINAT - " << endl;
	}
}
Jugador::~Jugador()
{
}

bool Jugador::esPenalitzat() const {
	return _penalitzacio > 0;
}

void Jugador::penalitzat(unsigned penalitzacio){
	_penalitzacio += penalitzacio;
}
void Jugador::actulitzaPenalitzacioJugador() {
	if(_penalitzacio>0)
	_penalitzacio -= 1;
}

void Jugador:: atualitzaPosicio(int &posicio,int size,int diners_sortida) {
	if(_posicio==0)
	_posicio = posicio;
	else if((_posicio+posicio)>(size-1)) {
		_diner += diners_sortida;
		_posicio = (_posicio + posicio) - size;
	}
	else {
		_posicio += posicio;
	}
	
}


string Jugador::obtenirNomJugador()const{
	return _nom;
}

void Jugador::setId(unsigned id) {
	_id = id;
}

unsigned Jugador::obtenirId()const {
	return _id+1;
}

void Jugador::Cobrar(int quantitat,char opcio, Jugador *jugador) {
	if (opcio != 's') {
		int diners = jugador->_diner;
		if (jugador->_diner < quantitat) {
			jugador->_diner = -1;
			_diner += diners;
		}
		else{ 
			jugador->_diner -= abs(quantitat);
		    _diner += quantitat;
		}
	}
	else {
		_diner += quantitat;
	}
}
int Jugador::obtenirPosicio()const {
	return _posicio;
}
bool Jugador::eliminar() const
{
	return _diner < 0;
}
void Jugador::pagar(int quantitat) {
	
	_diner -= abs(quantitat);

}

bool Jugador::esMenor(Jugador *j1)const{
	return _diner > j1->_diner;
}