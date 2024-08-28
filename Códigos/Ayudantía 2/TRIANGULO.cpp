#include <iostream>
using namespace std;
class Triangulo{
private:

int lado1, lado2, base, altura;

public:

// SET

void setLado1(int l1){
    lado1 = l1;
}
void setLado2(int l2){
    lado2 = l2;
}
void setBase(int b){
    base = b;
}
void setAltura(int a){
    altura = a;
}

// GET

int getLado1(){
    return lado1;
}
int getLado2(){
    return lado2;
}
int getBase(){
    return base;
}
int getAltura(){
    return altura;
}

// Calcular perimetro y area

int calcularPerimetro(){
    return lado1 + lado2 + base;
}

int calcularArea(){
    return (base*altura)/2;
}

};

int main(){
    Triangulo triangulo;
    int lado1, lado2, base, altura;
    // Aqui le entregamos los valores al triangulo, entonces quedaran guardados y podran ser entregados a los metodos
    cout << "Ingrese lado 1 del triangulo. " << endl;
    cin >> lado1;
    cout << "Ingrese lado 2 del triangulo. " << endl;
    cin >> lado2;
    cout << "Ingrese base del triangulo. " << endl;
    cin >> base;
    cout << "Ingrese altura del triangulo. " << endl;
    cin >> altura;

    triangulo.setLado1(lado1);
    triangulo.setLado2(lado2);
    triangulo.setBase(base);
    triangulo.setAltura(altura);

    cout << "Su triangulo de base: " << triangulo.getBase() << " y altura: " << triangulo.getAltura();
    cout << " | Lado 1: " << triangulo.getLado1() << " y Lado 2: " << triangulo.getLado2() << endl;
    cout << "Tiene un perimetro de " << triangulo.calcularPerimetro() << " Y Area de " << triangulo.calcularArea() << endl;


}