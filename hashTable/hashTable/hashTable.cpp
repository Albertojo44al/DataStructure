#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<Math.h>
#include<fstream>

using namespace std;


struct no_hash
{
	int data;
	int state; /* 0 para VACIO, 1 para REMOVIDO e 2 para OCUPADO */
};
// Calcula la función de distribución
int funcion(int k, int m, int i)
{
	return ((k + i) % m);
}
// Crea la tabla hash 
no_hash *Crea_Hash(int m)
{
	no_hash *temp;
	int i;
	if ((temp = (no_hash*)malloc(m * sizeof(no_hash))) != NULL)
	{
		for (i = 0; i < m; i++)
			temp[i].state = 0;
		return temp;
	}
	else
		exit(0);
}
// Inserta un elemento k en la tabla T de tamañ m
void Inserta_Hash(no_hash *T, int m, int k)
{
	int j, i = 0;
	do
	{
		j = funcion(k, m, i);
		if (T[j].state == 0 || T[j].state == 1)
		{
			T[j].data = k;
			T[j].state = 2;
			cout << "\nElemento insertado con éxito!";
			return;
		}
		else
			i++;
	} while (i < m);
	cout << "\nTabla llena!";
}
int Busca_Hash(no_hash *T, int m, int k, int i)
{
	int j;
	if (i < m)
	{
		j = funcion(k, m, i);
		if (T[j].state == 0)
			return -1;
		else
			if (T[j].state == 1)
				return Busca_Hash(T, m, k, i + 1);
			else
				if (T[j].data == k)
					return j;
				else
					return Busca_Hash(T, m, k, i + 1);
	}
	return -1;
}
int Remove_Hash(no_hash *T, int m, int k)
{
	int i;
	i = Busca_Hash(T, m, k, 0);
	if (i == -1)
		return -1;
	else
	{
		T[i].state = 1;
		return 1;
	}
}
void main()
{
	int m, i, k;
	int resp;
	no_hash *T;
	cout << "\nEntre con el tamaño de la tabla: ";
	cin >> m;
	T = Crea_Hash(m);
	while (1)
	{
		cout << "\n1.Insertar \n2.Buscar  \n3.Remover  \n4.Salir \n";
		cin >> resp;
		switch (resp)
		{
		case 1:
			cout << "\nIngrese el número a ser insertado en la tabla: ";
			cin >> k;
			Inserta_Hash(T, m, k);
			break;
		case 2:
			cout << "\nIngrese el número a ser buscado en la tabla: ";
			cin >> k;
			i = Busca_Hash(T, m, k, 0);
			if (i == -1)
				cout << "\nNumero no encontrado!";
			else
				cout << "\nNumero encontrado!";
			break;
		case 3:
			cout << "\nIngrese el número a ser eliminado de la tabla: ";
			cin >> k;
			i = Remove_Hash(T, m, k);
			if (i == -1)
				cout << "\nNumero no encontrado!";
			else
				cout << "\nNumero eliminado con éxito!";
			break;
		case 4:
			exit(0);
			break;
		}
	}
}