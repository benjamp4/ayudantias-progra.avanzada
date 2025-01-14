#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Persona {
protected:
 string nombre;
 string region;
 int edad;
public:
 Persona(string n = "", string r = "", int e = 0)
 : nombre(n), region(r), edad(e) {}
 virtual void imprimir() const {
 cout << "Nombre: " << nombre << endl;
 cout << "Región: " << region << endl;
 cout << "Edad: " << edad << endl;
 }
 int getEdad() const { return edad; }
};
class Docente : public Persona {
private:
 string asignatura;
 int anosDeExp;
public:
 Docente(string n = "", string r = "", int e = 0,
 string asig = "", int anos = 0)
 : Persona(n, r, e), asignatura(asig), anosDeExp(anos) {}
 void imprimir() const override {
 Persona::imprimir();
 cout << "Asignatura: " << asignatura << endl;
 cout << "Años de Experiencia: " << anosDeExp << endl;
 }
 string getRegion() const { return region; }
 int getAnosDeExp() const { return anosDeExp; }
 string getAsignatura() const { return asignatura; }
};
class Postulaciones {
private:
 vector<Docente> postulantes;
 vector<Docente> aceptados;
public:
 void postular(Docente* d) {
 postulantes.push_back(*d);
 }
 bool cantidadMinimaPostulantes() {
 return postulantes.size() >= 100;
 }
 int promedioEdad() {
 if (postulantes.empty()) return 0;
 int sumaEdades = 0;
 for (int i = 0; i < postulantes.size(); i++) {
 sumaEdades += postulantes[i].getEdad();
 }
 return sumaEdades / postulantes.size();
 }
 void validarPostulaciones() {
 if (!cantidadMinimaPostulantes()) {
 cout << "No se ha llegado a la cantidad mínima de postulantes." <<
endl;
 return;
 }
 aceptados.clear();
 for (int i = 0; i < postulantes.size(); i++) {
 if (postulantes[i].getRegion() == "Santiago" &&
 (postulantes[i].getAnosDeExp() > 10 ||
 postulantes[i].getAsignatura() == "Cálculo III")) {
 aceptados.push_back(postulantes[i]);
 }
 }
 }
 void imprimirAceptados() {
 cout << "Docentes Aceptados:" << endl;
 for (int i = 0; i < aceptados.size(); i++) {
 aceptados[i].imprimir();
 cout << "------------------------" << endl;
 }
 }
};