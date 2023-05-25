#ifndef SRC_LISTAPRODUCTOS_H_
#define SRC_LISTAPRODUCTOS_H_
#include "Producto.h"
#include <iostream>
using namespace std;
class ListaProductos {
	Producto *aProductos;
	int tam, numProductos;
public:

	//CONSTRUCTORES:
	ListaProductos();
	ListaProductos(int numProductos);

	//GETTERS:
	int getNumProductos();

	//ADMIN
	ListaProductos* buscarProducto(ListaProductos lp, int categoria);
	void aniadirProductoLista(const Producto &p);
	Producto masCaro(ListaProductos lp);
	void imprimir();
	int numProductosCategoria(ListaProductos lp, int categoria);
	Producto masCantidad(ListaProductos lp);
	void imprimirListaProductos();
	Producto* buscarProd(ListaProductos lista, char *codigo);
	virtual ~ListaProductos();
};

#endif /* SRC_LISTAPRODUCTOS_H_ */
