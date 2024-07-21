#include <iostream>
#include "funciones.h"
#include "orden.h"
using namespace std;

void mostrarCarta(string categoria, string platos[], float precios[], int numPlatos) {
    cout << "\n" << categoria << ":" << endl;
    for (int i = 0; i < numPlatos; i++) {
        cout << "  " << i + 1 << ") ";
        cout << platos[i] << " - Precio: $" << precios[i] << endl;
    }
}

void agregarOrden(string categoria, string menu[], float precios[], int maxPlatos, Orden ordenes[], int &numOrdenes, float &total) {
    mostrarCarta(categoria, menu, precios, maxPlatos);
    int eleccion;
    cout << "Elija el " << categoria << " que desea ordenar: ";
    cin >> eleccion;
    if ( 1 <= eleccion && eleccion <= maxPlatos) {
        ordenes[numOrdenes].nombre = menu[eleccion - 1];
        ordenes[numOrdenes].precio = precios[eleccion - 1];
        ordenes[numOrdenes].categoria = categoria;
        numOrdenes++;
        total += precios[eleccion - 1];
    } else {
        cout << "Opcion Incorrecta." << endl;
    }
}
