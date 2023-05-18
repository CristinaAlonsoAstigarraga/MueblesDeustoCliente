#include "Carrito.h"
#include <string.h>
#include <iostream>
using namespace std;

Carrito::Carrito() {
	aProductos = NULL;
	numProductos = 0;
	dni[0] = '\0';
	importeTotal = 0;



}

Carrito::Carrito(int np, char *d, float it) {
//	this->aProductos = new Carrito*[numProductos];
	this->numProductos = np;
	strcpy(dni, d);
	this->importeTotal = it;

	for (int i = 0; i < numProductos; i++) {
//			aProductos[i] = NULL;
	}
}

Producto * Carrito::getAProductos() const{
	return this->aProductos;
}

int Carrito::getNumProductos(){
	return numProductos;
}
char *Carrito::getDni(){
	return dni;
}
float Carrito::getImporteTotal(){
	return importeTotal;
}

//Carrito::Carrito(const Carrito &c) {
//
//}

//int Carrito::mostrarCarrito(Carrito *c) {
//
//}
void Carrito::imprimirCarrito(Carrito c) {
	cout << "\nCarrito del usuario:" << c.dni << endl;
	for (int i = 0; i < c.numProductos; i++) {
		cout << endl<<"[PRODUCTO " << i + 1;
		cout << ": CODIGO: " << c.aProductos[i].getCodigo();
		cout << ", NOMBRE: " << c.aProductos[i].getNombre();
		cout << ", CANTIDAD: " << c.aProductos[i].getCantidad();
		cout << ", PRECIO: " << c.aProductos[i].getPrecio() << "]" << endl;
	}
}
void Carrito::imprimirTicket(Carrito c, char *nombreFichero) {

}
void Carrito::eliminarProductoCarrito(Carrito *carrito, Producto producto) {
	int i;
	int encontrado = 0;

	for (i = 0; i < carrito->numProductos && !encontrado; i++) {
		if (strcmp(carrito->aProductos[i].getCodigo(), producto.getCodigo())
				== 0) {
			// Producto encontrado, eliminamos y actualizamos el importe total
			carrito->importeTotal -= carrito->aProductos[i].getPrecio();
			for (int j = i; j < carrito->numProductos - 1; j++) {
				carrito->aProductos[j] = carrito->aProductos[j + 1];
			}
			carrito->numProductos--;
			i--;
			encontrado = 1;
		}
	}
	if (carrito->numProductos == 0) {
		cout << "Su carrito está vacio.\n" << endl;
	} else if (encontrado == 0) {
		cout << "\nEl producto que desea eliminar no está en su carrito."
				<< endl;
	}
}
void Carrito::aniadirProductoCarrito(Carrito *carrito, Producto p) {
	carrito->numProductos++;
	Producto* newArray = new Producto[carrito->numProductos];
	std::copy(carrito->aProductos, carrito->aProductos + carrito->numProductos - 1, newArray);
	newArray[carrito->numProductos - 1] = p;
	delete[] carrito->aProductos;
	carrito->aProductos = newArray;

}
void Carrito::comprarCarrito(Carrito *carrito) {
	carrito->numProductos = 0;
	delete[] aProductos;
	carrito->aProductos = NULL;
	carrito->importeTotal = 0.0;
}
int Carrito::menuBuscar(Carrito *c, ListaProductos lp) {
	int opcion;
	char codigoProd[20] = "";
//	Producto *p;
	do {
		cout << "\n1. Aniadir un producto a mi carrito" << endl;
		cout << "0. Volver" << endl;
		cout << "Selecciona una opción: " << endl;
		cin >> opcion;
		switch (opcion) {
		case 1:
			cout
					<< "¿Qué producto de la tienda desea añadir a su carrito? (Introduzca su codigo): "
					<< endl;
			cin >> codigoProd;
//			p = buscarProd(lp, codigoProd);
//			aniadirProductoCarrito(c, *p);
			imprimirCarrito(*c);
			break;
		case 0:
			cout << "\nAgur!" << endl;
			break;
		default:
			cout << "Error!" << endl;
			break;
		}
	} while (opcion != 0);
	return opcion;
}

Carrito::~Carrito() {
	delete[] aProductos;
}

