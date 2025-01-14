#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <map>

using namespace std;

class Clima {
public:
    map<string, int> pronostico;

    // Método para llenar el mapa pronostico con los días y sus temperaturas
    void llenarPronostico(queue<int> temperaturas, stack<string> dias) {
        dias = invertirStack(dias);  // Invertimos el stack para que quede en orden de lunes a domingo

        while (!temperaturas.empty() && !dias.empty()) {
            pronostico[dias.top()] = temperaturas.front();
            temperaturas.pop();
            dias.pop();
        }
    }

    // Método para encontrar el día con la temperatura más alta
    string diaMasCaluroso() {
        int maxTemp = -1000;
        string diaCaluroso;

        map<string, int>::iterator it = pronostico.begin();
        while (it != pronostico.end()) {
            if (it->second > maxTemp) {
                maxTemp = it->second;
                diaCaluroso = it->first;
            }
            ++it;
        }

        return diaCaluroso;
    }

    // Método para encontrar el día con la temperatura más baja
    string diaMasFrio() {
        int minTemp = 1000;
        string diaFrio;

        map<string, int>::iterator it = pronostico.begin();
        while (it != pronostico.end()) {
            if (it->second < minTemp) {
                minTemp = it->second;
                diaFrio = it->first;
            }
            ++it;
        }

        return diaFrio;
    }

    // Método para imprimir los días con temperatura mayor a 30 grados
    void diasCalurosos() {
        cout << "Días con temperaturas mayores a 30 grados (usar bloqueador solar):" << endl;

        map<string, int>::iterator it = pronostico.begin();
        while (it != pronostico.end()) {
            if (it->second > 30) {
                cout << it->first << ": " << it->second << " grados - Recuerde usar bloqueador solar!" << endl;
            }
            ++it;
        }
    }
    // Función auxiliar para invertir un stack
    stack<string> invertirStack(stack<string> original) {
        stack<string> invertido;
        while (!original.empty()) {
            invertido.push(original.top());
            original.pop();
        }
        return invertido;
    }
private:

};

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

    // se crea una instancia de la clase Clima y llenar el pronóstico
    Clima clima;
    clima.llenarPronostico(temperaturas, dias);

    // encuentra y muestra el día más caluroso y más frío
    string diaCaluroso = clima.diaMasCaluroso();
    string diaFrio = clima.diaMasFrio();

    cout << "Día más caluroso: " << diaCaluroso << " con " << clima.pronostico[diaCaluroso] << " grados." << endl;
    cout << "Día más frío: " << diaFrio << " con " << clima.pronostico[diaFrio] << " grados." << endl;

    // Muestra los días con temperaturas mayores a 30 grados
    clima.diasCalurosos();

    return 0;
}
