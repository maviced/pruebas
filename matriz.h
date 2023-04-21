#ifndef _IMPRIMIRMATRIZ_
#define _IMPRIMIRMATRIZ_

void imprimirMatriz(double matriz[][3], int filas, int columnas);

#endif


#ifndef _MATRICESIGUALES_
#define _MATRICESIGUALES_


bool matricesIguales(double matriz1[][3], double matriz2[][3], int filas, int columnas);

#endif


#ifndef _TRANSPUESTA_
#define _TRANSPUESTA_

void transpuesta(double matriz[][3], int filas, int columnas);

#endif


#ifndef _MULT3X3_
#define _MULT3X3_

void mult3x3(double matriz1[3][3], double matriz2[3][3], double resultado[3][3]);

#endif


#ifndef _MULT3X1_
#define _MULT3X1_

void mult3x1(double matriz1[3][3], double matriz2[3][1], double resultado[3][1]);

#endif

#ifndef _MULT3MATRICES_
#define _MULT3MATRICES_

void mult3Matrices(double matriz1[3][3], double matriz2[3][3], double matriz3[3][3], double resultado[3][3]);

#endif


#ifndef _RX_
#define _RX_

void R_x(double angle, double rotmat[3][3]);

#endif
