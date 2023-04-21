#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <cmath>
#include "matriz.h"

using namespace std;


int main(){
	
	
	double matriz1[3][3] = {{1.0, 2.0, 3.0}, {3.0, 4.0, 5.0}, {3.0, 5.0, 6.0}};
    double matriz2[3][3] = {{1.0, 2.0, 3.0}, {3.0, 4.0, 5.0}, {3.0, 5.0, 6.0}};
    double matriz3[3][3] = {{1.0, 2.0, 5.0}, {3.0, 5.0, 6.0}, {3.0, 5.0, 6.0}};
	
	imprimirMatriz(matriz1, 3, 3);
	
	cout << "-----------------------------------" <<endl;
	
	//Test matrices iguales
    if (matricesIguales(matriz1, matriz2, 3, 3)) {
        cout << "Test matricesIguales(): passed" << endl;
    } else {
        cout << "Test matricesIguales(): failed" << endl;
    }
	
	if (!matricesIguales(matriz1, matriz3, 3, 3)) {
        cout << "Test matricesIguales(): passed" << endl;
    } else {
        cout << "Test matricesIguales(): failed" << endl;
    }
	
	cout << "-----------------------------------" <<endl;
	
	//Test transpuesta
	double m[3][3] = {{1.0, 2.0, 3.0}, {3.0, 4.0, 5.0}, {1.0, 4.0, 6.0}};
	double mT[3][3] = {{1.0, 3.0, 1.0}, {2.0, 4.0, 4.0}, {3.0, 5.0, 6.0}};
	
	transpuesta(m, 3, 3);
	
	if (matricesIguales(m, mT, 3, 3)) {
        cout << "Test transpuesta(): passed" << endl;
    } else {
        cout << "Test transpuesta(): failed" << endl;
    }
	
	cout << "-----------------------------------" <<endl;
	
	//Test multiplicacion 3x3*3x3
	double m1[3][3] = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};
    double m2[3][3] = {{9.0, 8.0, 7.0}, {6.0, 5.0, 4.0}, {3.0, 2.0, 1.0}};
	double m3[3][3] = {{30.0, 24.0, 18.0}, {84.0, 69.0, 54.0}, {138.0, 114.0, 90.0}};
    double resultado[3][3];

    mult3x3(m1, m2, resultado);
	
	if (matricesIguales(m3, resultado, 3, 3)) {
        cout << "Test mult3x3(): passed" << endl;
    } else {
        cout << "Test mult3x3(): failed" << endl;
    }
	
	cout << "-----------------------------------" <<endl;
	
	//Test multiplicacion 3x3*3x1
	double ma1[3][3] = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};
    double ma2[3][1] = {{1.0}, {2.0}, {3.0}};
	double ma3[3][1] = {{14.0}, {32.0}, {50.0}};
    double resultado2[3][1];

    mult3x1(ma1, ma2, resultado2);
	
	if (ma3[0][0]==resultado2[0][0] && ma3[1][0]==resultado2[1][0] && ma3[2][0]==resultado2[2][0]) {
        cout << "Test mult3x1(): passed" << endl;
    } else {
        cout << "Test mult3x1(): failed" << endl;
    }
	
	cout << "-----------------------------------" <<endl;
	
	//Test multiplicacion 3x3*3x1
	double matriz4[3][3] = {{184.0, 312.0, 416.0}, {348.0, 590.0, 786.0}, {414.0, 702.0, 936.0}};
	double result[3][3];
	
	mult3Matrices(matriz1, matriz2, matriz3, result);
	
	
	if (matricesIguales(matriz4, result, 3, 3)) {
        cout << "Test mult3Matrices(): passed" << endl;
    } else {
        cout << "Test mult3Matrices(): failed" << endl;
    }
	
	cout << "-----------------------------------" <<endl;
	
	
	//Test R_x
	double angle = M_PI/4;
    double rotmat[3][3];
	
	double r[3][3] ={{1.0, 0.0, 0.0},{0.0, cos(angle), sin(angle)}, {0.0, -1*sin(angle), cos(angle)}};

    R_x(angle, rotmat);
	
	if (matricesIguales(r, rotmat, 3, 3)) {
        cout << "Test R_x(): passed" << endl;
    } else {
        cout << "Test R_x(): failed" << endl;
    }
	
	
	return 0;
}