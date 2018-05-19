#include "stdafx.h"
#include "Propietat.h"
#include<string>
Propietat::Propietat():Casella("")
{
	_propietari =NULL;
	_preu = 0;
	_preu_casa = 0;
	_nombre_cases = 0;
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
void Propietat::processarJugada(Jugador *jugador,Baralla *baralla){
	char opcio = 'p';
	cout << "printng baralla----------------------" << endl;
	baralla->DisplayContent();
	cout << "printng baralla----------------------" << endl;
	if (!_propietari) {
		cout << jugador->obtenirNomJugador() << " vols comprar la propietat " << _nom << " per " << _preu << " \u20AC" << "?" << "  (S/N)" << endl;
		char opcio;
		cin >> opcio;
		if (opcio == 'S') {
			_propietari = jugador;
			_propietari->pagar(_preu);
			_nombre_cases = 0;
		}
	}
	else if (&_propietari==&jugador) {
		if (_nombre_cases < 5) {
			cout << "cases+1" << endl;
			_nombre_cases++;
		}
		else
			cout << "Teniu un hotel :)" << endl;
	}
	else {
		cout << "heu de cobrar " << endl;
		_propietari->Cobrar(_preu_casa,opcio,jugador);
	}
}

int Propietat::capitalEntrada()const { return 0; }

char Propietat::getType() const
{
	return 'P';
}

void Propietat::actualitzaPropietari()
{
	//propietari eliminar
	if (_propietari) {
	if (_propietari->eliminar()) _propietari = NULL;
	}
}


