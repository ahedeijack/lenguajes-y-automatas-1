#ifndef BUSQUEDAS_H
#define BUSQUEDAS_H

class  Busquedas{




public:
    Busquedas();                    //Puntero *          Referencia &
     void SecuencialDatosNoOrdenados(int *vec, int n, int X, int &pos);

     void SecuencialDatosOrdenados(int *vec, int X, int &pos);

     void Binaria(int *vec, int X, int &pos);

protected:

};



#endif // BUSQUEDAS_H

