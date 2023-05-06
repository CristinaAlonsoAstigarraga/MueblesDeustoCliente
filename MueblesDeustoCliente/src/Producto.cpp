/*
 * Producto.cpp
 *
 *  Created on: 4 may 2023
 *      Author: cris.alonso
 */

#include "Producto.h"
	#include <string.h>
	#include <iostream>
	using namespace std;

Producto::Producto() {
	cod_p[0] = '\0';
	nombre[0] = '\0';
	descripcion[0] = '\0';
	cantidad = 0;
	precio = 0;
	tipo = 0;
}

Producto::Producto(char *cod, char *n, char *d, int c, double p, int t) {
	strcpy(cod_p, cod);
	strcpy(nombre, n);
	strcpy(descripcion, d);
	cantidad = c;
	precio = p;
	tipo = t;
}

Producto::Producto(const Producto &p) {
	strcpy(cod_p, p.cod_p);
	strcpy(nombre, p.nombre);
	strcpy(descripcion, p.descripcion);
	cantidad = p.cantidad;
	precio = p.precio;
	tipo = p.tipo;
}

void Producto::quitarSalto(char *cad) {

}

void Producto::modificarProducto(Producto *p) {

}
void Producto::modificarNombre(Producto *p) {

}
void Producto::modificarDescripcion(Producto *p) {

}
void Producto::modificarCantidad(Producto *p) {

}
void Producto::modificarPrecio(Producto *p) {

}

Producto::~Producto() {
}

