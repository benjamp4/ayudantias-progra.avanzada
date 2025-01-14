#include <iostream>
#include <string>
using namespace std;

void reprobadosPorAsistencia(string rut[100], int asistencias[100], int numeroDeClases) {
    cout << "Alumnos reprobados por asistencia: " << endl;
    for (int i = 0; i < 100; i++) {
        if (asistencias[i] < (numeroDeClases * 0.6)) {
            cout << "RUT: " << rut[i] << endl;
        }
    }
}

void listarOrdenado(string rut[100], int asistencias[100], int numeroDeClases) {
    // Crear copias de los arreglos originales
    string rutOrdenado[100];
    int asistenciasOrdenadas[100];
    double porcentaje[100];

    for (int i = 0; i < 100; i++) {
        rutOrdenado[i] = rut[i];
        asistenciasOrdenadas[i] = asistencias[i];
        porcentaje[i] = (double)asistencias[i] / numeroDeClases * 100.0;
    }

    // Ordenamiento por porcentaje en forma descendente (sin swap)
    for (int i = 0; i < 100 - 1; i++) {
        for (int j = 0; j < 100 - i - 1; j++) {
            if (porcentaje[j] < porcentaje[j + 1]) {
                // Intercambiar manualmente los valores entre posiciones
                double tempPorcentaje = porcentaje[j];
                porcentaje[j] = porcentaje[j + 1];
                porcentaje[j + 1] = tempPorcentaje;

                string tempRut = rutOrdenado[j];
                rutOrdenado[j] = rutOrdenado[j + 1];
                rutOrdenado[j + 1] = tempRut;

                int tempAsistencias = asistenciasOrdenadas[j];
                asistenciasOrdenadas[j] = asistenciasOrdenadas[j + 1];
                asistenciasOrdenadas[j + 1] = tempAsistencias;
            }
        }
    }

    // Imprimir resultados ordenados
    cout << "Listado ordenado por porcentaje de asistencia: " << endl;
    for (int i = 0; i < 100; i++) {
        cout << "RUT: " << rutOrdenado[i]
             << ", Asistencias: " << asistenciasOrdenadas[i]
             << ", % Asistencia: " << porcentaje[i] << "%" << endl;
    }
}

int main() {
    string rut[100];
    int asistencias[100];
    int numeroDeClases;

    cout << "Ingrese el número total de clases: ";
    cin >> numeroDeClases;

    cout << "Ingrese los RUT de los 100 alumnos: " << endl;
    for (int i = 0; i < 100; i++) {
        cin >> rut[i];
    }

    cout << "Ingrese las asistencias de los 100 alumnos: " << endl;
    for (int i = 0; i < 100; i++) {
        cin >> asistencias[i];
    }

    reprobadosPorAsistencia(rut, asistencias, numeroDeClases);
    listarOrdenado(rut, asistencias, numeroDeClases);

    return 0;
}
