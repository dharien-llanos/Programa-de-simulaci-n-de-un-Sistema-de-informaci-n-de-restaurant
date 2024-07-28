#include "funciones.h"
#include<iostream>
#include<ctime>
using namespace std;


int detectarDia() {
    time_t tiempoActual=time(0);
    tm* tiempoLocal = localtime(&tiempoActual);

    const char* diasDeLaSemana[]={"Domingo", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado"};
    const char* mesesDelAnio[]={"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"};

    cout <<"Hoy es "<< diasDeLaSemana[tiempoLocal->tm_wday]<<", " 
         <<tiempoLocal->tm_mday<<" de " 
         <<mesesDelAnio[tiempoLocal->tm_mon]<<" de " 
         <<(tiempoLocal->tm_year + 1900)<<endl;

    int diaDeLaSemana=(tiempoLocal->tm_wday == 0) ? 7 : tiempoLocal->tm_wday;

    cout<<"El numero del dia de la semana es:"<<diaDeLaSemana<<endl;
    
    return diaDeLaSemana;
}






void mostrarCarta(const string& categoria, const string menu[], const float precios[], int tamano) {
    cout<<"\n"<<categoria<<":"<<endl;
    for (int i=0;i<tamano;i++) {
        cout<<"  "<<i+1<<") "<<menu[i]<<" - Precio: $"<<precios[i]<<endl;
    }
}

void agregarOrden(const string& categoria, const string menu[],const float precios[], int tamano, Orden ordenes[], int& numOrdenes) {
    mostrarCarta(categoria,menu,precios,tamano);
    int eleccion;
    cout<<"Elija el "<<categoria<<"que desea ordenar: ";
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

void mostrarOrdenes(Orden ordenes[],int numOrdenes) {
	float suma=0;
	float descuento;
    if (numOrdenes==0) {
        cout<<"No ha seleccionado ningun plato"<<endl;
    } else {
        cout<<"Platos seleccionados:"<<endl;
        for (int i=0; i<numOrdenes; i++) {
            cout<<i + 1<<" ) "<<ordenes[i].nombre<<" ("<<ordenes[i].categoria<<"): $"<<ordenes[i].precio<<endl;
            suma+=ordenes[i].precio;
        }
        cout<<"Total de consumo: S/"<<suma<<endl;
        if(numOrdenes > 10) {
            cout << "Descuento 20% al total de consumo"<<endl;
            descuento=suma*0.20;
        } 
		else if (numOrdenes>5) {
            cout<<"Descuento 10% al total de consumo"<<endl;
            descuento=suma*0.10;
        } 
		else {
            cout<<"Descuento 5% al total de consumo"<<endl;
            descuento=suma*0.05;
        }
        int totalfinal=suma-descuento; 
         cout<<"Total con descuento del consumo: $" << totalfinal<<endl;
         cout<<endl;
         cout<<"De las manos del chef, nacen obras maestras que conquistan el alma "<<endl;
    }
}

void borrarOrden(Orden ordenes[],int &numOrdenes,int indice) {
    for (int i=indice;i<numOrdenes-1;i++) {
        ordenes[i]=ordenes[i+1];
    }
    numOrdenes--;
    cout<<"Orden borrada."<<endl;
}


void dia1() {
    const int MAX_ENTRADAS=3;
    const int MAX_PLATOS_PRINCIPALES=4;
    const int MAX_ORDENES = 20;

    string menuEntradas[MAX_ENTRADAS]={
        "casuela de res",
        "caldo de pollo",
        "causa de pollo"
    };
    float preciosEntradas[MAX_ENTRADAS]={25.0, 20.0, 30.0};

    string menuPlatosPrincipales[MAX_PLATOS_PRINCIPALES] ={
        "arroz con pollo",
        "lomo saltado",    
        "picante a la tacneÃ±a",
        "chuleta frita"
    };
    float preciosPlatosPrincipales[MAX_PLATOS_PRINCIPALES]={45.0, 35.0, 50.0, 40.0};
    
    Orden ordenes[MAX_ORDENES];
    int numOrdenes=0;

    int opcion;
    do {
        cout<<"---- Restaurante ----" << endl;
        cout<<"1. Mostrar carta"<<endl;
        cout<<"2. Agregar orden"<<endl;
        cout<<"3. Mostrar orden"<<endl;
        cout<<"4. Borrar orden"<<endl;
        cout<<"5. Salir"<<endl;
        cout<<"Ingrese una opcion: ";
        cin>>opcion;

        switch (opcion) 
		{
            case 1:
                cout<<"Entradas:"<<endl;
                mostrarCarta("Entradas", menuEntradas, preciosEntradas, MAX_ENTRADAS);
                cout<<"\n Platos Principales:"<<endl;
                mostrarCarta("Platos Principales",menuPlatosPrincipales,preciosPlatosPrincipales,MAX_PLATOS_PRINCIPALES);
                break;
            case 2:
                int categoria;
                do {
                    cout<<"Seleccione la categoria:" << endl;
                    cout<<"1. Entradas" << endl;
                    cout<<"2. Platos Principales" << endl;
                    cout<<"3. Terminar seleccion" << endl;
                    cout<<"Ingrese la categoria: ";
                    cin>>categoria;
                    if(categoria==1) {
                        agregarOrden("Entradas",menuEntradas,preciosEntradas,MAX_ENTRADAS,ordenes,numOrdenes);
                    } 
					else if (categoria==2) {
                        agregarOrden("Platos Principales",menuPlatosPrincipales,preciosPlatosPrincipales,MAX_PLATOS_PRINCIPALES,ordenes,numOrdenes);
                    }
                } while (categoria!=3);
                break;
            case 3:
                mostrarOrdenes(ordenes,numOrdenes);
                break;
            case 4:
                if (numOrdenes>0) {
                    int indice;
                    cout<<"Ingrese el numero de la orden a borrar (1-" << numOrdenes << "): ";
                    cin>>indice;
                    if (indice>=1 && indice<=numOrdenes) {
                        borrarOrden(ordenes, numOrdenes,indice-1);
                    } else {
                        cout<<"Numero de orden invalido."<<endl;
                    }
                } else {
                    cout<<"No hay ordenes para borrar."<<endl;
                }
                break;    
            case 5:
                cout<<"* * * * * * Saliendo del programa * * * * * *"<<endl;
                break;
            default:
                cout<<"\n opcion Incorrecta."<<endl;
        }
    } while (opcion!=5);
}