#pragma once
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class Carta
{
public:
	Carta();
	//pre:cert
	//post:ha llegit una carta del fitxer
	void llegir(ifstream & in_file);
	//pre:cert
	//post:mostra la carta
	void mostrar()const;
	int obtenir_quantitat() const;
	int obtenir_penalitzacio()const;
private:
	string _inf;
	unsigned  _penalitzacio;
	int _quantitat;
	
};

