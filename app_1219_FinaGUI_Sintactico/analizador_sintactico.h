#ifndef ANALIZADOR_SINTACTICO_H
#define ANALIZADOR_SINTACTICO_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <QList>
#include <QString>

using namespace std;

#define MAXTOKEN 50
#define NUMPALRES 4
#define MAX 50




class analizador_sintactico
{
public:
    analizador_sintactico();
    void vabrirarch();
    int bytesarch();
    void vanalisislexico();
    QList<QString> vanalisis_sintactico();
    void viniedos();
    char nextchar();
    void vretract();
    int edoActesacept();
    QList<QString> vmuestra();
    void falla();
    int esId();
    void recuperaerror();
    void insertapila(string elem);
    int buscaTabla(char a[], char x[]);
    void eliminapila();
    int estoken(char x[]);
    void generararch(QString texto);
    QList<QString> analizar(QString texto);

};

#endif // ANALIZADOR_SINTACTICO_H
