#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Clase Estudiante
class Estudiante {
public:
    string nombre;
    int rut;
    vector<string> cursosMatriculados;

    Estudiante(string nombre, int rut) {
        this->nombre = nombre;  // asignación de los atributos usando this
        this->rut = rut;
        // el vector cursosMatriculados se inicializa automáticamente como vacío
    }

    // método para matricularse en el curso, ingresa un string curso a un vector de cursos.
    void matricularCurso(string curso) {
        cursosMatriculados.push_back(curso);  
    }

    // método para mostrar los cursos en los que el estudiante está matriculado
    void mostrarCursos() {
    cout << "Cursos matriculados por " << nombre << ": ";  
    for (int i = 0; i < cursosMatriculados.size(); i++) {  
        cout << cursosMatriculados[i] << ". ";
    }
    cout << endl;
}
};

class Curso {
public:
    string nombreCurso;
    string codigoCurso;
    vector<Estudiante*> estudiantesMatriculados; // vector de clases estudiante

    Curso(string nombreCurso, string codigoCurso) {
        this->nombreCurso = nombreCurso;
        this->codigoCurso = codigoCurso;
        // el vector estudiantesMatriculados se inicializa automáticamente como vacío
    }

    // Método para matricular un estudiante en el curso
    void matricularEstudiante(Estudiante* estudiante) {
        estudiantesMatriculados.push_back(estudiante);  
        estudiante->matricularCurso(nombreCurso); 
    }


    // Método para mostrar los estudiantes matriculados en el curso
    void mostrarEstudiantes() {
    cout << "Estudiantes matriculados en " << nombreCurso << ": ";  
    for (int i = 0; i < estudiantesMatriculados.size(); i++) {  
        cout << estudiantesMatriculados[i]->nombre << ". ";  
    }
    cout << endl;
}
};

int main() {

    Estudiante* estudiante1 = new Estudiante("Diego Mena", 21471976);
    Estudiante* estudiante2 = new Estudiante("Kanye West", 21733733);
    Estudiante* estudiante3 = new Estudiante("Vicente Diaz", 21733734);
    Estudiante* estudiante4 = new Estudiante("Pepe Miguel", 21733735);
    Estudiante* estudiante5 = new Estudiante("John Duart", 21733736);

    // Crear cursos dinámicamente con new
    Curso* curso1 = new Curso("Programación", "CIT1000");
    Curso* curso2 = new Curso("Progamación Avanzada", "CIT1010");

    curso1->matricularEstudiante(estudiante1);
    curso1->matricularEstudiante(estudiante2);
    curso1->matricularEstudiante(estudiante3);
    curso1->matricularEstudiante(estudiante4);
    curso1->matricularEstudiante(estudiante5);
    curso2->matricularEstudiante(estudiante1);

    // Mostrar estudiantes en cada curso
    curso1->mostrarEstudiantes();
    curso2->mostrarEstudiantes();

    // Mostrar los cursos en los que cada estudiante está matriculado
    estudiante1->mostrarCursos();
    estudiante2->mostrarCursos();
    estudiante3->mostrarCursos();
    estudiante4->mostrarCursos();
    estudiante5->mostrarCursos();

    return 0;
}
