#ifndef CARRITO_H_
#define CARRITO_H_
#include "Producto.h"

class Carrito{
	Producto *aProductos;
	int numProductos;
	char dni[10];
	float importeTotal;
public:
	Carrito();
	Carrito(int np, char *d, float it);
//	Carrito(const Carrito &c);
	int mostrarCarrito(Carrito *c);
	static void imprimirCarrito(Carrito c);
	void imprimirTicket (Carrito c, char *nombreFichero);
	static void eliminarProductoCarrito(Carrito *carrito, Producto producto);//el puntero de nombre no es 100% correcrto, hasta que se pergunte a marian
	static void aniadirProductoCarrito(Carrito* carrito, Producto p);
	void comprarCarrito(Carrito *carrito);
	int menuBuscar(Carrito *c, ListaProductos lp);
	virtual ~Carrito();
};

#endif /* CARRITO_H_ */
