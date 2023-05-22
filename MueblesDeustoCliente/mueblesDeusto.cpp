// IMPORTANT: Winsock Library ("ws2_32") should be linked

#include <stdio.h>
#include <winsock2.h>
#include <iostream>
#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 6000
using namespace std;
#include "src/Menus.h"
#include "src/Producto.h"
#include "src/Cliente.h"
#include "src/Carrito.h"
#include "src/ListaProductos.h"
#include "string.h"

ListaProductos recibirListaProductos(char *recvBuff, SOCKET s) {
	ListaProductos *lp;
	int tam;
	int cantidad, tipo;
	double precio;
	recv(s, recvBuff, sizeof(recvBuff), 0);
	sscanf(recvBuff, "%i", &tam);
//	cout << "Recibido: " << tam << endl;
	lp = new ListaProductos(tam);
	Producto p;
	for (int i = 0; i < tam; i++) {
		recvBuff[0]='\0';
		recv(s, recvBuff, sizeof(recvBuff), 0);
//		cout << "Recibido: " << recvBuff << endl;
		p.setCodigo(recvBuff);
		recvBuff[0]='\0';
		recv(s, recvBuff, sizeof(recvBuff), 0);
		p.setNombre(recvBuff);
		recvBuff[0]='\0';
		recv(s, recvBuff, sizeof(recvBuff), 0);
		p.setDescripcion(recvBuff);
		recvBuff[0]='\0';
		recv(s, recvBuff, sizeof(recvBuff), 0);
		sscanf(recvBuff, "%i", &cantidad);
		p.setCantidad(cantidad);
		recvBuff[0]='\0';
		recv(s, recvBuff, sizeof(recvBuff), 0);
		sscanf(recvBuff, "%lf", &precio);
		p.setPrecio(precio);
		recvBuff[0]='\0';
		recv(s, recvBuff, sizeof(recvBuff), 0);
		sscanf(recvBuff, "%i", &tipo);
		p.setTipo(tipo);

		//Con el resto de los campos

		lp->aniadirProductoLista(p);
	}

	return *lp;
}
int main(int argc, char *argv[]) {

	WSADATA wsaData;
	SOCKET s;
	struct sockaddr_in server;
	char sendBuff[512], recvBuff[512];

	/*
	 * En sendBuff guardaremos lo que el cliente le env�a al servidor
	 * En recvBuff guardaremos lo que el servidor le env�a al cliente
	 * */
	printf("\nInitialising Winsock...\n");
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
		printf("Failed. Error Code : %d", WSAGetLastError());
		return -1;
	}

	printf("Initialised.\n");

	//SOCKET creation
	if ((s = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
		printf("Could not create socket : %d", WSAGetLastError());
		WSACleanup();
		return -1;
	}

	printf("Socket created.\n");

	server.sin_addr.s_addr = inet_addr(SERVER_IP); //INADDR_ANY;
	server.sin_family = AF_INET;
	server.sin_port = htons(SERVER_PORT);

	//CONNECT to remote server
	if (connect(s, (struct sockaddr*) &server, sizeof(server)) == SOCKET_ERROR) {
		printf("Connection error: %d", WSAGetLastError());
		closesocket(s);
		WSACleanup();
		return -1;
	}

	printf("Connection stablished with: %s (%d)\n", inet_ntoa(server.sin_addr),
			ntohs(server.sin_port));

	/*EMPIEZA EL PROGRAMA DEL CLIENTE*/

	Cliente nuevoCliente;
	Cliente inicio;
	ListaProductos *lp;
	ListaProductos *lp2;
	Producto p;
	Producto codigoDevolver;
	Producto nombreProductoModificar;
	Producto nombreProductoEliminar;
	Producto caro;
	Producto mayorCantidad;
	int cantidad, tipo;
	double precio;
	int sillas, mesas, sofas, categoria;
	ListaProductos listaCat;

	char nom[20];
	int opcion = 10, opcion2 = 10, opcion3 = 10, i, clienteExiste, adminExiste,
			modif = 0, nuevaCantidad, elim = 0;
	Producto nuevoProducto;
	do {
		opcion = Menus::menuInicio();
		sprintf(sendBuff, "%i", opcion);
		send(s, sendBuff, sizeof(sendBuff), 0);

		switch (opcion) {
		case 1:
			nuevoCliente = nuevoCliente.registro();
			sprintf(sendBuff, "%s", nuevoCliente.getDni());
			send(s, sendBuff, sizeof(sendBuff), 0);

			recv(s, recvBuff, sizeof(recvBuff), 0);
			sscanf(recvBuff, "%d", &clienteExiste);
			if (clienteExiste) {
				cout << "El cliente ya existe" << endl;
			} else {
				cout << "Procedemos a registrar al cliente" << endl;
				sprintf(sendBuff, "%s", nuevoCliente.getUsuario());
				send(s, sendBuff, sizeof(sendBuff), 0);
				sprintf(sendBuff, "%s", nuevoCliente.getContrasenya());
				send(s, sendBuff, sizeof(sendBuff), 0);

			}
			break;
		case 2:
			clienteExiste = 0;
			adminExiste = 0;
			inicio = inicio.inicioSesion();
			sprintf(sendBuff, "%s", inicio.getUsuario());
			send(s, sendBuff, sizeof(sendBuff), 0);
			sprintf(sendBuff, "%s", inicio.getContrasenya());
			send(s, sendBuff, sizeof(sendBuff), 0);

			recv(s, recvBuff, sizeof(recvBuff), 0);
			sscanf(recvBuff, "%s", inicio.getDni());

			recv(s, recvBuff, sizeof(recvBuff), 0);
			sscanf(recvBuff, "%d", &clienteExiste);
			recv(s, recvBuff, sizeof(recvBuff), 0);
			sscanf(recvBuff, "%d", &adminExiste);

			if (clienteExiste) {
				cout << "¡Bienvenido a MueblesDeusto!" << endl;
				/*Carrito *carritoCliente = new Carrito[sizeof(Carrito)];
				carritoCliente->getAProductos() = NULL;
				carritoCliente->getNumProductos() = 0;		//GETTER O SETTER?
				strcpy(carritoCliente->getDni(), inicio.getDni());
				carritoCliente->getImporteTotal() = 0;
				*/
				do {
					opcion2 = Menus::menuCliente();
					sprintf(sendBuff, "%i", opcion2);
					send(s, sendBuff, sizeof(sendBuff), 0);

					switch (opcion2) {
					case 1:
//						if(carritoCliente->getNumProductos() == 0){
//							cout<<"No tienes ningun producto en el carrito"<<endl;
//						}else{
//							carritoCliente->imprimirCarrito(*carritoCliente);
//						}
//						cout << endl
//						<< "¿Estás seguro de  un producto? (si: 1, no: 0): "
//						<< endl;
//						cin >> modif;
						break;
					case 2:
						*lp = recibirListaProductos(recvBuff, s);
						lp->imprimirListaProductos(*lp);
						codigoDevolver =
								codigoDevolver.nombreProductoDevolver();
						sprintf(sendBuff, "%s", codigoDevolver.getCodigo());
						send(s, sendBuff, sizeof(sendBuff), 0);
						*lp = recibirListaProductos(recvBuff, s);
						lp->imprimirListaProductos(*lp);
						break;
					case 3:
						*lp = recibirListaProductos(recvBuff, s);
						lp->imprimirListaProductos(*lp);
						break;
					case 4:
						cout << endl
								<< "Introduce una categoria (0 - MESAS, 1 - SILLAS, 2 - SOFAS): ";
						cin >> categoria;
//						sprintf(sendBuff, "%i", categoria);
//						send(s, sendBuff, sizeof(sendBuff), 0);
						*lp = recibirListaProductos(recvBuff, s);
//						lp->imprimirListaProductos(*lp);
						listaCat = *(listaCat.buscarProducto(*lp, categoria));
						cout<<listaCat.numProductos<<endl;
						listaCat.imprimirListaProductos(listaCat);
						break;
					case 0:
						cout << endl << "Agur!" << endl << endl;
						break;
					}
				} while (opcion2 != 0);

			} else if (adminExiste) {
				cout << "¡Bienvenido a MueblesDeusto!" << endl;
				do {
					opcion2 = Menus::menuAdmin();
					sprintf(sendBuff, "%i", opcion2);
					send(s, sendBuff, sizeof(sendBuff), 0);

					switch (opcion2) {
					case 1:
						nuevoProducto = nuevoProducto.anadirProductoBD();
						sprintf(sendBuff, "%s", nuevoProducto.getCodigo());
						send(s, sendBuff, sizeof(sendBuff), 0);
						sprintf(sendBuff, "%s", nuevoProducto.getNombre());
						send(s, sendBuff, sizeof(sendBuff), 0);
						sprintf(sendBuff, "%s", nuevoProducto.getDescripcion());
						send(s, sendBuff, sizeof(sendBuff), 0);
						sprintf(sendBuff, "%i", nuevoProducto.getCantidad());
						send(s, sendBuff, sizeof(sendBuff), 0);
						sprintf(sendBuff, "%lf", nuevoProducto.getPrecio());
						send(s, sendBuff, sizeof(sendBuff), 0);
						sprintf(sendBuff, "%i", nuevoProducto.getTipo());
						send(s, sendBuff, sizeof(sendBuff), 0);

						break;
					case 2:
						cout << endl
								<< "¿Estás seguro de querer modificar un producto? (si: 1, no: 0): "
								<< endl;
						cin >> modif;
						if (modif == 1) {
							nombreProductoModificar =
									nombreProductoModificar.codigoProductoModificar();
							cout << "Introduce la nueva cantidad del producto: "
									<< endl;
							cin >> nuevaCantidad;
							//Enviamos la nueva cantidad
							sprintf(sendBuff, "%i", nuevaCantidad);
							send(s, sendBuff, sizeof(sendBuff), 0);

							//Enviamos el código del producto que vamos a modificar.
							sprintf(sendBuff, "%s",
									nombreProductoModificar.getCodigo());
							send(s, sendBuff, sizeof(sendBuff), 0);

						}

						break;
					case 3:
						cout << endl
								<< "¿Estás seguro de querer eliminar un producto? (si: 1, no: 0): "
								<< endl;
						cin >> elim;
						if (elim == 1) {
							nombreProductoEliminar =
									nombreProductoEliminar.codigoProductoBorrar();
							//Enviamos el código del producto que vamos a borrar.
							sprintf(sendBuff, "%s",
									nombreProductoEliminar.getCodigo());
							send(s, sendBuff, sizeof(sendBuff), 0);

						}
						break;
					case 4:
						*lp = recibirListaProductos(recvBuff, s);
						lp->imprimirListaProductos(*lp);

						break;
					case 5:
						cout << "ESTADÍSTICAS DE MUEBLES DEUSTO: " << endl
								<< endl;

						//PRODUCTO MÁS CARO DE LA TIENDA
						*lp = recibirListaProductos(recvBuff, s);
						caro = lp->masCaro(*lp);
						cout << "1. PRODUCTO MÁS CARO DE LA TIENDA: " << endl;
						cout << "	[Código: " << caro.getCodigo() << ", Nombre: "
								<< caro.getNombre() << ", Descripción: "
								<< caro.getDescripcion() << ", Cantidad: "
								<< caro.getCantidad() << ", Precio: "
								<< caro.getPrecio();
						if (caro.getTipo() == 0) {
							cout << ", Categoria: MESAS]" << endl;
						} else if (caro.getTipo() == 1) {
							cout << ", Categoria: SILLAS]" << endl;
						} else if (caro.getTipo() == 2) {
							cout << ", Categoria: SOFAS]" << endl;
						} else {
							cout << ", Categoria: Desconocida]" << endl;
						}

						//NÚMERO DE PRODUCTOS EN CADA CATEGORÍA
						cout << endl
								<< "2. NÚMERO DE PRODUCTOS EN CADA CATEGORÍA: "
								<< endl;
						mesas = 0;
						mesas = lp->numProductosCategoria(*lp, 0);
						sillas = 0;
						sillas = lp->numProductosCategoria(*lp, 1);
						sofas = 0;
						sofas = lp->numProductosCategoria(*lp, 2);
						cout << " 	MESAS: " << mesas << endl;
						cout << " 	SILLAS: " << sillas << endl;
						cout << " 	SOFÁS: " << sofas << endl;

						//PRODUCTO CON MAYOR CANTIDAD EN LA TIENDA
						mayorCantidad = lp->masCantidad(*lp);
						cout << endl
								<< "3. EL PRODUCTO CON MAYOR CANTIDAD EN LA TIENDA: "
								<< endl;
						cout << "	[Código: " << mayorCantidad.getCodigo()
								<< ", Nombre: " << mayorCantidad.getNombre()
								<< ", Descripción: "
								<< mayorCantidad.getDescripcion()
								<< ", Cantidad: " << mayorCantidad.getCantidad()
								<< ", Precio: " << mayorCantidad.getPrecio();
						if (mayorCantidad.getTipo() == 0) {
							cout << ", Categoria: MESAS]" << endl;
						} else if (mayorCantidad.getTipo() == 1) {
							cout << ", Categoria: SILLAS]" << endl;
						} else if (mayorCantidad.getTipo() == 2) {
							cout << ", Categoria: SOFAS]" << endl;
						} else {
							cout << ", Categoria: Desconocida]" << endl;
						}

						break;
					case 0:
						cout << endl << "Agur!" << endl << endl;
						break;
					}
				} while (opcion2 != 0);
			} else {
				cout << endl << "El usuario no está registrado." << endl;
			}
			break;
		case 0:
			cout << endl << "Agur!" << endl << endl;
			break;
		default:
			cout << endl << "Error" << endl;
			break;
		}

	} while (opcion != 0);

	/*ACABA EL PROGRAMA DEL CLIENTE*/
	// CLOSING the socket and cleaning Winsock...
	closesocket(s);
	WSACleanup();

	return 0;
}
