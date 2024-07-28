#include "funciones.h"
#include "orden.h"
#include <iostream>
#include <ctime>
using namespace std;
void limpiarPantalla() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}


int detectarDia() {
    time_t tiempoActual=time(0);
    tm* tiempoLocal = localtime(&tiempoActual);

    const char* diasDeLaSemana[]={"Domingo", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado"};
    const char* mesesDelAnio[]={"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"};

    cout<<"Hoy es "<<diasDeLaSemana[tiempoLocal->tm_wday] << ", " 
         <<tiempoLocal->tm_mday<<" de " 
         <<mesesDelAnio[tiempoLocal->tm_mon]<<" de " 
         << (tiempoLocal->tm_year + 1900)<<endl;

    int diaDeLaSemana=(tiempoLocal->tm_wday==0) ? 7 : tiempoLocal->tm_wday;

    cout<<"El numero del dia de la semana es: "<<diaDeLaSemana<<endl;

    return diaDeLaSemana;
}

void mostrarCarta(const string& categoria, const string menu[], const float precios[], int tamano) {
    cout<<"\n"<<categoria<<":"<<endl;
    for(int i=0;i<tamano;i++) {
        cout <<"  "<<i+1<< ") "<<menu[i]<<"-Precio: S/"<<precios[i]<<endl;
    }
    cout<<endl;
}

void agregarOrden(const string& categoria, const string menu[], const float precios[], int tamano, Orden ordenes[], int& numOrdenes) {
    mostrarCarta(categoria, menu, precios, tamano);
    int eleccion;
    cout<<"Elija el "<<categoria<<" que desea ordenar: ";
    cin>>eleccion;
    if(eleccion>=1 && eleccion<=tamano) {
        ordenes[numOrdenes].nombre=menu[eleccion - 1];
        ordenes[numOrdenes].precio=precios[eleccion - 1];
        ordenes[numOrdenes].categoria=categoria;
        numOrdenes++;
    } else 
	{
        cout<<"Opcion Incorrecta"<<endl;
    }
}

void mostrarOrdenes(Orden ordenes[], int numOrdenes) {
    float suma=0;
    float descuento;
    if (numOrdenes==0) {
        cout<<"No ha seleccionado ningun plato"<<endl;
    } else {
        cout<<"Platos seleccionados:" << endl;
        for (int i=0;i<numOrdenes;i++) {
            cout<<i+1<<" ) "<<ordenes[i].nombre<<" ("<<ordenes[i].categoria<<"): S/"<<ordenes[i].precio<<endl;
            suma+=ordenes[i].precio;
        }
        cout<<"Total de consumo: S/"<<suma<<endl;
    }
}

void borrarOrden(Orden ordenes[], int& numOrdenes, int indice) {
    if (numOrdenes > 0) {
        cout << "Platos:" << endl;
        for (int i = 0; i < numOrdenes; i++) {
            cout << i + 1 << ") " << ordenes[i].nombre << " (" << ordenes[i].categoria << "): S/" << ordenes[i].precio << endl;
        }
        cout << "Ingrese el numero de la orden a borrar (1-" << numOrdenes << ") : ";
        cin >> indice;
        if (indice >= 1 && indice <= numOrdenes) {
            for (int i = indice - 1; i < numOrdenes - 1; i++) {
                ordenes[i] = ordenes[i + 1];
            }
            numOrdenes--;
            cout << "Orden borrada" << endl;
        } else {
            cout << "Numero de orden invalido." << endl;
        }
    } else {
        cout << "No hay ordenes para borrar." << endl;
    }
    cout << "\nPresione Enter para continuar...";
    cin.ignore();
    cin.get();
}

void generarBoleta(const string& nombreCliente, Orden ordenes[], int numOrdenes) {
    float suma=0;
    float descuento=0;
    cout << "\n---- BOLETA ----"<<endl;
    cout << "Nombre del Cliente: "<<nombreCliente<<endl;
    if (numOrdenes == 0) {
        cout << "No ha seleccionado ningun plato"<<endl;
    } else {
        cout << "Platos seleccionados:"<<endl;
        for (int i = 0; i < numOrdenes;i++) {
            cout<<i + 1<<") "<<ordenes[i].nombre <<" ("<<ordenes[i].categoria<<"): S/"<<ordenes[i].precio<<endl;
            suma += ordenes[i].precio;
        }
        cout<<"Total de consumo: S/"<<suma<<endl;
        if (numOrdenes > 10) {
            cout<<"Descuento 20% al total de consumo"<<endl;
            descuento = suma * 0.20;
        } else if (numOrdenes > 5) {
            cout<<"Descuento 10% al total de consumo"<<endl;
            descuento=suma * 0.10;
        } else {
            cout<<"Descuento 5% al total de consumo."<<endl;
            descuento=suma * 0.05;
        }
        float totalFinal=suma-descuento;
        cout<<"Total con descuento del consumo: S/"<<totalFinal<<endl;
    }
    cout<<"-----------------------------"<<endl;
    cout<<"Gracias por su visita, "<<nombreCliente<<"!"<<endl;
    cout<<"De las manos del chef, nacen obras maestras que conquistan el alma."<<endl;
    cout<<"-----------------------------"<<endl;
}

void dia1(const string& nombreCliente) {
    const int MAX_ENTRADAS = 3;
    const int MAX_PLATOS_PRINCIPALES = 4;
    const int MAX_ORDENES = 20;
     const int MAX_POSTRES = 2;

    string menuEntradas[MAX_ENTRADAS] = {
        "Casuela de res",
        "Caldo de pollo",
        "Causa de pollo"
    };
    float preciosEntradas[MAX_ENTRADAS] = {25.0, 20.0, 30.0};

    string menuPlatosPrincipales[MAX_PLATOS_PRINCIPALES] = {
        "Arroz con pollo",
        "Lomo saltado",    
        "Picante a la tacnenia",
        "Chuleta frita"
    };
    float preciosPlatosPrincipales[MAX_PLATOS_PRINCIPALES] = {45.0, 35.0, 50.0, 40.0};
      string menuPostres[MAX_POSTRES] = {
        "Gelatina",
        "Tarta de pera"
    };
    float preciosPostres[MAX_POSTRES] = {12.0, 15.0};
    
    Orden ordenes[MAX_ORDENES];
    int numOrdenes = 0;

    int opcion;
    do {
    	 limpiarPantalla();
        cout << "---- Restaurante ----" << endl;
        cout << "1. Mostrar carta" << endl;
        cout << "2. Agregar orden" << endl;
        cout << "3. Mostrar orden" << endl;
        cout << "4. Borrar orden" << endl;
        cout << "5. Generar boleta y salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
				limpiarPantalla();
                
                mostrarCarta("Entradas", menuEntradas, preciosEntradas, MAX_ENTRADAS);
               
                mostrarCarta("Platos Principales", menuPlatosPrincipales, preciosPlatosPrincipales, MAX_PLATOS_PRINCIPALES);
               
                mostrarCarta("Postres", menuPostres, preciosPostres, MAX_POSTRES);
                cout<<"\nPresione Enter para continuar...";
                cin.ignore();
                cin.get();
                break;
            case 2:
            	limpiarPantalla();
                int categoria;
                do {
                    cout<<"Seleccione la categoria:"<<endl;
                    cout<<"1. Entradas" << endl;
                    cout<<"2. Platos Principales"<<endl;
                     cout<<"3. Postres"<<endl;
                    cout<<"4. Terminar seleccion"<<endl;
                    cout<<"Ingrese la categoria: ";
                    cin >> categoria;
                    if (categoria==1) {
                        agregarOrden("Entradas", menuEntradas, preciosEntradas, MAX_ENTRADAS, ordenes, numOrdenes);
                    } else if (categoria==2) {
                        agregarOrden("Platos Principales", menuPlatosPrincipales, preciosPlatosPrincipales, MAX_PLATOS_PRINCIPALES, ordenes, numOrdenes);
                    }
                    else if (categoria==3) {
                        agregarOrden("Postres", menuPostres, preciosPostres, MAX_POSTRES, ordenes, numOrdenes);
                    }
                } while (categoria!=4);
                break;
            case 3:
                limpiarPantalla(); 
                mostrarOrdenes(ordenes, numOrdenes);
                cout<<"\nPresione Enter para continuar...";
                cin.ignore();
                cin.get();
                break;
              
            case 4:
    limpiarPantalla();
    if (numOrdenes > 0) {
        int indice;
        cout<<"ingrese 1 si desea eliminar un plato  : ";
        cin>>indice;
        borrarOrden(ordenes, numOrdenes, indice - 1);
    } else {
        cout << "No hay ordenes para borrar." << endl;
    }
    cout << "\nPresione Enter para continuar...";
    cin.ignore();
    cin.get();
    break;
            case 5:
            	limpiarPantalla();
                generarBoleta(nombreCliente,ordenes,numOrdenes);
                opcion=6;
                break;
            default:
                cout<<"Opcion Incorrecta." << endl;
                cout<<"\nPresione Enter para continuar...";
                cin.ignore();
                cin.get();
        }
    } while (opcion!=6);
}


