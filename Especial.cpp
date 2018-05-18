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
	else if (_quantitat_p_c == 0 && _torn == 0)
		cout << "Especial: " << _nom << endl;
	else
		cout << "Especial: " << _nom << ": "<<_torn<< " torns sense tirar"<< endl;
 }
void Especial::processarJugada( Jugador * jugador) {
	//jugador.mostrar('l');
	//mostrar();
	jugador->penalitzat(_torn);
	cout << "En/La " << jugador->obtenirNomJugador() << " es queda " << _torn << " torns sence tirar" << endl;
};

int Especial::obtenirCapitalSortida()const {
	return _quantitat_p_c;
}

int Especial::capitalEntrada()const {
	return _quantitat_p_c;
}
