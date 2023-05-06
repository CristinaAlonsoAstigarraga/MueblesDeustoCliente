/*
 * Producto.h
 *
 *  Created on: 4 may 2023
 *      Author: cris.alonso
 */

#ifndef SRC_PRODUCTO_H_
#define SRC_PRODUCTO_H_
#include "CategoriaProducto.h"

class Producto {
	char cod_p[10];
	char nombre[20];
	char descripcion[20];
	int cantidad;
	double precio;
	int tipo;
public:
	Producto();
	Producto(char *cod, char *n, char *d, int c, double p, int t);
	Producto(const Producto &p);
	void quitarSalto(char *cad);
	//ADMIN
	void modificarProducto(Producto *p);
	void modificarNombre(Producto *p);
	void modificarDescripcion(Producto *p);
	void modificarCantidad(Producto *p);
	void modificarPrecio(Producto *p);
	virtual ~Producto();
};

class ListaProductos: public CategoriaProducto {
	Producto *aProductos;
	int numProductos;
public:
	ListaProductos();
	ListaProductos(int numProductos);
	ListaProductos buscarProducto(ListaProductos lp, CategoriaProducto c);
	void volcarFicheroAListaProductos(ListaProductos *lp, char *nombreFichero);
	void anadirProducto(ListaProductos *lp);
	void eliminarProducto(Producto p, ListaProductos *lp);
	virtual ~ListaProductos();
};

#endif /* SRC_PRODUCTO_H_ */
