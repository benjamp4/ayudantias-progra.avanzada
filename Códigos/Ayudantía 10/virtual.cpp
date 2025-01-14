#include <iostream>
using namespace std;

class Persona {
public:
    virtual void imprimir() { // Funcion virtual, que puede sobreponerse a la otra funcion sin virtual
        cout << "Nombre: Carlos " << endl;
        cout << "Edad: 20" << endl;
    }
};

class Profesor : public Persona {
public:
    void imprimir() { // 
        Persona::imprimir(); // Llama al método de la clase base
        cout << getAsignatura() << endl; // retorna aisgnatura
        cout << getAnosDeExp() << endl; // retorna años de exp
    }

    string getAsignatura() {
    return "Matemáticas"; 
    }

    int getAnosDeExp() { 
    return 10; 
    }

};

int main() {
    Persona* p = new Profesor();
    p->imprimir();
    return 0;
}

