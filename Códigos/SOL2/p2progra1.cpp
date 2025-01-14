// Cada vez que un vendedor realiza una venta quiere saber qué comisión ganó por la misma de acuerdo con la siguiente regla:
	// Si la venta es menor o igual 1000 no recibe nada
	// Si la venta es mayor que 1000 pero inferior a 15000 recibe $200
	// Si la venta es mayor o igual a 15000 y menor a $1000000 recibe $500
	// Si le venta es mayor o igual a 1000000 recibe el 0,5% de la venta

     // 1. Programe la función int comisión(int monto), que recibe el monto de la venta y devuelve la comisión

     // 2. Programe la función int totalcomision(int ventas[31]), que recibe como parámetro un arreglo de enteros de 
     // tamaño 31 (el arreglo ya contiene datos), que representa las ventas del mes y devuelve el monto total a 
     // recibir por concepto de comisiones de ventas.

#include <iostream>
using namespace std;

int comision(int monto) {
    if (monto <= 1000) {
        return 0; // no tiene comisión
    } else if (monto > 1000 && monto < 15000) {
        return 200; // comisión de 200
    } else if (monto >= 15000 && monto < 1000000) {
        return 500; // comisión de 500
    } else if (monto >= 1000000) {
        return monto * 0.005; // 0.5% de la venta | ojo! * 0.5 -> 50%, * 0.05 -> 5%, *0.005 -> 0.5%
    }
    return 0; 
}

int totalcomision(int ventas[31]) {
    int total = 0; // acumulador...
    for (int i = 0; i < 31; i++) {
        total += comision(ventas[i]); // sumar la comisión de cada venta
    }
    return total; 
}
