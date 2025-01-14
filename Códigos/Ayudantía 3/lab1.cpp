#include <iostream>
using namespace std;

class Criminal
{
	private:
		string nombreCriminal; // Atributo para almacenar el nombre del criminal
		int numeroIdentificacion, tiempoCondena; // Atributos para almacenar el número de identificación y el tiempo de condena en días
		
	public:
		Criminal(string nombreCriminal, int numeroIdentificacion, int tiempoCondena)
		{
			this->nombreCriminal = nombreCriminal; 
			this->numeroIdentificacion = numeroIdentificacion; // Inicialización del número de identificación
			this->tiempoCondena = tiempoCondena; // Inicialización del tiempo de condena
		}
		// SE HACE UN GET POR CADA ATRIBUTO DEL CRIMINAL
		string getNombre() // Método para obtener el nombre del criminal
		{
			return nombreCriminal;
		}
		
		int getNumeroIdentificacion() // Método para obtener el número de identificación del criminal
		{
			return numeroIdentificacion;
		}
		
		int getTiempoCondena() // Método para obtener el tiempo de condena del criminal
		{
			return tiempoCondena;
		}
		
		void actualizarTiempoPrision(int diasPasados) // Método para actualizar el tiempo de condena restando los días pasados
		{
			tiempoCondena -= diasPasados; // Disminuye el tiempo de condena por los días que han pasado
		}
};

class Prision
{
	private:
		string nombrePrision; // Atributo para almacenar el nombre de la prisión
		int dias; // Atributo para contar los días que han pasado en la prisión
		Criminal *criminales[4]; // Arreglo para almacenar punteros a los objetos Criminal (máximo 4 criminales)
		
	public:
		Prision(string nombrePrision, int dias)
		{
			this->nombrePrision = nombrePrision; // Inicialización del nombre de la prisión
			this->dias = dias; // Inicialización del contador de días
			for(int i = 0; i < 4; i++)
			{
				criminales[i] = NULL; // Inicialización del arreglo de criminales a NULL (vacío)
			}
		}
		// SE HACE UN GET POR CADA ATRIBUTO DE PRISION
		string getNombrePrision() // Método para obtener el nombre de la prisión
		{
			return nombrePrision;
		}
		
		int getDias() // Método para obtener el número de días que han pasado
		{
			return dias;
		}
		
		void arrestarCriminal(Criminal *c) // Método para arrestar a un criminal y agregarlo al arreglo de criminales
		{
			cout << "Se encarcelo al criminal " << c->getNombre() << " por un total de " << c->getTiempoCondena() << " dias. Su numero de identificacion sera el " << c->getNumeroIdentificacion() << endl;
			for(int i = 0; i < 4; i++)
			{
				if (criminales[i] == NULL) // Busca un espacio vacío en el arreglo para agregar al criminal
				{
					criminales[i] = c; // Agrega el criminal al arreglo
					break;
				}
			}
		}
		
		float promedioPresidioMayor() // Método para calcular el promedio de horas de condena en presidio mayor (5 a 10 años)
		{
		    int cantidadEnPM = 0; // Contador de criminales en presidio mayor
		    float acumulador = 0; // Acumulador para la suma de las condenas en días
		    for(int i = 0; i < 4; i++)
			{
				if (criminales[i]->getTiempoCondena() >= 1826 && criminales[i]->getTiempoCondena() <= 3650) // Verifica si la condena está entre 5 años y 1 día (1826 días) y 10 años (3650 días)
				{
				    cantidadEnPM++; // Incrementa el contador de criminales en presidio mayor, por ejemplo aqui entran 3 criminales
					acumulador += criminales[i]->getTiempoCondena(); // Suma de los dias de condena de los criminales
				}
			}
			return acumulador / cantidadEnPM * 24; // TOTAL CONDENAS / PERSONAS EN PRESIDIO MAYOR * 24 (DIAS A HORAS.)
		}
		
		void actualizarBaseDeDatos(int diasTranscurridos) // Método para actualizar la base de datos y reducir las condenas según los días transcurridos
		{
			dias += diasTranscurridos; // Actualiza el contador de días
			cout << "Han pasado " << dias << " dias en la prision desde que inicio el contador." << endl;
			for(int i = 0; i < 4; i++)
			{
				criminales[i]->actualizarTiempoPrision(diasTranscurridos); // Reduce el tiempo de condena para cada criminal
				if (criminales[i]->getTiempoCondena() <= 0) // Verifica si algún criminal ha cumplido su condena
				{
					cout << "El prisionero " << criminales[i]->getNumeroIdentificacion() << " ha cumplido su sentencia y ha sido liberado" << endl;
					criminales[i] = NULL; // Libera al criminal del arreglo (lo elimina)
				}
			}
		}	
};

int main()
{
	Prision *p = new Prision("GreenDolphinStreet", 0); // Se crea una prisión con el nombre "GreenDolphinStreet" e inicializa desde el día 0
	Criminal *c1 = new Criminal("Matias", 100001, 4361); // Se crea un criminal con 4361 días de condena (aprox. 12 años)
	Criminal *c2 = new Criminal("Felipe", 100002, 32); // Se crea un criminal con 32 días de condena
	Criminal *c3 = new Criminal("Enrique", 100003, 43); // Se crea un criminal con 43 días de condena
	Criminal *c4 = new Criminal("Florencia", 100004, 2551); // Se crea un criminal con 2551 días de condena (aprox. 7 años)
	p->arrestarCriminal(c1); // Se arresta al criminal c1
	p->arrestarCriminal(c2); // Se arresta al criminal c2
	p->arrestarCriminal(c3); // Se arresta al criminal c3
	p->arrestarCriminal(c4); // Se arresta al criminal c4
	if (p->promedioPresidioMayor() == 0) // Se verifica si hay criminales en presidio mayor
	{
	    cout << "No hay condena de presidio mayor" << endl; // Si no hay criminales en presidio mayor, se imprime este mensaje
	}
	else
	{
	    cout << "El promedio de horas por las condenas por presidio mayor es de " << p->promedioPresidioMayor() << " horas." << endl; // Si hay criminales en presidio mayor, se imprime el promedio de horas de condena
	}
}
