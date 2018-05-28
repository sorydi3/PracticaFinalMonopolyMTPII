#pragma once
#include "Casella.h"
#include"Jugador.h"
#include<iostream>
using namespace std;
class Sort :
	public Casella
{
public:
	//constructor
	Sort();
	//pre:--
	//post:llegeix dades de tipus sort des del fitxer
	void llegir(ifstream & in_file);
	//pre:--
	//post:mostra l'info de la casella de tipus sort
	void mostrar() const;
	//pre:--
	//post:fa una copia de la casella
	Casella* clonar() const;
	//pre:--
	//post:processa un jugador 
	void processarJugada(Jugador * jugador,Baralla * baralla);
	//pre:--
	//post:retorna la capital de sortida
	int capitalEntrada()const;
	//pre:--
	//post:retorna el tipus de la casella 
	char getType()const;
	//pre:--
	//post:actualitza el propierari(implementat nomes en propietat)
    void actualitzaPropietari();

	~Sort();
private:
};

