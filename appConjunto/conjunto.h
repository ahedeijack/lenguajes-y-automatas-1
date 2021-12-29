#ifndef CONJUNTO_H
#define CONJUNTO_H

#include <iostream>
#include <string.h>

using namespace std;

const int MAX = 20;
enum Mensaje{ OVERFLOW, OK, YAEXISTE };

class Conjunto
{
    //int elementos[20];

    int elementos[MAX];
    int numElementos;
public:
    Conjunto();
    ~Conjunto() { cout<<"\nENTRA EL DESTRUCTOR"; }; //cout<<"\nENTRA EL DESTRUCTOR";
    // vaciar
    void vacio() { numElementos = 0; }

    Mensaje agregarElemento(int);
    Mensaje agregarElementoProp(int);
    bool Pertenece(const int);
    void BorrarElemento(int);
    void mostrarElementos(string set);
    void copiar(Conjunto *);
    bool Igual(Conjunto *) const;
    bool operator == (Conjunto *) const;
    void Interseccion(Conjunto *, Conjunto *);
    Mensaje Union(Conjunto *s2, Conjunto *s3);
};

#endif // CONJUNTO_H
