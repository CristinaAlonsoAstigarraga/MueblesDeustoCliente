/*
 * CategoriaProducto.cpp
 *
 *  Created on: 4 may 2023
 *      Author: cris.alonso
 */

#include "CategoriaProducto.h"
#include <string.h>
#include <iostream>
using namespace std;

CategoriaProducto::CategoriaProducto() {
	// TODO Auto-generated constructor stub

}

int CategoriaProducto::imprimirListaCategorias() {
	int categoria;
	char get[2] = "";
	cout << "\nIntroduce una categoria (0 - MESAS, 1 - SILLAS, 2 - SOFAS): "
			<< endl;
	cin >> get;
	sscanf(get, "%d", &categoria);
	return categoria;
}

//const char* CategoriaProducto::obtenerNombreCategoria(CategoriaProducto categoria) {
//	switch (categoria) {
//	case MESAS:
//		return "MESAS";
//	case SILLAS:
//		return "SILLAS";
//	case SOFAS:
//		return "SOFAS";
//	default:
//		return "DESCONOCIDO";
//	}
//}


CategoriaProducto::~CategoriaProducto() {
	// TODO Auto-generated destructor stub
}

