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
	void mostrar(char opcio)const;
    //pre:--
	//post:retorna la quantitat que ha de pagar/cobrar el jugador
	int obtenir_quantitat() const;
	//pre:
	//post:retorna la penalitzacio d'aquesta carta
	int obtenir_penalitzacio()const;
private:
	string _inf;
	unsigned  _penalitzacio;
	int _quantitat;
	
};

