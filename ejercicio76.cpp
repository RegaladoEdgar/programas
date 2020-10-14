/*Autor: Edgar Eduardo Regalado Lopez
Programa que soluciona el problema: "Un experimento consiste
en lanzar una moneda hasta que salga águila. Hacer un programa
para efecuar 2,000 el experimento y contar el número de 
lanzamientos requeridos en cada caso. Imprimir la distribución
*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

// un experimento para contabilizar los intentos antes de obtener
// un águila
class Experimento {
private:
	bool finalizado;
	int contador_intentos;
public:
	Experimento();
	void lanzar();
	int consumir();
	bool getFinalizado();
};

// comienza el experimento
Experimento::Experimento() {
	this->finalizado = false;
	this->contador_intentos = 0;
}

void Experimento::lanzar() {
	if(rand() % 2 == 0) {// 0 significa sol
		this->contador_intentos++;
	} else { //águila, terminamos
		if(this->contador_intentos == 0) {
			/* si no se han registrado los intentos,
			entonces se obtuvo águila al primer intento
			entonces se debe de contar como 1 intento y
			no como 0 intentos
			*/
			this->contador_intentos = 1;
		}
		this->finalizado = true;
	}
}

bool Experimento::getFinalizado() {
	return this->finalizado;
}

// reinicia todas las variables del objeto, retornando el número de
// experimentos antes de obtener águila
int Experimento::consumir() {
	if(!this->finalizado) { //si no ha finalizado, no se puede consumir
		throw "No se puede consumir un experimento sin finalizar";
	} else {
		int regreso = this->contador_intentos;
		this->contador_intentos = 0;
		this->finalizado = false;
		return regreso;
	}
}


int main() {

	srand(time(NULL)); //inicializa los valores pseudoaleatorios
	const int experimentos = 2000;
	int distribucion[experimentos];

	Experimento experimento = Experimento();
	
	for(int i = 0; i < experimentos; i++) {
		while(!experimento.getFinalizado()) { //mientras no de águila
			experimento.lanzar();
		}
		//cuando de águila
		distribucion[i] = experimento.consumir();
	}

	// hora de generar la distribución de frecuencias
	// a partir de la distribución obtenida

	//primero buscar cada número que ocurre en la distribución
	map<int, int> frecuencias;

	//registrar todos los números que aparecen
	for(int i = 0; i < experimentos; i++) {
		if(frecuencias.find(distribucion[i]) == frecuencias.end()) {
			frecuencias[distribucion[i]] = 0; //crea una nueva frecuencia a contar
		}
	}

	//registrar las frecuencias de cada número
	for(int i = 0; i < experimentos; i++) {
		if(frecuencias.find(distribucion[i]) != frecuencias.end()) { //para el numero
			frecuencias[distribucion[i]]++;
		}
	}

	//mostrar la distribución final
	map<int, int>::iterator it;
	for(it = frecuencias.begin(); it != frecuencias.end(); it++) {
		cout << it->first << "-> " << it->second << endl;
	}

}
