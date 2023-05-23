#include "ListaProductos.h"
#include "Producto.h"
#include "string.h"

//CONSTRUCTORES:
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

//GETTERS:
int ListaProductos::getNumProductos() {
	return numProductos;
}

//ADMIN:
ListaProductos* ListaProductos::buscarProducto(ListaProductos lp,
		int categoria) {
	ListaProductos *listaCat = new ListaProductos();
	for (int i = 0; i < lp.numProductos; i++) {
		if (lp.aProductos[i].getTipo() == categoria) {
			listaCat->aniadirProductoLista(lp.aProductos[i]);
		}
	}
	cout << "Numero de productos :" << listaCat->numProductos << endl;
	return listaCat;
}

void ListaProductos::aniadirProductoLista(const Producto &p) {
	if (numProductos == 0) {
		aProductos = new Producto[1];
	} else {
		Producto *aux = new Producto[numProductos];
		for (int i = 0; i < numProductos; i++) {
			aux[i] = aProductos[i];
		}
		delete[] aProductos;
		aProductos = new Producto[numProductos + 1];
		for (int i = 0; i < numProductos; i++) {
			aProductos[i] = aux[i];
		}
		delete[] aux;
	}
	aProductos[numProductos] = p;
	numProductos++;

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
		cout << aProductos[i].getCodigo() << endl;
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
		cout << "[PRODUCTO " << i + 1;
		cout << ", CODIGO: " << lp.aProductos[i].getCodigo();
		cout << ", NOMBRE: " << lp.aProductos[i].getNombre();
		cout << ", DESCRIPCION: " << lp.aProductos[i].getDescripcion();
		cout << ", CANTIDAD: " << lp.aProductos[i].getCantidad();
		cout << ", PRECIO: " << lp.aProductos[i].getPrecio();
		cout << ", CATEGORIA: ";
		if (lp.aProductos[i].getTipo() == 0) {
			cout << "MESAS]" << endl;
		} else if (lp.aProductos[i].getTipo() == 1) {
			cout << "SILLAS]" << endl;
		} else if (lp.aProductos[i].getTipo() == 2) {
			cout << "SOFAS]" << endl;
		} else {
			cout << "Desconocida]" << endl;
		}
	}
}

Producto* ListaProductos::buscarProd(ListaProductos lista, char *codigo) {
	Producto *p = new Producto();
	fflush(stdout);
	lista.imprimirListaProductos(lista);
	for (int i = 0; i < lista.numProductos; i++) {
		if (strcmp(lista.aProductos[i].getCodigo(), codigo) == 0) {
			p->setCodigo(lista.aProductos[i].getCodigo());
			p->setNombre(lista.aProductos[i].getNombre());
			p->setDescripcion(lista.aProductos[i].getDescripcion());
			p->setCantidad(lista.aProductos[i].getCantidad());
			p->setPrecio(lista.aProductos[i].getPrecio());
			p->setTipo(lista.aProductos[i].getTipo());
		}
	}
	return p;
}

ListaProductos::~ListaProductos() {
	if (aProductos != NULL) {
		delete[] aProductos;
	}
}