void dia2(const string& nombreCliente) {
    const int MAX_ENTRADAS = 3;
    const int MAX_PLATOS_PRINCIPALES = 4;
    const int MAX_POSTRES = 2;
    const int MAX_ORDENES = 20;

    string menuEntradas[MAX_ENTRADAS] = {
        "Ensalada de atun",
        "Sopa de vegetales",
        "Tiradito de pescado"
    };
    float preciosEntradas[MAX_ENTRADAS] = {22.0, 18.0, 28.0};

    string menuPlatosPrincipales[MAX_PLATOS_PRINCIPALES] = {
        "Pescado a la plancha",
        "Pollo a la brasa",    
        "Pasta alfredo",
        "Ensalada cesar"
    };
    float preciosPlatosPrincipales[MAX_PLATOS_PRINCIPALES] = {38.0, 36.0, 32.0, 28.0};

    string menuPostres[MAX_POSTRES] = {
        "Flan",
        "Tarta de manzana"
    };
    float preciosPostres[MAX_POSTRES] = {12.0, 15.0};

    Orden ordenes[MAX_ORDENES];
    int numOrdenes = 0;
    int opcion;
    do {
    	 limpiarPantalla();
        cout << "---- Restaurante ----" << endl;
        cout << "1. Mostrar carta" << endl;
        cout << "2. Agregar orden" << endl;
        cout << "3. Mostrar orden" << endl;
        cout << "4. Borrar orden" << endl;
        cout << "5. Generar boleta y salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
				limpiarPantalla();
             
                mostrarCarta("Entradas", menuEntradas, preciosEntradas, MAX_ENTRADAS);
              
                mostrarCarta("Platos Principales", menuPlatosPrincipales, preciosPlatosPrincipales, MAX_PLATOS_PRINCIPALES);
    
                mostrarCarta("Postres", menuPostres, preciosPostres, MAX_POSTRES);
                cout<<"\nPresione Enter para continuar...";
                cin.ignore();
                cin.get();
                break;
            case 2:
            	limpiarPantalla();
                int categoria;
                do {
                    cout<<"Seleccione la categoria:"<<endl;
                    cout<<"1. Entradas" << endl;
                    cout<<"2. Platos Principales"<<endl;
                     cout<<"3. Postres"<<endl;
                    cout<<"4. Terminar seleccion"<<endl;
                    cout<<"Ingrese la categoria: ";
                    cin >> categoria;
                    if (categoria==1) {
                        agregarOrden("Entradas", menuEntradas, preciosEntradas, MAX_ENTRADAS, ordenes, numOrdenes);
                    } else if (categoria==2) {
                        agregarOrden("Platos Principales", menuPlatosPrincipales, preciosPlatosPrincipales, MAX_PLATOS_PRINCIPALES, ordenes, numOrdenes);
                    }
                    else if (categoria==3) {
                        agregarOrden("Postres", menuPostres, preciosPostres, MAX_POSTRES, ordenes, numOrdenes);
                    }
                } while (categoria!=4);
                break;
            case 3:
                limpiarPantalla(); 
                mostrarOrdenes(ordenes, numOrdenes);
                cout<<"\nPresione Enter para continuar...";
                cin.ignore();
                cin.get();
                break;
               
            case 4:
    limpiarPantalla();
    if (numOrdenes > 0) {
        int indice;
        cout<<"ingrese 1 si desea eliminar un plato  : ";
        cin>>indice;
        borrarOrden(ordenes, numOrdenes, indice - 1);
    } else {
        cout << "No hay ordenes para borrar." << endl;
    }
    cout << "\nPresione Enter para continuar...";
    cin.ignore();
    cin.get();
    break;
            case 5:
            	limpiarPantalla();
                generarBoleta(nombreCliente,ordenes,numOrdenes);
                opcion=6;
                break;
            default:
                cout<<"Opcion Incorrecta." << endl;
                cout<<"\nPresione Enter para continuar...";
                cin.ignore();
                cin.get();
        }
    } while (opcion!=6);
}

