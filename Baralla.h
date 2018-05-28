#pragma once
#include<iostream>
#include<fstream>
#include"Carta.h"
#include<cmath>
#include<string>
#include"Jugador.h"
class Baralla
{
public:
		Baralla();

	//pre:--
	//post:incialitza una baralla
	Baralla(const Baralla &source);
	//pre:--
	//post:constructor d'assignacio
	Baralla& operator=(const Baralla &source);
	//pre:--
	//post:mostra las cartas de la baralla
	void DisplayContent();
	//pre:--
	//post:afegeix una carta en la llista de cartes
	void AfegirCartes(string nom_fitxer);
	//pre:--
	//post:jugador ha agafat una carta de la baralla
	void procesa(unsigned _num,Jugador * jugador);
	//pre:--
	//post:actualizat dades del jugador 
	void processaJugador(Jugador * jugador)const;
	//destructor
	~Baralla();
private:
	struct Node
	{
		Carta carta;
		Node *next;
	};
	Node *_first;
	Node *_last;
	//pre:--
	//post:
	void copy(const Baralla& source);
	//pre:
	//post:allibera la memoria dinamica
	void FreeHeap();
	//pre--
	//post:diu si la llista de cartes es buida 
	bool isEmpty()const;
	//pre:--
	//post:encua una carta en una lista
	void addLast(Carta &carta);
	//pre:--
	//post:desencua el primer element de la cua
	void deleteFirst();
	//pre:diferent de null
	//post:retorna el primer element de la lista
	Carta Primer()const;
	//pre--
	//post:-elimina el darrer element de la lista
	void deleteLast();
};

