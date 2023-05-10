/*
 * Cliente.cpp
 *
 *  Created on: 4 may 2023
 *      Author: cris.alonso
 */

#include "Cliente.h"
#include <string.h>
#include <iostream>
using namespace std;

Cliente::Cliente() {
	dni[0] = '\0';
	usuario[0] = '\0';
	contrasena[0] = '\0';

}

Cliente::Cliente(char *d, char *u, char *con) {
	strcpy(dni, d);
	strcpy(usuario, u);
	strcpy(contrasena, con);
}

Cliente::Cliente(const Cliente &c) {
	strcpy(dni, c.dni);
	strcpy(usuario, c.usuario);
	strcpy(contrasena, c.contrasena);

}

Cliente Cliente::registro() {
	char get[20] = "";
	Cliente c;
	cout << "\nIntroduce tu DNI: " << endl;
	cin >> get;
	sscanf(get, "%s", c.dni);
	cout << "Introduce el nombre de usuario: " << endl;
	cin >> get;
	sscanf(get, "%s", c.usuario);
	cout << "Introduce la contrasena: " << endl;
	cin >> get;
	sscanf(get, "%s", c.contrasena);
	return c;
}

char* Cliente::getDni() {
        return dni;
}

char* Cliente::getUsuario(){
	return usuario;
}

char* Cliente::getContrasenya(){
	return contrasena;
}

Cliente::~Cliente() {
	// TODO Auto-generated destructor stub
}




//ListaClientes::ListaClientes(int numC) {
//	this->aClientes = new Cliente*[numC];
//	this->numC = numC;
//
//	for (int i = 0; i < numC; i++) {
//		aClientes[i] = NULL;
//	}
//}

void ListaClientes::anadirClientesALista(ListaClientes *lc,
		Cliente nuevoCliente) {
	Cliente *aux = new Cliente[lc->numC];
	for(int i=0;i<lc->numC;i++){
		aux[i] = lc->aClientes[i];
	}
	delete [] lc->aClientes;
	lc->aClientes = new Cliente[lc->numC + 1];
	for(int i=0;i<lc->numC;i++){
		lc->aClientes[i] = aux[i];
	}
	delete [] aux;
	lc->aClientes[lc->numC] = nuevoCliente;
	lc->numC++;
}

void ListaClientes::imprimirListaClientes(ListaClientes lc) {
	cout << "Lista de clientes de MueblesDeusto: " << endl;
	for (int i = 0; i < lc.numC; i++) {
		cout << "Cliente %d: " << i + 1 << endl;
		cout << "DNI: %s" << lc.aClientes[i].getDni() << endl;
		cout << "USUARIO: %s " << lc.aClientes[i].getUsuario() << endl;
		cout << "CONTRASENA: %s " << lc.aClientes[i].getContrasenya() << endl;
	}
}

void ListaClientes::volcarFicheroAListaClientes(ListaClientes *lc,
		char *nombreFichero) {

}

void ListaClientes::volcarListaClientesAFichero(ListaClientes *lc,
		char *nombreFichero) {

}

char* ListaClientes::buscarDniUsuario(ListaClientes lista, char *nombreUsuario) {
	for (int i = 0; i < lista.numC; i++) {
		if (strcmp(lista.aClientes[i].getUsuario(), nombreUsuario) == 0) {
			return lista.aClientes[i].getDni();
		}
	}
	return NULL;
}

ListaClientes::~ListaClientes() {
	delete[] aClientes;
}
