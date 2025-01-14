#include <iostream>
#include <map>
#include <string>

using namespace std;

class Tienda {
public:
    map<int, string> cds;
    map<string, string> clientes;
    map<string, int> cdsPrestados; // Mapa que asocia cada cliente con la cantidad de CDs prestados

    Tienda() {}

    void agregarCD(int id, string titulo) { // Agrega un CD al mapa de CDs disponibles
        cds[id] = titulo;
    }

    void registrarCliente(string rut, string nombre) { // Agrega un cliente al mapa de clientes
        clientes[rut] = nombre;
        cdsPrestados[rut] = 0; // CDs prestados asociados a ese rut parten en 0 
    }

    void prestarCD(string rutCliente, int idCD) { // Presta un CD a un cliente específico
        if (clientes.find(rutCliente) == clientes.end()) { // Verifica si el cliente está registrado
            cout << "El cliente con RUT " << rutCliente << " no está registrado." << endl;
            return;
        }

        if (cds.find(idCD) == cds.end()) { // Verifica si el CD está disponible
            cout << "El CD con ID " << idCD << " no está disponible." << endl;
            return;
        }

        if (cdsPrestados[rutCliente] >= 3) { // Limite de 3 CDs prestados por cliente
            cout << "El cliente con RUT " << rutCliente << " ya tiene 3 CDs prestados, no puede llevar más." << endl;
            return;
        }

        cdsPrestados[rutCliente]++; // Aumenta la cantidad de CDs prestados para el cliente
        cout << "El CD '" << cds[idCD] << "' ha sido prestado al cliente " << clientes[rutCliente] << "." << endl;
        cds.erase(idCD); // Elimina el CD de la lista de disponibles
    }

    void mostrarInfo() { // Muestra la información de los clientes y la cantidad de CDs prestados
        cout << "Información de clientes y CDs prestados:" << endl;
        map<string, string>::iterator itCliente; // Iterador para el mapa de clientes
        for (itCliente = clientes.begin(); itCliente != clientes.end(); itCliente++) {
            string rut = itCliente->first;
            cout << "RUT: " << rut << ", Nombre: " << itCliente->second << ", CDs prestados: " << cdsPrestados[rut] << endl;
        }
    }
};

/* int main() {

    Tienda tienda;

    tienda.agregarCD(1, "In Rainbows - Radiohead");
    tienda.agregarCD(2, "Schlagenheim - black midi");
    tienda.agregarCD(3, "Drukqs - Aphex Twin");
    tienda.agregarCD(4, "Remain in Light - Talking Heads");
    tienda.agregarCD(5, "Suck it and See - Arctic Monkeys");

    tienda.registrarCliente("21471976-9", "Charly");
    tienda.registrarCliente("21733733-2", "Gustavo");
    tienda.registrarCliente("21133071-6", "Vicente");

    tienda.prestarCD("21471976-9", 1);
    tienda.prestarCD("21471976-9", 2);
    tienda.prestarCD("21471976-9", 3);
    tienda.prestarCD("21471976-9", 4); // Esto debería dar un mensaje de error
    tienda.prestarCD("21133071-6", 5);

    tienda.mostrarInfo();

    return 0;
}
*/