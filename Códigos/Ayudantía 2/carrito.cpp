#include <iostream>

using namespace std;

class Producto {
private:
    string nombre;
    double precio;

public:
    Producto(){} // Constructor vacio por defecto
    // Constructor que requiere nombre y precio
    Producto(string nombre, double precio) {
        this->nombre = nombre;
        this->precio = precio;
    }

    string getNombre() {
        return nombre;
    }

    double getPrecio() {
        return precio;
    }
};

class CarritoDeCompras {
private:
    Producto productos[10]; // Arreglo para almacenar hasta 10 productos
    int cantidadProductos;   // Número actual de productos en el carrito

public:
    CarritoDeCompras() {
        this->cantidadProductos = 0;  // Inicialización usando 'this'
    }
    // La función recibe un objeto Producto llamado 'item'

    void agregarProducto(Producto item) { 
        if (cantidadProductos < 10) { // Verifica que haya espacio en el carrito
            productos[cantidadProductos] = item; // Agrega el producto al arreglo
            cantidadProductos++; // Incrementa la cantidad de productos
            cout << "Producto " << item.getNombre() << " agregado al carrito." << endl;
        } else {
            cout << "Carrito lleno. No se pueden agregar más productos." << endl;
        }
    }

    double calcularTotal() {
        double total = 0; // Se inicializa un total en 0
        for (int i = 0; i < cantidadProductos; ++i) { // Recorre el ciclo de cantidad de productos
            total += productos[i].getPrecio(); // Suma los precios de todos los productos en el carrito
        }
        return total; // Retorna el total
    }

    void mostrarCarrito() {
        cout << "Productos en el carrito:" << endl;
        for (int i = 0; i < cantidadProductos; ++i) { // Con un ciclo recorre todos los productos del carrito
            cout << "- " << productos[i].getNombre() << " : $" << productos[i].getPrecio() << endl;
        }
    }
};

int main() {
    CarritoDeCompras carrito; // Se crea un objeto de la clase CarritoDeCompras

    Producto producto1("Manzana", 500); // Se crean productos
    Producto producto2("Pan", 1200);
    Producto producto3("Leche", 990);
    Producto producto4("Chela", 1900);
    carrito.agregarProducto(producto1); // Se agregan productos al carrito
    carrito.agregarProducto(producto2);
    carrito.agregarProducto(producto3);
    carrito.agregarProducto(producto4);
    carrito.mostrarCarrito(); // Se muestran los productos en el carrito
    cout << "Total a pagar: $" << carrito.calcularTotal() << endl; // Se muestra el total a pagar

    return 0;
}

