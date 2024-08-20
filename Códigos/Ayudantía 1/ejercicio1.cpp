#include <iostream>
using namespace std;

class Perro {
private:
    string nombre, raza;
    float peso;

public:
    Perro(string nombre, string raza, float peso) {
        this->nombre = nombre;
        this->raza = raza;
        this->peso = peso;
    }

    void ingresarPerro() {
        cout << " " << endl;
        cout << "Ingrese el nombre del perro: ";
        cin >> nombre;
        cout << "Ingrese la raza del perro (Pequena, Mediana, Grande): ";
        cin >> raza;
        cout << "Ingrese el peso del perro (kg): ";
        cin >> peso;
    }

    void mostrarPerro(int numero) {
        cout << " " << endl;
        cout << "Datos del perro " << numero << ":" << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Raza: " << raza << endl;
        cout << "Peso: " << peso << " kg" << endl;
    }

    string evaluarPeso() {
        if (raza == "Pequena") {
            if (peso < 5.0) return "Bajo peso para raza pequena.";
            else if (peso > 25.0) return "Sobrepeso para raza pequena.";
            else return "Peso normal para raza pequena.";
        }
        else if (raza == "Mediana") {
            if (peso < 14.0) return "Bajo peso para raza mediana.";
            else if (peso > 27.0) return "Sobrepeso para raza mediana.";
            else return "Peso normal para raza mediana.";
        }
        else if (raza == "Grande") {
            if (peso < 21.0) return "Bajo peso para raza grande.";
            else if (peso > 39.0) return "Sobrepeso para raza grande.";
            else return "Peso normal para raza grande.";
        }
        return "Raza invalida";
    }
};

int main() {

    int cantidadPerros;
    cout << "¿Cuántos perros quieres ingresar?: ";
    cin >> cantidadPerros;

    Perro* perros[cantidadPerros];

    for (int i = 0; i < cantidadPerros; ++i) {
        perros[i] = new Perro("", "", 0.0); 
        perros[i]->ingresarPerro();
    }

    for (int i = 0; i < cantidadPerros; ++i) {
        perros[i]->mostrarPerro(i + 1);
        cout << perros[i]->evaluarPeso() << endl;
    }

    return 0;
    
}
