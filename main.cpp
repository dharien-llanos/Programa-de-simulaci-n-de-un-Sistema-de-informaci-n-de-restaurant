#include <iostream>
#include <string>
#include "orden.h"
#include "funciones.h"
using namespace std;

int main() {
    int diaDeLaSemana=detectarDia();

        switch (diaDeLaSemana) {
        case 1:
            dia1();
            break;
        default:
            cout<<"No hay un menu definido para hoy "<<endl;
    }
    return 0;
}