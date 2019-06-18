#pragma once
#include "Vertice.h"
#include <iostream>
using namespace std;
class Lista {
private:
	Vertice *primero = 0;   //Primer vertice en la lista
	Vertice *ultimo = 0;    //Ultimo vertice en la lista
	int cantidad;			 //Cantidad de vertices en la lista
	bool vacia;              //Variable booleana que me indica si está vacía o no
public:
	//Método constructor
	Lista() {
		cantidad = 0;
		vacia = true;
	}
	//Métodos accesores y modificadores
	Vertice* getPrimero() {
		return primero;
	}
	bool getVacia() {
		return vacia;
	}
	int getCantidad() {
		return cantidad;
	}

	//Este método se encarga de buscar un vértice e indicar la posición en la que se encuentra...
	//Recibe el valor que desea buscar(tipo char)
	//Retorna un entero correspondiente a la posición
	int getPos(char dato) {
		int cont = 0;
		for (Vertice *actual = primero; actual != 0; actual = actual->getSig()) {
			if (dato == actual->getDato())
				return cont;
			cont++;
		}
		return cont;
	}

	//Este meétodo busca un vértice en la posición dada e indica cuál es
	//Recibe la posición en la que se quiere buscar
	//Retorna el Vertice encontrado en esa posición
	Vertice* getVerticePorPos(int pos) {
		int cont = 0;
		for (Vertice *actual; actual != 0; actual = actual->getSig()) {
			if (cont == pos)
				return actual;
			cont++;
		}
		return 0;
	}

	//Inserta un vertice en la lista
	//Recibe el nuevo vertice
	void insertar(Vertice *nuevo) {
		if (vacia) {
			primero = nuevo;
			ultimo = nuevo;
			vacia = false;
		}
		else {
			ultimo->setSig(nuevo);
			ultimo = nuevo;
		}
		cantidad++;
	}

	void imprimir() {
		cout << "   ";
		for (Vertice *a = primero; a != 0; a = a->getSig()) {
			cout << " " << a->getDato() << " ";
		}
	}
};