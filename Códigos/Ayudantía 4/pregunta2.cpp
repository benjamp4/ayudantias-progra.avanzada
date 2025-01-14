#include <iostream>
using namespace std;
class Investigacion
 {
  private: // INT REVISTAS
   int Nature;
   int Science;
   int Astrophys;
  public:
  	Investigacion()
  	 { // REVISTAS INICIALIZADAS EN 0
  	 	Nature = 0;
  	 	Science = 0;
  	 	Astrophys = 0;
	   }
	void acumularEnRevista(string nombreRevista) // metodo acumularRevista que recibe una revista y la aumenta en uno
	 {
	  if (nombreRevista == "Nature")
	    {
	    Nature++;	
			}	
	  if (nombreRevista == "Science")
	    {
	    Science++;	
			} 
	  if (nombreRevista == "Astrophys")
	    {
	    Astrophys++;	
			}
	 }
	void eliminarArticuloRevista(string nombreRevista) // eliminar revista, recibe una revista y la elimina 
	 {
	  if (nombreRevista == "Nature" && Nature > 0) // tiene que tener por lo menos una revista
	    {
	    Nature--;	
			}	
	  if (nombreRevista == "Science" && Science > 0)
	    {
	    Science--;	
			} 
	  if (nombreRevista == "Astrophys" && Astrophys > 0)
	    {
	    Astrophys--;	
			}
	 }
void imprimirEstadisticas()
 {
 	cout << "ESTADISTICAS INVESTIGACION"<<endl; // Imprime todas las estadisticas 
 	cout << "Nature "<< Nature << " articulos" << endl; // 5
 	cout << "Science "<< Science << " articulos" << endl; // 10
 	cout << "Astrophys "<< Astrophys << " articulos" << endl; // 5
 	float suma = Nature + Science + Astrophys; // Suma de todas las revistas
 	if ( suma > 0) 
 	  {
       	cout << "Nature "<< Nature/suma *100.0 << " %" << endl; // Porcentaje de nature // 25%
	 	cout << "Science "<< Science/suma *100.0 << " %" << endl; // Porcentaje de science // 50%
 		cout << "Astrophys "<< Astrophys/suma *100.0 << " %" << endl; // Porcentaje de astrophys // 25%
 	  	
	   }
	cout << "----------------------"<<endl<<endl;
	  }	 
    };
int main()
 {
	Investigacion *inv = new Investigacion();
	inv->imprimirEstadisticas();
	inv->acumularEnRevista("Nature");
	inv->acumularEnRevista("Nature");
	inv->acumularEnRevista("Science");
	inv->acumularEnRevista("Nature");
	inv->acumularEnRevista("Nature");
	inv->acumularEnRevista("Astrophys");
	inv->acumularEnRevista("Astrophys");
	inv->imprimirEstadisticas();
 }

