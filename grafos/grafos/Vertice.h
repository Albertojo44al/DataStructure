#pragma once

class Vertice {
private:
	char dato;
	Vertice *sig;
public:

	Vertice(char dato) {
		this->dato = dato;
		sig = 0;
	}

	void setDato(char dato) {
		this->dato = dato;
	}

	char getDato() {
		return dato;
	}

	Vertice* getSig() {
		return sig;
	}

	void setSig(Vertice *sig) {
		this->sig = sig;
	}
};
