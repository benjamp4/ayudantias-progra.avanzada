#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    map<string, float> notas;

    notas["Miguel"] = 6.7;
    notas["Pepe"] = 4.0;
    notas["Charles"] = 6.3;

    cout << "Lista de estudiantes y sus notas:" << endl;
    map<string, float>::iterator i;
    for (i = notas.begin(); i != notas.end(); ++i) {
        cout << "Estudiante: " << i->first << ", Nota: " << i->second << endl;
    }

    string nombre;
    cout << "¿A qué alumno le quiere dar 5 décimas?" << endl;
    cin >> nombre;

    if (notas.find(nombre) != notas.end()) { // Si se cumple esto, osea que el nombre esté en el map, se suma las decimas
        float nueva_nota = notas[nombre] + 0.5; // Si no se cumple esto, osea, el nombre no está en el map, no se encuentra el estudiante

        if (nueva_nota > 7.0) {
            float decimas_restantes = nueva_nota - 7.0;
            nueva_nota = 7.0;
            cout << "La nota final de " << nombre << " es 7.0, y tiene " << decimas_restantes*10
                 << " décimas para la siguiente prueba, tsss... la vidita..." << endl;
        } else {
            notas[nombre] = nueva_nota;
            cout << "La nueva de " << nombre << " es: " << nueva_nota << "Wena!" << endl;
        }
    } else {
        cout << "Estudiante no encontrado." << endl;
    }

    return 0;
}
