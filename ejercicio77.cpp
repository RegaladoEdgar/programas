/* autor Edgar Eduardo Regalado Lopez

Programa que resuelve el problema: "Determinar
la media, mediana y moda del siguiente conjunto de valores:
153, 158, 161, 157, 150, 153, 149, 153, 155, 162
*/

#include <iostream>
#include <algorithm>

using namespace std;

double obtener_media(int arreglo[], int tamano) {
	int sumatoria = 0;
	for(int i = 0; i < tamano; i++) {
		sumatoria += arreglo[i]; //sumatoria de cada elemento
	}

	return (double) sumatoria / tamano;
}

double obtener_mediana(int arreglo[], int tamano) {
	sort(arreglo, arreglo + tamano);
	int mitad = tamano / 2;
	if(tamano % 2 == 0) { // numero par
		return (double) (arreglo[mitad] + arreglo[mitad - 1]) / 2;
	} else {
		return arreglo[mitad];
	}
}

int obtener_moda(int arreglo[], int tamano) {
	sort(arreglo, arreglo + tamano);
	int moda_actual = 0;
	int mayor_moda = 0;
	int repeticiones = 0;
	int repeticiones_actual = 0;
	
	for(int i = 0; i < tamano; i++) {
		//primera vez
		if(i == 0) {
			moda_actual = arreglo[i];
			mayor_moda = moda_actual;
			repeticiones = 1;
			repeticiones_actual = 1;
		} else {
			if(arreglo[i] == moda_actual) {
				repeticiones_actual++;
			} else { //cambio el numero
				if(repeticiones_actual > repeticiones) {
					mayor_moda = moda_actual;
				}
				moda_actual = arreglo[i];
				repeticiones_actual = 1;
			}
		}

	}

	return mayor_moda;
}


int main() {

	int tamano_arreglo = 10;
	int arreglo[] = {153, 162, 161, 158, 150, 157, 149, 153, 155, 153};
	
	cout << "Arreglo: " << endl;
	for(int i = 0; i < tamano_arreglo; i++) {
		cout << arreglo[i] << ", ";
	}
	cout << endl;

	cout << "Media: " << obtener_media(arreglo, tamano_arreglo)
		<< endl;

	cout << "Mediana: " << obtener_mediana(arreglo, tamano_arreglo)
		<< endl;

	cout << "Moda: " << obtener_moda(arreglo, tamano_arreglo)
		<< endl;
	return 0;
}
