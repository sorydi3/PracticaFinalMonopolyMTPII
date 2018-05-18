#pragma once
#include<fstream>
#include<iostream>
#include<string>
#include"Jugador.h"
using namespace std;
class Casella
{
public:
	Casella(string nom);
	virtual void llegir(ifstream & in_file);
	virtual void mostrar() const;
	virtual void processarJugada(Jugador *jugador);
	virtual Casella* clonar() const;
	virtual int capitalEntrada()const;

	~Casella();
protected:
	string _nom;
};

