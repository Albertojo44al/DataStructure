#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include "Vertice.h"
#include "Lista.h"
#include "Grafo.h"

using namespace std;

int main() {
	Grafo *grafo = new Grafo();
	bool salir = false;
	system("cls");
	while (!salir) {
		cout << "1. Insertar Conexion" << endl;
		cout << "2. Borrar Conexion" << endl;
		cout << "3. Imprimir matriz" << endl;
		cout << "4. Salir" << endl;
		cout << endl;
		int opcion = 0;
		cin >> opcion;
		switch (opcion) {
		case 1: {
			system("cls");
			char valor1 = 0;
			char valor2 = 0;
			cout << "Ingrese el primer valor: ";
			cin >> valor1;
			cout << "Ingrese el segundo valor: ";
			cin >> valor2;
			grafo->insertarConexion(valor1, valor2);
			continue;
		}
		case 2: {
			system("cls");
			char valor1 = 0;
			char valor2 = 0;
			cout << "Ingrese el primer valor: ";
			cin >> valor1;
			cout << "Ingrese el segundo valor: ";
			cin >> valor2;
			grafo->borrarConexion(valor1, valor2);
			continue;
		} 
		case 3: {
			system("cls");
			grafo->imprimirMatrizAdyacencia();
			continue;
		}
		case 4: {
			salir = true;
			continue;
		}
		}
	}
}