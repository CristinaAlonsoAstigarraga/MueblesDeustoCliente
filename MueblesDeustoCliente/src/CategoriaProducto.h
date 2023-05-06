/*
 * CategoriaProducto.h
 *
 *  Created on: 4 may 2023
 *      Author: cris.alonso
 */

#ifndef SRC_CATEGORIAPRODUCTO_H_
#define SRC_CATEGORIAPRODUCTO_H_

class CategoriaProducto {
	enum Tipo {
		MESAS = 0, SILLAS = 1, SOFAS = 2
	};
public:
	CategoriaProducto();
	int imprimirListaCategorias();
	const char* obtenerNombreCategoria(CategoriaProducto categoria);
	virtual ~CategoriaProducto();
};

#endif /* SRC_CATEGORIAPRODUCTO_H_ */
