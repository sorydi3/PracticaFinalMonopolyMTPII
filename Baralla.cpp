//#include "stdafx.h"
#include<iostream>
#include<iomanip>
#include"Baralla.h"
Baralla::Baralla()
{
	_first = NULL;
	_last = NULL;
}

//COPPY CONSTRUCTOR

Baralla::Baralla(const	Baralla& source) {
	copy(source);
}
void Baralla::copy(const Baralla& source) {
	Node *p = source._first;//declarem un punter auxiliar que apunta el primer element de la cua
	while (p) {
		addLast(p->carta);//encuem una nova sol.licitud a la cua  
		p = p->next;//recorrem la cua amb un punter auxiliar
	}
}

///////////////////////////////////////////////////////////////////////////////////
void Baralla::AfegirCartes(string nom_fitxer) {

	ifstream in_file(nom_fitxer.c_str());
	Carta carta1;
	if (in_file.is_open()) {
		while (!in_file.eof()) {
			Carta carta;
			carta.llegir(in_file);
			carta1 = carta;
			addLast(carta1);	
		}
		deleteLast();
	}
	else {
		cout << "no s'ha pogut obrir el fitxer baralla de cartes" << endl;
	}	

}
//////////////////////////////////////////////////////////////////////////////////

void Baralla::addLast(Carta &carta) {
	Node *nw = new Node;
	nw->carta = carta;
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
void Baralla::deleteFirst() {
	Node *t = _first;
	if (_first == _last) {
		_first = _last = NULL;
	}
	else {
		_first = _first->next;
	}
	delete t;
}
bool Baralla::isEmpty()const {
	return _first;
}
void Baralla::DisplayContent() {
	Node *temp = _first;
	while (temp) {
		temp->carta.mostrar('c');
		temp = temp->next;
	}
	if (!_first) {
		cout << "Cua buida." << endl;
		cout << "TOTAL = " << "0.00" << " \u20AC" << endl;

	}
}
void Baralla::FreeHeap() {
	while (_first) {
		Node *aux = _first;
		_first = _first->next;
		delete aux;
	}
	_last = _first = NULL;

}

Baralla::~Baralla()
{
	FreeHeap();
}

Baralla& Baralla::operator=(const Baralla& Baralla) {
	if (this != &Baralla) {
		FreeHeap();
		copy(Baralla);
	}
	return *this;
}

Carta Baralla::Primer()const {
	return _first->carta;
}
void Baralla::procesa(unsigned num,Jugador * jugador) {
	for (int i = 0; i < num; i++) {
		Node *aux = _first;
        cout << "En/la  " << jugador->obtenirNomJugador() <<" ha tret la carta: " <<endl;
		_first->carta.mostrar('s');
		processaJugador(jugador);
		addLast(aux->carta);
		deleteFirst();
	}
}

void Baralla::processaJugador(Jugador *jugador) const
{
	char opcio = 's';
	int cantidad = _first->carta.obtenir_quantitat();
	//cout << "quantitat--->"<<cantidad << endl;
	unsigned penalitzacio = _first->carta.obtenir_penalitzacio();
	if (cantidad != 0) {
		if (cantidad > 0) jugador->Cobrar(cantidad, opcio);
		else jugador->pagar(cantidad);
	}
	else {
		jugador->penalitzat(penalitzacio);
	}
}

void Baralla::deleteLast() {
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