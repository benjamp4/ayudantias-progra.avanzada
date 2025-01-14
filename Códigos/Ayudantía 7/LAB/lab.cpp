#include <vector>
#include <iostream>
using namespace std;

class Estudiante {
private:
    string nombre, region;
    int rut, ingresoFamiliar;
    float promedioNotas;

public:
    // Constructor con inicialización de todos los atributos requeridos
    Estudiante(string nombre, string region, int rut, int ingresoFamiliar, float promedioNotas) {
        this->nombre = nombre;
        this->region = region;
        this->rut = rut;
        this->ingresoFamiliar = ingresoFamiliar;
        this->promedioNotas = promedioNotas;
    }

    // Getters
    string getNombre() {
        return nombre;
    }

    string getRegion() {
        return region;
    }

    int getRut() {
        return rut;
    }

    int getIngresoFamiliar() {
        return ingresoFamiliar;
    }

    float getPromedioNotas() {
        return promedioNotas;
    }
};

class Beca {
private:
    vector<Estudiante *> postulantes; // Vector de estudiantes postulantes
    vector<Estudiante *> aceptados;   // Vector de estudiantes aceptados

public:
    // Constructor vacío
    Beca() {}

    // Método para agregar un estudiante al vector de postulantes
    void postular(Estudiante *e) {
        postulantes.push_back(e);
    }

    // Método para validar las postulaciones según los criterios especificados
    void validarPostulaciones() { // Validar postulaciones, recorre todos los postulantes
        for (int i = 0; i < postulantes.size(); i++) { // Recorrer postulaciones size
            if (postulantes.at(i)->getIngresoFamiliar() <= 300000) { // Si cierta postulacion es menor o igual a 300.000 
                if ((postulantes.at(i)->getRegion() == "Antofagasta") || (postulantes.at(i)->getPromedioNotas() > 5.5)) { // Si la region de la postulacion es antofa
                    aceptados.push_back(postulantes.at(i)); // Y el promedio es mayor a 5.5, se añade a aceptados
                } else {
                    cout << "Lamentablemente " << postulantes.at(i)->getRut() << " ha sido rechazado." << endl; // Rechazado si no se cumple que sea de antofa
                }
            } else { // Rechazado si no cumple el ingreso minimo
                cout << "Lamentablemente " << postulantes.at(i)->getRut() << " ha sido rechazado." << endl;
            }
        }
    }

    // Método para imprimir el nombre y RUT de los estudiantes aceptados
    void imprimirAceptados() {
        for (int i = 0; i < aceptados.size(); i++) {
            cout << "Nombre: " << aceptados.at(i)->getNombre() << " | Rut: " << aceptados.at(i)->getRut() << endl;
        }
    }
};


#include <iostream>
using namespace std;

int main() {

}

