#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

class Polaca {
private:
    map<string, stack<float> > calculadora;

public:
    Polaca() {
        calculadora["+"] = stack<float>();
        calculadora["-"] = stack<float>();
        calculadora["x"] = stack<float>();
        calculadora["/"] = stack<float>();
        calculadora["ELEVADO"] = stack<float>();
    }

    void agregarValor(string operacion, float valor) {
        if (calculadora.find(operacion) == calculadora.end()) {
            cout << "Operación no válida." << endl;
            return;
        }
        if (calculadora[operacion].size() >= 20) {
            cout << "Pila llena, no se pueden agregar más valores." << endl;
            return;
        }
        calculadora[operacion].push(valor);
    }

    void operar(string operacion) {
        if (calculadora.find(operacion) == calculadora.end()) {
            cout << "Operación no válida." << endl;
            return;
        }

        stack<float>& pila = calculadora[operacion];  // Ahora usamos la referencia a la pila original

        if (pila.size() < 2) {
            cout << "Faltan valores." << endl;
            return;
        }

        // Extraemos los dos valores del stack
        float a = pila.top(); pila.pop();
        float b = pila.top(); pila.pop();
        float resultado = 0.0;

        // Realizamos la operación según el tipo
        if (operacion == "+") {
            resultado = a + b;
        } else if (operacion == "-") {
            resultado = b - a;
        } else if (operacion == "x") {
            resultado = a * b;
        } else if (operacion == "/") {
            if (a == 0) {
                cout << "Error: División por cero." << endl;
                return;
            }
            resultado = b / a;
        } else if (operacion == "ELEVADO") {
            resultado = pow(b, a);
        } else {
            cout << "Operación no válida." << endl;
            return;
        }

        // Imprimimos el resultado de la operación
        cout << "Resultado de " << operacion << ": " << resultado << endl;

        // Añadimos el resultado de nuevo a la pila original
        pila.push(resultado);  // Ahora actualizamos la pila original con el resultado
    }

    float sumaTotal() {
        float suma = 0.0;
        map<string, stack<float> >::iterator it = calculadora.begin();

        while (it != calculadora.end()) {
            stack<float> copia = it->second; // Hacemos una copia de la pila
            while (!copia.empty()) {
                suma += copia.top();
                copia.pop();
            }
            ++it;
        }

        return suma;
    }
};

// Ejemplo de uso
int main() {
    Polaca calc;
    calc.agregarValor("+", 3);
    calc.agregarValor("+", 5);
    calc.agregarValor("+", 7);
    calc.operar("+"); // Resultado: 12
    calc.operar("+"); // Resultado: 15
    calc.agregarValor("-", 10);
    calc.agregarValor("-", 5);
    calc.operar("-"); // Resultado: 5
    cout << "Suma total: " << calc.sumaTotal() << endl; // Suma total: 20
    return 0;
}
