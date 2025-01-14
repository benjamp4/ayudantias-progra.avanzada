#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Clase base Vendedor
class Vendedor {
protected:
    string rut;
    string nombre;

public:
    Vendedor(string r, string n) {
        this->rut = r;
        this->nombre = n;
    }

    virtual void imprimir() {
        cout << "RUT: " << rut << ", Nombre: " << nombre << endl;
    }

    virtual bool despedir() = 0; // Método virtual puro
};

// Clase VendedorContratado
class VendedorContratado : public Vendedor {
private:
    float sueldoBase;
    float porcentajeComision;
    int minimoVentas;
    int ventasRealizadas;

public:
    VendedorContratado(string r, string n, float sueldo, float comision, int minimo)
        : Vendedor(r, n) {
        this->sueldoBase = sueldo;
        this->porcentajeComision = comision;
        this->minimoVentas = minimo;
        this->ventasRealizadas = 0;
    }

    void agregarVenta(int monto) {
        ventasRealizadas += monto;
    }

    void reiniciarMes() {
        ventasRealizadas = 0;
    }

    void imprimir() {
        Vendedor::imprimir();
        cout << "Sueldo Base: " << sueldoBase
             << ", Comisión: " << porcentajeComision
             << "%, Mínimo Ventas: " << minimoVentas
             << ", Ventas Realizadas: " << ventasRealizadas << endl;
    }

    bool despedir() {
        return ventasRealizadas < minimoVentas;
    }
};

// Clase VendedorPartTime
class VendedorPartTime : public Vendedor {
private:
    int diasTrabajados;
    int ventasSuperiores30000;

public:
    VendedorPartTime(string r, string n)
        : Vendedor(r, n) {
        this->diasTrabajados = 0;
        this->ventasSuperiores30000 = 0;
    }

    void agregarDíaDeTrabajo() {
        diasTrabajados++;
    }

    void agregarVenta(int monto) {
        if (monto > 30000) ventasSuperiores30000++;
    }

    void imprimir() {
        Vendedor::imprimir();
        cout << "Días Trabajados: " << diasTrabajados
             << ", Ventas > 30.000: " << ventasSuperiores30000 << endl;
    }

    bool despedir() {
        if (diasTrabajados == 0) return true;
        float promedio = ventasSuperiores30000 / (float)diasTrabajados;
        return promedio < 6.0;
    }
};

// Método global despedir
void despedir(vector<Vendedor*>& vendedores) {
    cout << "Nómina de despedidos:" << endl;
    for (int i = 0; i < vendedores.size(); i++) {
        if (vendedores[i]->despedir()) {
            vendedores[i]->imprimir();
        }
    }
}

// Ejemplo de uso
int main() {
    vector<Vendedor*> vendedores;

    VendedorContratado vc1("1-9", "Ana Perez", 500000, 10, 100000);
    VendedorPartTime vp1("2-7", "Luis Gomez");

    vc1.agregarVenta(90000); // No cumple meta
    vp1.agregarDíaDeTrabajo();
    vp1.agregarVenta(35000); // Cumple condición

    vendedores.push_back(&vc1);
    vendedores.push_back(&vp1);

    despedir(vendedores);

    return 0;
}
