#ifndef PILAT_H
#define PILAT_H
/*
struct Producto
{
    float precio;
    char *nombre;
    int cve;

};
*/
// TEMPLATE O PLANTILLA O CLASE GENÉRICA
template<class T> //T = TIPO DE DATO
class pilaT
{
    T* vec;
    int tam;
    int tope;
    bool vacia;
    bool llena;
public:
     //pilaT();
     pilaT(int n =10);//CONSTRUCTOR CON ARG. POR DEFAULT
     void push(T valor);
     T pop();
     bool estaVacia();
     bool estaLlena();
     //SOLICITAMOS INFO. DEL DATO QUE ESTA EN EL TOPE DE LA PILA
     T Tope();
};


#endif // PILAT_H
