#include <iostream>
#include <string>
using namespace std;

#include <string.h>
#include <stdlib.h>

// MACROS DE C/C++
#define leerCar(i) cadena[i++]
#define retrocederCar i--   // EQUIVALE AL  * EN EL DIAG. DE TRANSICIONES

//PROTOTIPOS
void scanner(char cadena[255]);  //   SCANNER = ANALIZADOR LEXICO
void inicializaEstados();
void fallo();
bool esLetra(char c);
bool esDigito(char c);
bool esDelimitador(char c);
bool estadoDeAceptacion();

//VARIABLES GLOBALES
int i, inicioToken, estadoInicial, estadoActual;


int main()
{

    char cadenaC[255];
    string cadenaS;
    char opcion;
    do
    {
        cout<<"CADENA A ANALIZAR : ";  //   a       =0;
        getline(cin,cadenaS,'\n');
        cadenaS+=';';

        strcpy(cadenaC,cadenaS.c_str());
        cout<<"\n CADENA DE ENTRADA : "<<cadenaC<<endl;

        scanner(cadenaC);

        cout<<"\n ANALIZAR OTRA CADENA (s/n) : ";
        cin>>opcion;
        cin.get();// PARA ELIMINAR EL ENTER
        //cin.ignore();
        //fflush(stdin);

    }while(strchr("Ss",opcion));


    return 0;
}

void scanner(char cadena[255])
{
    char caracter;
    inicializaEstados();
    //VARIABLES GLOBALES
    i = inicioToken = 0;
    while( i < (int)strlen(cadena) || estadoDeAceptacion())
    {
        switch(estadoActual)
        {
            case 0: caracter = leerCar(i);
                    if(esDelimitador(caracter))
                         estadoActual = 1;
                    else
                         fallo();
                   break;
            case 1: caracter = leerCar(i);
                    if(esDelimitador(caracter))
                        estadoActual = 1;
                    else
                        estadoActual = 2;
                    break;
            case 2: retrocederCar;  // DECREMENTA LA i  EN 1
                    cout<<"\n DELIMITADOR ";
                    inicializaEstados();
                    inicioToken = i;
                    break;    // a
            case 3:
                   {
                      caracter = leerCar(i);
                      if(esLetra(caracter) || caracter == '_')
                          estadoActual = 4;
                      else
                          fallo();
                   }
                   break;
            case 4: caracter = leerCar(i);
                    if(esLetra(caracter) || esDigito(caracter)|| caracter =='_')
                        estadoActual = 4;
                    else
                        estadoActual = 5;  //    a=
                    break;
            case 5: retrocederCar;
                    cout<<"\n IDENTIFICADOR ";
                    inicializaEstados();
                    inicioToken = i;
                    break;

        }
    }



}

void inicializaEstados()
{
    estadoInicial = estadoActual = 0;
}
void fallo()
{
    switch (estadoInicial)
    {
        case 0:{ estadoInicial = 3;
                i = inicioToken;
                }
                break;
        case 3: {estadoInicial = 6;
                i = inicioToken;
             }
                break;

    }
    estadoActual = estadoInicial;
}

bool estadoDeAceptacion()
{
    switch (estadoActual)
    {
         case 2:
         case 5:
         case 8:
         case 10:
            return true;
         default: return false;
    }
}

bool esLetra(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ;
}
bool esDigito(char c)
{
    if( c >= '0' && c <= '9')
        return true;
    else
        return false;
}
bool esDelimitador(char c)
{
    return (c == ' ' || c == '\t' ||  c == '\n');
}
