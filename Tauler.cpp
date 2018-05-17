#include "stdafx.h"
#include "Tauler.h"

Tauler::Tauler()
{
	_min = 0;
	_max = 0;
	_cptl = 0;
	_n = 0;
	_t = NULL;
}

Tauler::Tauler(const Tauler& o)
{
	copy(o);
}
Tauler::~Tauler()
{
	free();
}
int Tauler::capitaInicial() const {
	return _cptl;
}
int Tauler::jugadorsMax() const {
	return _max;
}
int Tauler::jugadorsMin() const {
	return _min;
}

void Tauler::free() {
	for (int i = 0; i < _n; i++) {
		delete _t[i];
	}
	delete[]_t;
}

void Tauler::reservar() {
	_t = new Casella *[_n];
	//for (int i = 0; i < _r; i++) {
		//_mat[i] = new int[_c];
	//}
}

Tauler & Tauler::operator=(const Tauler &o) {
	// Pre: --; Post: s’ha assignat sense aliasing la informació de t a l’objecte actual
	if (this != &o) {
		free();
		copy(o);
	}
	return *this;
}
void Tauler::copy(const Tauler& o) {
	//pre: cert
	//post:
	_n = o._n;
	reservar();
	for (int i = 0; i < o._n; i++) {
		_t[i] = o._t[i]->clonar();
	}
}

void Tauler::settupTauler(string nom_fitxer) {

	ifstream in_file(nom_fitxer.c_str());
	if (in_file.is_open()) {
		if (!in_file.eof())configVars(in_file);
		reservar();
		int i = 0;
		char tipus = ' ';
		in_file >> i;
		in_file >> tipus;
		while (!in_file.eof()) {
			switch (tipus)
			{
			case 'E':
				_t[i] = new Especial();
				break;
			case 'S':
				_t[i] = new Sort();
				break;
			case 'P':
				_t[i] = new Propietat();
				break;
			default:
				break;
			}
			if(tipus!='S')
			_t[i]->llegir(in_file);
			if (!in_file.eof()) {
				in_file >> i;
				in_file >> tipus;
			}
		}
	}
	else {
		cout << "no s'ha pogut obrir el fitxer baralla de cartes" << endl;
	}	
}			

void Tauler::configVars(ifstream & in_file) {
	in_file >> _min;
	in_file >> _max;
	in_file >> _cptl;
	in_file >> _n;
}
void Tauler::showTable()const {
	cout << "Tauler:" << endl;
	for (size_t i = 0; i < _n; i++)
	{
		cout << i << ": ";
		_t[i]->mostrar();
	}
}