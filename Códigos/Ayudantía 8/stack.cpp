#include <iostream>
#include <stack>
using namespace std;

class Pelicula {
private:
    string titulo, genero, director;
    int año, precio;
public:
    Pelicula(string titulo, string genero, string director, int año, int precio) {
        this->titulo = titulo;
        this->genero = genero;
        this->año = año;
        this->director = director;
        this->precio = precio;
    }
    string getGenero() {
        return genero;
    }
    void info() {
        cout << "Titulo: " << titulo << " - Genero: " << genero << " - Director: " << director << " - Año: " << año << " - Precio: " << precio << endl;
    }
};

class Blockbuster {
private:
    stack<Pelicula*> cajaDesordenada;
    stack<Pelicula*> cajaAnimacion;
    stack<Pelicula*> cajaDrama;
    stack<Pelicula*> cajaRomance;
public:
    Blockbuster() {
    }

    void agregarPelicula(Pelicula* pelicula) {
        cajaDesordenada.push(pelicula);
    }

    void ordenar() {
        while (!cajaDesordenada.empty()) { // Mientras la caja desordenada no esté vacía 
            string genero = cajaDesordenada.top()->getGenero(); // el género será el ultimo elemento añadido a la caja desordenada

            if (genero == "Animación") { // Si el genero es animacion
                cajaAnimacion.push(cajaDesordenada.top()); // Se añade el elemento en la cima de la pila de la caja desordenada a la caja de animación
                cout << "Pelicula Agregada a Animación." << endl; 
                cajaAnimacion.top()->info(); // Se muestra la info del elemento añadido a cajaAnimacion
            }
            else if (genero == "Drama") {
                cajaDrama.push(cajaDesordenada.top());
                cout << "Pelicula Agregada a Drama." << endl;
                cajaDrama.top()->info(); // Se muestra la info del elemento añadido a cajaDrama
            }
            else if (genero == "Romance") {
                cajaRomance.push(cajaDesordenada.top());
                cout << "Pelicula Agregada a Romance." << endl;
                cajaRomance.top()->info(); // Se muestra la info del elemento añadido a cajaComedia
            }
            else {
                cout << "Error al ordenar." << endl;
            }
            cajaDesordenada.pop(); // Se elimina el elemento de la caja desordenada, ya que este se copió a la caja que corresponde.
            cout << "-------------------------------------------------------------------------------------------------------" << endl;
        }
        cout << "Se han ordenado todas las peliculas" << endl;
    }
};

int main() {
    Blockbuster* tienda = new Blockbuster();

    // Agregar peliculas después de la creación del objeto
    tienda->agregarPelicula(new Pelicula("Fallen Angels", "Drama", "Wong Kar-wai", 1995, 15000));
    tienda->agregarPelicula(new Pelicula("Submarine", "Romance", "Richard Ayoade", 2010, 12000));
    tienda->agregarPelicula(new Pelicula("Isle of Dogs", "Animación", "Wes Anderson", 2018, 18000));
    tienda->agregarPelicula(new Pelicula("The End of Evangelion", "Animación", "Hideaki Anno", 1997, 17000));

    tienda->ordenar();

    return 0;
}