void dia3(const string& nombreCliente) {
    const int MAX_ENTRADAS = 3;
    const int MAX_PLATOS_PRINCIPALES = 4;
    const int MAX_POSTRES = 2;
    const int MAX_ORDENES = 20;

    string menuEntradas[MAX_ENTRADAS] = {
        "Ensalada de Lentejas",
        "Palta rellena",
        "Choclo revuelto con Huevos"
    };
    float preciosEntradas[MAX_ENTRADAS] = {25.0, 22.0, 30.0};

    string menuPlatosPrincipales[MAX_PLATOS_PRINCIPALES] = {
        "Chuletas de Cerdo Al Horno  ",
        "Arroz Chaufa De Pescado",    
        "Bistec Encebollado",
        "Ceviche de champiñones"
    };
    float preciosPlatosPrincipales[MAX_PLATOS_PRINCIPALES] = {40.0, 36.0, 34.0, 23.0};

    string menuPostres[MAX_POSTRES] = {
        "Tarta de frambuesa y queso crema",
        "Tarta de chocolate"
    };
    float preciosPostres[MAX_POSTRES] = {15.0, 10.0};

    Orden ordenes[MAX_ORDENES];
    int numOrdenes = 0;
   int opcion;
    do {
    	 limpiarPantalla();
        cout << "---- Restaurante ----" << endl;
        cout << "1. Mostrar carta" << endl;
        cout << "2. Agregar orden" << endl;
        cout << "3. Mostrar orden" << endl;
        cout << "4. Borrar orden" << endl;
        cout << "5. Generar boleta y salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
				limpiarPantalla();
               
                mostrarCarta("Entradas", menuEntradas, preciosEntradas, MAX_ENTRADAS);
               
                mostrarCarta("Platos Principales", menuPlatosPrincipales, preciosPlatosPrincipales, MAX_PLATOS_PRINCIPALES);
                
                mostrarCarta("Postres", menuPostres, preciosPostres, MAX_POSTRES);
                cout<<"\nPresione Enter para continuar...";
                cin.ignore();
                cin.get();
                break;
            case 2:
            	limpiarPantalla();
                int categoria;
                do {
                    cout<<"Seleccione la categoria:"<<endl;
                    cout<<"1. Entradas" << endl;
                    cout<<"2. Platos Principales"<<endl;
                    cout<<"3. Terminar seleccion"<<endl;
                     cout<<"4. Postres"<<endl;
                    cout<<"Ingrese la categoria: ";
                    cin >> categoria;
                    if (categoria==1) {
                        agregarOrden("Entradas", menuEntradas, preciosEntradas, MAX_ENTRADAS, ordenes, numOrdenes);
                    } else if (categoria==2) {
                        agregarOrden("Platos Principales", menuPlatosPrincipales, preciosPlatosPrincipales, MAX_PLATOS_PRINCIPALES, ordenes, numOrdenes);
                    }
                    else if (categoria==3) {
                        agregarOrden("Postres", menuPostres, preciosPostres, MAX_POSTRES, ordenes, numOrdenes);
                    }
                } while (categoria!=4);
                break;
            case 3:
                limpiarPantalla(); 
                mostrarOrdenes(ordenes, numOrdenes);
                cout<<"\nPresione Enter para continuar...";
                cin.ignore();
                cin.get();
                break;
               
            case 4:
    limpiarPantalla();
    if (numOrdenes > 0) {
        int indice;
        cout<<"ingrese 1 si desea eliminar un plato  : ";
        cin>>indice;
        borrarOrden(ordenes, numOrdenes, indice - 1);
    } else {
        cout << "No hay ordenes para borrar." << endl;
    }
    cout << "\nPresione Enter para continuar...";
    cin.ignore();
    cin.get();
    break;
            case 5:
            	limpiarPantalla();
                generarBoleta(nombreCliente,ordenes,numOrdenes);
                opcion=6;
                break;
            default:
                cout<<"Opcion Incorrecta." << endl;
                cout<<"\nPresione Enter para continuar...";
                cin.ignore();
                cin.get();
        }
    } while (opcion!=6);
}


