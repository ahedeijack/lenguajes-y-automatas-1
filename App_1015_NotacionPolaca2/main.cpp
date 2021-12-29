#include <iostream>
#include "notacionpolaca.h"

using namespace std;

void parentesis(string cad){
    int cont=0;
    for(int i=0; i<(int)cad.length(); i++){
        if(cad[i] == '(')
            cont++;
        if(cad[i] == ')')
            cont--;
    }
    cout<<"Cont: "<<cont<<endl;
}

int main()
{
    //string expIn = "a^b*((C-D)+e)/f*G+h()";//Metodo para revisar que no tenga blankspaces y si los hay, eliminarlos y cuente los operadores y pizq
    //1^2*((3-4)+5)/(6*8+9)
    string dec;
    do{
        string expIn;
        cout<<"Ingrese su expresion infija: ";
        getline(cin,expIn);

        NotacionPolaca *expresion = new NotacionPolaca();

        float resp=0;
        //char *resul = new char[expIn.length()];
        string resul;

        resul = expresion->convertirAPosFija(expIn);
        resp = expresion->solucionPost(resul);

        cout<<"\nExpresion infija: "<<expIn<<endl;
        cout<<"Expresion posfija: "<<resul<<endl;
        if(resp != 0x20)
            cout<<"Resultado: "<<resp<<endl;
        else
            cout<<"Los operadores necesitan ser numeros para solucionar la expresion."<<endl;

        cout<<"\nIngresar otra expresion?: ";
        getline(cin,dec);
        cout<<"\n";
    }while(dec == "s" || dec == "S");

    return 0;
}
