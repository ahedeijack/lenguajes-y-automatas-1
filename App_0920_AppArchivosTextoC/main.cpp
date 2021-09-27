#include <iostream>
#include<string.h>
#include "ArchivosDeC.h"
using namespace std;

//Copiar metodo burbuja de cadenas

void BurbujaDsc(char vec[][25], int n){
            int comp = 0;
            int interc = 0;
            for (int i = 0; i < n-1-1; i++){
                for (int j = n - 1; i < j; j--){
                    comp++;
                    if (strcmp(vec[j - 1],vec[j]) > 0){
                        char aux[25];
                        strcpy(aux,vec[j-1]);
                        strcpy(vec[j - 1], vec[j]);
                        strcpy(vec[j],aux);
                        interc++;
                    }
                }
            }
            printf("\nComparaciones : %d ",comp);
            printf("\nIntercambios  : %d \n", interc);
        }

void BurbujaAsc(char vec[][25], int n){
            int comp = 0;
            int interc = 0;
            for (int i = 0; i < n-1-1; i++){
                for (int j = n - 1; i < j; j--){
                    comp++;
                    if (strcmp(vec[j - 1],vec[j]) < 0){
                        char aux[25];
                        strcpy(aux,vec[j-1]);
                        strcpy(vec[j - 1], vec[j]);
                        strcpy(vec[j],aux);
                        interc++;
                    }
                }
            }
            printf("\nComparaciones : %d ",comp);
            printf("\nIntercambios  : %d \n", interc);
        }

int main()
{
    cout << "Hello World!" << endl;
    char nombres[10][25] = {"Joaquin","El Chapo","Alejandro","Raul","BEATRIZ","AMLO","Hola","Carlos","Jazmin","Felix"};
    char apellidos[10][25] = {"PEREZ", "Sosa","Luna","Ciseña","Martinez","Jimenez", "Suarez","Vazquez","Castaleda","Esquivel"};
    //copiar el arreglo de nombres

     for( int i = 0; strcmp(nombres[i],"\0"); i++){
         cout<<nombres[i]<<endl;
     }

    string nomarch, path;
    cout<<"Nombre del archivo sin extensión:"<<endl;
    getline(cin, nomarch, '\n');

    nomarch+=".txt";

    //path = "C:/Users/betto/Desktop";
    path += nomarch;

    ArchivosDeC archivo;
    //ArchivosDeC *archivo1 = new ArchivosDeC();

    //Como se capturo con string, hay que cambiarse a char[]

    char narch[100];
    strncpy(narch, path.c_str(), sizeof(narch));
    archivo.guardar(narch,nombres);
    return 0;

}
