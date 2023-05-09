#include "Carrito.h"
#include <string.h>
#include <iostream>
using namespace std;

//Carrito::Carrito() {
//	aProductos = new Carrito[strlen+1];
//	numProductos = 0;
//	dni[0] = '\0';
//	importeTotal = 0;
//
//
//
//}

Carrito::Carrito(int np, char *d, float it) {
//	this->aProductos = new Carrito*[numProductos];
	this->numProductos = np;
	strcpy(dni, d);
	this->importeTotal = it;

	for (int i = 0; i < numProductos; i++) {
//			aProductos[i] = NULL;
	}
}

//Carrito::Carrito(const Carrito &c) {
//
//}

//int Carrito::mostrarCarrito(Carrito *c) {
//
//}
void Carrito::imprimirCarrito(Carrito c) {
	cout << "\nCarrito del usuario '%s':" << c.dni << endl;
	for (int i = 0; i < c.numProductos; i++) {
		cout << "[PRODUCTO %d: " << i + 1 << endl;
		cout << "CODIGO: %s, " << c.aProductos[i].getCodigo() << endl;
		cout << "NOMBRE: %s, " << c.aProductos[i].getNombre() << endl;
		cout << "CANTIDAD: %d, " << c.aProductos[i].getCantidad() << endl;
		cout << "PRECIO: %.2f]" << c.aProductos[i].getPrecio() << endl;
	}
}
void Carrito::imprimirTicket(Carrito c, char *nombreFichero) {

}
void Carrito::eliminarProductoCarrito(Carrito *carrito, Producto producto) {
	int i;
	int encontrado = 0;

	for (i = 0; i < carrito->numProductos && !encontrado; i++) {
		if (strcmp(carrito->aProductos[i].getCodigo(), producto.getCodigo()) == 0) {
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

}
void Carrito::comprarCarrito(Carrito *carrito) {
	carrito->numProductos = 0;
	delete[] aProductos;
	carrito->aProductos = NULL;
	carrito->importeTotal = 0.0;
}
int Carrito::menuBuscar(Carrito *c, ListaProductos lp) {
	int opcion;
	char get[20] = "";
	char codigoProd[20] = "";
//	Producto *p;
	do {
		cout<<"\n1. Aniadir un producto a mi carrito"<<endl;
		cout<<"0. Volver"<<endl;
		cout<<"Selecciona una opción: "<<endl;
		cin>>get;
		sscanf(get, "%d", &opcion);
		switch (opcion) {
		case 1:
			cout<<"¿Qué producto de la tienda desea añadir a su carrito? (Introduzca su codigo): "<<endl;
			cin>>get;
			sprintf(codigoProd, "%s", get);
//			p = buscarProd(lp, codigoProd);
//			aniadirProductoCarrito(c, *p);
			imprimirCarrito(*c);
			break;
		case 0:
			cout<<"\nAgur!"<<endl;
			break;
		default:
			cout<<"Error!"<<endl;
			break;
		}
	} while (opcion != 0);
	return opcion;
}

Carrito::~Carrito() {
	delete[] aProductos;
}

