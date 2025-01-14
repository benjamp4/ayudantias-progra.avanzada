#include <iostream>
#include <map>
using namespace std;

class Almacenero
{
	private:
		map<string, int> deuda;
	public:
		Almacenero(){
		}
		
		bool fiar(string rut, int monto){
			if (monto > 10000) // Si el monto es mayor a 10 mil no se acepta el fiado
				return false;
			
			if (deuda.find(rut) == deuda.end()){ // Si no existe el rut se crea la casilla 
				deuda[rut] = monto;  // creada
				return true;
			}
			else { // si tiene deuda, osea ya hay un rut registrado a esa deuda
				if (monto + deuda[rut] <= 10000){ // nueva deuda dentro del monto
					deuda[rut] = deuda[rut] + monto; // se le suma el monto a la deuda
					return true;
				}
				else{
					return false; // Si no, return false...
				}
			}
			
		}
		
		int pagarDeuda(string rut, int monto){
			if(deuda.find(rut) != deuda.end()){ // tiene deuda
				if (deuda[rut] >= monto){ // La deuda tiene que ser mayor o igual al monto a pagar
					deuda[rut] = deuda[rut] - monto; // Para que la deuda se le reste al monto a pagar
				}
				return deuda[rut]; // Retorna la deuda actualizada
			}
			else { //no tiene deuda que pagar
				return -1;
			}
		}
		
		int deudaTotal(){
			map<string, int>::iterator it; // Iterador para recorrer el map
			int suma=0;
			for (it = deuda.begin(); it != deuda.end(); it++) // Recorre el second, todas las deudas y las suma.
				suma += it->second;			
			return suma;
		}
};


int main(){
	return 0;
}
