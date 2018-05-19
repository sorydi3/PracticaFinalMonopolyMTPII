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
	void processarJugada(Jugador * Jugador,Baralla * baralla);
	Casella* clonar() const;
	int capitalEntrada()const;
	char getType()const;
	void actualitzaPropietari();
	~Propietat();
private:
	unsigned _preu;
	unsigned _preu_casa;
	Jugador * _propietari;
	unsigned _nombre_cases;
};
