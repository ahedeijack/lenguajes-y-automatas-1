#include "analizador_sintactico.h"
#include <QString>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

//char *PalRes[]= {"char", "float","int","puts"}; //printf
char PalRes[5][10]= {"char", "float","int","puts"}; //printf

//si se usa objeto string, cambiar el uso de strcmp
//string PalRes[10]= {"char", "float","int","puts"}; //printf

char sLexema[127];
char sLinea[127];
//char *non="13579", *par="24680";
char non[6]="13579", par[6]="24680";
char asTokens [MAXTOKEN][100];
int indice=0, edoAct, edoIni, iniToken=0, k, numBytesArch;

int cima = -1;
char pilac[MAX][10];

bool finarch = false;
FILE *Fd;

char token[22][8] = {"x", ";", ",", "*", "Id", "[", "]", "Num", "char", "int", "float",
    "puts", "(", ")", "Cte.Lit", "{", "}", "=","+","-","/", "Real"};

char varsint[15][3]={"x", "D", "L", "L'", "I", "I'", "A", "A'", "K",
    "T", "F", "E", "P"};
                                                   // e -> cadena vacia
int tablaM[100][8]= {{1, 5, 1, 5, 999, -1, 999, 999}, //[ D->I';
                     {1, 5, 1, 5, 999, -1, 999, 999}, //; D->I';
                     {1, 1, 1, 5, 999, -1, 999, 999}, //id D->PL';
                    {1, 7, 1, 5, 3, -1, 999, 999}, //num D->I'L';
                    {1, 8, 1, 9, 2, -1, 999, 999}, //char D->TL;
                    {1, 9, 1, 9, 2, -1, 999, 999}, //int D->TL;
                    {1, 10, 1, 9, 2, -1, 999, 999}, //float D->TL;
       /* 5 */      {2, 3, 2, 4, 3, 999, 999, 999}, // * L->IL'
                    {2, 4, 2, 4, 3, 999, 999, 999}, //Id L->IL'
                    {3, 1, 3, 5, 999, 999, 999, 999}, //; L'->I'
                    {3, 1, 3, 999, 999, 999, 999, 999},//; L'->e
                    {3, 2, 3, -2, 4, 3, 999, 999}, //, L'->,IL'
      /* 10 */      {3, 3, 3, -3, 8, 3, 999, 999}, //* L'->*KL'
                    {3, 18, 3, 12, 3, 999, 999, 999}, //+ L'->PL'
                    {3, 19, 3, 12, 3, 999, 999, 999}, //- L'->PL'
                    {3, 20, 3, 12, 3, 999, 999, 999}, // / L'->PL'
                    {3, 14, 3, -14, 5, 999, 999, 999},// cte. Lit. L'->cte Lit. I'
                    {4, 3, 4, -3, -4, 5, 999, 999}, // * I->*Id I'
                    {4, 4, 4, -4, 5, 999, 999, 999},// Id I->Id I'
                    {5, 1, 5, 999, 999, 999, 999, 999},// ; I'->e
     /* 15 */       {5, 2, 5, 999, 999, 999, 999, 999},// , I'->e
                    {5, 5, 5, 6, 999, 999, 999, 999}, // [ I' -> A
                    //{5, 7, 5, -7, 999, 999, 999, 999}, //Num I' -> Num
                    //{5, 12, 5, 7, 8, 11, 999, 999}, //( I' -> Num
                    {5, 14, 5, -14, 999, 999, 999, 999}, //cte lit I'->cte lit
     /* -> */       {5, 17, 5, -17, 8, 999, 999, 999}, //= I'->=K
                    {6, 5, 6, -5, 8, 11, 999, 999}, //[ A->[ KE
     /* 20 */       {7, 1, 7, 999, 999, 999, 999, 999},//; A'->e
                    {7, 2, 7, 999, 999, 999, 999, 999},//, A'->e
                    {7, 5, 7, -5, 8, -6, 7, 999}, //[ A' -> [K]A'
                    {7, 12, 7, -12, 999, 999, 999, 999}, //( A' -> (
                    {8, 4, 8, -4, 999, 999, 999, 999}, //Id K -> Id
                    {8, 5, 8, -5, 8, 11, 999, 999}, //[ K -> [ KE
                    {8, 7, 8, -7, 999, 999, 999, 999}, //Num K -> Num
                    {8, 21, 8, -21, 999, 999, 999, 999}, //Real K -> Num
                    {8, 12, 8, -12, 8, 11, 999, 999}, //( K -> ( KE
                    {8, 15, 8, -15, 8, 10, 999, 999}, //{ K -> { KF
                    {9, 8, 9, -8, 999, 999, 999, 999}, //char T->Char
                    {9, 9, 9, -9, 999, 999, 999, 999}, //int T->int
                    {9, 10, 9, -10, 999, 999, 999, 999},//float T->float
                    /*segunda gramatica */
        /* 25 */    {10, 11, 10, -11, 11, -1, 999, 999},//puts F-> puts E;
                    {10, 16, 10, -16, 999, 999, 999, 999},//} F-> };
                    {11, 6, 11, -6, 1, 999, 999, 999},//]E -> ]D
                    {11, 12, 11, -12, 12, -13, 999, 999},//( E -> (P)
                    {11, 13, 11, -13, 999, 999, 999, 999},//)E -> )
                    {12, 14, 12, -14, 999, 999, 999, 999},//cte lit P->cte lit
                    {12, 18, 12, -18, 8, 999, 999, 999},//+ P -> + k
                    {12, 19, 12, -19, 8, 999, 999, 999},//- P -> - k
                    {12, 20, 12, -20, 8, 999, 999, 999},// / P ->/ k
                   };

