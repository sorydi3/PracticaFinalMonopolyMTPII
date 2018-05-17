#pragma once
#include<fstream>
#include<iostream>
#include<string>
using namespace std;
class Casella
{
public:
	Casella(string nom);
	virtual void llegir(ifstream & in_file);
	virtual void mostrar() const;
	//virtual void processarJugada();
	virtual Casella* clonar() const;
	~Casella();
protected:
	string _nom;
};

