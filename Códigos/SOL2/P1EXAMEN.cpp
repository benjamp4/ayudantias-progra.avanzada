#include <iostream>
using namespace std;

//Primer requerimiento
int revisarApuesta(int numeroGanador, int numeroJugado)
{
	if(numeroJugado==numeroGanador) // Si el numero jugado es igual al numero ganador...
	{
		return 1000000;
	}
	else if(numeroJugado/100==numeroGanador/100 or numeroJugado%100==numeroGanador%100) // Si acierta a los dos primeros numeros O dos ultimos numeros
	{
		return 5000;
	}
	else if(numeroJugado%10==numeroGanador%10) // Si acierta al ultimo numero
	{
		return 500;
	}
	else // Si no, no gana nada
	{
		return 0;
	}
}

//Segundo Requerimiento 
int premioTotalObtenido(int numeroGanador, int apuestas[20]) // El premio total recibe el numero ganador y total de apuestas
{
	int montoPremio = 0; //Acumulador para obtener el total del premios
	for(int i=0;i<20;i++) // 20 apuestas...
	{
		montoPremio = montoPremio + revisarApuesta(numeroGanador,apuestas[i]); 
		//Usando cada índice en el arreglo "apuestas" (uno por uno) se invoca a la función revisarApuesta y se acumula el premio. 
	}
	return montoPremio; //El return debe estar "fuera" del ciclo for. 
}


//Tercer requerimiento 
int main()
{
 	int numeroGanador, premioTotal;
 	int gastoTotalEnApuestas = 600*20; // Gasto 600 en 20 apuestas // 
 	int apuestas[20];
 	
 	cout<<"Ingrese el numero ganador --> ";
 	cin>>numeroGanador; // Numero que debe ganar
 	cout<<"----"<<endl;
	
	for(int i=0;i<20;i++)
	{
		cout<<"Ingrese la apuesta "<<i+1<<" --> "; // MI apuesta
		cin>>apuestas[i];
	}	
	
	cout<<"---"<<endl;
	premioTotal = premioTotalObtenido(numeroGanador,apuestas); // Premio total va a recibir el numero apostado y la cantidad apuestas
	cout<<"El premio total que usted ha obtenido es: "<<premioTotal<<endl; // El premio total es...
	cout<<"---"<<endl;
	
	if(premioTotal>=gastoTotalEnApuestas) // Si el premio total es mayor a lo que gasté...
	{
		cout<<"Dado su premio, usted recupero el gasto que hizo en apuestas"<<endl;
	}
	else
	{
		cout<<"Dado su premio, usted no pudo recuperar el gasto que hizo en apuestas"<<endl;
	} 
}