#include <iostream>
#include <queue>
#include <string>
using namespace std;

class Cliente {
private:
    string nombre;
public:
    Cliente(string nombre) {
        this->nombre = nombre;
    }

    string getNombre() {
        return nombre;
    }

    void mostrarInfo() {
        cout << "Cliente: " << nombre << endl;
    }
};

class Banco {
private:
    queue<Cliente*> colaClientes; // Cola de clientes
public:
    void agregarCliente(Cliente* cliente) {
        colaClientes.push(cliente);
        cout << cliente->getNombre() << " ha sido añadido a la cola." << endl;
    }

    void atenderCliente() {
        if (!colaClientes.empty()) {
            cout << "Atendiendo al cliente: ";
            colaClientes.front()->mostrarInfo();
            colaClientes.pop(); // Elimina al cliente al frente de la cola
        } else {
            cout << "No hay clientes en la cola para atender." << endl;
        }
    }

    void mostrarProximoCliente() {
        if (!colaClientes.empty()) {
            cout << "El próximo cliente en ser atendido es: ";
            colaClientes.front()->mostrarInfo();
        } else {
            cout << "La cola está vacía." << endl;
        }
    }

    void mostrarEstadoCola() {
        if (colaClientes.empty()) {
            cout << "No hay clientes en la cola." << endl;
            return;
        }

        cout << "Clientes restantes en la cola:" << endl;
        queue<Cliente*> tempQueue = colaClientes; // Copia temporal de la cola para mostrar los elementos
        while (!tempQueue.empty()) {
            tempQueue.front()->mostrarInfo();
            tempQueue.pop();
        }
    }
};

int main() {
    Banco banco;

    // Crear y agregar clientes
    banco.agregarCliente(new Cliente("Vicente"));
    banco.agregarCliente(new Cliente("Maicol"));
    banco.agregarCliente(new Cliente("Josefina"));
    banco.agregarCliente(new Cliente("Pepe"));

    // Mostrar el próximo cliente a ser atendido
    banco.mostrarProximoCliente();

    // Atender al primer cliente
    banco.atenderCliente();

    // Mostrar el próximo cliente después de atender uno
    banco.mostrarProximoCliente();

    // Mostrar el estado de la cola
    banco.mostrarEstadoCola();

    return 0;
}


