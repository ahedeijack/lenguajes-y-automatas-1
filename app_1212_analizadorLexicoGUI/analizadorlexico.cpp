#include "analizadorlexico.h"

// MACROS DE C/C++
#define leerCar(i) cadena[i++]
#define retrocederCar i--   // EQUIVALE AL  * EN EL DIAG. DE TRANSICIONES


AnalizadorLexico::AnalizadorLexico()
{

}

void AnalizadorLexico::abrir2(char* nomArchivo, char cad[][255])
{
    FILE *parchivo;

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
}

void AnalizadorLexico::abrir(string nombreArch)
{
    string linea, resultado;
    char cadena[255];
    ifstream Archivo(nombreArch);
    while(getline(Archivo, linea)){
        resultado += scanner(strcpy(cadena,linea.c_str()));
    }
}

string AnalizadorLexico::scanner(char cadena[255])
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
                    resultado +="\n Es Delimitador. ";
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
                    resultado +="\n Es Identificador ";
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
                    resultado += "\n Es Num. Entero";
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
                    resultado += "\n Es Num. Real";
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
                    resultado += "\n Es un Op. Logico";
                    inicializaEstados();
                    inicioToken = i;
                    break;
            case 14: caracter = leerCar(i);
                    estadoActual = 15;
                    break;
            case 15: retrocederCar;
                    resultado += "\n Es un Op. Relacional";
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
                    resultado += "\n Es un Op. De Asignacion";
                    inicializaEstados();
                    inicioToken = i;
                    break;
            case 19: caracter = leerCar(i);
                    estadoActual = 20;
                    break;
            case 20: retrocederCar;
                    resultado += "\n Es un Op. Relacional";
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
                    resultado += "\n Op Relacional (>)";
                    inicializaEstados();
                    inicioToken = i;
                    break;
            case 24: caracter = leerCar(i);
                    estadoActual = 25;
                    break;
            case 25: retrocederCar;
                    resultado += "\n Op Relacional (>=)";
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
                   resultado += "\n Op. Relacional (<)";
                   inicializaEstados();
                   inicioToken = i;
                   break;
           case 29: caracter = leerCar(i);
                   estadoActual = 30;
                   break;
           case 30: retrocederCar;
                   resultado += "\n Op Relacional (<=)";
                   inicializaEstados();
                   inicioToken = i;
                   break;
        }
    }

    return resultado;
}


void AnalizadorLexico::inicializaEstados()
{
    estadoInicial = estadoActual = 0;
}

void AnalizadorLexico::fallo()
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

bool AnalizadorLexico::estadoDeAceptacion()
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

bool AnalizadorLexico::esLetra(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ;
}
bool AnalizadorLexico::esDigito(char c)
{
    if( c >= '0' && c <= '9')
        return true;
    else
        return false;
}
bool AnalizadorLexico::esDelimitador(char c)
{
    return (c == ' ' || c == '\t' ||  c == '\n');
}
