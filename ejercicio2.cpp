#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <stdio.h>
#include <cstring>

using namespace std;

//memoria dinámica
//en c++ hay que borrar la memoria 

/*

Procedimiento:

1. Declaramos un puntero a FILE llamado fp.
2. Abrimos el archivo de texto "eop19620101.txt" comprobando que se ha abierto correctamente.
3. Creamos una matriz dinámica de tamaño 19716 x 13, llamada matriz, usando el operador new.
4. Leemos el fichero usando la función fscanf(), y los guardamos en la matriz.
5. Mostramos por pantalla las tres primeras filas de la matriz.
6. Liberamos la memoria reservada para la matriz con el operador delete.
*/

int main(){
	
	FILE *fp;
	
	fp = fopen("eop19620101.txt", "r");
	
	if(fp == NULL){
		cout << "No se ha podido abrir el archivo eop19620101.txt" << endl;
		return 0;
	}
	
	double **matriz =new double*[19716];
	for (int i=0; i<19716; i++){
		matriz[i] = new double[13];
	}
	
		for(int i=0; i<19716; i++){
		fscanf(fp, "%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf", &matriz[i][0], &matriz[i][1], &matriz[i][2], &matriz[i][3], &matriz[i][4],
		&matriz[i][5], &matriz[i][6], &matriz[i][7], &matriz[i][8], &matriz[i][9], &matriz[i][10], &matriz[i][11], &matriz[i][12]);
	}
	
	// Imprimir las tres primeras filas de la matriz
	for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 13; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
	
	for (int i=0; i<19716; i++){
		delete[] matriz[i];
	}
	delete [] matriz;
	
	fclose(fp);
	
	return 0;
}