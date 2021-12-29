#ifndef ANALIZADORLEXICO_H
#define ANALIZADORLEXICO_H

#include <string>
using namespace std;

#include <string.h>
#include <stdlib.h>

#include <fstream>

class AnalizadorLexico
{
public:
    AnalizadorLexico();
    string scanner(char cadena[255]);  //   SCANNER = ANALIZADOR LEXICO
    void inicializaEstados();
    void fallo();
    bool esLetra(char c);
    bool esDigito(char c);
    bool esDelimitador(char c);
    bool estadoDeAceptacion();
    void abrir(string nombreArch);
    void abrir2(char* nomArchivo, char cad[][255]);
    int i, inicioToken, estadoInicial, estadoActual;
};

#endif // ANALIZADORLEXICO_H