void dia4(const string& nombreCliente) {
    const int MAX_ENTRADAS = 3;
    const int MAX_PLATOS_PRINCIPALES = 4;
    const int MAX_POSTRES = 2;
    const int MAX_ORDENES = 20;

    string menuEntradas[MAX_ENTRADAS] = {
        "Ensalada de Pallares",
        "Salpicon De Pollo",
        "Cauche Con Queso"
    };
    float preciosEntradas[MAX_ENTRADAS] = {25.0, 20.0, 17.0};

    string menuPlatosPrincipales[MAX_PLATOS_PRINCIPALES] = {
        "Pollo broaster con arroz  ",
        "Guiso de trigo con pollo",    
        "Pollo a la chiclayana",
        "Locro de gallina"
    };
    float preciosPlatosPrincipales[MAX_PLATOS_PRINCIPALES] = {25.0, 18.0, 20.0, 12.0};

    string menuPostres[MAX_POSTRES] = {
        "Crema de queso y fresa",
        "Crema de chocolate y moka"
    };
    float preciosPostres[MAX_POSTRES] = {14.0, 16.0};

    Orden ordenes[MAX_ORDENES];
    int numOrdenes = 0;
    int opcion;
    do {
    	 limpiarPantalla();
        cout << "---- Restaurante ----" << endl;
        cout << "1. Mostrar carta" << endl;
        cout << "2. Agregar orden" << endl;
        cout << "3. Mostrar orden" << endl;
        cout << "4. Borrar orden" << endl;
        cout << "5. Generar boleta y salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
				limpiarPantalla();
              
                mostrarCarta("Entradas", menuEntradas, preciosEntradas, MAX_ENTRADAS);
               
                mostrarCarta("Platos Principales", menuPlatosPrincipales, preciosPlatosPrincipales, MAX_PLATOS_PRINCIPALES);
                
                mostrarCarta("Postres", menuPostres, preciosPostres, MAX_POSTRES);
                cout<<"\nPresione Enter para continuar...";
                cin.ignore();
                cin.get();
                break;
            case 2:
            	limpiarPantalla();
                int categoria;
                do {
                    cout<<"Seleccione la categoria:"<<endl;
                    cout<<"1. Entradas" << endl;
                    cout<<"2. Platos Principales"<<endl;
                    cout<<"3. Terminar seleccion"<<endl;
                     cout<<"4. Postres"<<endl;
                    cout<<"Ingrese la categoria: ";
                    cin >> categoria;
                    if (categoria==1) {
                        agregarOrden("Entradas", menuEntradas, preciosEntradas, MAX_ENTRADAS, ordenes, numOrdenes);
                    } else if (categoria==2) {
                        agregarOrden("Platos Principales", menuPlatosPrincipales, preciosPlatosPrincipales, MAX_PLATOS_PRINCIPALES, ordenes, numOrdenes);
                    }
                    else if (categoria==3) {
                        agregarOrden("Postres", menuPostres, preciosPostres, MAX_POSTRES, ordenes, numOrdenes);
                    }
                } while (categoria!=4);
                break;
            case 3:
                limpiarPantalla(); 
                mostrarOrdenes(ordenes, numOrdenes);
                cout<<"\nPresione Enter para continuar...";
                cin.ignore();
                cin.get();
                break;
               
            case 4:
    limpiarPantalla();
    if (numOrdenes > 0) {
        int indice;
        cout<<"ingrese 1 si desea eliminar un plato  : ";
        cin>>indice;
        borrarOrden(ordenes, numOrdenes, indice - 1);
    } else {
        cout << "No hay ordenes para borrar." << endl;
    }
    cout << "\nPresione Enter para continuar...";
    cin.ignore();
    cin.get();
    break;
            case 5:
            	limpiarPantalla();
                generarBoleta(nombreCliente,ordenes,numOrdenes);
                opcion=6;
                break;
            default:
                cout<<"Opcion Incorrecta." << endl;
                cout<<"\nPresione Enter para continuar...";
                cin.ignore();
                cin.get();
        }
    } while (opcion!=6);
}








