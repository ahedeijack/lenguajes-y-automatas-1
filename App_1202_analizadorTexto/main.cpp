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

    /*

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
    */

    //Para mañana el editor
    //Reconocimiento del !!, !=, =, ==
    //Leer desde un archivo la entrada y mandarlo a analizar por scanner.

    cout<<"Simulador de un editor para terminar .-ENTER EN LA LINEA NUEVA.-" <<endl;

    //Archivos
    FILE *parchivo;
    string nomArchivo = "texto.txt";

    char *cadena = new char[255];
    int i = 0;

    if((parchivo = fopen(nomArchivo, "r")) == nullptr)
        printf("ERROR");
    else
    {
        while(!feof(parchivo))
        {
            printf("\nLeyendo\n");
            while(fgets(cadena,255,parchivo))
            {
                printf("%s",cadena);
                strcpy_s(cad[i], cadena);
                i++;
            }
        }
    }


    return 0;
}

string AnalizadorLexico(char cadena[255])
{
    string resultado;
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
                    resultado +="\n DELIMITADOR ";
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
                    resultado +="\n IDENTIFICADOR ";
                    inicializaEstados();
                    inicioToken = i;
                    break;
            //Números enteros y reales
            case 6: caracter = leerCar(i);
                    if(esDigito(caracter))
                        estadoActual = 7;
                    else
                        fallo();
                    break;
            case 7: caracter = leerCar(i);
                    if(esDigito(caracter))
                        estadoActual = 7;
                    else if(caracter == '.')
                        estadoActual = 9;
                    else
                        estadoActual = 8;
                    break;
            case 8: retrocederCar;
                    resultado += "\n NUMERO ENTERO";
                    inicializaEstados();
                    inicioToken = i;
                    break;
            case 9: caracter = leerCar(i);
                    if(esDigito(caracter))
                        estadoActual = 9;
                    else
                        estadoActual = 10;
                    break;
            case 10: retrocederCar;
                    resultado += "\n NUMERO REAL";
                    inicializaEstados();
                    inicioToken = i;
                    break;
            //TAREA:
            case 11: caracter = leerCar(i);
                    if(caracter == '!')
                        estadoActual = 12;
                    else
                        fallo();
                    break;
            case 12: caracter = leerCar(i);
                    if(caracter == '=')
                        estadoActual = 14;
                    else
                        estadoActual = 13;
                    break;
            case 13: retrocederCar;
                    resultado += "\n OP LOGICO";
                    inicializaEstados();
                    inicioToken = i;
                    break;
            case 14: caracter = leerCar(i);
                    estadoActual = 15;
                    break;
            case 15: retrocederCar;
                    resultado += "\n OP RELACIONAL";
                    inicializaEstados();
                    inicioToken = i;
                    break;
            case 16: caracter = leerCar(i);
                    if(caracter == '=')
                        estadoActual = 17;
                    else
                        fallo();
                    break;
            case 17: caracter = leerCar(i);
                    if(caracter == '=')
                        estadoActual = 19;
                    else
                        estadoActual = 18;
                    break;
            case 18: retrocederCar;
                    resultado += "\n OP DE ASIGNACION";
                    inicializaEstados();
                    inicioToken = i;
                    break;
            case 19: caracter = leerCar(i);
                    estadoActual = 20;
                    break;
            case 20: retrocederCar;
                    resultado += "\n OP RELACIONAL";
                    inicializaEstados();
                    inicioToken = i;
                    break;
     // > y >=
            case 21: caracter = leerCar(i);
                    if(caracter == '>')
                        estadoActual = 22;
                    else
                        fallo();
                    break;
            case 22: caracter = leerCar(i);
                    if(caracter == '=')
                        estadoActual = 24;
                    else
                        estadoActual = 23;
                    break;
            case 23: retrocederCar;
                    resultado += "\n OP DE RELACIONAL (>)";
                    inicializaEstados();
                    inicioToken = i;
                    break;
            case 24: caracter = leerCar(i);
                    estadoActual = 25;
                    break;
            case 25: retrocederCar;
                    resultado += "\n OP RELACIONAL (>=)";
                    inicializaEstados();
                    inicioToken = i;
                    break;
    // < y <=
           case 26: caracter = leerCar(i);
                   if(caracter == '<')
                       estadoActual = 27;
                   else
                       fallo();
                   break;
           case 27: caracter = leerCar(i);
                   if(caracter == '=')
                       estadoActual = 29;
                   else
                       estadoActual = 28;
                   break;
           case 28: retrocederCar;
                   resultado += "\n OP DE RELACIONAL (<)";
                   inicializaEstados();
                   inicioToken = i;
                   break;
           case 29: caracter = leerCar(i);
                   estadoActual = 30;
                   break;
           case 30: retrocederCar;
                   resultado += "\n OP RELACIONAL (<=)";
                   inicializaEstados();
                   inicioToken = i;
                   break;
        }
    }

    return resultado;
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
        //TAREAAA:
        case 6: {estadoInicial = 11;
                i = inicioToken;
                }
                break;
        case 11: {estadoInicial = 16;
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
         case 13:
         case 15:
         case 18:
         case 20:
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