analizador_sintactico::analizador_sintactico()
{

}

int analizador_sintactico::bytesarch() {
    int aux;                //La variable aux se utiliza para guardar la posicion de un byte en un archivo
    fseek(Fd,0L,SEEK_END);  //Situa el apuntador de Fd al final del archivo con 0 de desplazamiento
    aux = (int) ftell(Fd);  //la funcion ftell guarda en aux la posicion del apuntador de Fd
    fseek(Fd,0L,SEEK_SET);
    return aux;             //Retorna la posicion
}

void analizador_sintactico::vanalisislexico() {
    char cCarent;
    indice = iniToken = k = 0;
    viniedos();

    while(indice < numBytesArch || edoActesacept())
    {
        switch(edoAct)
        {
            case 0: cCarent=nextchar();
                if (strchr(non,cCarent))
                    edoAct = 1;
                else
                    if(strchr(par,cCarent))
                        edoAct = 2;
                    else
                        if(cCarent == '.')
                            edoAct = 37;
                    else
                        falla();
                break;

            case 1: cCarent=nextchar();
                if(strchr(non,cCarent))
                    edoAct=1;
                else
                    if(strchr(par,cCarent))
                        edoAct = 2;
                else if(cCarent== '.')
                        edoAct = 37;
                    else
                        falla();
                break;

            case 2: cCarent=nextchar();
                if(strchr(non,cCarent))
                    edoAct=1;
                else
                    if (strchr(par,cCarent))
                        edoAct=2;
                    else if(cCarent== '.')
                            edoAct = 37;
                    else
                        edoAct=3;
                break;

            case 3: vretract();
                strcpy(asTokens[k++],"Num");
                if (indice >= numBytesArch)
                    return;
                iniToken=indice;
                viniedos();
                break;

            case 4: cCarent=nextchar();
                switch(cCarent)
                {
                    case '+': edoAct=5; break;
                    case '-': edoAct=6; break;
                    case '*': edoAct=7; break;
                    case '/': edoAct=8; break;
                    default: falla();
                }
                break;

            case 5: strcpy(asTokens[k++], "+");
                if (indice >= numBytesArch)
                    return;
                iniToken=indice;
                viniedos();
                break;

            case 6: strcpy(asTokens[k++], "-");
                if (indice>=numBytesArch)
                    return;
                iniToken=indice;
                viniedos();
                break;

            case 7: strcpy(asTokens[k++], "*");
                if (indice>=numBytesArch)
                    return;
                iniToken=indice;
                viniedos();
                break;

            case 8: strcpy(asTokens[k++], "/");
                if (indice>=numBytesArch)
                    return;
                iniToken=indice;
                viniedos();
                break;


            case 9: cCarent=nextchar();
                if (strchr(par,cCarent))
                    edoAct=10;
                else
                    if(strchr(non,cCarent))
                        edoAct=11;
                    else if(cCarent== '.')
                            edoAct = 37;
                    else
                        falla();
                break;

            case 10: cCarent=nextchar();
                if (strchr(par,cCarent))
                    edoAct=10;
                else
                    if(strchr(non,cCarent))
                        edoAct=11;
                    else if(cCarent== '.')
                            edoAct = 37;
                    else
                        falla();
                break;

            case 11 : cCarent=nextchar();
                if (strchr(non,cCarent))
                    edoAct=11;
                else
                    if(strchr(par,cCarent))
                        edoAct=10;
                    else if(cCarent== '.')
                            edoAct = 37;
                    else
                        edoAct=12;
                break;

                // NON - PAR
            case 12: vretract();
                strcpy(asTokens[k++],"Num");
                if (indice>=numBytesArch)
                    return;
                iniToken=indice;
                viniedos();
                break;

            case 13: cCarent=nextchar();
                if ((isalpha(cCarent)|| cCarent=='_'))
                    edoAct=14;
                else
                    falla();
                break;

            case 14: cCarent=nextchar();
                if ((isalpha(cCarent)|| cCarent=='_') || isdigit(cCarent))
                    edoAct=14;
                else
                    edoAct= 15;
                break;

            case 15: vretract();
                if(esId())
                    strcpy(asTokens[k++], "Id");
                else
                    strcpy(asTokens[k++],sLexema);

                if(indice>=numBytesArch)
                    return;
                iniToken=indice;
                viniedos();
                break;

            case 16: cCarent=nextchar();
                if(cCarent==';')
                    edoAct=17;
                else
                    falla();
                break;

                /* Al encontrar el caracter ';' , que indica fin de linea,
                 Se copia el caracter '$' al fin del arreglo astokens
                 */
            case 17: strcpy(asTokens[k++], ";");
                strcpy(asTokens[k], "$");
                if (indice >= numBytesArch)
                    return;
                iniToken=indice;
                viniedos();
                break;

            case 18: cCarent=nextchar();
                if(cCarent=='[')
                    edoAct=19;
                else
                    falla();
                break;

            case 19: strcpy(asTokens[k++], "[");
                if (indice >= numBytesArch)
                    return;
                iniToken=indice;
                viniedos();
                break;

            case 20: cCarent=nextchar();
                if(cCarent==']')
                    edoAct=21;
                else
                    falla();
                break;

            case 21: strcpy(asTokens[k++], "]");
                if (indice >= numBytesArch)
                    return;
                iniToken = indice;
                viniedos();
                break;

            case 22: cCarent = nextchar();
                if(cCarent == ',')
                    edoAct=23;
                else
                    falla();
                break;

            case 23: strcpy(asTokens[k++], ",");
                if (indice >= numBytesArch)
                    return;
                iniToken=indice;
                viniedos();
                break;

            case 24: cCarent = nextchar();
                if (('"' == cCarent) && cCarent)
                    edoAct=25;
                else
                    falla();
                break;

            case 25: cCarent=nextchar();
                if (('"' != cCarent) && cCarent)
                    edoAct=25;
                else
                    if(cCarent)
                        edoAct=26;
                break;

            case 26: strcpy(asTokens[k++],"Cte.Lit");
                if (indice >= numBytesArch)
                    return;
                iniToken=indice;
                viniedos();
                break;

            case 27: cCarent=nextchar();
                if(cCarent == '(')
                    edoAct=28;
                else
                    falla();
                break;

            case 28: strcpy(asTokens[k++], "(");
                if (indice>=numBytesArch)
                    return;
                iniToken = indice;
                viniedos();
                break;

            case 29:cCarent=nextchar();
                if(cCarent == ')')
                    edoAct=30;
                else
                    falla();
                break;

            case 30: strcpy(asTokens[k++], ")");
                if (indice>=numBytesArch)
                    return;
                iniToken=indice;
                viniedos();
                break;

            case 31: cCarent = nextchar();
                if(cCarent == '{')
                    edoAct = 32;
                else
                    falla();
                break;

            case 32: strcpy(asTokens[k++], "{");
                if (indice >= numBytesArch)
                    return;
                iniToken = indice;
                viniedos();
                break;

            case 33: cCarent = nextchar();
                if(cCarent == '}')
                    edoAct = 34;
                else
                    falla();
                break;

            case 34: strcpy(asTokens[k++], "}");
                if (indice >= numBytesArch)
                    return;
                iniToken = indice;
                viniedos();
                break;

            case 35: cCarent = nextchar();
                if(cCarent == '=')
                    edoAct = 36;
                else
                    falla();
                break;

            case 36: strcpy(asTokens[k++], "=");
                if (indice >= numBytesArch)
                    return;
                iniToken = indice;
                viniedos();
                break;

        case 37: cCarent = nextchar();
            if (strchr(non, cCarent))
                edoAct = 38;
            else
                if(strchr(par, cCarent))
                    edoAct = 39;
                else
                    falla();
            break;
        case 38: cCarent = nextchar();
            if(strchr(non, cCarent))
                edoAct=38;
            else
                if(strchr(par, cCarent))
                    edoAct = 39;
                else
                    edoAct = 40;
            break;

        case 39: cCarent = nextchar();
            if(strchr(non, cCarent))
                edoAct = 38;
            else
                if (strchr(par, cCarent))
                    edoAct = 39;
                else
                    edoAct = 40;
            break;
        case 40: vretract();
            strcpy(asTokens[k++],"Real");
            if (indice >= numBytesArch)
                return;
            iniToken=indice;
            viniedos();
            break;
        }/*switch*/
    } /*while*/
}

