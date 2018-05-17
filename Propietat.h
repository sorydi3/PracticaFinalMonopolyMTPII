#pragma once
#include<iostream>
#include<string>
#include "Casella.h"
#include<fstream>
using namespace std;

class Propietat :
	public Casella
{
public:
	Propietat();
	void llegir(ifstream & in_file);
	void mostrar() const;
	void processarJugada()const;
	Casella* clonar() const;

	~Propietat();
private:
	unsigned _preu;
	unsigned _preu_casa;
};
