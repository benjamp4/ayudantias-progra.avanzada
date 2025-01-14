#include <iostream>
#include <map>
#include <string>

using namespace std;

class Tienda {
public:
    map<int, string> cds;
    map<string, string> clientes;
    map<string, int> cdsPrestados;

    Tienda() {}

    void agregarCD(int id, string titulo) { // Agrega cd, iguala los parámetros que le pasemos a un mapa
        cds[id] = titulo;
    }

    void registrarCliente(string rut, string nombre) { // Agrega un cliente, iguala los parámetros que le pasamos a un mapa
        clientes[rut] = nombre;
        cdsPrestados[rut] = 0; // CDs prestados asociados a ese rut parten en 0 
    }

    void prestarCD(string rutCliente, int idCD) { // Prestar cd, para esto queremos saber el rut de quien se lo queremos prestar y el id del cd
        if (clientes.find(rutCliente) == clientes.end()) { // Si el cliente no existe
            cout << "El cliente con RUT " << rutCliente << " no está registrado." << endl; // El cliente no está registrado
            return;
        }

        if (cds.find(idCD) == cds.end()) { // Si el id del cd no existe
            cout << "El CD con ID " << idCD << " no está disponible." << endl; // El cd no está disponible
            return;
        }

        if (cdsPrestados[rutCliente] >= 3) { // Verificador para que el cliente no sea pesao y se lleve más de 3 cds
            cout << "El cliente con RUT " << rutCliente << " ya tiene 3 CDs prestados, no sea pesao, dejele a los demás..." << endl;
            return;
        }

        cdsPrestados[rutCliente]++; // Si se cumple toda nornalmente va aumentar la cantidad de cds prestados que tiene el rut asociado
        cout << "El CD '" << cds[idCD] << "' ha sido prestado al cliente " << clientes[rutCliente] << "." << endl; // Mostrar por pantalla
        cds.erase(idCD); // se elimina el cd porque lo tomaron prestado, osea no está disponible si queremos tomarlo prestado
    }

    void devolverCD(string rutCliente, int idCD, string titulo) { // metodo que recibe el rut cliente que quiere devolver, la id del cd que quiere devolver y el nombre del cd que queremos devolver
        if (clientes.find(rutCliente) == clientes.end()) { // Si no se encuentra el rut... 
            cout << "El cliente con RUT " << rutCliente << " no está registrado." << endl;
            return;
        }

        if (cdsPrestados[rutCliente] == 0) { // Si el cliente quiere devolver un cd pero tiene 0 cdss asociados
            cout << "El cliente con RUT " << rutCliente << " no tiene CDs prestados." << endl;
            return;
        }

        cdsPrestados[rutCliente]--; // Si va todo normal se disminuye la cantidad de cds prestados que tiene el rut asociado
        cds[idCD] = titulo; // volvemos a agregar el cd de la misma manera que los añade la funcion del principio del codigo
        cout << "El cliente " << clientes[rutCliente] << " ha devuelto el CD '" << titulo << "'." << endl;
    }

    void mostrarCDs() { // Queremos mostrar los cds...
        cout << "CDs disponibles en la tienda:" << endl;
        map<int, string>::iterator it; // iterador
        for (it = cds.begin(); it != cds.end(); it++) { // Mostramos los cds de principio a fin 
            cout << "ID: " << it->first << ", Título: " << it->second << endl; // Ocupamos el iterador
        }
    }

    void mostrarClientes() { // Queremos mostrar los clientes y los cds que le prestaron
        cout << "Clientes registrados en la tienda:" << endl;
        map<string, string>::iterator it; // iterador
        for (it = clientes.begin(); it != clientes.end(); it++) { // Mostramos los clientes de principio a fin 
            cout << "RUT: " << it->first << ", Nombre: " << it->second << ", CDs prestados: " << cdsPrestados[it->first] << endl; // Ocupamos el iterador
        }
    }
};

int main() {

    Tienda tienda; // Clase tienda, donde por alguna razon prestan cds... rarisimo

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
    tienda.prestarCD("21471976-9", 4);
    tienda.prestarCD("21133071-6", 5);


    tienda.mostrarCDs();
    tienda.mostrarClientes();

    tienda.devolverCD("21471976-9", 1, "In Rainbows - Radiohead");

    tienda.mostrarCDs();

    tienda.prestarCD("21733733-2",1);

    return 0;
}


