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
	if (cad[strlen(cad) - 1] == '\n')
		cad[strlen(cad) - 1] = '\0';
}

Producto Producto::nombreProductoDevolver() {
	char get[20] = "";
	Producto p;
	cout<< "\n¿Qué producto desea devolver? (introduzca el codigo del producto): "<< endl;
	cin >> get;
	sprintf(p.cod_p, "%s", get);
	return p;
}

Producto Producto::codigoProductoBorrar() {
	char get[20] = "";
	Producto p;
	cout<< "\n¿Qué producto desea eliminar? (introduzca el código del producto): "<< endl;
	cin >> get;
	sprintf(p.cod_p, "%s", get);
	return p;
}

double Producto::getPrecio(){
	return precio;
}

char * Producto::getCodigo(){
	return cod_p;
}

char * Producto::getNombre(){
	return nombre;
}

int Producto::getCantidad(){
	return cantidad;
}

int Producto::nuevaCantidadProducto() {
	int nuevaCantidad;
	char get[1000] = "";
	cout << "Introduce la nueva cantidad del producto: " << endl;
	cin >> get;
	sscanf(get, "%d", &nuevaCantidad);
	return nuevaCantidad;
}

Producto Producto::codigoProductoModificar() {
	char get[20] = "";
	Producto p;
	cout
			<< "\n¿Qué producto desea modificar? (introduzca el código del producto): "
			<< endl;
	cin >> get;
	sprintf(p.cod_p, "%s", get);
	return p;
}

Producto Producto::anadirProductoBD() {
	char get[20] = "";
	Producto p;
	cout<<"\nIntroduce los datos del nuevo producto: "<<endl;
	cout<<"Codigo: "<<endl;
	cin>>get;
	quitarSalto(get);
	sprintf(p.cod_p, "%s", get);
	cout<<"Nombre: "<<endl;
	cin>>get;
	quitarSalto(get);
	sprintf(p.nombre, "%s", get);
	cout<<"Descripcion: "<<endl;
	cin>>get;
	quitarSalto(get);
	sprintf(p.descripcion, "%s", get);
	cout<<"Cantidad: "<<endl;
	cin>>get;
	quitarSalto(get);
	sscanf(get, "%i", &p.cantidad);
	cout<<"Precio: "<<endl;
	cin>>get;
	quitarSalto(get);
	sscanf(get, "%lf", &p.precio);
	cout<<"Categoria: "<<endl;
	cin>>get;
	quitarSalto(get);
	sscanf(get, "%d", &p.tipo);
	return p;
}

//No hemos reservado memoria para nada, no hay nada que destruir.
//Producto::~Producto() {
//
//}



//LISTA PRODUCTOS:


