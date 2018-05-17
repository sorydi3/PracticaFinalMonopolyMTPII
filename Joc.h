#pragma once
#include<iostream>
#include<fstream>
#include<cmath>
#include<string>
#include"Jugador.h"
#include"Baralla.h"
#include"Tauler.h"
using namespace std;
class Joc
{
public:
	Joc();

	//copy constructor
	Joc(const Joc &source);
	Joc& operator=(const Joc &source);
	void inicialitzarBaralla();
	void inicialitzarTauler();
	void DisplayContent();
	void AfegirJugadors();
	void procesa(unsigned _num);

	~Joc();
private:
	Baralla _baralla;
	Tauler _tauler;
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
};