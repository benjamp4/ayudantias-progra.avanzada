#include <vector>
#include <iostream>
using namespace std;

class Persona {
private:
    string nombre, region;
    int edad;
public:
    // Constructor con inicialización de todos los atributos requeridos
    Persona(string nombre, string region, int edad) {
        this->nombre = nombre;
        this->region = region;
        this->edad=edad;
    }

     void imprimir() {
        cout << "Nombre: " << nombre << " | Región: " << region << " | Edad: " << edad << endl;
    }

    // Getters
    string getNombre() {
        return nombre;
    }

    string getRegion() {
        return region;
    }

    int getEdad(){
        return edad;
    }
};

class Docente : public Persona {
private:
    string asignatura;
    int anosDeExp;

public:
    // Constructor
    Docente(string nombre, string region, int edad, string asignatura, int anosDeExp): Persona(nombre, region, edad) {
        this->asignatura = asignatura;
        this->anosDeExp = anosDeExp;
    }

    // Getters
    string getAsignatura() {
        return asignatura;
    }

    int getAnosDeExp() {
        return anosDeExp;
    }

};


class Postulaciones {
private:
    vector<Docente *> postulantes; // Vector de estudiantes postulantes
    vector<Docente *> aceptados;   // Vector de estudiantes aceptados

public:
    // Constructor vacío
    Postulaciones() {}

    // Método para agregar un estudiante al vector de postulantes
    void postular(Docente *d) {  /////////////////////////////////////////////////////////////////////////////////////// METODO POSTULAR
        postulantes.push_back(d);
    }

    bool cantidadMinimaPostulantes() { /////////////////////////////////////////////////////////////////////////////////////// METODO CANTIDAD MINIMA
    if (postulantes.size() >= 100) {
        return true; // Retorna true si el tamaño del vector es mayor o igual a 100
    } else {
        return false; // Retorna false en caso contrario
    }
    }

    int promedioEdad() { /////////////////////////////////////////////////////////////////////////////////////// METODO PROMEDIO EDAD

        if (postulantes.empty()) {
            return 0;
        }

        int sumaEdades = 0;
        for (int i = 0; i < postulantes.size(); i++) {
            sumaEdades += postulantes[i]->getEdad();
        }
        return sumaEdades / postulantes.size();
    }

    void validarPostulaciones() { /////////////////////////////////////////////////////////////////////////////////////// METODO VALIDAR POSTULACIONES
    // Validar que haya al menos 100 postulantes
    if (!cantidadMinimaPostulantes()) { // Si no se cumple la cantidad minima...
        cout << "No se llegó a la cantidad mínima de postulantes (100)." << endl;
        return;
    }

    for (int i = 0; i < postulantes.size(); i++) { // Recorrer postulantes
        if (postulantes.at(i)->getRegion() == "Santiago") { // Verificar si la región es Santiago
            if (postulantes.at(i)->getAnosDeExp() > 10 || postulantes.at(i)->getAsignatura() == "Cálculo III") {
                // Si tiene más de 10 años de experiencia o enseña Cálculo III
                aceptados.push_back(postulantes.at(i)); // Añadir al vector de aceptados

            } else {
                cout << "Lamentablemente " << postulantes.at(i)->getNombre()
                     << " ha sido rechazado por no cumplir los criterios de experiencia o asignatura." << endl;
            }
        } else { // Rechazado si no pertenece a Santiago
            cout << "Lamentablemente " << postulantes.at(i)->getNombre()
                 << " ha sido rechazado por no pertenecer a la región de Santiago." << endl;
        }
    }
}


virtual void imprimirAceptados() { /////////////////////////////////////////////////////////////////////////////////////// METODO VIRTUAL IMPRIMIR ACEPTADOS
        for (int i = 0; i < aceptados.size(); i++) { // Uso de int para el índice
            Docente* d = aceptados[i];
            // Imprimir atributos heredados
            cout << "Nombre: " << d->getNombre() << " | Región: " << d->getRegion()
                 << " | Edad: " << d->getEdad();
            // Imprimir atributos específicos de Docente
            cout << " | Asignatura: " << d->getAsignatura()
                 << " | Años de experiencia: " << d->getAnosDeExp() << endl;
        }
    }





};


#include <iostream>
using namespace std;

int main() {

}

