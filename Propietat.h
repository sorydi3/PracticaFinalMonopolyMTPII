#pragma once
#include<iostream>
#include<string>
#include "Casella.h"
#include"Jugador.h"
#include<cmath>
#include<fstream>

using namespace std;

class Propietat :
	public Casella
{
public:
	//constructor
	Propietat();
	//pre:--
	//post:llegeix dades de tipus propietat des del fitxer
	void llegir(ifstream & in_file);
	//pre:--
	//post:mostra l'info de la casella de tipus especial
	void mostrar() const;
	//pre:--
	//post:processa un jugador
	void processarJugada(Jugador * Jugador,Baralla * baralla);
	     // pre:--
		//post:fa una copia de la casella
	Casella* clonar() const;
	//pre:--
	//post:retorna la capital de sortida
	int capitalEntrada()const;
	//pre:--
	//post:retorna el tipus de la casella
	char getType()const;
	//pre:--
	//post:actualitza el propierari(implementat nomes en propietat)
	void actualitzaPropietari();
	//pre:
	//post:calcula el preu del lloguer 
	double preuLloguer()const;
	//destructor
	~Propietat();
private:
	unsigned _preu;
	unsigned _preu_casa;
	Jugador * _propietari;
	unsigned _nombre_cases;
};
