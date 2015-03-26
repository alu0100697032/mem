/*
 * multiplicacion.cpp
 *
 *  Created on: 27/03/2014
 *      Author: Victor
 */
#include "multiplicacion.h"
/*
 * CONSTRUCTOR
 */
MultEnc::MultEnc() {
	n_mat = 0;
	cin >> n_mat;
	tabla = new int*[n_mat];
	val_k = new int*[n_mat];
	for (int i = 0; i < n_mat; i++) {
		tabla[i] = new int[n_mat];
		val_k[i] = new int[n_mat];
	}
	/*
	 * Inicializar a 0 las matrices
	 */
	for (int i = 0; i < n_mat; i++) {
		for (int j = 0; j < n_mat; j++) {
			tabla[i][j] = 0;
			val_k[i][j] = 0;
		}
	}
	dimensiones = new int[n_mat + 1];
	cout << "Introduzca las dimensiones de la matriz " << endl;
	for (int i = 0; i < n_mat + 1; i++) {
		cin >> dimensiones[i];
	}
}
MultEnc::MultEnc(int n) {
	n_mat = n;
	tabla = new int*[n_mat];
	val_k = new int*[n_mat];
	for (int i = 0; i < n_mat; i++) {
		tabla[i] = new int[n_mat];
		val_k[i] = new int[n_mat];
	}
	/*
	 * Inicializar a 0 las matrices
	 */
	for (int i = 0; i < n_mat; i++) {
		for (int j = 0; j < n_mat; j++) {
			tabla[i][j] = 0;
			val_k[i][j] = 0;
		}
	}
	dimensiones = new int[n_mat + 1];
	for (int i = 0; i < n_mat + 1; i++) {
		dimensiones[i] = i + 100;
	}
}
/*
 * DESTRUCTOR
 */
MultEnc::~MultEnc() {
	for (int i = 0; i < n_mat; i++) {
		delete tabla[i];
	}
	delete[] tabla;
	delete[] dimensiones;
	for (int i = 0; i < n_mat; i++) {
		delete val_k[i];
	}
	delete[] val_k;
}
/*
 * MOSTRAR COSTES
 */
void MultEnc::mostrarCost() {
	for (int i = 0; i < n_mat; i++) {
		for (int j = 0; j < n_mat; j++) {
			cout << tabla[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
/*
 * MOSTRAR K
 */
void MultEnc::mostrarK() {
	for (int i = 0; i < n_mat; i++) {
		for (int j = 0; j < n_mat; j++) {
			cout << val_k[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

void MultEnc::rellenar() {
	int j = 0;
	int q = 0;
	for (int s = 0; s <= n_mat; s++) {
		for (int i = 0; i < n_mat - s - 1; i++) {
			j = i + s + 1;
			tabla[i][j] = 99999999;
			for (int k = i; k <= j; k++) {
				q = tabla[i][k - 1] + tabla[k][j]
						+ dimensiones[i] * dimensiones[k] * dimensiones[j + 1];
				if (q < tabla[i][j]) {
					tabla[i][j] = q;
					val_k[i][j] = k;
				}
			}
		}
	}
}

void MultEnc::rellenarFil() {
	int j = 0;
	int q = 0;
	for (int s = 0; s < n_mat-1; s++) {
		for (int i = s+1; i < n_mat; i++) { //Recorre diagonal
			j = s; //marca la fila
			tabla[j][i] = 99999999;
			//cout << "Pos(" << i << "," << j << ")" << endl;
			for (int k = j; k <= i; k++) {
				q = tabla[j][k - 1] + tabla[k][i]
						+ dimensiones[j] * dimensiones[k] * dimensiones[i + 1];
				if (q < tabla[j][i]) {
					tabla[j][i] = q;
					val_k[j][i] = k;
				}
			}
		}
	}
}

void MultEnc::rellenarCol() {
	int j = 0;
	int q = 0;
	for (int s = 0; s < n_mat - 1; s++) {
		for (int i = s; i >= 0; i--) { //recorre de abajo arriba la columna
			j = s + 1; //marca la columna +1 porque la primera columna queda por debajo de la diagonal
			tabla[i][j] = 99999999;
			//cout << "Pos(" << i << "," << j << ")" << endl;
			for (int k = i; k <= j; k++) {
				q = tabla[i][k - 1] + tabla[k][j]
						+ dimensiones[i] * dimensiones[k] * dimensiones[j + 1];
				if (q < tabla[i][j]) {
					tabla[i][j] = q;
					val_k[i][j] = k;
				}
			}
		}
	}
}
string MultEnc::parent(int i, int j) {
	string aux;
	string aux2;
	string aux3;
	string aux4;
	if (i == j) {
		i++;
		aux3 = "M";
		return aux3;
	} else if (i + 1 == j) {
		i++;
		j++;
		aux4 = "(MxM)";
		return aux4;
	} else {
		aux = parent(i, val_k[i][j] - 1);
		aux2 = parent(val_k[i][j], j);
		return "(" + aux + "x" + aux2 + ")";
	}
}
/*
 int MultEnc::parent(int i, int j){
 //int aux = 0;
 //int aux2 = 0;
 if(i == j){
 cout << "M" << i+1;
 i++;
 return i;
 }else if(i+1 == j){
 cout << "(M" << i+1 << "xM" << j+1 << ")";
 i++;
 j++;
 return i;
 }else{
 parent(i,val_k[i][j]-1);
 parent(val_k[i][j],j);
 //cout << aux << "x" << aux2;
 return 0;
 }
 }
 */
