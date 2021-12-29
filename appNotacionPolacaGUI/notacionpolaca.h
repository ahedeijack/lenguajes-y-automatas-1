#ifndef NOTACIONPOLACA_H
#define NOTACIONPOLACA_H

#include "pilat.h"
#include "pilat.cpp"

#include <string>
using namespace std;

//PARA ESTABLECER LA PRECEDENCIA DE LOS OPERADORES
enum Simbolo{OPERANDO, PIZQ, PDER, SUMRES, MULTDIV, POW};

class NotacionPolaca
{


public:
    NotacionPolaca();
           // EI = EXPRESION INFIJA
    char *ConvertirAPosFija(string EI);

    //string ConvertirAPosFija(string EI);

    Simbolo tipoYPrecedencia(char s);

    //DISEÑAR E IMPLEMENTAR EL METODO PARA LA SOLUCION DE LA EXPRESION POSTFIJA

    //  EJ:   (A+B)-C   : AB+C-    NO SE PUEDE RESOLVER
    //  EJ:   (1+2)-3   : 12+3- = 0    SI SE PUEDE RESOLVER

    //   double solucionExpresionPostfija(string EPOS)    <<<<-----


   //      "(1+2)-3"
    //  '1' caracter = 1 decimal

    //   '1'-'0' = 1

    //   49 - 48 = 1


};

#endif // NOTACIONPOLACA_H
