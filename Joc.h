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
	//pre:---
	//post:inicialitzat tots els atributs del joc
	void inicialitzaJoc();
	//pre:--
	//post:mostra el jugadors de la lista
	void DisplayContent()const;
  //pre:--
	//pst:inicialitza el joc
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
	//pre:
	//post:copia la memoria dynamica reservada en un altre objecte
	void copy(const Joc& source);
	//pre:
	//post:allibera la memoria dynamica reservada
	void FreeHeap();
	//pre:--
	//post:diu si la llista de judaor es vuida o no
	bool isEmpty()const;
	//pre:--
	//post:afageix un jugador a l'ultima posicio de la llista de jugadors
	void addLast(Jugador &jugador);
	//pre:_primer!=NULL
	//post:elimina el primer element de la llista
	void deleteFirst();
	//pre:_primer!=NULL
	//PSOT:retorna el primer jugador de la llista de jugadrs
	Jugador Primer()const;
	//pre:_primer!=NULL
	//psot:elimina l'ultim element de la llista de jugadors
	void deleteLast();
	//pre:x_n>0
	//post:genera un nombre aleatori donat una llavo
	void rand(unsigned &res, unsigned &x_n) const;
	//pre:--
	//post:inicialita la baralla de cartes
	void inicialitzarBaralla();

	//pre:
	//post:inicialitza el tauler
	void inicialitzarTauler();
	//pre:--
	//post:afageix els jugadors a la llista
	void AfegirJugadors();
	unsigned  tirarDaus(unsigned tirades);
	//pre:
	//post:mostra el guanyadors del joc
	void mostraGuanyador()const;
	//pre:--
	//post:diu si n'hi ha mes de un jugador en la llista de jugadors
	bool mesDeUnJugador()const;
	//pre:--
	//post:fa un torn complet passant per tots el jugadors
	void torn();

};