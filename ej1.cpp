#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>

using namespace std;

//memoria estática
const int N=361;
double Cnm[N][N];
double Snm[N][N];

/*
Procedimiento:

1. Abrimos el fichero "egm.txt" y comprobamos si se ha abierto correctamente.
2. Leemos los valores del fichero y los almacenamos en las matrices Cnm y Snm.
3. Mostramos algunos valores de las matrices Cnm y Snm.

*/

int main(){
	
	FILE *fp;
	double temp[6];
	
	fp = fopen("egm.txt", "r");
	
	if(fp == NULL){
		cout << "No se ha podido abrir el archivo egm.txt" << endl;
		return 0;
	}
	for(int n=0; n<361; n++){
		for(int m=0; m<=n; m++){
			fscanf(fp, "%hd %hd %lf %lf %lf %lf", &temp[0], &temp[1], &temp[2], &temp[3], &temp[4], &temp[5]);
			Cnm[n][m]=temp[2];
			Snm[n][m]=temp[3];
		}
	}
	fclose(fp);
	
	cout << Cnm[0][0] << " " << Snm[0][0] <<endl;
	cout << Cnm[1][0] << " " << Snm[1][0] <<endl;
	cout << Cnm[2][0] << " " << Snm[2][0] <<endl;
	cout << Cnm[2][1] << " " << Snm[2][1] <<endl;
	
	return 0;
}