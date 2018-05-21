#include "stdafx.h"
#include "Carta.h"
Carta::Carta()
{
	  _inf = "";
	  _penalitzacio = 0;
	  _quantitat = 0;
}


void Carta::llegir(ifstream& in_file) {
	getline(in_file, _inf);
	in_file >> _quantitat;
	in_file>> _penalitzacio;
	in_file.ignore(100,'\n');
}

void Carta::mostrar(char opcio)const {
	if (opcio == 'c') {

		if (_quantitat != 0) {
			if(_quantitat>0)
			cout <<"El jugador ha de cobrar "<< _quantitat << " \u20AC" << endl;
			else cout << "El jugador ha de pagar " << abs(_quantitat) <<" \u20AC"<< endl;

		}
		else {
			cout <<"El jugador es queda "<< _penalitzacio <<" torns sense tirar"<< endl;
		}
	}
	else {
		cout << _inf << endl;
	}
}

int Carta::obtenir_quantitat() const
{
	
	return _quantitat;
}

int Carta::obtenir_penalitzacio() const
{
	return _penalitzacio;
}
