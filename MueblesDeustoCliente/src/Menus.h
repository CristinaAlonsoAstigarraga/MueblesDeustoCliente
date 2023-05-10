/*
 * Menus.h
 *
 *  Created on: 4 may 2023
 *      Author: cris.alonso
 */

#ifndef SRC_MENUS_H_
#define SRC_MENUS_H_

class Menus {
public:
	static int menuInicio();
	static int menuAdmin();
	static int menuCliente();

//	Cliente inicioSesion();
	void leerConfig(char *nomfich, char *nombd);
	virtual ~Menus();
};

#endif /* SRC_MENUS_H_ */
