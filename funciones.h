#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <string>
#include "orden.h"
using namespace std;

void mostrarCarta(string categoria, string platos[], float precios[], int numPlatos);
void agregarOrden(string categoria, string menu[], float precios[], int maxPlatos, Orden ordenes[], int &numOrdenes, float &total);

#endif