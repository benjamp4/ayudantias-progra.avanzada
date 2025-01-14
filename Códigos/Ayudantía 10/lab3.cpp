#include <iostream>
#include <vector>
using namespace std;

class Persona
{
    protected:
        string nombre, region;
        int edad;
    public:
        Persona(string nombre, string region, int edad)
        {
            this->nombre = nombre;
            this->region = region;
            this->edad = edad;
        }
        
        string getNombre()
        {
            return nombre;
        }
        
        string getRegion()
        {
            return region;
        }
        
        int getEdad()
        {
            return edad;
        }
        
        void imprimir()
        {
            cout<<getNombre()<<endl;
            cout<<getRegion()<<endl;
            cout<<getEdad()<<endl;
        }
};

class Docente : public Persona
{
    private:
        string asignatura;
        int anosDeExp;
        
    public:
        Docente(string nombre, string region, int edad, string asignatura, int anosDeExp) : Persona (nombre, region, edad)
        {
            this->asignatura = asignatura;
            this->anosDeExp = anosDeExp;
        }
        
        string getAsignatura()
        {
            return asignatura;
        }
        
        int getAnosDeExp()
        {
            return anosDeExp;
        }
        
        void virtual imprimir()
        {
            cout<<getAsignatura()<<endl;
            cout<<getAnosDeExp()<<endl;
        }
};

class Postulaciones
{
    private:
        vector<Docente *>postulantes;
        vector<Docente *>aceptados;
        
    public:
        void postular(Docente *d)
        {
            postulantes.push_back(d);
        }
        
        bool cantidadMinimaPostulantes()
        {
            if (postulantes.size() >= 100)
            {
                return true;
            }
            return false;
        }
        
        int promedioEdad()
        {
            int sumaEdades = 0;
            for(int i = 0; i<postulantes.size() ; i++)
            {
                sumaEdades += postulantes[i]->getEdad();
            }
            return sumaEdades/postulantes.size();
        }
        
        void validarPostulaciones()
        {
            if (cantidadMinimaPostulantes() == false)
            {
                cout<<"No se llego a la cantidad necesaria"<<endl;
                return;
            }
            for(int i = 0; i<postulantes.size() ; i++)
            {
                if (postulantes[i]->getRegion() == "Santiago")
                {
                    if ((postulantes[i]->getAnosDeExp() > 10) or postulantes[i]->getAsignatura() == "Calculo III")
                    {
                        aceptados.push_back(postulantes[i]);
                    }
                }
            }
        }
        
        void imprimir()
        {
            for(int i = 0; i<postulantes.size(); i++)
            {
                postulantes[i]->imprimir();
            }
        }
};