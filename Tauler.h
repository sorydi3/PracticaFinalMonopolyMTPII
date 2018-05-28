#pragma once
#include<iostream>
#include<fstream>
#include"Casella.h"
#include "Especial.h"
#include "Propietat.h"
#include "Sort.h"
#include"Jugador.h"
#include "Baralla.h"

using namespace std;

class Tauler

{
public:
	//contructor tauler
	Tauler();
	//contructor de copia del tauler
	Tauler(const Tauler &t);
	//operator d'assignacio del tauler
	Tauler &operator=(const Tauler &t);
	//pre:
	//post:inicialita el tauler 
	void settupTauler(string nom_fitxer);
	//pre:--
	//post:mostra el tauler
	void showTable()const;
	//pre:--
	//post:processa un jugador determinat depenent del tipus casella que l'hi tocat
	void processa(Jugador *jugador,Baralla *baralla, int posicio) const;
	//pre:--
	//post:retorna el capital inicia del jugadors
	int capitaInicial()const;
	//pre:--
	//post:retorna el capital que ha de rebre un jugador el terminar un torn
	int capitalEntrada()const;
	//pre:--
	//post:retorn el nombre de jugadors minims que pots jugar
	int jugadorsMin()const;
	//pre:--
	//post:retorn el nombre axim de jugadors
	int jugadorsMax()const;
	//pre:--
	//post:retorna la mida del tauler
	int getSize()const;
	//pre:--
	//post:actualitza el propietats que no tenen propietari
	void resetPropietats();
	//destructor 
	~Tauler();
private:
	Casella **_t;
	int _min;
	int _max;
	int _cptl;
	int  _n;
	//pre:--
	//post:reserva una taula dynamica
	void reservar();
	//pre:
	//post:allibera la memoria dynamica resrvada
	void free();
	//pre:--
	//post:llegeix del fitxer les variables per configurar el tauler
	void configVars(ifstream & in_file);
	////pre:--
	//post:fa una copia de la memoria dynamica reservada en un altre objecte
	void copy(const Tauler& o);
};