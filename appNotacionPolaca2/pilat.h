#ifndef PILAT_H
#define PILAT_H

template<class T>
class pilaT
{
    T* vec;
    int tam;
    int tope;
    bool vacia;
    bool llena;
public:
    pilaT();//Ya no se necesita
    pilaT(int n=10);//Constructor con argumentos por default
    void push(T valor);
    T pop();
    bool estaVacia();
    bool estaLlena();
    T Tope();


};

#endif // PILAT_H
