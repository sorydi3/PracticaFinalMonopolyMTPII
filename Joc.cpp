#include "stdafx.h"
#include<iostream>
#include<iomanip>
#include"Joc.h"
Joc::Joc()
{
	
	_first = NULL;
	_last = NULL;
}

//COPPY CONSTRUCTOR

Joc::Joc(const	Joc& source) {
	copy(source);
}
void Joc::copy(const Joc& source) {
	Node *p = source._first;//declarem un punter auxiliar que apunta el primer element de la cua
	while (p) {
		addLast(p->jugador);//encuem una nova sol.licitud a la cua  
		p = p->next;//recorrem la cua amb un punter auxiliar
	}
}

////////////////////////////////////INICIALITZACIO BARALLA DE CARTES I EL TAULER///////////////////////////////////////////////
void Joc::AfegirJugadors() {
	cout << "Introdueix el nombre de jugadors" << endl;
	unsigned n;
	cin >> n;
	int capital = _tauler.capitaInicial();
	for (int i = 0; i < n; i++)
	{
		cout << "Entra el nom del jugador " << i + 1 << endl;
		Jugador jugador;
		jugador.llegir(capital);
		addLast(jugador);
	}
}
void Joc::inicialitzarTauler() {
	cout << "*** JOC DEL MONOPOLY ***" << endl;
	cout << "Introdueix el nom del fitxer de configuració" << endl;
	string nom_fitxer;
	cin >> nom_fitxer;
	_tauler.settupTauler(nom_fitxer);
	_tauler.showTable();
}
void Joc::inicialitzarBaralla() {
	cout << "Introdueix el nom del fitxer de cartes de sort" << endl;
	string nom_fitxer;
	cin >> nom_fitxer;
	_baralla.AfegirCartes(nom_fitxer);
	_baralla.DisplayContent();

}
//////////////////////////////////////////////////////////////////////////////////

void Joc::addLast(Jugador &jugador) {
	Node *nw = new Node;
	nw->jugador = jugador;
	nw->next = NULL;
	if (!_first) {
		_first = nw;
		_last = nw;
	}
	else {
		_last->next = nw;
		_last = nw;
	}
}
void Joc::deleteFirst() {
	Node *t = _first;
	if (_first == _last) {
		_first = _last = NULL;
	}
	else {
		_first = _first->next;
	}
	delete t;
}
bool Joc::isEmpty()const {
	return _first;
}
void Joc::DisplayContent() {
	Node *temp = _first;
	while (temp) {
		temp->jugador.mostrar();
		temp = temp->next;
	}
	if (!_first) {
		cout << "Cua buida." << endl;
		cout << "TOTAL = " << "0.00" << " \u20AC" << endl;

	}
}
void Joc::FreeHeap() {
	while (_first) {
		Node *aux = _first;
		_first = _first->next;
		delete aux;
	}
	_last = _first = NULL;

}

Joc::~Joc()
{
	FreeHeap();
}

Joc& Joc::operator=(const Joc& Joc) {
	if (this != &Joc) {
		FreeHeap();
		copy(Joc);
	}
	return *this;
}

Jugador Joc::Primer()const {
	return _first->jugador;
}
void Joc::procesa(unsigned num) {
	for (int i = 0; i < num; i++) {
		Node *aux = _first;
		cout << "Jugador " << i + 1 << endl;
		aux->jugador.mostrar();
		addLast(aux->jugador);
		deleteFirst();
	}
}

void Joc::deleteLast() {
	Node *ant = NULL;
	Node *t = _first;
	bool trobat = false;
	while (t && !trobat) {
		if (t->next != NULL) {
			ant = t;
			t = t->next;
		}
		else {
			trobat = true;
		}
	}

	ant->next = NULL;
	_last = ant;
	delete t;
}