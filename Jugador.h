#pragma once
#include<iostream>
#include<string>
using namespace std;

class Jugador
{
public:
	Jugador();
	void llegir(int capital_inicial);
	void setId(unsigned id);
	unsigned obtenirId()const;
	void mostrar(char opcio)const;
	bool esPenalitzat() const;
	void penalitzat(unsigned penalitzacio);
	string obtenirNomJugador()const;
	void actulitzaPenalitzacioJugador();
	void atualitzaPosicio(unsigned &posicio,int size,unsigned diners_sortida);
	void pagar(unsigned quantitat);
	bool esMenor(Jugador *j1)const;
	void Cobrar(unsigned quantitat,char opcio,Jugador * jugador = NULL);
	int obtenirPosicio()const;
	bool eliminar()const;
	~Jugador();
private:
	unsigned _id;
	string _nom;
	int _posicio;
	int _diner;
	unsigned _penalitzacio;
};