void dia6(const string& nombreCliente) {
    const int MAX_ENTRADAS=3;
    const int MAX_PLATOS_PRINCIPALES=4;
    const int MAX_POSTRES=3;
    const int MAX_ORDENES=20;
    

    string menuEntradas[MAX_ENTRADAS]=
	{
        "ensalada mixta",
        "sopa de pollo",
        "ceviche de pescado"
    };
    float preciosEntradas[MAX_ENTRADAS]={20.0, 18.0, 25.0};

    string menuPlatosPrincipales[MAX_PLATOS_PRINCIPALES]={
        "bistec a lo pobre",
        "aji de gallina",    
        "arroz chaufa",
        "carapulcra"
    };
    float preciosPlatosPrincipales[MAX_PLATOS_PRINCIPALES] = {40.0,35.0,30.0,38.0};

    string menuPostres[MAX_POSTRES] = {
        " Queque de naranja",
        "Crema volteada",
        "Arros con leche"
    };
    float preciosPostres[MAX_POSTRES] = {10.0, 8.0, 12.0};

    Orden ordenes[MAX_ORDENES];
    int numOrdenes=0;
     int opcion;
    do {
    	 limpiarPantalla();
        cout << "---- Restaurante ----" << endl;
        cout << "1. Mostrar carta" << endl;
        cout << "2. Agregar orden" << endl;
        cout << "3. Mostrar orden" << endl;
        cout << "4. Borrar orden" << endl;
        cout << "5. Generar boleta y salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
				limpiarPantalla();
              
                mostrarCarta("Entradas", menuEntradas, preciosEntradas, MAX_ENTRADAS);
               
                mostrarCarta("Platos Principales", menuPlatosPrincipales, preciosPlatosPrincipales, MAX_PLATOS_PRINCIPALES);
               
                mostrarCarta("Postres", menuPostres, preciosPostres, MAX_POSTRES);
                cout<<"\nPresione Enter para continuar...";
                cin.ignore();
                cin.get();
                break;
            case 2:
            	limpiarPantalla();
                int categoria;
                do {
                    cout<<"Seleccione la categoria:"<<endl;
                    cout<<"1. Entradas" << endl;
                    cout<<"2. Platos Principales"<<endl;
                     cout<<"3. Postres"<<endl;
                    cout<<"4. Terminar seleccion"<<endl;
                    cout<<"Ingrese la categoria: ";
                    cin >> categoria;
                    if (categoria==1) {
                        agregarOrden("Entradas", menuEntradas, preciosEntradas, MAX_ENTRADAS, ordenes, numOrdenes);
                    } else if (categoria==2) {
                        agregarOrden("Platos Principales", menuPlatosPrincipales, preciosPlatosPrincipales, MAX_PLATOS_PRINCIPALES, ordenes, numOrdenes);
                    }
                    else if (categoria==3) {
                        agregarOrden("Postres", menuPostres, preciosPostres, MAX_POSTRES, ordenes, numOrdenes);
                    }
                } while (categoria!=4);
                break;
            case 3:
                limpiarPantalla(); 
                mostrarOrdenes(ordenes, numOrdenes);
                cout<<"\nPresione Enter para continuar...";
                cin.ignore();
                cin.get();
                break;
                
            case 4:
            	
    limpiarPantalla();
    if (numOrdenes > 0) {
        int indice;
        cout<<"ingrese 1 si desea eliminar un plato  : ";
        cin>>indice;
        borrarOrden(ordenes, numOrdenes, indice - 1);
    } else {
        cout << "No hay ordenes para borrar." << endl;
    }
    cout << "\nPresione Enter para continuar...";
    cin.ignore();
    cin.get();
    break;
            case 5:
            	limpiarPantalla();
                generarBoleta(nombreCliente,ordenes,numOrdenes);
                opcion=6;
                break;
            default:
                cout<<"Opcion Incorrecta." << endl;
                cout<<"\nPresione Enter para continuar...";
                cin.ignore();
                cin.get();
        }
    } while (opcion!=6);
}

