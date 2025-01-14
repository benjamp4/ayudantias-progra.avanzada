// Un profesor de progra tiene 3 secciones, de 30, 20 y 40 alumnos y guarda esta información en arreglos de float.
// 1. Programe la funcion leer que lee por teclado las notas para las 3 secciones y las deja en su correspondiente arreglo.
// 2. Programe una funcion que devuelva la cantidad de rojos
// 3. Programe una funcion que devuelva la cantidad de azules.
// 4. Programe una funcion listar que ordena una a una todas las notas de forma ordenada
// 5. Programe la funcion ocurrencias que lista todas las notas entre 1 y 7 e indica cuantas veces se repitio dicha nota entre todos los cursos


#include <iostream>
using namespace std;

void leerNotas(float sec1[30], float sec2[20], float sec3[40]) {
    cout << "Ingrese las notas para la sección 1 (30 estudiantes):";
    for (int i = 0; i < 30; i++) {
        cout << "Nota del estudiante " << i + 1 << ": ";
        cin >> sec1[i]; // CIN es leer por teclado Console In, CIN C Ingresar... 
    }
    cout << "Ingrese las notas para la sección 2 (20 estudiantes):";
    for (int i = 0; i < 20; i++) {
        cout << "Nota del estudiante " << i + 1 << ": ";
        cin >> sec2[i];
    }
    cout << "Ingrese las notas para la sección 3 (40 estudiantes):";
    for (int i = 0; i < 40; i++) {
        cout << "Nota del estudiante " << i + 1 << ": ";
        cin >> sec3[i];
    }
}

int rojos(float sec1[30], float sec2[20], float sec3[40]) {
    int count = 0;
    for (int i = 0; i < 30; i++) { // 1.0[0] 3.0[1] 4.0 1.0 5.0 3.0 
        if (sec1[i] < 4) {
            count++;
        }
    }
    for (int i = 0; i < 20; i++) {
        if (sec2[i] < 4) {
            count++;
        }
    }
    for (int i = 0; i < 40; i++) {
        if (sec3[i] < 4) {
            count++;
        }
    }
    return count;
}

int azules(float sec1[30], float sec2[20], float sec3[40]) {
    int count = 0;
    for (int i = 0; i < 30; i++) {
        if (sec1[i] > 4) {
            count++;
        }
    }
    for (int i = 0; i < 20; i++) {
        if (sec2[i] > 4) {
            count++;
        }
    }
    for (int i = 0; i < 40; i++) {
        if (sec3[i] > 4) {
            count++;
        }
    }
    return count;
}

void listarNotas(float sec1[30], float sec2[20], float sec3[40]) {
    // BubbleSort 

    for (int i = 0; i < 29; i++) {
        for (int j = 0; j < 29 - i; j++) {
            if (sec1[j] > sec1[j + 1]) {
                float temp = sec1[j];
                sec1[j] = sec1[j + 1];
                sec1[j + 1] = temp;
            }
        }
    }

    cout << "Notas ordenadas de la sección 1: ";
    for (int i = 0; i < 30; i++) {
        cout << sec1[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19 - i; j++) {
            if (sec2[j] > sec2[j + 1]) {
                float temp = sec2[j];
                sec2[j] = sec2[j + 1];
                sec2[j + 1] = temp;
            }
        }
    }
    cout << "Notas ordenadas de la sección 2: ";
    for (int i = 0; i < 20; i++) {
        cout << sec2[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < 39; i++) {
        for (int j = 0; j < 39 - i; j++) {
            if (sec3[j] > sec3[j + 1]) {
                float temp = sec3[j];
                sec3[j] = sec3[j + 1];
                sec3[j + 1] = temp;
            }
        }
    }
    cout << "Notas ordenadas de la sección 3: ";
    for (int i = 0; i < 40; i++) {
        cout << sec3[i] << " ";
    }
    cout << endl;
}

void ocurrencias(float sec1[30], float sec2[20], float sec3[40]) {
    cout << "Ocurrencias de notas en la sección 1:";
    for (float i = 1.0; i <= 7.0; i += 0.1) { // 1.0, 1.1, 1.2, 1.3,
        int count = 0;
        for (int j = 0; j < 30; j++) {
            if (sec1[j] == i) {
                count++;
            }
        }
        if (count > 0) {
            cout << "La nota " << i << " se repitió " << count << " veces.";
        }
    }
    cout << "Ocurrencias de notas en la sección 2:";
    for (float i = 1.0; i <= 7.0; i += 0.1) {
        int count = 0;
        for (int j = 0; j < 20; j++) {
            if (sec2[j] == i) {
                count++;
            }
        }
        if (count > 0) {
            cout << "La nota " << i << " se repitió " << count << " veces.";
        }
    }
    cout << "Ocurrencias de notas en la sección 3:";
    for (float i = 1.0; i <= 7.0; i += 0.1) {
        int count = 0;
        for (int j = 0; j < 40; j++) {
            if (sec3[j] == i) {
                count++;
            }
        }
        if (count > 0) {
            cout << "La nota " << i << " se repitió " << count << " veces.";
        }
    }
}

int main() {
    float sec1[30], sec2[20], sec3[40];
    leerNotas(sec1, sec2, sec3);
    cout << "Cantidad de rojos: " << rojos(sec1, sec2, sec3) << endl;
    cout << "Cantidad de azules: " << azules(sec1, sec2, sec3) << endl;
    listarNotas(sec1, sec2, sec3);
    ocurrencias(sec1, sec2, sec3);
    return 0;
}
