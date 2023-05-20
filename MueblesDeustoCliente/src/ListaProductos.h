#ifndef SRC_LISTAPRODUCTOS_H_
#define SRC_LISTAPRODUCTOS_H_
#include "Producto.h"
#include <iostream>
using namespace std;
class ListaProductos {
	Producto *aProductos;
	int tam, numProductos;
public:
	ListaProductos();
	ListaProductos(int numProductos);
	ListaProductos buscarProducto(ListaProductos lp, int categoria);
	void volcarFicheroAListaProductos(ListaProductos *lp, char *nombreFichero);
	void anadirProducto(ListaProductos *lp);
	void aniadirProductoLista(const Producto &p);
	void eliminarProducto(Producto p, ListaProductos *lp);
	void imprimir();
	virtual ~ListaProductos();
};

#endif /* SRC_LISTAPRODUCTOS_H_ */
