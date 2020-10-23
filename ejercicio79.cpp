/* Autor Edgar Eduardo Regalado Lopez

Programa que resuelve el problema: "Encontrar el promedio de 1,000 números
tomados al azar
*/

#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
	srand(time(NULL)); //iniciar el generador aleatorio

	int tamano = 1000;
	double sumatoria = 0;
	int numero = 0;
	for(int i = 0; i < tamano; i++) {
		numero = rand() % 1000; //numero del 0 al 1000
		cout << "(" << i + 1 << ": " << numero << ")" << ",";
		sumatoria += numero;
 	}
	cout << endl;

 	cout << "promedio: " << (double) sumatoria / tamano << endl;
	return 0;
}
