/* Autor: Edgar Eduardo Regalado Lopez

programa que resuelve el problema: "5 estudiantes obtuvieron las 
notas en su examen final: 75, 93, 41, 98, 71. Escribir un programa
para calcular el promedio de de esas notas" 
*/

#include <iostream>
using namespace std;

int main() {

	int calificaciones[] = {75, 93, 41, 98, 71};
	int tamano = 5;

	int sumatoria = 0;

	cout << "Calificaciones: ";
	for(int i = 0; i < tamano; i++) {
		cout << calificaciones[i] << ", ";
		sumatoria += calificaciones[i];
	}
	cout << endl;

	cout << "promedio: " << (double) sumatoria / tamano << endl;

	return 0;
}
