/*
 * multiplicacion.h
 *
 *  Created on: 27/03/2014
 *      Author: Victor
 */

#ifndef MULTIPLICACION_H_
#define MULTIPLICACION_H_
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <string>
#include <ctime>
#include <conio.h>
#include <iomanip>

using namespace std;

class MultEnc{
private:
	int n_mat;
	int* dimensiones;
	int** val_k;
	int** tabla; //rellenar con 0
public:
	MultEnc();
	MultEnc(int n);
	~MultEnc();
	void mostrarCost();
	void mostrarK();
	void rellenar();
	void rellenarFil();
	void rellenarCol();
	string parent(int i, int j);
};

#endif /* MULTIPLICACION_H_ */
