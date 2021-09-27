#include <iostream>
#include <string.h>
#include <cstring>
using namespace std;

void esMay(char *cadena){
    for(int i = 0; i<sizeof (cadena);i++){
        if(cadena[i] >= 'a' && cadena[i] <= 'z'){
            char a = cadena[i] - 32;
            cout<<a;
        }
        else{
            cout<<cadena[i];
        }

    }
    cout<<endl;
}

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

int srchNombre(char nombre[][25], char *buscar,int n){
    int pos = -1;
    int i = 0;
    while(pos == -1 && i < n){
        if(strcmp(nombre[i],buscar)>0){
            pos = i;
        }
        i++;
    }
    return i;
}

int main(){
    char nombres[10][25] = {"Joaquin","El Chapo","Alejandro","Raul","BEATRIZ","AMLO","Hola","Carlos","Jazmin","Felix"};
    char apellidos[10][25] = {"PEREZ", "Sosa","Luna","Ciseña","Martinez","Jimenez", "Suarez","Vazquez","Castaleda","Esquivel"};

    for(int i = 0; i<10; i++){
        strncat(nombres[i]," ",sizeof (nombres[i]));
        strncat(nombres[i], apellidos[i], sizeof (nombres[i]));
        cout<<nombres[i]<<endl;
    }


    cout<<"Nombres en el arreglo: "<<endl;
    for(int i = 0; i < 10; i++){
        cout<<nombres[i]<<endl;
    }
    cout<<endl;

    cout<<"Nombres en el arreglo en mayusculas: "<<endl;
    for(int i = 0; i < 10;i++){
        esMay(nombres[i]);
    }
    cout<<endl;

    cout<<"Nombres ordenados descendente: "<<endl;
    BurbujaDsc(nombres, 10);
    for(int i = 0; i < 10; i++){
        cout<<nombres[i]<<endl;
    }
    cout<<endl;

    cout<<"Nombres ordenados ascendente: "<<endl;
    BurbujaAsc(nombres, 10);
    for(int i = 0; i < 10; i++){
        cout<<nombres[i]<<endl;
    }
    cout<<endl;

    char srch;
    cout<<"Que nombre quieres localizar?"<<endl;
    cin>>srch;

    string nombre;
    nombre = srch;

    int pos = srchNombre(nombres,&srch,10);
    cout<<"El nombre de "<<nombre <<", esta en la posicion  ("<<pos + 1 <<")"<<endl;


    return 0;
}
