#include "funciones.h"
#include <iostream>
using namespace std;

void mostrarCarta(const string& categoria, const string menu[], const float precios[], int tamano) {
    cout<<"\n"<<categoria<<":"<<endl;
    for (int i=0;i<tamano;i++) {
        cout<<"  "<<i+1<<") "<<menu[i]<<" - Precio: $"<<precios[i]<<endl;
    }
}

void agregarOrden(const string& categoria, const string menu[],const float precios[], int tamano, Orden ordenes[], int& numOrdenes) {
    mostrarCarta(categoria,menu,precios,tamano);
    int eleccion;
    cout<<"Elija el "<<categoria<<" que desea ordenar: ";
    cin>>eleccion;
    if (eleccion>=1&&eleccion<=tamano) {
        ordenes[numOrdenes].nombre=menu[eleccion-1];
        ordenes[numOrdenes].precio=precios[eleccion-1];
        ordenes[numOrdenes].categoria=categoria;
        numOrdenes++;
    } else {
        cout<<"Opcion Incorrecta."<<endl;
    }
}

void mostrarOrdenes(Orden ordenes[], int numOrdenes) {
    if (numOrdenes==0) {
        cout<<"No ha seleccionado ningun plato"<<endl;
    } else {
        cout<<"Platos seleccionados:"<<endl;
        for (int i=0;i<numOrdenes;i++) {
            cout<<i+1<<") "<<ordenes[i].nombre<<" ("<<ordenes[i].categoria<<"): $"<<ordenes[i].precio<<endl;
        }
    }
}

void borrarOrden(Orden ordenes[], int &numOrdenes) {
    if (numOrdenes == 0) {
        cout<<"No hay órdenes para borrar."<<endl;
        return;
    }
    
    int indice;
    cout<<"Ingrese el índice de la orden que desea borrar (1-"<<numOrdenes<<"): ";
    cin>>indice;

    if (indice<1||indice>numOrdenes) {
        cout<<"Índice inválido."<<endl;
        return;
    }

    for (int i=indice-1; i<numOrdenes-1; ++i) {
        ordenes[i]=ordenes[i + 1];
    }

    --numOrdenes;
    cout<<"Orden borrada exitosamente."<<endl;
}
