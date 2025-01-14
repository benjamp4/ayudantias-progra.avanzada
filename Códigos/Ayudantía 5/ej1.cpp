#include <iostream>
#include <string>
using namespace std;

class Instrumento {
protected:
    string tipo;
    string marca;
    float precio;
public:
    Instrumento(string tipo, string marca, float precio) {
        this->tipo = tipo;
        this->marca = marca;
        this->precio = precio;
    }

    void mostrarInfo() {
        cout << "Instrumento: " << tipo << " - Marca: " << marca << ", Precio: $" << precio << endl;
    }
};

class Guitarra : public Instrumento {
public:
    Guitarra(string marca, float precio) : Instrumento("Guitarra", marca, precio) {}

    void tocarUnSolo(){
        cout << "Estoy tocando un solo de guitarra!!! wauuu!!!" << endl;
    }
};

class Bajo : public Instrumento {
public:
    Bajo(string marca, float precio) : Instrumento("Bajo", marca, precio) {}
};

class Bateria : public Instrumento {
public:
    Bateria(string marca, float precio) : Instrumento("Batería", marca, precio) {}
};

class Persona {
protected:
    string nombre;
    int edad;
    string ocupacion;
public:
    Persona(string nombre, int edad, string ocupacion) {
        this->nombre = nombre;
        this->edad = edad;
        this->ocupacion = ocupacion;
    }

    void presentarse() {
        cout << "Soy " << ocupacion << ". Nombre: " << nombre << ", Edad: " << edad << " años" << endl;
    }
};

class Guitarrista : public Persona {
public:
    Guitarrista(string nombre, int edad) : Persona(nombre, edad, "guitarrista") {}
};

class Bajista : public Persona {
public:
    Bajista(string nombre, int edad) : Persona(nombre, edad, "bajista") {}
};

class Baterista : public Persona {
public:
    Baterista(string nombre, int edad) : Persona(nombre, edad, "baterista") {}
};

int main() {

    Guitarra *guitarra1 = new Guitarra("Fender", 1200.0);
    Bajo *bajo1 = new Bajo("Squier", 900.0);
    Bateria *bateria1 = new Bateria("Alesis", 1500.0);

    cout << "Inventario de la tienda de instrumentos:" << endl;
    guitarra1->mostrarInfo();
    bajo1->mostrarInfo();
    bateria1->mostrarInfo();
    
    Guitarrista *persona1 = new Guitarrista("Diego", 25);
    Bajista *persona2 = new Bajista("Vicente", 30);
    Baterista *persona3 = new Baterista("Claudio", 27);

    cout << "Clientes en la tienda:" << endl;
    persona1->presentarse();
    persona2->presentarse();
    persona3->presentarse();

    cout << "El guitarrista toca un solo..." << endl;
    guitarra1->tocarUnSolo();


    return 0;
}
