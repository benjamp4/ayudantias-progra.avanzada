#include <iostream>
#include <vector>
using namespace std;
class Empresa{ // Tenemos empresas que van a tener herencias de tiendas
protected:
    string duenio, rut; // Cada empresa tiene un rut y un dueño
    int saldoT; // Y un saldo total
public:
    Empresa(string duenio,string rut){
        this->duenio = duenio;
        this->rut = rut;
        this->saldoT = 0;
    }
    void info(){ // Info imprime información de la empresa
        cout<<"Nombre Duenio: " << duenio << endl; // getDuenio
        cout <<"Rut Empresa: "<< rut << endl; //getRut
        cout << "Saldo: "<< saldoT <<endl; // getSaldo
    }
    void acumularSaldo(int ingreso){ // Acumular saldo recibe los ingresos y los suma al saldo total   
        this->saldoT += ingreso;
    }
};
class TiendaRopa : public Empresa{ // Tienda de ropa hereda de empresa
protected:
    vector<float> fardos; // Tienda de ropa tiene un vector de fardos
public:

    TiendaRopa(string duenio, string rut):Empresa(duenio,rut){ // Tienda de ropa hereda de empresa

        for (int i = 0; i < 4; ++i) { // se agregan 4 fardos inicialmente...

            fardos.push_back((i+1)*10); // Se agregan fardos de 10, 20, 30, 40 kg respectivamente.

        }
    }
    float exportarFardo(){ // Elimina ultimo fardo
        float ultimo = fardos.back(); // Selecciona ultimo fardo
        fardos.pop_back(); // Elimina el ultimo fardo
        return ultimo; // Retorna el ultimo fardo
    }
    bool verificarFardos(){ // Verifican si quedan fardos

         /* return !fardos.empty(); // Esto retorna true si los fardos no están vacíos */ // (Esto es una forma mucho más corta de verificar el true o false)
          if(fardos.empty()){ // Aquí pasa lo mismo, si fardos está vacío retorna falso
           return false;
           } else{
           return true; // Si no está vacío es true.
           }
         
    }
    void ver(){ // Ver fardos
        int n = fardos.size(); // n es el tamaño de los fardos
        for (int i = 0; i < n; ++i) { // Recorre el tamaño de todos los fardos
            cout<<"Fardo N° "<<i+1<<": "<<fardos.at(i)<<endl;
        }
    }

};
class Sucursal1: public TiendaRopa{ // Sucursal hereda de tienda de ropa
public:

    Sucursal1(string duenio, string rut): TiendaRopa(duenio, rut){}

    void venta(int cantidad){ // Recibe una cantidad de kilos a vender (Kilo a 1000)
        int kilos;
        while(this->verificarFardos() && cantidad > 0){ // Verifica si quedan fardos
            cantidad--; // Resta a la cantidad pq se vende un fardo
            cout<<"Fardo vendido!"<<endl;
            kilos = this->exportarFardo(); // Como se vendio se elimina 
            this->acumularSaldo(kilos*1000); // Se acumula al saldo a kilos * 1000
        }

    }
};
int main(){
    Sucursal1 *s = new Sucursal1("Miguel", "12345678-7");
    s->info();
    s->venta(4);
    s->info();
    return 0;
}