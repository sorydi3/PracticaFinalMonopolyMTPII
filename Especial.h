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
	Especial();
	int obtenirCapitalSortida()const;
	void llegir(ifstream & in_file);
	void mostrar() const;
	Casella* clonar() const;
	void processarJugada(Jugador * jugador);
	int capitalEntrada()const;

private:
	int _quantitat_p_c;
	unsigned _torn;
};

                      