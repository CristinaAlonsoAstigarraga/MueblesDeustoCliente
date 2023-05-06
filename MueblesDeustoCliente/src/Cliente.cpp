///*
// * Cliente.cpp
// *
// *  Created on: 4 may 2023
// *      Author: cris.alonso
// */
//
//#include "Cliente.h"
//#include <string.h>
//#include <iostream>
//using namespace std;
//
//Cliente::Cliente() {
//	dni[0] = '\0';
//	usuario[0] = '\0';
//	contrasena[0] = '\0';
//
//}
//
//Cliente::Cliente(char *d, char *u, char *con) {
//	strcpy(dni, d);
//	strcpy(usuario, u);
//	strcpy(contrasena, con);
//}
//
//Cliente::Cliente(const Cliente &c) {
//	strcpy(dni, c.dni);
//	strcpy(usuario, c.usuario);
//	strcpy(contrasena, c.contrasena);
//
//}
//
//Cliente::Cliente registro() {
//
//}
//
//Cliente::~Cliente() {
//	// TODO Auto-generated destructor stub
//}
//
//ListaClientes::ListaClientes(int numC) {
//	this->aClientes = new Cliente*[numC];
//	this->numC = numC;
//
//	for (int i = 0; i < numC; i++) {
//		aClientes[i] = NULL;
//	}
//}
//void ListaClientes::anadirClientesALista(ListaClientes *lc,
//		Cliente nuevoCliente) {
//
//}
//void ListaClientes::imprimirListaClientes(ListaClientes lc) {
//
//}
//void ListaClientes::volcarFicheroAListaClientes(ListaClientes *lc,
//		char *nombreFichero) {
//
//}
//void ListaClientes::volcarListaClientesAFichero(ListaClientes *lc,
//		char *nombreFichero) {
//
//}
//char* ListaClientes::buscarDniUsuario(ListaClientes lista,
//		char *nombreUsuario) {
//
//}
//void ListaClientes::liberarMemoria(ListaClientes *lc) {
//
//}
//ListaClientes::~ListaClientes() {
//
//}
