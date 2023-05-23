/*
 * Cliente.h
 *
 *  Created on: 4 may 2023
 *      Author: cris.alonso
 */

#ifndef SRC_CLIENTE_H_
#define SRC_CLIENTE_H_

class Cliente {
	char dni[10];
	char usuario[20];
	char contrasena[20];
public:

	//CONSTRUCTORES:
	Cliente();
	Cliente(char *d, char *u, char *con);
	Cliente(const Cliente &c);

	//GETTERS:
	char* getDni();
	char* getUsuario();
	char* getContrasenya();

	//CLIENTE:
	Cliente registro();
	Cliente inicioSesion();

	virtual ~Cliente();
};
#endif /* SRC_CLIENTE_H_ */
