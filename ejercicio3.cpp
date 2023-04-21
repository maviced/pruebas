#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

/*

Procedimiento:

1. Abrimos el fichero GEOS3.txt utilizando ifstream y compruebamos si se ha abierto correctamente.
2. Almacenamos en tline cada línea del fichero de entrada GEOS3.txt.
3. Utilizamos while que extrae y procesa cada línea fichero, almacenando los valores en las variables correspondientes y luego msotramos dichos valores por pantalla.

*/

int main(){
	
	
	
	string tline;
	int Y, M, D, h, m;
    double s, az, el, Dist;
	
	ifstream fichGEO("GEOS3.txt");
	
	if (!fichGEO.is_open()) {
		cout << "No se pudo abrir el archivo GEOS3.txt" << endl;
		return 0;
	}
	
	
	while(getline(fichGEO, tline)){
		
		Y = stoi(tline.substr(0, 4));
        M = stoi(tline.substr(5, 2));
        D = stoi(tline.substr(8, 2));
        h = stoi(tline.substr(12, 2));
        m = stoi(tline.substr(15, 2));
        s = stod(tline.substr(18, 6));
        az = stod(tline.substr(25, 8));
        el = stod(tline.substr(35, 7));
        Dist = stod(tline.substr(44, 10));
		
		
		
		cout << Y << " " << M << " " << D << " " << h << " " << m << " " << fixed << setprecision(2) << s << " " << fixed << setprecision(4) << az << " " << el << " " << Dist << std::endl;
	}
	
	fichGEO.close();
	
	return 0;
	
}