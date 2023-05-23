#ifndef CARRITO_H_
#define CARRITO_H_
#include "Producto.h"
#include "ListaProductos.h"
class Carrito {
	Producto *aProductos;
	int numProductos;
	char dni[10];
	float importeTotal;
public:

	//CONSTRUCTORES:
	Carrito();
	Carrito(int np, char *d, float it);

	//GETTERS:
	Producto* getAProductos() const;
	int getNumProductos();
	char* getDni();
	float getImporteTotal();

	//CLIENTE:
	void eliminarProductoCarrito(Carrito *carrito, Producto producto);
	void aniadirProductoCarrito(Carrito *carrito, Producto p);
	void comprarCarrito(Carrito *carrito);

	//ADMIN:
	void imprimirCarrito(Carrito c, char *nombreCliente);
	void imprimirTicket(Carrito c, char *nombreFichero);
	int menuBuscar(Carrito *c, ListaProductos lp);

	virtual ~Carrito();
};

#endif /* CARRITO_H_ */
