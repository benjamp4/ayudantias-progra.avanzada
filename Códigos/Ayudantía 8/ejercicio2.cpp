#include <iostream>
#include <stack>
#include <queue>
#include <string>

using namespace std;

// Función auxiliar para invertir un stack, ya que si trabajamos con colas y pilas hay que invertir el stack para que se mantenga el orden
stack<string> invertirStack(stack<string> original) {
    stack<string> invertido;
    while (!original.empty()) {
        invertido.push(original.top());
        original.pop();
    }
    return invertido;
}

// Función para encontrar el día con la temperatura más alta
string diaMasCaluroso(queue<int> temperaturas, stack<string> dias) {
    dias = invertirStack(dias); // llamamos a la funcion que invierte
    int maxTemp = -1000; // numero muy bajo
    string diaCaluroso;

    while (!temperaturas.empty() && !dias.empty()) {
        if (temperaturas.front() > maxTemp) { // comparamos el valor de al frente de la cola con un valor muy grande
            maxTemp = temperaturas.front();
            diaCaluroso = dias.top();
        }
        temperaturas.pop();
        dias.pop();
    }

    return diaCaluroso;
}

// Función para encontrar el día con la temperatura más baja
string diaMasFrio(queue<int> temperaturas, stack<string> dias) {
    dias = invertirStack(dias); // llamamos a la funcion que invierte
    int minTemp = 1000; // numero muy alto
    string diaFrio;

    while (!temperaturas.empty() && !dias.empty()) {
        if (temperaturas.front() < minTemp) { // comparamos el valor de al frente de la cola con un valor muy pequeño
            minTemp = temperaturas.front();
            diaFrio = dias.top();
        }
        temperaturas.pop();
        dias.pop();
    }

    return diaFrio;
}

// Función para imprimir los días con temperatura mayor a 30 grados
void diasCalurosos(queue<int> temperaturas, stack<string> dias) {
    dias = invertirStack(dias); // Invertimos el stack para obtener el orden de "Lunes" a "Domingo"
    cout << "Días con temperaturas mayores a 30 grados (usar bloqueador solar):" << endl;

    while (!temperaturas.empty() && !dias.empty()) {
        if (temperaturas.front() > 30) {
            cout << dias.top() << ": " << temperaturas.front() << " grados - Recuerde usar bloqueador solar!" << endl;
        }
        temperaturas.pop();
        dias.pop();
    }
}

int main() {
    // Stack de días de la semana en orden de Lunes a Domingo
    stack<string> dias;
    dias.push("Lunes");
    dias.push("Martes");
    dias.push("Miércoles");
    dias.push("Jueves");
    dias.push("Viernes");
    dias.push("Sábado");
    dias.push("Domingo");

    // Cola de temperaturas para cada día (ordenada de Lunes a Domingo)
    queue<int> temperaturas;
    temperaturas.push(28); // lunes
    temperaturas.push(32); // martes    
    temperaturas.push(29); // miercoles
    temperaturas.push(35); // jueves 
    temperaturas.push(31); // viernes
    temperaturas.push(27); // sabado
    temperaturas.push(33); // domingo

    // Encuentra y muestra el día más caluroso y más frío
    string diaCaluroso = diaMasCaluroso(temperaturas, dias);
    string diaFrio = diaMasFrio(temperaturas, dias);

    cout << "Día más caluroso: " << diaCaluroso << "." << endl;
    cout << "Día más frío: " << diaFrio << "." << endl;

    // Muestra los días con temperaturas mayores a 30 grados
    diasCalurosos(temperaturas, dias);

    return 0;
}
