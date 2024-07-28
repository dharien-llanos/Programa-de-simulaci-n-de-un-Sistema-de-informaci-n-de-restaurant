#include <iostream>
#include <string>
#include "orden.h"
#include "funciones.h"
using namespace std;

int main() {
    string nombreCliente;
    cout << "Bienvenido al restaurante!" << endl;
    cout << "Por favor, ingrese su nombre: ";
    getline(cin, nombreCliente);
    int diaDeLaSemana = detectarDia();

    switch (diaDeLaSemana) {
        case 1:
            dia1(nombreCliente);
            break;
            case 2:
            dia2(nombreCliente);
            break;
            case 3:
            dia3(nombreCliente);
            break;
        default:
            cout << "No hay un menu definido para hoy." << endl;
    }
    return 0;
}
