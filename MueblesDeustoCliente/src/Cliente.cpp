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

//CONSTRUCTORES:
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

//GETTERS:
char* Cliente::getDni() {
	return dni;
}

char* Cliente::getUsuario() {
	return usuario;
}

char* Cliente::getContrasenya() {
	return contrasena;
}

//CLIENTE:
Cliente Cliente::registro() {
	Cliente c;
	cout << "\nIntroduce tu DNI: " << endl;
	cin >> c.dni;
	cout << "Introduce el nombre de usuario: " << endl;
	cin >> c.usuario;
	cout << "Introduce la contrasena: " << endl;
	cin >> c.contrasena;
	return c;
}

Cliente Cliente::inicioSesion() {
	Cliente c;
	cout << "\nIntroduce el nombre de usuario: ";
	cin >> c.usuario;
	cout << "Introduce la contrasenya: ";
	cin >> c.contrasena;
	return c;
}

Cliente::~Cliente() {
	// TODO Auto-generated destructor stub
}

