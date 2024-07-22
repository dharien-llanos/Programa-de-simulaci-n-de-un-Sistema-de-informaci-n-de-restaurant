#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <string>
#include "orden.h"
using namespace std;

void mostrarCarta(const string& categoria, const string menu[], const float precios[], int tamano);
void agregarOrden(const string& categoria, const string menu[], const float precios[], int tamano, Orden ordenes[], int& numOrdenes);
void mostrarOrdenes(Orden ordenes[], int numOrdenes);
void borrarOrden(Orden ordenes[], int &numOrdenes);

#endif 
