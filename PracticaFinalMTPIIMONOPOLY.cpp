// PracticaFinalMTPIIMONOPOLY.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include<iostream>
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
    return 0;
}

