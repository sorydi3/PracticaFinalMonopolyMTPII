#pragma once
#include<fstream>
#include<iostream>
#include<string>
#include"Jugador.h"
#include"Baralla.h"
using namespace std;
class Casella	
{
public:
	Casella(string nom);
	virtual void llegir(ifstream & in_file);
	virtual void mostrar() const;
	virtual void processarJugada(Jugador *jugador,Baralla *baralla);
	virtual Casella* clonar() const;
	virtual int capitalEntrada()const;
	virtual char getType()const;
	virtual void actualitzaPropietari();
	~Casella();
protected:
	string _nom;
};

