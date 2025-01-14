#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> x;
    x.push(10);
    x.push(20);
    x.push(30);
    x.push(40);
    // Creamos una copia del stack, como un auxiliar
    stack<int> aux = x;
    cout << "Recorriendo la pila... " << endl;

    while (!aux.empty()) {  // Mientras auxiliar tenga elementos... 
        cout << aux.top() << endl;  // Imprimimos el elemento de la cima
        aux.pop();  // Y eliminamos el elemento auxiliar...
    }

    return 0;
}
