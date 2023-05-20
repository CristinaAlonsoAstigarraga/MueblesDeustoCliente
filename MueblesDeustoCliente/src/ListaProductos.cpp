
#include "ListaProductos.h"

ListaProductos::ListaProductos(){
	aProductos = NULL;
	tam = 0;
	numProductos = 0;
}

ListaProductos::ListaProductos(int numProductos){
	aProductos = new Producto[numProductos];
	this->tam = numProductos;
	this->numProductos = 0;
}
void ListaProductos::aniadirProductoLista(const Producto &p){
	if(numProductos<tam){
		aProductos[numProductos] = p;
		numProductos++;
	}
}
void ListaProductos::imprimir(){
	for(int i=0;i<numProductos;i++){
		cout<<aProductos[i].getCodigo()<<endl ; //Habría que hacer método imprimir
	}
}
ListaProductos::~ListaProductos(){
	if(aProductos!=NULL){
		delete [] aProductos;
	}
}

