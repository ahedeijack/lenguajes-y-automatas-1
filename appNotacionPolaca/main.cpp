#include <iostream>

using namespace std;

#include "notacionpolaca.h"

int main()
{
    //string expInfija = "a+b-c";

    string expInfija = "(7 + 8)-5*6^2";//TAREA : ANALIZAR LA CADENA DE ENTRADA QUE NO CONTENGA ESPACIOS EN BLANCO
                                       // SI HAY, SE DEBERAN ELIMINAR

    cout<<"Expresion Infija : "<<expInfija<<endl;

    int _ = 10;
    if (_ > 5){
        cout<"_ = " <<_;
    }

    NotacionPolaca *expresion = new NotacionPolaca();

    char *resul = new char[expInfija.length()];

    resul = expresion->ConvertirAPosFija(expInfija);

    cout<<"\n EXPRESION POSTFIJA = "<<resul<<endl;

    delete expresion;
    delete []resul;
    return 0;
}
