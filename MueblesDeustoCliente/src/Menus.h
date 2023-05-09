/*
 * Menus.h
 *
 *  Created on: 4 may 2023
 *      Author: cris.alonso
 */

#ifndef SRC_MENUS_H_
#define SRC_MENUS_H_
#include "Cliente.h"

class Menus : public Cliente{
public:
	Menus();
	int menuInicio();
	int menuAdmin();
	int menuCliente();

	Cliente inicioSesion();
	void leerConfig(char *nomfich, char *nombd);
	virtual ~Menus();
};

#endif /* SRC_MENUS_H_ */
