#include <iostream>
#include<string.h>

using namespace std;

#include "tabladesimbolos.h"


int main()
{
    cout << "Tabla de Simbolos " <<endl;

    char *cad1 = new char[128];

    string cad1S = "val1";
    strcpy(cad1, cad1S.c_str());

    TablaDeSimbolos tablaS(10);
    tablaS.AddSym(cad1, 5); // (val1, 5) = val1 = 5
    tablaS.AddSym("val2",5);
    tablaS.AddSym("val3",0);
    tablaS.AddSym("_a",10);
    tablaS.AddSym("a_",0);
    tablaS.AddSym("i", 0);
    tablaS.AddSym("j", 0);

   tablaS.ImprimirTabla();

   cout<<"Valor de Val2 = "<<tablaS.FindSym("val2")->valor<<endl;
   cout<<"Valor de i = "<<tablaS.FindSym("i")->valor<<endl;

   cout<<"Eliminar: _a"<<endl;
   tablaS.RemoveSymbol("_a");
   tablaS.ImprimirTabla();

   cout<<"Elimiar: val1"<<endl;
   tablaS.RemoveSymbol("val1");
   tablaS.ImprimirTabla();

    return 0;
}
