#include <iostream>
using namespace std;

class Persona {
private:
    string rut, nombre;
public:
    Persona(string rut, string nombre) {
        this->rut = rut;
        this->nombre = nombre;
    }

    string getNombre() {
        return nombre;
    }

    string getRut() {
        return rut;
    }
};

class SalaCine {
private:
    Persona* butacas[100]; // Se crea una sala de cine con 100 butacas

public:
    SalaCine() { // Se inicializa la sala de cine con butacas vacías
        for (int i = 0; i < 100; ++i) {
            butacas[i] = NULL;
        }
    }

    bool personaYaTieneAsiento(Persona* persona) {
        for (int i = 0; i < 100; ++i) { // Si la butaca que ocupa este rut es igual a el rut de la persona, está ocupada (Y si está distinta de vacío)
            if (butacas[i] != NULL && butacas[i]->getRut() == persona->getRut()) { // Se verifica si el rut de la persona de la butaca es el mismo del que estamos buscando
                return true; // La persona ya tiene un asiento
            }
        }
        return false; // La persona no tiene asiento
    }

    void venta(Persona* persona, int asiento) {
        if(butacas[asiento] == NULL && !personaYaTieneAsiento(persona)){ // Si la butaca no está ocupada y la persona no tiene asiento
            butacas[asiento] = persona; // Se le asigna la butaca a la persona
            cout << "Butaca numero " << asiento << " asignada" << endl;
        } else {
            if(butacas[asiento] != NULL) {
                cout << "La butaca está ocupada" << endl;
            } else {
                cout << "La persona ya tiene un asiento asignado" << endl;
            }
        }
    }

    void buscarPersona(string rut) { // Busca una persona por rut
        bool verificador = true;
        for (int i = 0; i < 100; ++i) { // Recorre las 100 butacas
            if(butacas[i] != NULL && butacas[i]->getRut() == rut) {
                cout << "Persona encontrada en la butaca " << i << endl;
                verificador = false;
                break;
            }
        }
        if(verificador) {
            cout << "No se encuentra a la persona." << endl;
        }
    }

    void imprimirSala() { // Imprime todas las butacas ocupadas en la sala
        for (int i = 0; i < 100; ++i) {
            if(butacas[i] != NULL) {
                cout << "----------------------" << endl;
                cout << "Butaca: " << i << endl;
                cout << " - rut: " << butacas[i]->getRut() << endl;
                cout << " - nombre: " << butacas[i]->getNombre() << endl;
            }
        }
    }

    void eliminarPersona(string rut) { // Elimina una persona por rut
        bool verificador = true;
        for (int i = 0; i < 100; ++i) {
            if(butacas[i] != NULL && butacas[i]->getRut() == rut) {
                butacas[i] = NULL; // Libera la butaca
                cout << "Persona eliminada de la butaca " << i << endl;
                verificador = false;
            }
        }
        if(verificador) {
            cout << "No se encuentra a la persona." << endl;
        }
    }
};

int main() {
    SalaCine* laSala = new SalaCine(); // Se crea una nueva sala de cine
    Persona* persona1 = new Persona("12345", "Miguel"); // Se crea una nueva persona
    Persona* persona2 = new Persona("111111", "Pepe"); // Se crea otra persona
    Persona* persona3 = new Persona("123", "Diego");
    laSala->venta(persona1, 69); // Se asigna la butaca 69 a persona1
    laSala->venta(persona2, 7); // Se asigna la butaca 7 a persona2
    laSala->venta(persona3, 3);
    laSala->eliminarPersona("111111"); // Se elimina a la persona con rut 111111
    laSala->buscarPersona("12345");
    laSala->imprimirSala(); // Se imprimen los datos de las butacas ocupadas
    return 0;
}
