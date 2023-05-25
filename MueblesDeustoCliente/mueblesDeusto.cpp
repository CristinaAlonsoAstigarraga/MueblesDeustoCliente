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

/**
 * Método para recibir una lista de productos desde el lado del servidor.
 */
ListaProductos recibirListaProductos(char *recvBuff, SOCKET s) {
	ListaProductos *lp;
	int tam;
	int cantidad, tipo;
	double precio;
	recv(s, recvBuff, sizeof(recvBuff), 0);
	sscanf(recvBuff, "%i", &tam);
	lp = new ListaProductos(tam);
	Producto p;
	int n;
	for (int i = 0; i < tam; i++) {
		recvBuff[0] = '\0';
		n=recv(s, recvBuff, sizeof(recvBuff), 0);
		sprintf(recvBuff,"%s",recvBuff);
		cout<<"Recibido "<<recvBuff<<endl;
		p.setCodigo(recvBuff);
		recvBuff[0] = '\0';
		n=recv(s, recvBuff, sizeof(recvBuff), 0);
		//recvBuff[n]='\0';
		sprintf(recvBuff,"%s",recvBuff);
		cout<<"Recibido "<<recvBuff<<endl;
		p.setNombre(recvBuff);
		recvBuff[0] = '\0';
		n=recv(s, recvBuff, sizeof(recvBuff), 0);
		//recvBuff[n]='\0';
		sprintf(recvBuff,"%s",recvBuff);
		cout<<"Recibido "<<recvBuff<<endl;
		p.setDescripcion(recvBuff);
		recvBuff[0] = '\0';
		n=recv(s, recvBuff, sizeof(recvBuff), 0);
		//recvBuff[n]='\0';
		sprintf(recvBuff,"%s",recvBuff);
		cout<<"Recibido "<<recvBuff<<endl;

		sscanf(recvBuff, "%i", &cantidad);
		p.setCantidad(cantidad);
		recvBuff[0] = '\0';
		n=recv(s, recvBuff, sizeof(recvBuff), 0);
		//recvBuff[n]='\0';
		sprintf(recvBuff,"%s",recvBuff);
		cout<<"Recibido "<<recvBuff<<endl;

		sscanf(recvBuff, "%lf", &precio);
		p.setPrecio(precio);
		recvBuff[0] = '\0';
		n=recv(s, recvBuff, sizeof(recvBuff), 0);
		//recvBuff[n]='\0';
		sprintf(recvBuff,"%s",recvBuff);
		cout<<"Recibido "<<recvBuff<<endl;

		sscanf(recvBuff, "%i", &tipo);
		p.setTipo(tipo);
		lp->aniadirProductoLista(p);
	}
	lp->imprimirListaProductos();
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

	//Clientes:
	Cliente nuevoCliente;
	Cliente inicio;

	//Listas de Productos:
	ListaProductos *lp;
	ListaProductos *lpModif;
	ListaProductos *lpBor;
	ListaProductos listaCat;

	//Productos:
	Producto p;
	Producto codigoDevolver;
	Producto nombreProductoModificar;
	Producto nombreProductoEliminar;
	Producto caro;
	Producto mayorCantidad;
	Producto comprar;
	Producto borrar;
	Producto nuevoProducto;

	//Carritos:
	Carrito *carritoCliente = new Carrito(0, inicio.getDni(), 0);

	//Enteros, doubles y cadenas:
	int opcion = 10, opcion2 = 10, opcion3 = 10, opcion4 = 10, clienteExiste,
			adminExiste, modif = 0, nuevaCantidad, elim = 0;
	int sillas, mesas, sofas, categoria, borrarP;
	char *nombreProductoComprar;
	char *codProductoBorrar;

	//MENÚ PRINCIPAL
	do {
		opcion = Menus::menuInicio();
		sprintf(sendBuff, "%i", opcion);
		send(s, sendBuff, sizeof(sendBuff), 0);

		switch (opcion) {
		case 1:	//REGISTRO DE UN NUEVO CLIENTE
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
		case 2:	//INICIO DE SESION (DE CLIENTE O DE ADMIN)
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
				cout << endl << "¡Bienvenido a MueblesDeusto!" << endl;
				do {	//INICIO DE SESIoN DE CLIENTE Y SU MENÚ
					opcion2 = Menus::menuCliente();
					sprintf(sendBuff, "%i", opcion2);
					send(s, sendBuff, sizeof(sendBuff), 0);

					switch (opcion2) {
					case 1:	//VISUALIZAR EL CARRITO DE LA COMPRA
						do {
							carritoCliente->imprimirCarrito(*carritoCliente,
									inicio.getDni());
							cout << endl << "1. Comprar" << endl;
							cout << "2. Eliminar producto" << endl;
							cout << "0. Volver" << endl;
							cout << "Selecciona una opcion: ";
							cin >> opcion3;
							switch (opcion3) {
							case 1:	//COMPRAR EL CARRITO DE LA COMPRA
								if (carritoCliente->getNumProductos() == 0) {
									cout << "El carrito esta vacio." << endl;
								} else {
									//imprimirTicket(*carritoCliente, "Ticket");
									cout
											<< "Numero de productos en el carrito del cliente ANTES DE LA COMPRA: "
											<< carritoCliente->getNumProductos()
											<< endl;
									carritoCliente->comprarCarrito(
											carritoCliente);
									cout
											<< "La compra se ha realizado con exito y su ticket de la compra ha sido generado."
											<< endl;
									cout
											<< "Numero de productos en el carrito del cliente DESPUeS DE LA COMPRA: "
											<< carritoCliente->getNumProductos()
											<< endl;
								}
								break;
							case 2: //ELIMINAR UN PRODUCTO DEL CARRITO DE LA COMPRA
								cout << endl
										<< "Estas seguro de que desea eliminar un producto de su carrito? (1: si, 0: no)"
										<< endl;
								cin >> borrarP;
								if (borrarP == 1) {
									carritoCliente->imprimirCarrito(
											*carritoCliente,
											inicio.getUsuario());
									cout << endl
											<< "Introduce el codigo del producto que desee eliminar del carrito: "
											<< endl;
									cin >> codProductoBorrar;
									borrar.setCodigo(codProductoBorrar);
									carritoCliente->eliminarProductoCarrito(
											carritoCliente, borrar);
									cout << endl
											<< "Producto eliminado correctamente"
											<< endl;
									carritoCliente->imprimirCarrito(
											*carritoCliente,
											inicio.getUsuario());
								} else {
									break;
								}
								break;
							case 0:	//VOLVER
								break;
							}
						} while (opcion3 != 0);
						break;
					case 2:	//DEVOLVER UN PRODUCTO
						*lp = recibirListaProductos(recvBuff, s);
						lp->imprimirListaProductos();
						codigoDevolver =
								codigoDevolver.nombreProductoDevolver();
						sprintf(sendBuff, "%s", codigoDevolver.getCodigo());
						send(s, sendBuff, sizeof(sendBuff), 0);
						*lp = recibirListaProductos(recvBuff, s);
						lp->imprimirListaProductos();
						break;
					case 3: //VISUALIZAR TODOS LOS PRODUCTOS DE LA TIENDA
						*lp = recibirListaProductos(recvBuff, s);
						lp->imprimirListaProductos();
						break;
					case 4:	//BUSCAR UN PRODUCTO EN LA TIENDA - POR CATEGORIAS
						cout << endl
								<< "Introduce una categoria (0 - MESAS, 1 - SILLAS, 2 - SOFAS): ";
						cin >> categoria;
						*lp = recibirListaProductos(recvBuff, s);
						listaCat = *(listaCat.buscarProducto(*lp, categoria));
						listaCat.imprimirListaProductos();

						//COMPRAR UN PRODUCTO DESDE LA BÚSQUEDA
						do {
							cout << endl
									<< "1. Aniadir un producto a mi carrito"
									<< endl;
							cout << "0. Volver" << endl;
							cout << "Selecciona una opcion: ";
							cin >> opcion4;
							switch (opcion4) {
							case 1:	//COMPRAR UN PRODUCTO
								cout << endl
										<< "¿Que producto de la tienda desea añadir a su carrito? (Introduzca su codigo): ";
								cin >> nombreProductoComprar;
								comprar.setCodigo(nombreProductoComprar);
								lp->buscarProd(*lp, comprar.getCodigo());
								carritoCliente->aniadirProductoCarrito(
										carritoCliente, comprar);
								carritoCliente->imprimirCarrito(*carritoCliente,
										inicio.getUsuario());
								break;
							case 0:	//VOLVER
								cout << endl << "Agur!" << endl;
								break;
							}
						} while (opcion4 != 0);
						break;
					case 0:
						cout << endl << "Agur!" << endl << endl;
						break;
					}
				} while (opcion2 != 0);

			} else if (adminExiste) {//INICIO DE SESIoN ADMINISTRADOR Y SU MENÚ
				cout << "¡Bienvenido a MueblesDeusto!" << endl;
				do {
					opcion2 = Menus::menuAdmin();
					sprintf(sendBuff, "%i", opcion2);
					send(s, sendBuff, sizeof(sendBuff), 0);

					switch (opcion2) {
					case 1:	//AÑADIR UN PRODUCTO A LA BBDD DE LA TIENDA
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
					case 2:	//MODIFICAR UN PRODUCTO DE LA BBDD DE LA TIENDA
						cout << endl
								<< "¿Estas seguro de querer modificar un producto? (si: 1, no: 0): "
								<< endl;
						cin >> modif;

						if (modif == 1) {
							*lp = recibirListaProductos(recvBuff, s);
							lp->imprimirListaProductos();
							nombreProductoModificar =
									nombreProductoModificar.codigoProductoModificar();
							cout << "Introduce la nueva cantidad del producto: "
									<< endl;
							cin >> nuevaCantidad;
							//Enviamos la nueva cantidad
							sprintf(sendBuff, "%i", nuevaCantidad);
							send(s, sendBuff, sizeof(sendBuff), 0);

							//Enviamos el codigo del producto que vamos a modificar.
							sprintf(sendBuff, "%s",
									nombreProductoModificar.getCodigo());
							send(s, sendBuff, sizeof(sendBuff), 0);
							*lp = recibirListaProductos(recvBuff, s);
							lp->imprimirListaProductos();
						}

						break;
					case 3:	//ELIMINAR UN PRODUCTO DE LA BBDD DE LA TIENDA
						cout << endl
								<< "¿Estas seguro de querer eliminar un producto? (si: 1, no: 0): "
								<< endl;
						cin >> elim;
						if (elim == 1) {
							*lp = recibirListaProductos(recvBuff, s);
							lp->imprimirListaProductos();
							nombreProductoEliminar =
									nombreProductoEliminar.codigoProductoBorrar();
							//Enviamos el codigo del producto que vamos a borrar.
							sprintf(sendBuff, "%s",
									nombreProductoEliminar.getCodigo());
							send(s, sendBuff, sizeof(sendBuff), 0);
							*lp= recibirListaProductos(recvBuff, s);
							lp->imprimirListaProductos();

						}
						break;
					case 4:	//MOSTRAR EL ALMACEN DE LA TIENDA (LOS PRODUCTOS DE LA BBDD)
						*lp = recibirListaProductos(recvBuff, s);
						lp->imprimirListaProductos();
						break;
					case 5:	//MOSTRAR LAS ESTADÍSTICAS DE LA TIENDA
						cout << "ESTADISTICAS DE MUEBLES DEUSTO: " << endl
								<< endl;

						//PRODUCTO MaS CARO DE LA TIENDA
						*lp = recibirListaProductos(recvBuff, s);
						caro = lp->masCaro(*lp);
						cout << "1. PRODUCTO MAS CARO DE LA TIENDA: " << endl;
						cout << "	[Codigo: " << caro.getCodigo() << ", Nombre: "
								<< caro.getNombre() << ", Descripcion: "
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
								<< "2. NuMERO DE PRODUCTOS EN CADA CATEGORIA: "
								<< endl;
						mesas = 0;
						mesas = lp->numProductosCategoria(*lp, 0);
						sillas = 0;
						sillas = lp->numProductosCategoria(*lp, 1);
						sofas = 0;
						sofas = lp->numProductosCategoria(*lp, 2);
						cout << " 	MESAS: " << mesas << endl;
						cout << " 	SILLAS: " << sillas << endl;
						cout << " 	SOFAS: " << sofas << endl;

						//PRODUCTO CON MAYOR CANTIDAD EN LA TIENDA
						mayorCantidad = lp->masCantidad(*lp);
						cout << endl
								<< "3. EL PRODUCTO CON MAYOR CANTIDAD EN LA TIENDA: "
								<< endl;
						cout << "	[Codigo: " << mayorCantidad.getCodigo()
								<< ", Nombre: " << mayorCantidad.getNombre()
								<< ", Descripcion: "
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
					case 0:	//VOLVER
						cout << endl << "Agur!" << endl << endl;
						break;
					}
				} while (opcion2 != 0);
			} else { //USUARIO YA REGISTRADO
				cout << endl << "El usuario no esta registrado." << endl;
			}
			break;
		case 0:	//SALIR DE LA APLICACIoN
			cout << endl << "Agur!" << endl << endl;
			break;
		default: //ERROR
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