void analizador_sintactico::viniedos() {                       //Metodo para inicializar los estados
    edoAct=0;
    edoIni=0;
}

char analizador_sintactico::nextchar() {                       //Retorna el caracter en el indice acual e incrementa el indice
    char cAux;
    fread(&cAux,sizeof(cAux),1,Fd);
    indice++;
    return cAux;
}

void analizador_sintactico::vretract() {                       //Regresa una posicion y devuelve el caracter de el indice
    indice--;
    fseek(Fd,(long)indice,SEEK_SET);
}

int analizador_sintactico::edoActesacept() {
    switch (edoAct){
    case 8: case 5: case 7: case 6: case 3:
    case 12: case 15: case 17: case 19: case 21:
    case 23 : case 26: case 28: case 30: case 32:
    case 34: case 36: case 40:
        return true;
        default : return false;
    }
}

void analizador_sintactico::falla() {                          //
    switch (edoIni)
    {
        case 0 : edoIni=4;
        indice=iniToken;
        fseek(Fd, (long)iniToken, SEEK_SET);
        break;

    case 4 : edoIni=9;
        indice=iniToken;
        fseek(Fd, (long)iniToken, SEEK_SET);
        break;

    case 9 : edoIni=13;
        indice=iniToken;
        fseek(Fd, (long)iniToken, SEEK_SET);
        break;

    case 13 : edoIni=16;
        indice = iniToken;
        fseek(Fd, (long)iniToken, SEEK_SET);
        break;

    case 16 : edoIni=18;
        indice = iniToken;
        fseek(Fd, (long)iniToken, SEEK_SET);
        break;

    case 18 : edoIni=20;
        indice=iniToken;
        fseek(Fd, (long)iniToken, SEEK_SET);
        break;

    case 20 : edoIni=22;
        indice = iniToken;
        fseek(Fd, (long)iniToken, SEEK_SET);
        break;

    case 22 : edoIni=24;
        indice = iniToken;
        fseek(Fd, (long)iniToken, SEEK_SET);
        break;

    case 24 : edoIni=27;
        indice = iniToken;
        fseek(Fd, (long)iniToken, SEEK_SET);
        break;

    case 27 : edoIni=29;
        indice = iniToken;
        fseek(Fd, (long)iniToken, SEEK_SET);
        break;

    case 29: edoIni = 31;
        indice = iniToken;
        fseek(Fd, (long)iniToken, SEEK_SET);
        break;

    case 31: edoIni = 33;
        indice = iniToken;
        fseek(Fd, (long)iniToken, SEEK_SET);
        break;

    case 33: edoIni = 35;
        indice = iniToken;
        fseek(Fd, (long)iniToken, SEEK_SET);
        break;

    case 35: recuperaerror();
    }
    edoAct=edoIni;
}


