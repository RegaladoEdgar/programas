/* Autor Edgar Eduardo Regalado Lopez
Programa que resuelve el problema: "Encontrar la inversión promedio en
en banco si la libreta registró los siguientes valores el primer día
de cada año: $1000, $1040, $1081.6, $1124.86*/

#include <iostream>

using namespace std;

int main() {
	int tamano = 4;
	double valores[] = {1000, 1040, 1081.60, 1124.86};

	double sumatoria = 0.0;
	//sumatoria
	for(int i = 0; i < tamano; i++) {
		sumatoria += valores[i];
	}

	double promedio = sumatoria / tamano;

	cout << "Inversión promedio: " << promedio << endl;
}
