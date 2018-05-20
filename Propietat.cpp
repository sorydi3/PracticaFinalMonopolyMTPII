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
	if(!_propietari)
	cout << "Propietat: " << _nom << " : " << _preu <<" \u20AC"<< endl;
	else cout << "Propietat: " << _nom << " : " << _preu << " \u20AC" <<", Propietari: "<<_propietari->obtenirId()<<endl;

}
void Propietat::processarJugada(Jugador *jugador,Baralla *baralla){
	char opcio = 'p';
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
		cout << "Construin Cases" << endl;
		if (_nombre_cases < 5) {
			cout << "cases+1" << endl;
			_nombre_cases++;
		}
		else
			cout << "Teniu un hotel :)" << endl;
	}
	else {
		cout << "heu de cobrar " << endl;
		_propietari->Cobrar(preuLloguer(),opcio,jugador);
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

double Propietat::preuLloguer() const
{
	double preu = ceil((0.1*_preu) + (_nombre_cases*_preu_casa)*0.3);
	return preu;
}


