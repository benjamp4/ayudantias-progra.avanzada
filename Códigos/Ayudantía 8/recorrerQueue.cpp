#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> x;
    x.push(10);
    x.push(20);
    x.push(30);
    x.push(40);
    // Creamos una copia del queue, como un auxiliar
    queue<int> aux = x;
    cout << "Recorriendo la cola... " << endl;

    while (!aux.empty()) {  // Mientras auxiliar tenga elementos... 
        cout << aux.front() << endl;  // Imprimimos el elemento de la cima
        aux.pop();  // Y eliminamos el elemento auxiliar...
    }

    return 0;
}
