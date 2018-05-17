#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include "Casella.h"
using namespace std;


class Especial :
	public Casella
{
public:
	Especial();
	void llegir(ifstream & in_file);
	void mostrar() const;
	Casella* clonar() const;
	void processarJugada()const;
private:
	int _quantitat_p_c;
	unsigned _torn;
};

                      