#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include "Casella.h"
#include"Jugador.h"
using namespace std;


class Especial :
	public Casella
{
public:
	//constructor
	Especial();
	//pre:--
	//post:llegeix dades de tipus especial des del fitxer
	void llegir(ifstream & in_file);
	//pre:--
	//post:retorna la capital de sortida
	int obtenirCapitalSortida()const;
	//pre:--
	//post:mostra l'info de la casella de tipus especial
	void mostrar() const;
	//pre:--
	//post:fa una copia de la casella
	Casella* clonar() const;

	//pre:--
	//post:processa un jugador
	void processarJugada(Jugador * jugador,Baralla * baralla);
	int capitalEntrada()const;
	//pre:--
	//post:retorna el tipus de la casella
	char getType()const;
	//pre:--
	//post:actualitza el propierari(implementat nomes en propietat)
	void actualitzaPropietari();
private:
	int _quantitat_p_c;
	unsigned _torn;
};
