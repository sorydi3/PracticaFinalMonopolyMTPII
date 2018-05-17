#pragma once
#include<iostream>
#include<string>
using namespace std;

class Jugador
{
public:
	Jugador();
	void llegir(int capital_inicial);
	void mostrar()const;
	~Jugador();
private:
	string _nom;
	int _posicio;
	int _diner;
	unsigned _penalitzacio;
};

