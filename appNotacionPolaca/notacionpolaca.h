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

};

#endif // NOTACIONPOLACA_H
