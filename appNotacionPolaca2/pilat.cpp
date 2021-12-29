#include "pilat.h"

/*
pilaT::pilaT()
{

}*/

template<class T>
pilaT<T>::pilaT(int n)
{
    tam = n;
    // vec = new T[tam+1];
    // tope = 1;
    vec = new T[tam];
    tope = 0;
    vacia = true;
    llena = false;
}

template<class T>
void pilaT<T>::push(T valor)
{
    vacia = false;
    vec[tope++] = valor;
    if (tope == tam)
        llena = true;
}

template<class T>
T pilaT<T>::pop()
{
    /*if (--tope == 0)
                    vacia = true;
    */
    llena = false;
    if (--tope == 0)
    {
        vacia = true;
        //  return vec[tope];
    }
    if (tope == -1)
        tope = 0;
    return vec[tope];
}

template<class T>
bool pilaT<T>::estaVacia()
{
    return vacia;
}

template<class T>
bool pilaT<T>::estaLlena()
{
    return llena;
}

template<class T>
T pilaT<T>::Tope()
{
    return vec[tope - 1];
}
