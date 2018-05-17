// PracticaFinalMTPIIMONOPOLY.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include<iostream>
#include<string>
#include"Baralla.h"
#include"Tauler.h"
#include"Joc.h"
using namespace std;

const unsigned A = 1103515245;
const unsigned C= 12345;
const unsigned M = 32767;


void rand(unsigned &seed, unsigned &res, unsigned &x_n) {
	//pre:
	//post:
	res= (seed*A + C)%M;
	x_n = (res%6)+1;
}
int main()
{
	Baralla baralla;
	/*
	cout << "*** TEST DAU ***" << endl;
	cout << "Entra la llavor" << endl;
	unsigned seed;
	cin >> seed;
	cout << "Entra el nombre de tirades" << endl;
	unsigned tirades;
	cin >> tirades;
	unsigned resultat = 0;
	unsigned res = 0;//guarda resultat
	cout << "Tirades del dau" << endl;
	for (int i = 0; i < tirades; i++) {
		rand(seed,res,resultat);
		cout <<resultat << endl;
		seed =res;
	}
	/*
	cout << "*** TEST CARTES DE LA SORT ***" << endl;
	cout << "Introdueix el nom del fitxer de cartes de sort" << endl;
	string nom_fitxer;
	cin >> nom_fitxer;
	cout << "Entra el nombre de cartes" << endl;
	unsigned nombre;
	cin >> nombre;
	baralla.AfegirCartes(nom_fitxer);
	baralla.procesa(nombre);
	*/

	/*
	cout << "*** TEST TAULER ***" << endl;
	cout << "Introdueix el nom del fitxer de configuració" << endl;
	string nom_fitxer;
	cin >> nom_fitxer;
	Tauler tauler;
	tauler.settupTauler(nom_fitxer);
	tauler.showTable();
    return 0;
	*/
	Joc joc;
	joc.inicialitzarTauler();
	joc.inicialitzarBaralla();
	joc.AfegirJugadors();
	joc.DisplayContent();
}

