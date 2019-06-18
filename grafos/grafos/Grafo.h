#pragma once
#include "Lista.h"

class Grafo {
private:
	Lista *listaDeVertices = new Lista();  //Lista de vertices en el grafo
	int tamanio = 20;						   //Tamanio del grafo, default
	int matrizDeAdyacencia[20][20];        //Matriz de adyacencia
public:

	Grafo() {
	}

	//inserta un vertice a la lista de vertices
	void insertarVertice(Vertice *pNuevoVertice) {
		listaDeVertices->insertar(pNuevoVertice);
	}

	//Valida la existencia de vertice, si no esta lo inserta y retorna false, si esta solo retorna true
	bool validarExistencia(int verticeOrigen, int verticeFinal) {
		bool encontradoOrigen = false;
		bool encontradoFinal = false;
		for (Vertice *actual = listaDeVertices->getPrimero(); actual != NULL; actual = actual->getSig()) {
			if (actual->getDato() == verticeOrigen) encontradoOrigen = true;
			if (actual->getDato() == verticeFinal) encontradoFinal = true;
		}

		if (!encontradoOrigen) listaDeVertices->insertar(new Vertice(verticeOrigen));
		if (!encontradoFinal) listaDeVertices->insertar(new Vertice(verticeFinal));
		if (!encontradoOrigen || !encontradoFinal) return false;
		else return true;
	}
	//Inserta una conexion entre dos vertices
	void insertarConexion(char verticeOrigen, char verticeFinal) {
		validarExistencia(verticeOrigen, verticeFinal);
		int posicionOrigen = listaDeVertices->getPos(verticeOrigen);
		int posicionFinal = listaDeVertices->getPos(verticeFinal);
		for (int i = 0; i < tamanio; i++) {
			if (i == posicionOrigen) {
				for (int j = 0; j < tamanio; j++) {
					if (j == posicionFinal) matrizDeAdyacencia[i][j] = 1;
				}
			}
		}
	}
	//Borra una conexion
	void borrarConexion(char verticeOrigen, char verticeFinal) {
		if (validarExistencia(verticeOrigen, verticeFinal)) {
			int posicionOrigen = listaDeVertices->getPos(verticeOrigen);
			int posicionFinal = listaDeVertices->getPos(verticeFinal);
			for (int i = 0; i < tamanio; i++) {
				if (i == posicionOrigen) {
					for (int j = 0; j < tamanio; j++) {
						if (j == posicionFinal) {
							matrizDeAdyacencia[i][j] = 0;
							break;
						}
					}
				}
			}
		}
		else printf("No existe esta conexion\n");
	}

	void imprimirMatrizAdyacencia() {
		if (!listaDeVertices->getVacia()) {
			listaDeVertices->imprimir();
			cout << endl;
			for (Vertice *actual = listaDeVertices->getPrimero(); actual != NULL; actual = actual->getSig()) {
				cout << actual->getDato();
				cout << "  ";
				for (int i = 0; i < listaDeVertices->getCantidad(); i++) {
					cout << " " << matrizDeAdyacencia[listaDeVertices->getPos(actual->getDato())][i] << " ";
				}
				cout << endl;
				cout << endl;
			}
		}
		else cout << "Matriz de Adyacencia Vacia" << endl;
	}
};



