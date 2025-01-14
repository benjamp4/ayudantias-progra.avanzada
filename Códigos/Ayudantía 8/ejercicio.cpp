#include <iostream>
#include <stack>

using namespace std;

void leerStack(stack<int> pila){
    stack<int> aux = pila;
    while (!aux.empty()) {  // Mientras auxiliar tenga elementos... 
        cout << aux.top() << endl;  // Imprimimos el elemento de la cima
        aux.pop();  // Y eliminamos el elemento auxiliar...
    }
}

void leerStackEnOrden(stack<int> pila) {
    // Stack auxiliar para revertir el orden de los datos
    stack<int> pilaAux;

    // Transferimos los datos del stack principal al stack auxiliar para revertir el orden
    while (!pila.empty()) {
        pilaAux.push(pila.top()); // Ingresamos elementos de una pila a otra pila, asi invertimos los elementos.
        pila.pop();
    }

    // Leemos los datos en el orden original de ingreso (1,2,3,4,5)
    cout << "Lectura de los datos en orden de ingreso: " << endl;
    while (!pilaAux.empty()) {
        cout << pilaAux.top() << endl;
        pilaAux.pop();
    }
}

int main() {
    stack<int> pila;

    // Ingresamos los datos directamente en el main
    pila.push(1);
    pila.push(2);
    pila.push(3);
    pila.push(4);
    pila.push(5);

    cout << "Datos ingresados en el stack." << endl;
    cout << "Lectura de los datos del stack." << endl;
    leerStack(pila);
    // Llamamos a la función para leer el stack en el orden de ingreso
    leerStackEnOrden(pila);

    return 0;
}
