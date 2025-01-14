#include <iostream>
#include <string>
using namespace std;

void cargarPalabras(string palabras[100]) {
    cout << "Ingrese las 100 palabras: " << endl;
    for (int i = 0; i < 100; i++) {
        cin >> palabras[i];
    }
}

int ocurrencias(string palabraRespuesta, string palabras[100]) {
    int contador = 0;
    for (int i = 0; i < 100; i++) {
        if (palabras[i] == palabraRespuesta) {
            contador++;
        }
    }
    return contador;
}

bool yaAdivinada(string palabra, string palabrasAdivinadas[], int totalAdivinadas) {
    for (int i = 0; i < totalAdivinadas; i++) {
        if (palabrasAdivinadas[i] == palabra) {
            return true;
        }
    }
    return false;
}

int jugar(string palabras[100]) {
    string palabrasAdivinadas[100]; // Lista de palabras que ya fueron adivinadas
    int totalAdivinadas = 0;
    int fallos = 0;
    int puntaje = 0;

    while (fallos < 3) {
        string intento;
        cout << "Adivine una palabra: ";
        cin >> intento;

        if (!yaAdivinada(intento, palabrasAdivinadas, totalAdivinadas)) {
            int ocurrenciasPalabra = ocurrencias(intento, palabras);
            if (ocurrenciasPalabra > 0) {
                puntaje += ocurrenciasPalabra;
                palabrasAdivinadas[totalAdivinadas++] = intento;
                cout << "Correcto! Puntaje actual: " << puntaje << endl;

                if (puntaje == 100) {
                    cout << "Ganador!" << endl;
                    return puntaje;
                }
            } else {
                fallos++;
                cout << "Incorrecto. Intentos restantes: " << (3 - fallos) << endl;
            }
        } else {
            cout << "Ya adivinaste esa palabra." << endl;
        }
    }

    cout << "Perdió por intentos. Puntaje acumulado: " << puntaje << endl;
    return puntaje;
}

int main() {
    string palabras[100];
    cargarPalabras(palabras);
    jugar(palabras);
    return 0;
}