//#include "stdafx.h"
#include<iostream>
#include<iomanip>
#include"Joc.h"

Joc::Joc()
{
	_countador = 0;
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
	while (n > _tauler.jugadorsMax() || n < _tauler.jugadorsMin()) {
	cout << "Nombre de jugadors incorrecte. Valor entre " << _tauler.jugadorsMin() << " i " << _tauler.jugadorsMax() << endl;
	cin >> n;
	}

	_countador = n;
	int capital = _tauler.capitaInicial();
	for (int i = 0; i < n; i++)
	{
		cout << "Entra el nom del jugador " << i + 1 << endl;
		Jugador jugador;
		jugador.llegir(capital);
		jugador.setId(i);
		addLast(jugador);
	}
}
void Joc::inicialitzarTauler() {
	cout << "*** JOC DEL MONOPOLY ***" << endl;
	cout << "Introdueix el nom del fitxer de configuració" << endl;
	string nom_fitxer;
	cin >> nom_fitxer;
	_tauler.settupTauler(nom_fitxer);
	//_tauler.showTable();
}
void Joc::inicialitzarBaralla() {
	cout << "Introdueix el nom del fitxer de cartes de sort" << endl;
	string nom_fitxer;
	cin >> nom_fitxer;
	_baralla.AfegirCartes(nom_fitxer);
	//_baralla.DisplayContent();

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
void Joc::DisplayContent()const {
	cout << "Llistat de jugadors:" << endl;
	Node *temp = _first;
	while (temp) {
		temp->jugador.mostrar('l');
		temp = temp->next;
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
////////////////////////////////////////////////////////////RANDS METHODS//////////////////////////////////////////////////////
unsigned Joc::tirarDaus(unsigned tirades){
	unsigned resultat = 0;
	unsigned res = 0;//guarda resultat
	unsigned sum = 0;
	for (int i = 0; i < tirades; i++) {
		rand(res, resultat);
		
		sum += resultat;
		_seed = res;
	}
	return sum;
}
void  Joc ::rand(unsigned &res, unsigned &x_n) const{
	//pre:
	//post:
	res = (_seed*A_RAND + C_RAND) % M_RAND;
	x_n = (res % 6) + 1;
}
////////////////////////////////////////////////////////////////////PUBLIC METHODS///////////////////////////////////////////////////////////
void Joc::inicialitzaJoc() {
	inicialitzarTauler();
	inicialitzarBaralla();
	cout << "Entra la llavor" << endl;
	cin >> _seed;
	AfegirJugadors();
}

//////////////////////////////////////////////////////////INIT GAME////////////////////////////////////////////////////
void Joc::torn() {
	Node * aux = _first;
	int size=_tauler.getSize();
	int capitalEntrada = _tauler.capitalEntrada();
	int _posicio = 0;
	bool trobat = false;
	while (aux) {
		if (!aux->jugador.eliminar()) {
				if (!aux->jugador.esPenalitzat()) {
					int posicio = tirarDaus(2);
					_posicio = posicio;
					aux->jugador.atualitzaPosicio(_posicio,size,capitalEntrada);
					cout << "En/la " << aux->jugador.obtenirNomJugador() << " ha tret un " << posicio << endl;
					_tauler.processa(&aux->jugador,&_baralla, aux->jugador.obtenirPosicio());
					_tauler.resetPropietats();
				}
				else {
					aux->jugador.mostrar('p');
					aux->jugador.actulitzaPenalitzacioJugador();
				}
	}
		if (!mesDeUnJugador())break;
		aux = aux->next;
	}
}

void Joc::inici() {
	bool continuar = true;
	char opcio;
	cout << "Vols mostrar el tauler? (S/N)" << endl;
	cin >> opcio;
	if (opcio == 'S') _tauler.showTable();

	while (continuar && mesDeUnJugador() ) {
		torn();
		if (!mesDeUnJugador())break;
		cout << "Vols mostrar el tauler? (S/N)" << endl;
		cin >> opcio;
		if (opcio == 'S') _tauler.showTable();

		cout << "Vols mostrar l'estat dels jugadors? (S/N)" << endl;
		cin >> opcio;
		if (opcio == 'S') DisplayContent();
		cout << "Vols continuar? (S/N)" << endl;
		cin >> opcio;
		if (opcio == 'N') continuar = false;
	
	}
	cout << "Guanyador:" << endl;
	mostraGuanyador();
	cout << "***FI DEL MONOPOLY***" << endl;
}


void Joc:: mostraGuanyador()const {
	Node* aux = _first;
	Node *guanyador = aux;
	aux = aux->next;
	while (aux) {
		if (aux->jugador.esMenor(&guanyador->jugador)) {
			guanyador = aux;
		}
		aux = aux->next;
	}
	guanyador->jugador.mostrar('l');
}


bool Joc::mesDeUnJugador()const {
	Node *aux = _first;
	bool trobat = false;
	unsigned countador = 0;
	while (aux && !trobat) {

		if (!aux->jugador.eliminar() ) {
			countador++;
		}
		if (countador > 1)trobat = true;
		aux = aux->next;
	}
	return trobat;
}