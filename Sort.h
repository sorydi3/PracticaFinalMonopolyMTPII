#pragma once
#include "Casella.h"
#include"Jugador.h"
#include<iostream>
using namespace std;
class Sort :
	public Casella
{
public:
	Sort();
	void llegir(ifstream & in_file);
	void mostrar() const;
	Casella* clonar() const;
	void processarJugada(Jugador * jugador,Baralla * baralla);
	int capitalEntrada()const;
	char getType()const;
    void actualitzaPropietari();

	~Sort();
private:
};