void analizador_sintactico::recuperaerror() {                          //Se iguala el token vuelve al indice y se inicializan los estados
    iniToken = indice;
    viniedos();
}

int analizador_sintactico::esId() {
    int n,m,found = false;
    fseek(Fd, (long)iniToken, SEEK_SET);          //Situa el puntero de lectura en la posicion del token

    for (m=iniToken, n=0; m<indice; m++, n++)  //Recorre desde el inicio del token hasta la posicion del indice guardando en n la cantidad de espacios avanzados
        fread(&sLexema[n], sizeof(char), 1, Fd);  //Guarda en la posicion actual de "sLexema" el elemento leido en el puntero de Fd

    sLexema[n]= '\0';                           //Añade un salto de linea al final de la cadena

    for (m=0 ; m < NUMPALRES && !found ;)       //Compara el lexema con todas las palabras reservadas en busca de una coincidencia
        if (strcmp(PalRes[m], sLexema)==0)
            found = true;
        else
            m++;

    return (found ? 0 : 1);                     //Retorna true si se encontro el lexema en las palabras reservadas
}

void analizador_sintactico::generararch(QString texto)                      //Metodo para generar el archivo binario
{
    char car;
    char nomArch[100];                  //Arreglo para guardar el nombre el archivo

    string nombre = "text";

    sprintf(nomArch,"%s.dat", nombre.c_str());

    Fd = fopen(nomArch,"w+b");          //Abre el archivo en la direccion guardada y se abre en modo de escritura binaria

    for(int i = 0 ; i < texto.length() ; i++) {
        car = texto.at(i).toLatin1();

        if( car == '\n')                //Si es '\n' hace un salto de linea
        {
            car = '\n';
            printf("\n");
        }

        if(car == 0)                    //Si el caracter es nulo lee el siguiente
            car = cin.get();            //getch();

        if(car != 27 && car != 8)       //Si el caracter no es un retroceso o un escape
            fwrite(&car,sizeof(car),1,Fd);  //Lo escribe en el archivo

    }

    fclose(Fd);                         //Cierra el flujo del archivo
}


