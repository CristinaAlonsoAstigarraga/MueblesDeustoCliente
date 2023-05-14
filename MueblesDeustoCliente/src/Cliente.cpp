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
	Cliente c;
	cout << "\nIntroduce tu DNI: " << endl;
	cin >> c.dni;
	cout << "Introduce el nombre de usuario: " << endl;
	cin >> c.usuario;
	cout << "Introduce la contrasena: " << endl;
	cin >> c.contrasena;
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

