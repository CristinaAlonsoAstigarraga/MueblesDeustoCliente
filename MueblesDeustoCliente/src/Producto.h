/*
 * Producto.h
 *
 *  Created on: 4 may 2023
 *      Author: cris.alonso
 */

#ifndef SRC_PRODUCTO_H_
#define SRC_PRODUCTO_H_
//#include "CategoriaProducto.h"
//#include "ListaProductos.h"

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
	double getPrecio();
	char * getCodigo();
	char * getNombre();
	char * getDescripcion();
	int getTipo();
	int getCantidad();



	//CLIENTE
	Producto nombreProductoDevolver();
	Producto codigoProductoBorrar();
	int nuevaCantidadProducto();
	Producto codigoProductoModificar();
	Producto anadirProductoBD();
	void setCantidad(int cantidad);
	void setPrecio(double precio);
	void setTipo(int tipo);
	void setCodigo(char * cod);
	void setNombre(char * nom);
	void setDescripcion(char * desc);
};


#endif /* SRC_PRODUCTO_H_ */
