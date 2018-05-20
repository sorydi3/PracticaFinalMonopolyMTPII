#pragma once
#include<iostream>
#include<fstream>
#include<cmath>
#include<string>
#include"Jugador.h"
#include"Baralla.h"
#include"Tauler.h"
using namespace std;
static const unsigned A_RAND = 1103515245;
static const unsigned C_RAND = 12345;
static const unsigned M_RAND = 32767;
class Joc
{
public:
	Joc();

	//copy constructor
	Joc(const Joc &source);
	Joc& operator=(const Joc &source);
	void inicialitzaJoc();
	void DisplayContent();
	void procesa(unsigned _num);
	void torn();
	void inici();

	~Joc();
private:
	Baralla _baralla;
	Tauler _tauler;
	unsigned _countador;
	unsigned _seed;
	struct Node
	{
		Jugador jugador;
		Node *next;
	};
	Node *_first;
	Node *_last;
	void copy(const Joc& source);
	void FreeHeap();
	bool isEmpty()const;
	void addLast(Jugador &jugador);
	void deleteFirst();
	Jugador Primer()const;
	void deleteLast();
	void rand(unsigned &res, unsigned &x_n) const;
	void inicialitzarBaralla();
	void inicialitzarTauler();
	void AfegirJugadors();
	unsigned  tirarDaus(unsigned tirades);
	void mostraGuanyador()const;
	void eliminaJugador();
	void deleteBetween(Node *ant,Node * t);


};