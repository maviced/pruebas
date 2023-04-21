#include <iostream>
#include <cmath>
#include "matriz.h"


using namespace std;

/*
Entradas:

- matriz: matriz bidimensional de tipo double que queremos mostrar por pantalla.
- filas: número de filas de la matriz.
- columnas: número de columnas de la matriz.

Pre: 
Post: Muestra por pantalla la matriz matriz.

*/

void imprimirMatriz(double matriz[][3], int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

/*
Entradas:

- matriz1: matriz bidimensional de tipo double que queremos comprobar.
- matriz2: matriz bidimensional de tipo double que queremos comprobar.
- filas: número de filas de las matrices.
- columnas: número de columnas de las matrices.

Pre: Las matrices matriz1 y matriz2 tienen que tener el mismo tamaño.
Post: Devuelve verdadeo si la matriz matriz1 es igual a la matriz2, es decir, que sus elementos sean iguales y falso en caso contrario.

*/

bool matricesIguales(double matriz1[][3], double matriz2[][3], int filas, int columnas) {
    
    // Comprobar si los elementos de las matrices son iguales
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (matriz1[i][j] != matriz2[i][j]) {
                return false;
            }
        }
    }
    return true;
}

/*

Entradas:

- matriz: matriz bidimensional de tipo double que queremos transponer.
- filas: número de filas de la matriz.
- columnas: número de columnas de la matriz.

Pre: 
Post: Función que calcula la matriz transpuesta de la matriz matriz.

*/
void transpuesta(double matriz[][3], int filas, int columnas) {
    double aux;
    for (int i = 0; i < filas; i++) {
        for (int j = i+1; j < columnas; j++) {
            aux = matriz[i][j];
            matriz[i][j] = matriz[j][i];
            matriz[j][i] = aux;
        }
    }
}


/*

Entradas:

- matriz1: matriz bidimensional de tipo double que queremos multiplicar.
- matriz2: matriz bidimensional de tipo double que queremos multiplicar.
- resultado: matriz bidimensional de tipo double resultado de la multiplicacion.

Pre: matriz1, matriz2 y resultado son de dimensiones 3x3.
Post: Calcula la multiplicacion de matriz1 por matriz2 y guarda el resultado en la matriz resultado.

*/
void mult3x3(double matriz1[3][3], double matriz2[3][3], double resultado[3][3]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            resultado[i][j] = 0;
            for(int k = 0; k < 3; k++) {
                resultado[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }
}


/*

Entradas:

- matriz1: matriz bidimensional de tipo double que queremos multiplicar.
- matriz2: matriz bidimensional de tipo double que queremos multiplicar.
- resultado: matriz bidimensional de tipo double resultado de la multiplicacion.

Pre: matriz1 es de dimensiones 3x3, y matriz2 y resultado son de dimensiones 3x1.
Post: Calcula la multiplicacion de matriz1 por matriz2 y guarda el resultado en la matriz resultado.

*/
void mult3x1(double matriz1[3][3], double matriz2[3][1], double resultado[3][1]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 1; j++) {
			resultado[i][j] = 0;
			for (int k = 0; k < 3; k++) {
				resultado[i][j] += matriz1[i][k] * matriz2[k][j];
			}
		}
        
    }
}


/*

Entradas:

- matriz1: matriz bidimensional de tipo double que queremos multiplicar.
- matriz2: matriz bidimensional de tipo double que queremos multiplicar.
- matriz3: matriz bidimensional de tipo double que queremos multiplicar.
- resultado: matriz bidimensional de tipo double resultado de la multiplicacion.

Pre: matriz1, matriz2, matriz3 y resultado son de dimensiones 3x3.
Post: Calcula la multiplicacion de matriz1, matriz2 y matriz3, y guarda el resultado en la matriz resultado.

*/
void mult3Matrices(double matriz1[3][3], double matriz2[3][3], double matriz3[3][3], double resultado[3][3]) {
    double result[3][3];
	mult3x3(matriz1, matriz2, result);
	mult3x3(result, matriz3, resultado);
}



void R_x(double angle, double rotmat[3][3]) {
	
	double C, S;
    C = cos(angle);
    S = sin(angle);
    rotmat[0][0] = 1.0; rotmat[0][1] = 0.0; rotmat[0][2] = 0.0;
    rotmat[1][0] = 0.0; rotmat[1][1] = C; rotmat[1][2] = S;
    rotmat[2][0] = 0.0; rotmat[2][1] = -1.0*S; rotmat[2][2] = C;
}