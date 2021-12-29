#include <QCoreApplication>
#include <iostream>
using namespace std;
#include <time.h>
#include <stdlib.h>

#include "busquedas.h"


int main(){
    srand((unsigned)time(NULL));

    int tam = 7;
    //int tam=rand()%11+5;
    //int *vec=new int[tam];
    int vec[] = {18,90,121,32,12,31,17};
    for (int i = 0; i < tam; ++i) {
        vec[i] = rand() % 90 + 10;
        cout<<"Vec[ "<<(i+1)<<" ]: "<<vec[i] <<endl;
    }

    Busquedas *busquedas = new Busquedas();

    cout<<"Dato a buscar: ";
    int dato, pos;
    //cin>>dato;
    dato = 17;
    busquedas->SecuencialDatosNoOrdenados(vec, tam, dato, pos);

    if(pos != -1){
        cout<<"Dato : "<<dato <<" , se encuentra en la posicion: "<<(pos+1)<<endl;
    } else {
        cout <<"El dato no existe"<<endl;
    }
    return 0;

 //Agregar secuencial ordenada, binaria y binaria recursiva
}
