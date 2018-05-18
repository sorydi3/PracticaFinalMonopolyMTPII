#pragma once
#include<iostream>
#include<string>
#include "Casella.h"
#include"Jugador.h"
#include<fstream>

using namespace std;

class Propietat :
	public Casella
{
public:
	Propietat();
	void llegir(ifstream & in_file);
	void mostrar() const;
	void processarJugada(Jugador * Jugador);
	Casella* clonar() const;
	int capitalEntrada()const;

	~Propietat();
private:
	unsigned _preu;
	unsigned _preu_casa;
	Jugador * _propietari;
};
