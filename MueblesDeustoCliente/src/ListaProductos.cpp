#include "ListaProductos.h"
#include "Producto.h"
#include "string.h"

ListaProductos::ListaProductos() {
	aProductos = NULL;
	tam = 0;
	numProductos = 0;
}

ListaProductos::ListaProductos(int numProductos) {
	aProductos = new Producto[numProductos];
	this->tam = numProductos;
	this->numProductos = 0;
}
void ListaProductos::aniadirProductoLista(const Producto &p) {
	if (numProductos < tam) {
		aProductos[numProductos] = p;
		numProductos++;
	}
}

int ListaProductos::getNumProductos() {
	return numProductos;
}

Producto ListaProductos::masCaro(ListaProductos lp) {
	char codigoCaro[20];
	int precio = 0;
	Producto p;
	for (int i = 0; i < lp.numProductos; i++) {
		if (lp.aProductos[i].getPrecio() > precio) {
			precio = lp.aProductos[i].getPrecio();
			strcpy(codigoCaro, lp.aProductos[i].getCodigo());
		}
	}
	for (int i = 0; i < lp.numProductos; i++) {
		if (strcmp(lp.aProductos[i].getCodigo(), codigoCaro) == 0) {
			p.setCodigo(codigoCaro);
			p.setNombre(lp.aProductos[i].getNombre());
			p.setDescripcion(lp.aProductos[i].getDescripcion());
			p.setCantidad(lp.aProductos[i].getCantidad());
			p.setPrecio(lp.aProductos[i].getPrecio());
			p.setTipo(lp.aProductos[i].getTipo());
		}
	}

	return p;

}

void ListaProductos::imprimir() {
	for (int i = 0; i < numProductos; i++) {
		cout << aProductos[i].getCodigo() << endl; //Habría que hacer método imprimir
	}
}

int ListaProductos::numProductosCategoria(ListaProductos lp, int categoria) {
	int resultado = 0;
	for (int i = 0; i < lp.getNumProductos(); i++) {
		if (lp.aProductos[i].getTipo() == categoria) {
			resultado++;
		}
	}

	return resultado;
}

Producto ListaProductos::masCantidad(ListaProductos lp) {
	Producto p;
	int cantidad = 0;
	for (int i = 0; i < lp.numProductos; i++) {
		if (lp.aProductos[i].getCantidad() > cantidad) {
			p.setCodigo(lp.aProductos[i].getCodigo());
			p.setNombre(lp.aProductos[i].getNombre());
			p.setDescripcion(lp.aProductos[i].getDescripcion());
			p.setCantidad(lp.aProductos[i].getCantidad());
			p.setPrecio(lp.aProductos[i].getPrecio());
			p.setTipo(lp.aProductos[i].getTipo());
		}
		cantidad = lp.aProductos[i].getCantidad();
	}
	return p;
}

void ListaProductos::imprimirListaProductos(ListaProductos lp) {
	cout << "\nLista de productos de MueblesDeusto: \n";
	for (int i = 0; i < lp.numProductos; i++) {
		cout << "[PRODUCTO "<< i + 1;
		cout << ", CODIGO: "<< lp.aProductos[i].getCodigo();
		cout << ", NOMBRE: "<< lp.aProductos[i].getNombre();
		cout << ", DESCRIPCION: "<< lp.aProductos[i].getDescripcion();
		cout << ", CANTIDAD: "<< lp.aProductos[i].getCantidad();
		cout << ", PRECIO: "<< lp.aProductos[i].getPrecio();
		cout << ", CATEGORIA: ";
		if (lp.aProductos[i].getTipo() == 0) {
			cout << "MESAS]" << endl;
		} else if (lp.aProductos[i].getTipo()  == 1) {
			cout << "SILLAS]" << endl;
		} else if (lp.aProductos[i].getTipo()  == 2) {
			cout << "SOFAS]" << endl;
		} else {
			cout << "Desconocida]" << endl;
		}
	}
}

ListaProductos ListaProductos::buscarProducto(ListaProductos lp, int categoria){
	ListaProductos listaCat;
	for (int i=0; i<numProductos; i++){
		if(lp.aProductos[i].getTipo() == categoria){
			listaCat.aniadirProductoLista(lp.aProductos[i]);
		}
	}
	return listaCat;
}

ListaProductos::~ListaProductos() {
	if (aProductos != NULL) {
		delete[] aProductos;
	}
}