void dia7(const string& nombreCliente) {
    const int MAX_ENTRADAS=3;
    const int MAX_PLATOS_PRINCIPALES=4;
    const int MAX_POSTRES=2;
    const int MAX_BEBIDAS=3;
    const int MAX_ORDENES=20;

    string menuEntradas[MAX_ENTRADAS] = {
        "tamales",
        "anticuchos",
        "rocoto relleno"
    };
    float preciosEntradas[MAX_ENTRADAS] = {30.0, 25.0, 35.0};

    string menuPlatosPrincipales[MAX_PLATOS_PRINCIPALES] = {
        "seco de cabrito",
        "carapulcra",
        "pachamanca",
        "arroz chaufa"
    };
    float preciosPlatosPrincipales[MAX_PLATOS_PRINCIPALES] = {55.0, 50.0, 60.0, 45.0};

    string menuPostres[MAX_POSTRES] = {
        "mazamorra morada",
        "suspiro a la limenia"
    };
    float preciosPostres[MAX_POSTRES] = {10.0, 12.0};

    string menuBebidas[MAX_BEBIDAS] = {
        "pisco sour",
        "cerveza artesanal",
        "jugo de maracuya"
    };
    float preciosBebidas[MAX_BEBIDAS] = {15.0, 18.0, 10.0};

    Orden ordenes[MAX_ORDENES];
    int numOrdenes=0;
   int opcion;
    do {
    	 limpiarPantalla();
        cout << "---- Restaurante ----" << endl;
        cout << "1. Mostrar carta" << endl;
        cout << "2. Agregar orden" << endl;
        cout << "3. Mostrar orden" << endl;
        cout << "4. Borrar orden" << endl;
        cout << "5. Generar boleta y salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
				limpiarPantalla();
                
                mostrarCarta("Entradas", menuEntradas, preciosEntradas, MAX_ENTRADAS);
                
                mostrarCarta("Platos Principales", menuPlatosPrincipales, preciosPlatosPrincipales, MAX_PLATOS_PRINCIPALES);
            
                mostrarCarta("Postres", menuPostres, preciosPostres, MAX_POSTRES);
                cout<<"\nPresione Enter para continuar...";
                cin.ignore();
                cin.get();
                break;
            case 2:
            	limpiarPantalla();
                int categoria;
                do {
                    cout<<"Seleccione la categoria:"<<endl;
                    cout<<"1. Entradas" << endl;
                    cout<<"2. Platos Principales"<<endl;
                    cout<<"3. Postres"<<endl;
                    cout<<"4. Terminar seleccion"<<endl;
                    cout<<"Ingrese la categoria: ";
                    cin >> categoria;
                    if (categoria==1) {
                        agregarOrden("Entradas", menuEntradas, preciosEntradas, MAX_ENTRADAS, ordenes, numOrdenes);
                    } else if (categoria==2) {
                        agregarOrden("Platos Principales", menuPlatosPrincipales, preciosPlatosPrincipales, MAX_PLATOS_PRINCIPALES, ordenes, numOrdenes);
                    }
                    else if (categoria==3) {
                        agregarOrden("Postres", menuPostres, preciosPostres, MAX_POSTRES, ordenes, numOrdenes);
                    }
                } while (categoria!=4);
                break;
            case 3:
                limpiarPantalla(); 
                mostrarOrdenes(ordenes, numOrdenes);
                cout<<"\nPresione Enter para continuar...";
                cin.ignore();
                cin.get();
                break;
                
            
            	case 4:
    limpiarPantalla();
    if (numOrdenes > 0) {
        int indice;
        cout<<"ingrese 1 si desea eliminar un plato  : ";
        cin>>indice;
        borrarOrden(ordenes, numOrdenes, indice - 1);
    } else {
        cout << "No hay ordenes para borrar." << endl;
    }
    cout << "\nPresione Enter para continuar...";
    cin.ignore();
    cin.get();
    break;
            case 5:
            	limpiarPantalla();
                generarBoleta(nombreCliente,ordenes,numOrdenes);
                opcion=6;
                break;
            default:
                cout<<"Opcion Incorrecta." << endl;
                cout<<"\nPresione Enter para continuar...";
                cin.ignore();
                cin.get();
        }
    } while (opcion!=6);
}


    