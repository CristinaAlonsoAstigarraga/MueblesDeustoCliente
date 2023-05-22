#ifndef SRC_LISTAPRODUCTOS_H_
#define SRC_LISTAPRODUCTOS_H_
#include "Producto.h"
#include <iostream>
using namespace std;
class ListaProductos {
	Producto *aProductos;
	public:
	int tam, numProductos;
public:
	ListaProductos();
	ListaProductos(int numProductos);
	ListaProductos* buscarProducto(ListaProductos lp, int categoria);
	void volcarFicheroAListaProductos(ListaProductos *lp, char *nombreFichero);
	void anadirProducto(ListaProductos *lp);
	void aniadirProductoLista(const Producto &p);
	void eliminarProducto(Producto p, ListaProductos *lp);
	int getNumProductos();
	void imprimir();
	virtual ~ListaProductos();
	Producto masCaro(ListaProductos lp);
	int numProductosCategoria(ListaProductos lp, int categoria);
	Producto masCantidad(ListaProductos lp);
	void imprimirListaProductos(ListaProductos lp);
};

#endif /* SRC_LISTAPRODUCTOS_H_ */
