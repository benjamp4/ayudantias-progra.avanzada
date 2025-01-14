#include <iostream>
using namespace std;

class Animal {
protected:
    string nombre;
    int edad;
public:
    Animal(string nombre, int edad) {
        this->nombre = nombre;
        this->edad = edad;
    }
    
    void mostrarInfo() {
        cout << "Nombre: " << nombre << ", Edad: " << edad << " años" << endl;
    }
};

class Perro : public Animal {
public:
    Perro(string nombre, int edad) : Animal(nombre, edad) {}

    void ladrar() {
        cout << nombre << " está ladrando: ¡Guau, guau!" << endl;
    }
};

class Gato : public Animal {
public:
    Gato(string nombre, int edad) : Animal(nombre, edad) {}

    void maullar() {
        cout << nombre << " está maullando: ¡Miau, miau!" << endl;
    }
};

int main() {
    Perro *perro1 = new Perro("Rex", 3);
    Gato *gato1 = new Gato("Michi", 2);
    
    cout << "Información del Perro:" << endl;
    perro1->mostrarInfo();
    perro1->ladrar();
    cout << "Información del Gato:" << endl;
    gato1->mostrarInfo();
    gato1->maullar();

    return 0;
}
