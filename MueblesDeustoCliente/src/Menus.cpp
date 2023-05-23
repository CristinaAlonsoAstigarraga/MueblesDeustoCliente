/*
 * Menus.cpp
 *
 *  Created on: 4 may 2023
 *      Author: cris.alonso
 */

#include "Menus.h"
#include <string.h>
#include <iostream>
using namespace std;

int Menus::menuInicio() {
	int opcion = 0;
	cout << "\nMENÚ INICIO: " << endl;
	cout << "---------------------- " << endl;
	cout << "1. Registrarse " << endl;
	cout << "2. Iniciar sesion " << endl;
	cout << "0. Salir" << endl;
	cout << "Selecciona una opción: " << endl;
	cin >> opcion;
	return opcion;

}
int Menus::menuAdmin() {
	int opcion = 0;
	cout << "\nMENÚ ADMIN: " << endl;
	cout << "---------------------- " << endl;
	cout << "1. Anadir un producto " << endl;
	cout << "2. Modificar un producto " << endl;
	cout << "3. Eliminar un producto " << endl;
	cout << "4. Mostrar almacen " << endl;
	cout << "5. Estadisticas " << endl;
	cout << "0. Salir " << endl;
	cout << "Selecciona una opción: " << endl;
	cin >> opcion;
	return opcion;
}
int Menus::menuCliente() {
	int opcion = 0;
	cout << "\nMENÚ CLIENTE: " << endl;
	cout << "---------------------- " << endl;
	cout << "1. Visualizar el carrito de la compra " << endl;
	cout << "2. Devolver un producto " << endl;
	cout << "3. Visualizar los productos de la tienda " << endl;
	cout << "4. Buscar un producto " << endl;
	cout << "0. Salir " << endl;
	cout << "Selecciona una opción: " << endl;
	cin >> opcion;
	return opcion;
}

Menus::~Menus() {
}

