#include <iostream>
using namespace std;
class Animal
{
	protected:
		string nombre;
	public:
		Animal(string nombre)
		{
			this->nombre=nombre;
		}
		void Sonido() // Este método va con virtual para que sea sobreescrito por los demás métodos
		{
			cout<<"WAAAAAAAAA"<<endl; // Si no se usa virtual no se sobreescribirá y se llamará a este método
		}
};

class Perro : public Animal
{
	protected:
		string color;
	public:
		Perro(string nombre, string color) : Animal(nombre)
		{
			this->color=color;
		}
		void Sonido() // Si se usa este método, sobreescribirá el método de la clase base
		{
			cout<<"El perro con nombre: "<<nombre<<", es de color: "<<color<<" dice: guau guau soy un perro"<<endl;
		}
};

class Gato : public Animal
{
	protected:
		string color;
	public:
		Gato(string nombre, string color) : Animal(nombre)
		{
			this->color=color;
		}
		void Sonido() // Si se usa este método, sobreescribirá el método de la clase base
		{
			cout<<"El gato con nombre: "<<nombre<<", es de color: "<<color<<" dice: miau miau soy un gato"<<endl;
		}
};
int main()
{
	Perro * p = new Perro("Blu", "Cafe");
	Gato * g = new Gato("Gordo", "Naranjo");

	Animal* Arreglo[2]={p,g};

	for(int i=0;i<2;i++) // objeto p va a llamar a sonido y despues g a sonido 
	{
		Arreglo[i]->Sonido();
	}
}

