#pragma once
#include<iostream>
#include<string>
using namespace std;

class Jugador
{
public:
	//constructor
	Jugador();
	//pre:--
	//post:llegeix un jugador i assignan li un capital inicial
	void llegir(int capital_inicial);
	//pre:--
	//post:assigna a un jugador una id
	void setId(unsigned id);
	//pre:--
	//post:retrna el id del jugador
	unsigned obtenirId()const;
	//pre:--
	//post:mostra el jugador
	void mostrar(char opcio)const;
	//pre:--
	//post:diu si el jugador esta penalitzat o no
	bool esPenalitzat() const;
	//pre:--
	//post:penalitza a un jugador
	void penalitzat(unsigned penalitzacio);
	//pre:--
	//post:retorna el nom del jugador
	string obtenirNomJugador()const;
	//pre:--
	//post:actualitza la penalitzacio de un judaor
	void actulitzaPenalitzacioJugador();
	//pre:--
	//post:actualitza la posicio de un jugador
	void atualitzaPosicio(int &posicio,int size,int diners_sortida);
	//pre:--
	//post:el jugador paga un quantitat determinada passat per parametre
	void pagar(double quantitat);
	//pre:--
	//post:compara els diners de dues jugadors 
	bool esMenor(Jugador *j1)const;
	//pre:--
	//post:el llugador cobra una quatitat determinada passat per parametre
	void Cobrar(double quantitat,char opcio,Jugador * jugador = NULL);
	//pre:--
	//post:retorna la posicio del jugador
	int obtenirPosicio()const;
	//pre:--
	//post:diu si aquest jugador esta elinat o no
	bool eliminar()const;
	//destructoe
	~Jugador();
private:
	unsigned _id;
	string _nom;
	int _posicio;
	double _diner;
	unsigned _penalitzacio;
};

