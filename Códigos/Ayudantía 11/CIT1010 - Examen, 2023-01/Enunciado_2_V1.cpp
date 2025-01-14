#include <iostream>
#include <map>
using namespace std;


class Almacenero
{
	private:
		map <string, int> deuda; 
		//Rut será tratado como string dado que el método fiar explicita ese tipo de dato
	
	public:
		Almacenero(){} //Constructor vacio.
	
	bool fiar(string rut, int monto)
	{
		map <string, int>::iterator miIterador;
		miIterador = deuda.find(rut);
		int montoNuevo;
		
		if(miIterador!=deuda.end()) //Se podría aceptar el fiado ya que el rut existe
		{
			montoNuevo = deuda[miIterador->first] + monto;
			if(montoNuevo<=10000) //Se acepta el fiado
			{
				deuda[miIterador->first] = montoNuevo;
				cout<<"Se acepta el fiado... su deuda es de "<<deuda[miIterador->first]<<endl;
				return true;	
			}
			cout<<"No se acepta el fiado dado que su deuda actual es de "<<deuda[miIterador->first]<<endl;
			return false; //No se aceptó el fiado
			
		}
		else if(monto<=10000) //Se acepta el fiado y el rut no existe
		{
			deuda[rut] = monto; 
			cout<<"Se acepta el fiado... su deuda es de "<<deuda[rut]<<endl;
			return true;
		}
		else //No se acepta el fiado
		{
			cout<<"No se acepta el fiado..."<<endl;
			return false;
		}
	}
	
	int pagarDeuda(string rut, int monto)
	{
		map <string, int>::iterator miIterador;
		miIterador = deuda.find(rut);
		
		if(miIterador!=deuda.end()) //Se podría pagar ya que el rut existe
		{
			if(deuda[miIterador->first]<monto) //Si va a pagar más de lo que debe, la deuda queda en cero
			{
				deuda[miIterador->first] = 0;
				cout<<"Deuda pagada. Su registro de deuda quedo en "<<deuda[miIterador->first]<<" pesos"<<endl;
				return 0;
			}
			else //Si paga todo lo que debe o menos... se actualiza a deuda actual menos el monto
			{
				deuda[miIterador->first] = deuda[miIterador->first] - monto;
				cout<<"Deuda pagada. Su registro de deuda quedo en "<<deuda[miIterador->first]<<" pesos"<<endl;
				return deuda[miIterador->first]; //Retorna la nueva deuda
			}
		}
		else
		{
			cout<<"Cliente no existe. No corresponde pagar deuda."<<endl;
			return 0;
		}		
	}	
};

int main()
{
	Almacenero *laJoyita = new Almacenero();
	laJoyita->fiar("111",15000);
	laJoyita->fiar("111",9000);
	laJoyita->fiar("111",2000);
	laJoyita->fiar("111",1000);
	laJoyita->pagarDeuda("111",3000);
	laJoyita->pagarDeuda("222",2000);
	laJoyita->pagarDeuda("111",6000);
	laJoyita->pagarDeuda("111",50000);
		
	return 0;
}