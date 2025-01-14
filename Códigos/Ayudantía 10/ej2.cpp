#include <iostream>
#include <map>
#include <stack>
using namespace std;

class Elecciones {
private:
    map<string, stack<int> > votos; // Mapa donde cada comuna tiene un stack de votos

public:
    Elecciones() {}

    // Método para agregar un voto a una comuna
    void agregarVoto(string comuna, int voto) {
        votos[comuna].push(voto); // Agrega el voto al stack de la comuna 
    }

    // Método para mostrar los votos de todas las comunas
    void mostrarVotos() {
        map<string, stack<int> >::iterator it; // Ocupamos un iterador para contar los votos
        for (it = votos.begin(); it != votos.end(); it++) { // Desde el principio hasta el fin
            cout << "Comuna: " << it->first << endl; // Comuna es igual a el primer elemento del map
            stack<int> tempStack = it->second; // Stack temporal es igual al segundo elemento del map

            // Mostramos los votos en el stack
            while (!tempStack.empty()) { // Mientras el stack tmemporal no esté vacio
                cout << "Voto: " << tempStack.top() << endl; // Imprimr el elemento en la cima del stack
                tempStack.pop(); // Eliminar del stack temporal
            }
        }
    }

    // Método para contar los votos totales de una comuna
    void contarVotos(string comuna) { // Contar votos por comuna
        if (votos.find(comuna) != votos.end()) { // Buscar hasta que sea distinto al final
            int total = 0; // total en 0
            stack<int> tempStack = votos[comuna]; // Stack temporal para almacenar votos por comuna
            while (!tempStack.empty()) { // Mientra el stack temporal no esté vacio
                total += tempStack.top(); // Sumar al total el elemento de la cima del stack
                tempStack.pop(); // Eliminar elemento temporal del stack
            }
            cout << "Total de votos en " << comuna << ": " << total << endl;
        } else {
            cout << "No hay votos registrados para la comuna " << comuna << endl;
        }
    }

    // Método para contar los votos totales de varias comunas y mostrar el porcentaje por comuna
    void contarVotosPorCiudad(map<string, int> comunas) { // Contar votos por ciudad
        int totalCiudad = 0; // Total por ciudad en 0
        map<string, int>::iterator it; // Iterador

        // Calculamos el total de votos de la ciudad sumando los votos de las comunas seleccionadas
        for (it = comunas.begin(); it != comunas.end(); it++) { // Recorrer comunas 
            string comuna = it->first; // La comuna es igual al primer elemento del map
            if (votos.find(comuna) != votos.end()) { // Recorrer votos hasta el final
                stack<int> tempStack = votos[comuna]; // Temp stack es igual a los votos
                while (!tempStack.empty()) { 
                    totalCiudad += tempStack.top();
                    tempStack.pop();
                }
            }
        }

        // Mostramos el total de votos de la ciudad
        cout << "Total de votos en la ciudad: " << totalCiudad << endl; // Total ciudad es la suma de los votos x comuna

        // Calculamos y mostramos el porcentaje de votos por comuna
        for (it = comunas.begin(); it != comunas.end(); it++) {
            string comuna = it->first;
            if (votos.find(comuna) != votos.end()) {
                int votosComuna = 0;
                stack<int> tempStack = votos[comuna];
                while (!tempStack.empty()) {
                    votosComuna += tempStack.top();
                    tempStack.pop();
                }
                int porcentaje = votosComuna * 100 / totalCiudad; // Porcentaje por cada comuna respecto a la ciudad
                cout << "Comuna " << comuna << ": " << votosComuna << " votos (" << porcentaje << "%)" << endl;
            }
        }
    }
};

int main() {
    Elecciones elecciones;

    // Agregamos votos a diferentes comunas
    elecciones.agregarVoto("Maipu", 33);
    elecciones.agregarVoto("Maipu", 20);
    elecciones.agregarVoto("Quilicura", 15);
    elecciones.agregarVoto("Quilicura", 10);
    elecciones.agregarVoto("Indepedencia", 25);

    // Mostramos los votos de todas las comunas
    elecciones.mostrarVotos();

    // Contamos los votos totales para una comuna específica
    elecciones.contarVotos("Maipu");
    elecciones.contarVotos("Quilicura");
    elecciones.contarVotos("Las Condes"); // Comuna sin votos

    // Definimos las comunas de la ciudad
    map<string, int> comunasCiudad;
    comunasCiudad["Maipu"] = 0;
    comunasCiudad["Quilicura"] = 0;
    comunasCiudad["Indepedencia"] = 0;

    // Contamos los votos por ciudad y mostramos el porcentaje
    elecciones.contarVotosPorCiudad(comunasCiudad);

    return 0;
}
