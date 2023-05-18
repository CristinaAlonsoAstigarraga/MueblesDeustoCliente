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
#include "string.h"
/*
 char menu(){
 char opcion;
 cout<<"1. Registrarse"<<endl;
 cout<<"2. Iniciar Sesi�n"<<endl;
 cout<<"0. Salir"<<endl;
 cout<<"Elige una opci�n: ";
 cin>>opcion;
 return opcion;
 }
 char menuAdministrador(){
 char opcion;
 cout<<"MENU ADMINISRADOR"<<endl;
 cout<<"1. "<<endl;
 cout<<"2. "<<endl;
 cout<<"0. Salir"<<endl;
 cout<<"Elige una opci�n: ";
 cin>>opcion;
 return opcion;
 }
 char menuCliente(){
 char opcion;
 cout<<"MENU CLIENTE"<<endl;
 cout<<"1. "<<endl;
 cout<<"2. "<<endl;
 cout<<"0. Salir"<<endl;
 cout<<"Elige una opci�n: ";
 cin>>opcion;
 return opcion;
 }*/
//esto es una pruebawedvwebvweb
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
//	Producto p("123", "nombreP1", "descrP1", 10, 10, 1);
//	Producto p2("234", "nombreP2", "descrP2", 22, 22, 2);
//
//	Menus::menuAdmin();
//	Menus::menuCliente();
//	Menus::menuInicio();
//
	Cliente nuevoCliente;
	Cliente inicio;
//	Carrito carritoPrueba;
//	Carrito::aniadirProductoCarrito(&carritoPrueba, p);
//	Carrito::aniadirProductoCarrito(&carritoPrueba, p2);
//	Carrito::imprimirCarrito(carritoPrueba);
//	Carrito::eliminarProductoCarrito(&carritoPrueba, p);
//	cout<<endl<<"Hemos borrado un producto"<<endl;
//	Carrito::imprimirCarrito(carritoPrueba);
////	Carrito::comprarCarrito(&carritoPrueba);
//	cout<<endl<<"Hemos comprado todo el carrito"<<endl;
//	Carrito::imprimirCarrito(carritoPrueba);

	char nom[20];
	int opcion = 10, opcion2 = 10, opcion3 = 10, i, clienteExiste, adminExiste;
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

			recv(s, recvBuff, sizeof(recvBuff), 0); //Recibe el resultado del Inicio de Sesi�n
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
			sprintf(sendBuff, "%s", nuevoCliente.getUsuario());
			send(s, sendBuff, sizeof(sendBuff), 0);
			sprintf(sendBuff, "%s", nuevoCliente.getContrasenya());
			send(s, sendBuff, sizeof(sendBuff), 0);

			recv(s, recvBuff, sizeof(recvBuff), 0); //Recibe el resultado del Inicio de Sesi�n
			sscanf(recvBuff, "%s", inicio.getDni());

			recv(s, recvBuff, sizeof(recvBuff), 0); //Recibe el resultado del Inicio de Sesi�n
			sscanf(recvBuff, "%d", &clienteExiste);
			recv(s, recvBuff, sizeof(recvBuff), 0); //Recibe el resultado del Inicio de Sesi�n
			sscanf(recvBuff, "%d", &adminExiste);

			if (clienteExiste) {
				cout << "¡Bienvenido a MueblesDeusto!" << endl;
//				Carrito *carritoCliente = new Carrito*[sizeof(Carrito)];
//				carritoCliente->getAProductos() = NULL;
//				carritoCliente->getNumProductos() = 0;		//GETTER O SETTER?
//				strcpy(carritoCliente->getDni(), inicio.getDni());
//				carritoCliente->getImporteTotal() = 0;

				do {
					opcion2 = Menus::menuCliente();
					switch (opcion2) {
					case 1:
//						opcion3 = carritoCliente->mostrarCarrito(
//								carritoCliente);
						break;
					case 2:
						/*MIRARLO CON MARIAN -- BBDD*/
						break;
					case 3:
						break;
					case 4:
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
						sprintf(sendBuff, "%f", nuevoProducto.getPrecio());
						send(s, sendBuff, sizeof(sendBuff), 0);
						sprintf(sendBuff, "%i", nuevoProducto.getTipo());
						send(s, sendBuff, sizeof(sendBuff), 0);

						break;
					case 2:
						/*MIRARLO CON MARIAN -- BBDD*/
						break;
					case 3:
						break;
					case 4:
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

	/*char opcion,opcionA,opcionC;
	 char nom[20],con[20];
	 int resul;
	 do{
	 opcion = menu();
	 sprintf(sendBuff,"%c",opcion);
	 send(s, sendBuff, sizeof(sendBuff), 0);



	 switch(opcion){
	 case '1': break;
	 case '2':
	 cout<<"NOMBRE: ";cin>>nom;
	 cout<<"CONTRASE�A: ";cin>>con;
	 sprintf(sendBuff,"%s",nom);
	 send(s, sendBuff, sizeof(sendBuff), 0); //Env�o el nombre al servidor
	 sprintf(sendBuff,"%s",con);
	 send(s, sendBuff, sizeof(sendBuff), 0); //Env�o la contrase�a al servidor

	 recv(s, recvBuff, sizeof(recvBuff), 0); //Recibe el resultado del Inicio de Sesi�n
	 sscanf(recvBuff,"%d",&resul);
	 cout<<"RESULTADO: "<<resul<<endl;
	 if(resul==1){
	 do{
	 opcionA = menuAdministrador();
	 switch(opcionA){
	 case '1': break;
	 case '2': break;
	 case '0': break;
	 default: cout<<"La opci�n no es correcta"<<endl;
	 }
	 }while(opcionA!='0');
	 }else if(resul ==2){
	 do{
	 opcionC = menuCliente();
	 switch(opcionC){
	 case '1': break;
	 case '2': break;
	 case '0': break;
	 default: cout<<"La opci�n no es correcta"<<endl;
	 }
	 }while(opcionC!='0');
	 }else{
	 cout<<"El Inicio de Sesi�n no ha sido correcto"<<endl;
	 }
	 break;
	 case '0': cout<<"AGUR"<<endl;break;
	 default: cout<<"La opci�n seleccionada no es correcta"<<endl;
	 }

	 }while(opcion!='0');
	 */
	/*ACABA EL PROGRAMA DEL CLIENTE*/
	// CLOSING the socket and cleaning Winsock...
	closesocket(s);
	WSACleanup();

	return 0;
}
