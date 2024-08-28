#include <iostream>
using namespace std;

class Direccion {
public:
    string calle;
    int numero;

    Direccion(string c, int n) : calle(c), numero(n) {}
};

class Persona {
public:
    string nombre;
    Direccion direccion; // La clase Persona tiene un objeto de la clase Direccion, de cierto modo le paso el objeto a otra clase

    Persona(string n, Direccion d) : nombre(n), direccion(d) {} // Inicializando la clase persona con un objeto dirección de la clase persona

    void mostrarInformacion() {
        cout << "Nombre: " << nombre << endl;
        cout << "Calle: " << direccion.calle << endl;
        cout << "Numero: " << direccion.numero << endl;
    }
};

int main() {
    Direccion miDireccion("Plaza UDPorros", 420); // Crear un objeto Direccion

    Persona persona("Charles Piña", miDireccion); // Crear un objeto Persona con un objeto miDireccion dentro

    persona.mostrarInformacion(); // Mostrar información de la persona

    return 0;
} 
