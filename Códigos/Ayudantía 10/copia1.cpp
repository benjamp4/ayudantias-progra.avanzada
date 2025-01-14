#include <iostream>
#include <vector>
using namespace std;
class Persona{
protected:
string nombre;
string region;
int edad;
public:
Persona(string nombre, string region,int edad){
this->nombre=nombre;
this->region=region;
this->edad=edad;
}
virtual void imprimirdatos(){
cout<<"nombre: "<<nombre<<cout<<"region: "<<cout<<"edad: "<<endl;
}
};
class Docente: public Persona{
private:
string asignatura;
string anosdeexperiencia;
public:
Docente(string nombre,string region,int edad, string asignatura, string
anosdeexperiencia):Persona(nombre,region,edad){
this->asignatura=asignatura;
this->anosdeexperiencia=anosdeexperiencia;
}
void imprimirdatos() override{
persona:
cout<<"nombre: "<<nombre<<cout<<"region: "<<cout<<"edad:
"<<cout<<"asignatura: "<<asignatura<<cout<<"anosdeexperiencia: "<<
anosdeexperiencia<<endl;
}
};
class Postulaciones{
private:
vector<Docente*> postulantes;
vector<Docente*> aceptados;
public:
void postular(Docente *d) {
postulantes.push_back(d)
}
bool cantidadminimapostulantes() {
return postulantes.size() >= 100;
}
int promedioedad() {
if (postulantes.empty()) return 0;
int sumaEdades = 0;
for (auto docente : postulantes) {
sumaEdades += docente->edad;
}
return sumaEdades / postulantes.size();
}
int main()
{
int main() {
Postulaciones sistema;
sistema.postular(new Docente("Pepe", "Santiago", 45, "Calculo 1", 15));
sistema.postular(new Docente("Lucas", "Vallenar", 30, "Fisica", 5));
sistema.postular(new Docente("Tego", "Copiapo", 25, "Matemáticas", 3));
sistema.postular(new Docente("Alejandrasco", "Santiago", 85, "Quimica", 40));
}
cout << "Promedio de edad de los postulantes: " << sistema.promedioEdad() <<
endl;
return 0;
}