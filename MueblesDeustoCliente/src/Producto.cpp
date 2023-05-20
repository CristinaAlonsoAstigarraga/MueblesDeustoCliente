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

Producto Producto::nombreProductoDevolver() {
	Producto p;
	cout
			<< "\n¿Qué producto desea devolver? (introduzca el codigo del producto): "
			<< endl;
	cin >> p.cod_p;
	return p;
}

Producto Producto::codigoProductoBorrar() {
	Producto p;
	cout
			<< "\n¿Qué producto desea eliminar? (introduzca el código del producto): "
			<< endl;
	cin >> p.cod_p;
	return p;
}

double Producto::getPrecio() {
	return precio;
}

char* Producto::getCodigo() {
	return cod_p;
}

char* Producto::getNombre() {
	return nombre;
}

int Producto::getCantidad() {
	return cantidad;
}


char * Producto::getDescripcion(){
	return descripcion;
}

int Producto::getTipo(){
	return tipo;
}

int Producto::nuevaCantidadProducto() {
	int nuevaCantidad;
	char get[1000] = "";
	cout << "Introduce la nueva cantidad del producto: " << endl;
	cin >> nuevaCantidad;
	return nuevaCantidad;
}

Producto Producto::codigoProductoModificar() {
	Producto p;
	cout << "\n¿Qué producto desea modificar? (introduzca el código del producto): " << endl;
	cin >> p.cod_p;
	return p;
}

Producto Producto::anadirProductoBD() {
	Producto p;
	cout << "\nIntroduce los datos del nuevo producto: " << endl;
	cout << "Codigo: " << endl;
	cin >> p.cod_p;
	cout << "Nombre: " << endl;
	cin >> p.nombre;
	cout << "Descripcion: " << endl;
	cin >> p.descripcion;
	cout << "Cantidad: " << endl;
	cin >> p.cantidad;
	cout << "Precio: " << endl;
	cin >> p.precio;
	cout << "Categoria: " << endl;
	cin >> p.tipo;
	return p;
}

void Producto::setCantidad(int cantidad) {
	this->cantidad = cantidad;
}

void Producto::setPrecio(double precio) {
	this->precio = precio;
}

void Producto::setTipo(int tipo) {
	this->tipo = tipo;
}

void Producto::setCodigo(char * cod){
	strcpy(cod_p,cod);
}
//No hemos reservado memoria para nada, no hay nada que destruir.
//Producto::~Producto() {
//
//}
