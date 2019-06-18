#include <iostream>
#include <cstdlib>
using namespace std;

int n = 0;

class nodo {
public:
	int nro;
	nodo *izq, *der;
	nodo * padre;

};


nodo* crearNodo(int x, nodo* padre)
{
	nodo* nuevoNodo = new nodo;
	nuevoNodo->nro = x;
	nuevoNodo->izq = NULL;
	nuevoNodo->der = NULL;
	nuevoNodo->padre = padre;

	return nuevoNodo;
}
void insertar(nodo* &arbol, int x, nodo* padre)
{
	if (arbol == NULL)
	{
		arbol = crearNodo(x, padre);
	}
	else if (x < arbol->nro)
		insertar(arbol->izq, x, arbol);
	else if (x > arbol->nro)
		insertar(arbol->der, x, arbol);
}

void agregar(nodo*& raiz, int valor) {
	if (raiz == 0) {
		raiz->nro = valor;
		raiz->izq = 0;
		raiz->der = 0;
	}
	else if (valor < raiz->nro) {
		agregar(raiz->izq, valor);
	}
	else if (valor > raiz->nro) {
		agregar(raiz->der, valor);
	}
}

//
void postOrden(nodo* raiz) {
	if (raiz != 0) {
		postOrden(raiz->izq);
		postOrden(raiz->der);
		cout << raiz->nro << endl;
	}
}
//
void preOrden(nodo* raiz) {
	if (raiz != 0) {
		cout << raiz->nro << endl;
		preOrden(raiz->izq);
		preOrden(raiz->der);
	}
}
void inOrden(nodo* raiz) {
	if (raiz != 0) {
		inOrden(raiz->izq);
		cout << raiz->nro << endl;
		inOrden(raiz->der);
	}
}

void Hojas(nodo* arbol) {
	if (arbol != NULL)
	{
		if (!arbol->der && !arbol->izq)
			cout << arbol->nro << " ";
		Hojas(arbol->izq);
		Hojas(arbol->der);

	}
}
void preOrden(nodo* arbol)
{
	if (arbol != NULL)
	{
		cout << arbol->nro << " ";
		preOrden(arbol->izq);
		preOrden(arbol->der);
	}
}

void enOrden(nodo* arbol)
{
	if (arbol != NULL)
	{
		enOrden(arbol->izq);
		cout << arbol->nro << " ";
		enOrden(arbol->der);
	}
}

void postOrden(nodo* arbol)
{
	if (arbol != NULL)
	{
		postOrden(arbol->izq);
		postOrden(arbol->der);
		cout << arbol->nro << " ";
	}
}

int tamanio(nodo* arbol, int n) {
	if (arbol != 0) {
		tamanio(arbol->izq, n);
		tamanio(arbol->der, n);
		return n + 1;
	}
}

void verArbol(nodo* arbol, int n)
{
	if (arbol == NULL)
		return;
	verArbol(arbol->der, n + 1);

	for (int i = 0; i < n; i++)
		cout << "   ";

	cout << arbol->nro << endl;

	verArbol(arbol->izq, n + 1);
}

nodo* minimo(nodo* arbol) {
	if (arbol != 0) {
		if (arbol->izq)
			return minimo(arbol->izq);
		else
			return arbol;
	}
	else
		return 0;
}
void reemplazar(nodo* arbol, nodo* nuevoNodo) {
	if (arbol->padre) {
		if (arbol->nro == arbol->padre->izq->nro) {
			arbol->padre->izq = nuevoNodo;
		}
		else if (arbol->nro == arbol->padre->der->nro) {
			arbol->padre->der = nuevoNodo;
		}
	}
	if (nuevoNodo) {
		nuevoNodo->padre = arbol->padre;
	}
}
void destruirNodo(nodo* nodoDestruir) {
	nodoDestruir->izq = 0;
	nodoDestruir->der = 0;
	delete nodoDestruir;
}

void eliminarNodo(nodo* nodoEliminar) {
	if (nodoEliminar->izq && nodoEliminar->der) { //tiene ambos hijos
		nodo* menor = minimo(nodoEliminar->der);
		nodoEliminar->nro = menor->nro;
		eliminarNodo(menor);
	}
	else if (nodoEliminar->izq) { // tiene hijo izquerdo
		reemplazar(nodoEliminar, nodoEliminar->izq);
		destruirNodo(nodoEliminar);
	}
	else if (nodoEliminar->der) { // tiene hijo derecho
		reemplazar(nodoEliminar, nodoEliminar->der);
		destruirNodo(nodoEliminar);
	}
	else {//es un nudo hoja
		reemplazar(nodoEliminar, 0);
		destruirNodo(nodoEliminar);
	}
}

void eliminar(nodo* arbol, int n) {
	if (arbol != 0) {
		if (n < arbol->nro) {
			eliminar(arbol->izq, n);
		}
		else if (n > arbol->nro) {
			eliminar(arbol->der, n);
		}
		else {
			eliminarNodo(arbol);
		}
	}
}

int main()
{
	nodo* arbol = 0;   // creado Arbol
	int opcion = 0;
	int numero;
	cout << "\n\t\t  * * * ARBOL BINARIO DE BUSQUEDA * * *  \n\n";
	do {
		cout << "\n\n1.Insertar nodo\n" <<
			"2.Pre orden\n" <<
			"3.Post orden\n" <<
			"4.In orden\n" <<
			"5.Eliminar nodo\n" <<
			"6.Imprimir datos\n" <<
			"7.Salir\n" <<
			"Opcion: ";
		cin >> opcion;
		switch (opcion) {
		case 1:

			cout << "\n\nIngrese un numero: ";
			cin >> numero;
			insertar(arbol, numero, 0);
			break;
		case 2:
			cout << "\n\n Pre Orden  :  ";   preOrden(arbol);
			break;
		case 3:
			cout << "\n\n Post Orden :  ";   postOrden(arbol);
			break;
		case 4:
			cout << "\n\n En orden   :  ";   enOrden(arbol);
			break;
		case 5:
			cout << "\n\nIngrese un numero a elimnar: ";
			cin >> numero;
			eliminar(arbol, numero);
			break;
		case 6:
			cout << " \n\ntamanio: " << tamanio(arbol, n);
			cout << " \nHojas del arbol: "; Hojas(arbol);
			break;
		case 7:
			cout << "SALIENDO DEL SISTEMA...";
			break;
		}

	} while (opcion != 7);

}