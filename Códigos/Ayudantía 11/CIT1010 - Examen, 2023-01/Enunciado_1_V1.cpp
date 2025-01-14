#include <iostream>
#include <queue>
using namespace std;

class ManejoListaDeEspera
{
	private:
		queue <string> urgencia;
		queue <string> normal;
		int control_llamadas;
	
	public:
		ManejoListaDeEspera()
		{
			this->control_llamadas = 0; //Debe iniciar en cero
		}

	void añadirPaciente(string nombre, int criticidad) 
	{
		if(criticidad == 1) // Criticidad es igual a 1 pasa a urgencia
		{
			urgencia.push(nombre); 
			cout<<"Agregado a lista de Urgencia"<<endl;
		}
		else if(criticidad == 0) // Si es 0 pasa a normal
		{
			normal.push(nombre);
			cout<<"Agregado a lista normal"<<endl;
		}
		else // Si no es ninguna de las dos no se puede
		{
			cout<<"No se puede agregar. Criticidad debe ser 0 o 1. Reintente"<<endl;
		}
	}
	
	string llamarPaciente()
	{
		string n; // Nombre paciente
		if(!normal.empty() && control_llamadas==5) // Normal tiene pacientes y toca atender esta fila
		{
			control_llamadas = 0;
			n = normal.front(); // Se atiende al paciente normal porque hay pacientes normales y ya se llamaron 5 de urgencias
			normal.pop();
		}
		else if(!urgencia.empty() && control_llamadas!=5) //Urgencia tiene pacientes y toca atender esta fila
		{
			control_llamadas = control_llamadas + 1; // Se le suma 1 a urgencias porque hay pacientes en urgencias y no se han llamado 5 pacientes
			n = urgencia.front();
			urgencia.pop();
		}
		else if(urgencia.empty() && !normal.empty()) //Urgencia no tiene pacientes, pero la normal si
		{
			control_llamadas = 0; //Se atiende uno normal, se vuelve a cero el contador
			n = normal.front();
			normal.pop();			
		}
		else if(!urgencia.empty() && normal.empty()) //Urgencia tiene pacientes y, aunque su contador esté en 5, atiende porque la normal no tiene pacientes
		{
			n = normal.front();
			normal.pop();
			if(control_llamadas!=5)
			{
				control_llamadas = control_llamadas + 1; //Solo sumamos si es que el contador no era 5. Esto asegura mantener la condición. 
			}
		}
		else //Ambas filas están vacías
		{
			n = "No hay pacientes en espera";
		}
		return n;
	}
	
	
	void estadisticaEspera()
	{
		int urg, norm, tot;
		urg = urgencia.size(); // Es igual al tamaño de la cola
		norm = normal.size(); // Igual al tamaño de la cola..
		tot = urg + norm; // Se suman los dos tamaños...
		
		cout<<"Hay un total de "<<tot<<" pacientes en espera"<<endl;
		cout<<"De los pacientes en espera "<<urg<<" corresponden a la fila de Urgencia"<<endl;
		cout<<"De los pacientes en espera "<<norm<<" corresponden a la fila Normal"<<endl;
	}	
};


int main()
{
	return 0;
}