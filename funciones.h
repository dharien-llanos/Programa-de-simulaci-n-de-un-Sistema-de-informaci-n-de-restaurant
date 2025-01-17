#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <string>
#include "orden.h"
#include <windows.h> 
using namespace std;

int detectarDia();
void mostrarCarta(const string& categoria, const string menu[], const float precios[], int tamano);
void agregarOrden(const string& categoria, const string menu[], const float precios[], int tamano, Orden ordenes[], int& numOrdenes);
void mostrarOrdenes(Orden ordenes[], int numOrdenes);
void borrarOrden(Orden ordenes[], int& numOrdenes, int indice);
void dia1(const string& nombreCliente);
void dia2(const string& nombreCliente);
void dia3(const string& nombreCliente);
void dia4(const string& nombreCliente);
void dia5(const string& nombreCliente);
void dia6(const string& nombreCliente);
void dia7(const string& nombreCliente);
void generarBoleta(const string& nombreCliente, Orden ordenes[], int numOrdenes);
void limpiarPantalla();
void menu1();
void menu2();
void linea_horizontal();
void mostrarMenuPrincipal();
void cambiarColor(int color);
#endif 
