#include <iostream>
using namespace std;

// Clase Mascota
class Mascota {
private:
    string nombre;
    string color;
    string tipo;

public:
    // Constructor
    Mascota(string n, string c, string t) : nombre(n), color(c), tipo(t) {}

    // Método para mostrar la información de la mascota
    void mostrarInformacion() {
        cout << "Nombre: " << nombre << ", Color: " << color << ", Tipo: " << tipo << endl;
    }
};

int main() {
    // Creación de objetos Perro y Gato
    Mascota *gato = new Mascota("Diego", "Blanco", "Gato");
    Mascota *perro1 = new Mascota("Mailo", "Cafe", "Perro");
    Mascota *perro2 = new Mascota("Miguel", "Blanco", "Perro");

    // Mostrar la información de las mascotas
    gato->mostrarInformacion();
    perro1->mostrarInformacion();
    perro2->mostrarInformacion();

    return 0;
}