#pragma once
#include<iostream>
#include<iomanip>
#include<fstream>
#include"Casella.h"
#include "Especial.h"
#include "Propietat.h"
#include "Sort.h"

using namespace std;

class Tauler

{
public:
	Tauler();
	Tauler(const Tauler &t);
	Tauler &operator=(const Tauler &t);
	void settupTauler(string nom_fitxer);
	void showTable()const;
	int capitaInicial()const;
	int jugadorsMin()const;
	int jugadorsMax()const;
	~Tauler();
private:
	Casella **_t;
	int _min;
	int _max;
	int _cptl;
	int  _n;

	void reservar();
	void free();
	void configVars(ifstream & in_file);
	void copy(const Tauler& o);
};