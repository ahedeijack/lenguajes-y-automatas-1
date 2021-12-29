#ifndef TABLADESIMBOLOS_H
#define TABLADESIMBOLOS_H

#endif // TABLADESIMBOLOS_H
#include <iostream>
#include <iomanip>
using namespace std;

#include<string.h>

//Define un alias
typedef int SymValue ; //Symbalue es elñ nombre que se usara para los int

struct Symbol{
    char *nombre;
    SymValue valor;
    Symbol *next;



};

class TablaDeSimbolos{
private:
    Symbol **tabla;
    int size;
    int Hash(char *);
public:
    TablaDeSimbolos(int);
    TablaDeSimbolos(Symbol **tabla, int size);
    Symbol *AddSym(char *, SymValue);
    Symbol *FindSym(char *);
    bool RemoveSymbol(char *);
    void ImprimirTabla();

    bool setValue(char *cad, SymValue val);
    bool getValue(char *cad, SymValue *val);
};

class tablaDeSimbolos{
public:
       tablaDeSimbolos();
};