QList<QString> analizador_sintactico::analizar(QString texto)
{
    generararch(texto);
    Fd = fopen("text.dat","r+b");
    numBytesArch = bytesarch();
    vanalisislexico();
    fclose(Fd);
    return vanalisis_sintactico();

}



QList<QString> analizador_sintactico::vmuestra(){
    int iJ;
    QString tokens;
    QList<QString> lista;

    for(iJ = 0; iJ < k; iJ++)
    {
        tokens.append(asTokens[iJ]);
        tokens.append("\n");
    }
    lista.append(tokens);
    return lista;
}

QList<QString> analizador_sintactico::vanalisis_sintactico() {                   //Metodo principal del analizador sintactico
    int ip=0,i,j;
    int renglon, iast;
    char x[10], a[10];
    QList<QString> lista;

    insertapila("$");

    if(strcmp(asTokens[ip],"puts")== 0)
        insertapila("F");
    else
        insertapila("D");

    QString linea = "Expresion: \n";

    for(i = 0; i < cima ; i++) {
        linea.append(asTokens[i]);
        linea.append(" ");
    }

    lista.append(linea);

    do {
        strcpy(x,pilac[cima]);
        strcpy(a,asTokens[ip]);

        if(estoken(x) || (strcmp(x,"$")== 0)) //strcmp compara x y "$"
        {
            if(strcmp(x,a)==0) {
                eliminapila();
                ip++;
            } else {
                if(strcmp(asTokens[ip],"puts")==0)
                    insertapila("F");
                else
                    insertapila("D");

                strcpy(x,pilac[cima]);
            }

        } else {

            renglon = buscaTabla(a,x);
            QString linea;

            if(renglon != 999) {

                eliminapila();
                iast = 0;

                linea.append(varsint[tablaM[renglon][0]]);
                linea.append("-> ");

                for(j= 3; iast != 999; j++)
                {
                    iast = tablaM[renglon][j];  //999
                    if(iast < 0)
                    {
                        iast *= -1;
                        linea.append(token[iast]);
                        linea.append(" ");
                    }
                    else
                    {
                        if(iast !=999) {
                            linea.append(varsint[iast]);
                            linea.append(" ");
                        }
                    }
                }
                lista.append(linea);
                for(i = j-2; i > 2; i--)
                {
                    iast = tablaM[renglon][i];
                    if(iast < 0)
                    {
                        iast *= -1;
                        insertapila(token[iast]);
                    }
                    else
                        insertapila(varsint[iast]);
                }
            }
            else if (renglon == 999)
            {
                lista.append("Error de Sintaxis");
                return lista;
            }
        }
    } while(strcmp(x,"$")!= 0);

    return lista;
}

