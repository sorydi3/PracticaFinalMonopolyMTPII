#pragma once
#include<iostream>
#include<fstream>
#include"Carta.h"
#include<cmath>
#include<string>
using namespace std;

class Baralla
{
public:
		Baralla();

	//copy constructor
	Baralla(const Baralla &source);
	Baralla& operator=(const Baralla &source);
	void DisplayContent();
	void AfegirCartes(string nom_fitxer);
	void procesa(unsigned _num);

	~Baralla();
private:
	struct Node
	{
		Carta carta;
		Node *next;
	};
	Node *_first;
	Node *_last;
	void copy(const Baralla& source);
	void FreeHeap();
	bool isEmpty()const;
	void addLast(Carta &carta);
	void deleteFirst();
	Carta Primer()const;
	void deleteLast();
};

