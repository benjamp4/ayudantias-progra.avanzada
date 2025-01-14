#include <iostream>
using namespace std;

class Persona {
private:
    string nombre;

public:
    Persona(string nombre) {
        this->nombre = nombre;
    }

    void mostrarNombre() {
        cout << "Nombre: " << nombre << endl;
    }
};

class Grupo {
private:
    Persona* personas[3]; // arreglo de punteros a Persona

public:
    Grupo() {
        // Inicializar el arreglo en NULL
        for (int i = 0; i < 3; i++) {
            personas[i] = NULL;
        }
    }

    // método que agrega una persona al grupo en el primer espacio disponible
    void agregarPersona(Persona* persona) {
        for (int i = 0; i < 3; i++) {
            if (personas[i] == NULL) {
                personas[i] = persona;
                cout << "Persona agregada al grupo." << endl;
                return;
            }
        }
        cout << "El grupo está lleno, no se puede agregar más personas." << endl;
    }

    // Mostrar las personas del grupo
    void mostrarPersonas() {
        for (int i = 0; i < 3; i++) {
            if (personas[i] != NULL) {
                personas[i]->mostrarNombre();
            } else {
                cout << "Persona en índice " << i << " está vacía." << endl;
            }
        }
    }

    // Destructor para liberar memoria
    ~Grupo() {
        for (int i = 0; i < 3; i++) {
            delete personas[i];
        }
    }
};

int main() {
    Grupo* grupo = new Grupo(); // Crear un grupo dinámicamente
    Persona* p1 = new Persona("René Puente");  // Crear personas dinámicamente
    Persona* p2 = new Persona("Mauricio Paredes");
    Persona* p3 = new Persona("Diego Mena");

    // Agregar personas al grupo
    grupo->agregarPersona(p1);
    grupo->agregarPersona(p2);
    grupo->agregarPersona(p3);

    // Mostrar las personas del grupo
    grupo->mostrarPersonas();

    // Liberar memoria del grupo
    delete grupo;

    return 0;
}
