#include "stdafx.h"
#include "Propietat.h"
#include<string>
Propietat::Propietat():Casella("")
{
	_propietari =NULL;
	_preu = 0;
	_preu_casa = 0;
}
Casella* Propietat::clonar() const {
	return new Propietat(*this);
 }


Propietat::~Propietat()
{
	delete _propietari;
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
void Propietat::processarJugada(Jugador *jugador){
	if (!_propietari) {
		cout << jugador->obtenirNomJugador() << " vols comprar la propietat " << _nom << " per " << _preu << " \u20AC" << "?" << "  (S/N)" << endl;
		char opcio;
		cin >> opcio;
		if (opcio == 'S') {
			_propietari = jugador;
			_propietari->pagar(_preu);
		}
	}
	else {
		cout << "heu de cobrar " << endl;
		_propietari->Cobrar(jugador, _preu_casa);
	}
}

int Propietat::capitalEntrada()const { return 0; }