void analizador_sintactico::insertapila(string elem) { //Metodo para agregar un elemento a la pila

    if(cima == -1) {   //Si la cima es -1 significa que la pila esta vacia por lo tanto se iguala a 0 y se introduce un elemento en esa posicion
        cima = 0;
        strcpy(pilac[cima],elem.c_str());
      //string copy (x, y) copiar el contenido de y en x

    } else {

        if(cima == MAX - 1)     //Si la cima + 1 es igual a el tamaño maximo manda un mensaje de que la pila esta llena
            puts("Pila LLena");
        else {                  //Si todo esta bien, incrementa la cima y guarda la cadena en ese espacio
            cima++;
            strcpy(pilac[cima],elem.c_str());
        }
    }
}

void analizador_sintactico::eliminapila() {    //Metodo para eliminar de la pila 1 elemento

    if(cima == -1)      //Si la pila esta vacia solo se imprime eso
        puts("Pila Vacia");

    else {              //Se introduce una cadena vacia y se resta a la cima
        strcpy(pilac[cima],"");
        cima--;
    }
}

int analizador_sintactico::estoken(char x[]) {             //Metodo para determinar si el arreglo de caracteres (cadena) es un token
    for(int i = 0; i < 23; i++)
    {
        if(strcmp(x,token[i])==0)   //Compara la cadena con todos los terminales registrados en la gramatica en el arreglo "token"
            return 1;
    }

    return 0;
}

int analizador_sintactico::buscaTabla(char a[], char x[]) {
    int indx=0, inda=0, i;
    cout << "Buscando: " << a << " y " << x << endl;

    cout << "Pila actual: " ;
    for(i = 0; i < cima ; i++)
        cout << pilac[i];

    cout << endl;

    for(i = 0; i < 23; i++)             //Compara todos los terminales con a y si encuentra coincidencia guarda el indice del terminal
        if(strcmp(a,token[i])==0)
            inda = i;

    for(i = 0; i < 15; i++)             //Hace lo mismo con x en los no terminales y guarda en indx
        if(strcmp(x,varsint[i])==0)
            indx=i;

    for(i = 0; i < 51; i++)
        if(indx == tablaM[i][0])
            if(inda == tablaM[i][1])
                return i;

    return 999;
}



