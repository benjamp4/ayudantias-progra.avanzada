#include <iostream>
#include <vector>
using namespace std;
class Cliente{
private:
    string rut, nombre;
    vector<float> productos;
public:
    Cliente(string rut, string nombre){
       this->rut = rut;
       this->nombre = nombre;
    }
    void ingresarVectorProductos(vector<float> prod){
        int n = prod.size();
        for (int i = 0; i < n; i++){
            productos.push_back(prod.at(i));
        }
    }
    void ingresarProducto(float prod){
        productos.push_back(prod);
    }

    void lista(){
        int n = productos.size();
        for (int i = 0; i < n; ++i) {
            cout<<"Precio Producto "<<i+1<<": "<<productos[i]<<endl;
        }
    }
    void mostrarInformacion() {
        cout << "Información del Cliente:" << endl;
        cout << "RUT: " << rut << endl;
        cout << "Nombre: " << nombre << endl;
    }

    void precioTotal() {
    float total = 0;
    for (int i = 0; i < productos.size(); i++) {
        total = total + productos[i];
    }
    cout << "El precio total de productos es: " << total << endl;
    }
};
int main(){
    Cliente *c =  new Cliente("21420690","Tyler");
    vector<float> productos = {120,320,900,1000};
    c->mostrarInformacion();
    c->ingresarProducto(7);
    c->ingresarVectorProductos(productos);
    c->lista();
    c->precioTotal();
    return 0;
}
