#include <iostream>
using namespace std;
class PreguntaRespuesta
 {
  private:
   int respuestaAlumno; // Atributos Alumno, Correcta, Puntaje
   int respuestaCorrecta;
   float puntajePregunta; //el que otorga si la respuesta es correcta
  public:
   PreguntaRespuesta(int respuestaAlumno, int respuestaCorrecta, float puntajePregunta)
    {
    	this->respuestaAlumno = respuestaAlumno;
    	this->respuestaCorrecta = respuestaCorrecta;
    	this->puntajePregunta = puntajePregunta;
		}	
	float getPuntajePregunta()
	 {
	 	return puntajePregunta;
	 }
    float getPuntaje()
     {
     	if (respuestaAlumno == respuestaCorrecta) // Vamos a otorgar puntaje si la respuesta = correcta
     	 {
     	 	return puntajePregunta;
		  }
		else // Si no, no tenemos puntaje, tenemos 0.
		 {
		 	return 0;
		 }
	 }
   void imprimir()
    {
    	cout << "Respuesta Alumno: "<<respuestaAlumno << endl;
    	cout << "Respuesta Correcta: "<<respuestaCorrecta << endl;
    	cout << "Puntaje: "<<getPuntaje() << endl; // Por ejemplo, si aqui estuvo buena 1.5 Puntaje: 1.5
	}
 };
class Evaluacion
{
private:
	private:
		PreguntaRespuesta *lista[6];
	public:
		Evaluacion()
		 {
		  for(int i = 0; i <6; i++)
		   {
		   	lista[i] = NULL;
			   }	
		 }
		void agregarPregunta(PreguntaRespuesta *resp) 
		 {
		 	bool encontro=false;
		 	for(int i = 0; i < 6; i++)
		 	 {
		 	 	if (lista[i] == NULL)
		 	 	  {
		 	 	  	lista[i] = resp;
		 	 	  	encontro = true;
		 	 	  	cout << "Respuesta asignada"<<endl;
		 	 	  	break; // Parar el ciclo
					}
			  }
			if (encontro == false)
			 {
			 	cout << "No se puede agregar respuesta por falta de espacio"<<endl;
			 }
		 }
		bool validaPuntajes()
		 {
		  float suma = 0;
		  for (int i = 0; i < 6; i++)
		   {
		   	if (lista[i] != NULL)
		   	  {
		   	  	suma = suma + lista[i]->getPuntajePregunta();
				 }
			   }
		   if (suma == 6)
		    {
		    	return true;
				}	
		   else
		    {
		    	return false;
			}
		 }
	 float notaObtenida()
	   {
	   	float suma = 0;
	   	if (validaPuntajes() == false)
	   	 {
	   	 	return -1;
			}
		else
		 {
		  for (int i = 0; i < 6; i++)
		   {
		   	if (lista[i] != NULL)
		   	  {
		   	  	suma = suma + lista[i]->getPuntaje();
				 }
			   }
		    return suma+1;
	      }
	  }
};
int main()
 {
 	PreguntaRespuesta *pr1 = new PreguntaRespuesta(1,2,1); // 1 alumno, 2 correcta, y vale 1
	PreguntaRespuesta *pr2 = new PreguntaRespuesta(3,3,1); // Buena
	PreguntaRespuesta *pr3 = new PreguntaRespuesta(1,1,1); // Buena
 	PreguntaRespuesta *pr4 = new PreguntaRespuesta(2,2,2.5); // Buena
	Evaluacion *e = new Evaluacion(); // 
	e->agregarPregunta(pr1);
    pr1->imprimir();
	e->agregarPregunta(pr2);
    pr2->imprimir();
	e->agregarPregunta(pr3);
    pr3->imprimir(); 
	e->agregarPregunta(pr4);
    pr4->imprimir();
	cout << "Su nota es: " << e->notaObtenida() <<endl; // 1+1.5+1+2.5
 }

