/*
 * Producto.h
 *
 *  Created on: 4 may 2023
 *      Author: cris.alonso
 */

#ifndef SRC_PRODUCTO_H_
#define SRC_PRODUCTO_H_

class Producto {
	char cod_p[10];
	char nombre[20];
	char descripcion[20];
	int cantidad;
	double precio;
	int tipo;
public:

	//CONSTRUCTORES
	Producto();
	Producto(char *cod, char *n, char *d, int c, double p, int t);
	Producto(const Producto &p);

	//GETTERS
	char* getCodigo();
	char* getNombre();
	char* getDescripcion();
	int getCantidad();
	double getPrecio();
	int getTipo();

	//SETTERS
	void setCodigo(char *cod);
	void setNombre(char *nom);
	void setDescripcion(char *desc);
	void setCantidad(int cantidad);
	void setPrecio(double precio);
	void setTipo(int tipo);

	//CLIENTE
	Producto nombreProductoDevolver();
	Producto codigoProductoBorrar();
	int nuevaCantidadProducto();
	Producto codigoProductoModificar();
	Producto anadirProductoBD();

};

#endif /* SRC_PRODUCTO_H_ */
