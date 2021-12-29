#include "busquedas.h"

Busquedas::Busquedas(){

}

void Busquedas::SecuencialDatosNoOrdenados(int *vec,int  n, int X, int &pos){

    //PARA MANEJAR LA REFERENCIA
    //Y TENER VARIABLE DE ENTRADA

    pos = -1;
       int i = 0;
       //ENCONTRAR LA PRIMER OCURRENCIA DEL DA6O A BUSCAR
       while(pos == -1 && i < X)
       {
           if(vec[i] == X)
           {
               pos = i;
           }
           i++;
       }


       //return pos;
   }

void Busquedas::SecuencialDatosOrdenados(int *vec, int X, int &pos){
    pos = -1;
    int i = 0;
    while (vec[i]<X) {
        i++;
    }

    if(vec[i] == X){
        pos = i;
    }
}

void Busquedas::Binaria(int *vec, int X, int &pos){
    pos = -1;
    int LI = 0;
    int LS = sizeof (*vec)-1;

    int i;
    while ((LI <= LS) && (pos == -1)) {
        i = (LI + LS)/2;
         if (vec[i] == X) {
             pos = i;
         //HACER LA PRUEBA CON break Y continue
         //Cual funciona?
         } else if (vec[i] < X) {
             LI = i+1;
         } else {
         LS = i-1;
     }
    }

}
