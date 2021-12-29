#ifndef NOTACIONPOLACA_H
#define NOTACIONPOLACA_H
#include "pilat.h"
#include "pilat.cpp"//Es necesario inlcuir el cpp en el h cuando se crea un template
#include <string>
#include <cstring>
#include <math.h>
using namespace std;

//Para establecer la precedencia de los operadores
enum Simbolo{OPERANDO,PIZQ,PDER,SUMRES,MULTDIV,POW};

class NotacionPolaca
{
public:
    NotacionPolaca();
    //EI = espresion infija
    string convertirAPosFija(string EI);
    //Cambiar a que regrese un string
    Simbolo tipoYPrecedencia(char s);
    void ajusteExpresion(string &, int&);
    char* ajusteExpresion2(string &, int&);
    float conversion(char);
    float solucionPost(string);
};

#endif // NOTACIONPOLACA_H
