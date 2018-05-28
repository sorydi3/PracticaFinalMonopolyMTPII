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
	//pre:
	//post:inicialtza una casella
	Casella(string nom);
	//pre:--
	//post:ha llegit un tipu casella
	virtual void llegir(ifstream & in_file);
	//pre:--
	//post:mostra un tipu casella
	virtual void mostrar() const;
	//pre:--
	//post:processa un tipus casella 
	virtual void processarJugada(Jugador *jugador,Baralla *baralla);
	//pre:--
	//post:fa una copia de casella
	virtual Casella* clonar() const;
	//pre:--
	//post:retorna el capital icial que ha de rebre tots el jugadors el inici del joc
	virtual int capitalEntrada()const;
	//pre:--
	//post:retorna el tipus de cada casella
	virtual char getType()const;
	//pre:--
	//post:actultza les caselles propietats en les que el propietari ha sigut eliminat del joc
	virtual void actualitzaPropietari();
	~Casella();
protected:
	string _nom;
};

