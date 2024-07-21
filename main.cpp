#include <iostream>
#include <string>
#include "orden.h"
#include "funciones.h"

using namespace std;

int main() {
    const int MAX_ENTRADAS = 5;
    const int MAX_PLATOS_PRINCIPALES = 5;
    const int MAX_POSTRES = 5;
    const int MAX_BEBIDAS = 3;
    const int MAX_ORDENES = 20;

    string menuEntradas[MAX_ENTRADAS] = {
        "Foie Gras con Mermelada de Higos y Pan Brioche",
        "Tartar de Atun con Aguacate y Mango",
        "Vieiras Selladas con Pure de Coliflor y Salsa de Trufa",
        "Ensalada de Langosta con Vinagreta de Citricos",
        "Sopa de Langosta Bisque"
    };
    float preciosEntradas[MAX_ENTRADAS] = {25.0, 20.0, 30.0, 35.0, 15.0};

    string menuPlatosPrincipales[MAX_PLATOS_PRINCIPALES] = {
        "Filete Mignon con Reduccion de Vino Tinto y Esparragos Gratinados",
        "Salmon en Papillote con Verduras de Temporada",    
        "Rack de Cordero con Costra de Hierbas y Pure de Batata",
        "Pato a la Naranja con Risotto de Champinones",
        "Ravioles de Trufa Negra con Crema de Parmesano"
    };
    float preciosPlatosPrincipales[MAX_PLATOS_PRINCIPALES] = {45.0, 35.0, 50.0, 40.0, 30.0};
    
    Orden ordenes[MAX_ORDENES];
    int numOrdenes = 0;

    int opcion;
    do {
        system("cls");
        cout << "--- Restaurante ---" << endl;
        cout << "1. Mostrar carta" << endl;
        cout << "2. Agregar orden" << endl;
        cout << "3. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                system("cls");
                cout << "Entradas:" << endl;
                mostrarCarta("Entradas", menuEntradas, preciosEntradas, MAX_ENTRADAS);
                cout << "\nPlatos Principales:" << endl;
                mostrarCarta("Platos Principales", menuPlatosPrincipales, preciosPlatosPrincipales, MAX_PLATOS_PRINCIPALES);    
                system("pause");
                break;
            case 2:
                system("cls");
                cout << "Agregar orden:" << endl;
                agregarOrden("Entradas", menuEntradas, preciosEntradas, MAX_ENTRADAS, ordenes, numOrdenes);
                agregarOrden("Platos Principales", menuPlatosPrincipales, preciosPlatosPrincipales, MAX_PLATOS_PRINCIPALES, ordenes, numOrdenes);
                cout << "Orden agregada." << endl;
                system("pause");
                break;
            case 3:
                cout << "* * * * * Saliendo del programa * * * * * " << endl;
                break;
            default:
                cout << "\nOpción Incorrecta." << endl << endl;
                system("pause");
        }
    } while (opcion != 3);

    return 0;
}
