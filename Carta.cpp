//#include "stdafx.h"
#include "Carta.h"
Carta::Carta()
{
	string _inf = "";
	unsigned  _penalitzacio = 0;
	int _quantitat = 0;
}


void Carta::llegir(ifstream& in_file) {
	getline(in_file, _inf);
	in_file >> _quantitat;
	in_file>> _penalitzacio;
	in_file.ignore();
}

void Carta::mostrar()const {
	cout << _inf << endl;
	if (_quantitat != 0) {
		if(_quantitat>0)
		cout <<"El jugador ha de cobrar "<< _quantitat << " \u20AC" << endl;
		else cout << "El jugador ha de pagar " << abs(_quantitat) <<" \u20AC"<< endl;

	}
	else {
		cout <<"El jugador es queda "<< _penalitzacio <<" torns sense tirar"<< endl;
	}
}