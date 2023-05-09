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
	Cliente();
	Cliente(char *d, char *u, char *con);
	Cliente(const Cliente &c);
	Cliente registro();
	char* getDni();
	char * getUsuario();
	char * getContrasenya();
	virtual ~Cliente();
};

class ListaClientes : public Cliente{
	Cliente *aClientes;
	int numC;
public:
	ListaClientes(int numC);
	void anadirClientesALista(ListaClientes *lc, Cliente nuevoCliente);
	void imprimirListaClientes (ListaClientes lc);
	void volcarFicheroAListaClientes(ListaClientes *lc, char *nombreFichero);
	void volcarListaClientesAFichero(ListaClientes *lc, char *nombreFichero);
	char* buscarDniUsuario(ListaClientes lista, char* nombreUsuario);
	void liberarMemoria(ListaClientes *lc);
	virtual ~ListaClientes();
};

#endif /* SRC_CLIENTE_H_ */
