#include <iostream>
#include <string>
#include <string.h>

using namespace std;

const char Par[6] = "02468";
const char Non[6] = "13579";

bool analizarNumero( char *cadena )
{
    char carEntrada;
    int estadoActual = 0;
    int i = 0;
    bool band = false;

    while( i < (int)strlen(cadena) && !band )
    {
        switch ( estadoActual ) {
            case 0: {
                carEntrada = cadena[i++];
                if( strchr(Par,carEntrada) )
                    estadoActual = 1;
                else if ( strchr(Non, carEntrada) )
                    estadoActual = 2;
            }
            break;
            case 1: {
                carEntrada = cadena[i++];
                if ( strchr(Par,carEntrada) )
                    estadoActual = 1;
                else if ( strchr(Non, carEntrada) )
                    estadoActual = 2;
                else { // otro
                    estadoActual = 3;
                    i--;
                }
            }
            break;
            case 2: {
                carEntrada = cadena[i++];
                if ( strchr(Par,carEntrada) )
                    estadoActual = 1;
               else if ( strchr(Non, carEntrada) )
                    estadoActual = 2;
            }
            break;
            case 3: { // fin expresión
                cout<<"-->> NUMERO PAR <<--"<<endl;
                band = true; // estado de aceptación.
            }
            break;
        } // fin switch
    } // fin while
    return band;
}

int main()
{
    char opc;
    string cadena = "142";

    cout<<"Determinar numeros pares en una cadena"<< endl;
    do {
        cout<<"Escribe un numero: ";
        getline(cin, cadena, '\n');
        cadena += ";";
        cout<<"Tu numero = "<<cadena;
        char *cad = new char[ cadena.length() ];
        strcpy(cad, cadena.c_str());

        if ( !analizarNumero(cad) )
            cout<<" -->> Numero NON <<--"<<endl;

        cout<<"ANALIZAR OTRO NUMERO (S/N) : ";
        opc = cin.get();
        cin.get(); // eliminar enter

    } while(strchr("Ss", opc));
    return 0;
}
