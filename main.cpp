#include <iostream>
#include <string>
#include "orden.h"
#include "funciones.h"
using namespace std;

int main() {
    const int MAX_ENTRADAS=3;
    const int MAX_PLATOS_PRINCIPALES=4;
    const int MAX_POSTRES=5;
    const int MAX_BEBIDAS=3;
    const int MAX_ORDENES=20;

    string menuEntradas[MAX_ENTRADAS]={
        "casuela de res",
        "caldo de pollo",
        "causa de pollo"
       
    };
    float preciosEntradas[MAX_ENTRADAS]={25.0, 20.0, 30.0};

    string menuPlatosPrincipales[MAX_PLATOS_PRINCIPALES]={
        "arros con pollo",
        "lomo saltado",    
        "picante a la tacneia",
        "chuleta frita"
       
    };
    float preciosPlatosPrincipales[MAX_PLATOS_PRINCIPALES]={45.0, 35.0, 50.0, 40.0};
    
    Orden ordenes[MAX_ORDENES];
    int numOrdenes=0;

    int opcion;
    do {
        cout<<"---- Restaurante ----"<<endl;
        cout<<"1. Mostrar carta"<<endl;
        cout<<"2. Agregar orden"<<endl;
        cout<<"3. Mostrar orden"<<endl;
        cout<<"4. Borrar orden"<<endl;
        cout<<"5. Salir"<<endl;
        cin>>opcion;

        switch (opcion) {
            case 1:
                cout<<"Entradas:"<<endl;
                mostrarCarta("Entradas", menuEntradas, preciosEntradas, MAX_ENTRADAS);
                cout<<"\nPlatos Principales:"<<endl;
                mostrarCarta("Platos Principales", menuPlatosPrincipales, preciosPlatosPrincipales, MAX_PLATOS_PRINCIPALES);
                break;
            case 2:
                int categoria;
                do {
                    cout<<"Seleccione la categoria:"<<endl;
                    cout<<"1. Entradas"<<endl;
                    cout<<"2. Platos Principales"<<endl;
                    cout<<"3. Terminar seleccion"<<endl;
                    cout<<"Ingrese la categoria: ";
                    cin>>categoria;
                    if (categoria==1) {
                        agregarOrden("Entradas", menuEntradas, preciosEntradas, MAX_ENTRADAS, ordenes, numOrdenes);
                    } else if (categoria==2) {
                        agregarOrden("Platos Principales", menuPlatosPrincipales, preciosPlatosPrincipales, MAX_PLATOS_PRINCIPALES, ordenes, numOrdenes);
                    }
                } while(categoria!=3);
                break;
            case 3:
                mostrarOrdenes(ordenes, numOrdenes);
                break;
            case 4:
                borrarOrden(ordenes, numOrdenes);
                break;     
            case 5:
                cout<<"* * * * * * Saliendo del programa * * * * * *"<<endl;
                break;
            default:
                cout<<"\nOpcion Incorrecta."<<endl;
        }
    } while (opcion!=5);

    return 0;
}
