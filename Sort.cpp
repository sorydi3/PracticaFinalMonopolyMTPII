//#include "stdafx.h"
#include "Sort.h"

Sort::Sort():Casella(""){}
Casella* Sort::clonar() const {
	return new Sort(*this);
}

Sort::~Sort(){}
void Sort::llegir(ifstream & in_file) {}
void Sort::mostrar() const {
   cout << "Casella de Sort " <<_nom<< endl;
}
void Sort::processarJugada(Jugador * jugador,Baralla * baralla){

	baralla->procesa(1,jugador);
}
int Sort::capitalEntrada()const { return 0; }
char Sort::getType() const
{
	return 'S';
}
void Sort::actualitzaPropietari(){}

