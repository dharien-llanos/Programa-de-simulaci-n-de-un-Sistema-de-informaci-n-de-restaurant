#include "funciones.h"
#include <iostream>

using namespace std;

void mostrarCarta(const string& categoria, const string menu[], const float precios[], int tamano) {
    cout << "\n" << categoria << ":" << endl;
    for (int i=0;i<tamano;i++) {
        cout<<"  "<<i + 1<<") "<<menu[i]<<" - Precio: $"<<precios[i]<< endl;
    }
}

void agregarOrden(const string& categoria, const string menu[],const float precios[], int tamano, Orden ordenes[], int& numOrdenes) {
    mostrarCarta(categoria,menu,precios,tamano);
    int eleccion;
    cout << "Elija el "<< categoria <<" que desea ordenar: ";
    cin>>eleccion;
    if (eleccion>=1 && eleccion<=tamano) {
        ordenes[numOrdenes].nombre=menu[eleccion - 1];
        ordenes[numOrdenes].precio=precios[eleccion - 1];
        ordenes[numOrdenes].categoria=categoria;
        numOrdenes++;
    } else {
        cout <<"Opción Incorrecta."<<endl;
    }
}
