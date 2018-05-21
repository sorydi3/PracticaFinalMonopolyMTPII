#include "stdafx.h"
#include "Especial.h"
#include<cmath>
Especial::Especial():Casella(""){
	_quantitat_p_c = 0;
	_torn = 0;
}

Casella* Especial::clonar()const {
	return new Especial(*this);
}
void Especial::llegir(ifstream & in_file) {
	in_file.ignore(100,'\n');
	getline(in_file, _nom);
	in_file >> _quantitat_p_c;
	in_file >> _torn;
}
void Especial::mostrar() const {
	if (_quantitat_p_c != 0) {
		if (_quantitat_p_c > 0)
			cout << "Especial: " << _nom << ": cobrar " << _quantitat_p_c << " \u20AC" << endl;
		else
		    cout << "Especial: " << _nom << ": pagar " <<abs(_quantitat_p_c) << " \u20AC" << endl;
	}
	else if (_torn != 0)
		cout << "Especial: " << _nom << ": "<<_torn<< " torns sense tirar"<< endl;
	else
		cout << "Especial: " << _nom << endl;
 }
void Especial::processarJugada(Jugador * jugador, Baralla * baralla) {
	if (_quantitat_p_c != 0) {
		if (_quantitat_p_c > 0) {
			cout << "En/La " << jugador->obtenirNomJugador() << " ha de cobrar " << _quantitat_p_c << " \u20AC" << endl;
		    jugador->Cobrar(_quantitat_p_c, 's');
		}
		else {
			cout << "En/La " << jugador->obtenirNomJugador() << " ha de pagar " <<abs(_quantitat_p_c) << " \u20AC" << endl;
			jugador->pagar(_quantitat_p_c);
		}
	}
	else {
		   cout << "En/La " << jugador->obtenirNomJugador() << " es queda " << _torn << " torns sence tirar" << endl;
		   jugador->penalitzat(_torn);
	}
}

int Especial::obtenirCapitalSortida()const {
	return _quantitat_p_c;
}

int Especial::capitalEntrada()const {
	return _quantitat_p_c;
}

char Especial::getType() const
{
	return 'E';
}

void Especial::actualitzaPropietari(){}
