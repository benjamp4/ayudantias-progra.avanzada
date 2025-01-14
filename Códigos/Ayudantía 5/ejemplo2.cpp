#include <iostream>
using namespace std;

class Individuo {
protected:
    string nombre;
    int edad;
public:
    Individuo(string nombre, int edad) {
        this->nombre = nombre;
        this->edad = edad;
    }
};

class DuenoEstacionamiento : public Individuo {  // Dueño del estacionamiento
protected:
    int* lugaresDisponibles;  // Arreglo de lugares disponibles por estacionamiento
public:
    DuenoEstacionamiento(string nombre, int edad, int cantidadEstacionamientos) : Individuo(nombre, edad) {
        // Inicializamos el arreglo dinámicamente y lo dejamos en NULL
        this->lugaresDisponibles = new int[cantidadEstacionamientos];
        for (int i = 0; i < cantidadEstacionamientos; i++) {
            this->lugaresDisponibles[i] = NULL; // NULL indica que no se ha asignado lugar
        }
    }
    
    void mostrarLugaresDisponibles() {
        cout << "Lugares disponibles por estacionamiento:\n";
        for (int i = 0; i < 3; i++) {  // Supone que hay 3 estacionamientos
            if (this->lugaresDisponibles[i] == NULL) {
                cout << "Estacionamiento " << i + 1 << ": No asignado\n";
            } else {
                cout << "Estacionamiento " << i + 1 << ": " << this->lugaresDisponibles[i] << " lugares disponibles\n";
            }
        }
    }
};

class Cliente : public Individuo {  // Cliente del estacionamiento
protected:
    double montoAPagar;  // Monto a pagar por el tipo de vehículo
    string tipoVehiculo;
public:
    Cliente(string nombre, int edad, string tipoVehiculo) : Individuo(nombre, edad) {
        this->tipoVehiculo = tipoVehiculo;
        this->montoAPagar = 0.0;  // Inicializamos montoAPagar
    }

    void calcularMonto() {
        // Asignar monto con base en el tipo de vehículo
        if (this->tipoVehiculo == "auto") {
            this->montoAPagar = 2000.0;  // Auto: 2000 pesos
        } else if (this->tipoVehiculo == "moto") {
            this->montoAPagar = 1000.0;  // Moto: 1000 pesos
        } else if (this->tipoVehiculo == "camion") {
            this->montoAPagar = 3000.0;  // Camión: 3000 pesos
        } else {
            this->montoAPagar = 0.0;  // Tipo desconocido, sin monto
        }
    }
    
    void mostrarMonto() {
        if (this->montoAPagar == 0.0) {
            cout << "No se ha calculado monto para el tipo de vehículo: " << this->tipoVehiculo << "\n";
        } else {
            cout << "Monto a pagar por " << this->tipoVehiculo << ": " << this->montoAPagar << " pesos\n";
        }
    }
};

int main() {
    DuenoEstacionamiento* dueno = new DuenoEstacionamiento("Pepe", 50, 3);  // Tiene 3 estacionamientos
    dueno->mostrarLugaresDisponibles();

    Cliente* cliente = new Cliente("Juan", 22, "auto");
    cliente->calcularMonto();
    cliente->mostrarMonto();

    return 0;
}
