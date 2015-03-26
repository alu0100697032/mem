/*
 * main.cpp
 *
 *  Created on: 27/03/2014
 *      Author: Victor
 */
#include "multiplicacion.h"
int main(){

	MultEnc a(250);

	float secs;
	clock_t dvcomienzo;
	clock_t dvfin;

	/*COLUMNAS*/
	dvcomienzo = clock();
	a.rellenarCol();
	dvfin = clock();
	secs = (float) (dvfin - dvcomienzo) / CLOCKS_PER_SEC;
	cout << "Columnas " << setprecision(10) << fixed << secs << endl;
	cout << endl;

	/*FILAS*/
	dvcomienzo = clock();
	a.rellenarFil();
	dvfin = clock();
	secs = (float) (dvfin - dvcomienzo) / CLOCKS_PER_SEC;
	cout << "Filas " << setprecision(10) << fixed << secs << endl;
	cout << endl;

	/*DIAGONAL*/
	dvcomienzo = clock();
	a.rellenar();
	dvfin = clock();
	secs = (float) (dvfin - dvcomienzo) / CLOCKS_PER_SEC;
	cout << "Diagonales " << setprecision(10) << fixed << secs << endl;
	cout << endl;
	//a.mostrarK();
	//cout << a.parent(0, x-1) << endl;
	return 0;
}


