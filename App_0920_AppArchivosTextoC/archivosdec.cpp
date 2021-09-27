#include "archivosdec.h"
ArchivosDeC::ArchivosDeC()
{


}

void ArchivosDeC::abrir(char *nomArch, char cadenas[][25],int &cant){
    FILE *parchivo;
    char *cadena = new char [25];
    int i = 0;
    if ((parchivo = fopen(nomArch, "r")) == nullptr){
        printf("\n ERROR SL SBRIR EL ARCHIVO \n");
    } else {
        while (!feof(parchivo)) {
            printf("\n LEYENDO DESDE EL METODO ABRIR \n");
            while(fgets(cadena, 25, parchivo)){
                printf("%s", cadena);
                strcpy(cadenas[i], cadena);
                //strcpy_s(cadenas[i], cadena);
                i++;
           }
        }
    }
    cant = i;
    fclose(parchivo);

//Leer FGET y FPUT
}

void ArchivosDeC::guardar(char *nomArch, char (*cadenas)[25]){

    FILE *parchivo;
    int i = 0;
    if ((parchivo = fopen(nomArch, "w"))){ //Es una coomparación implicita con null

        printf("\n Estemamos utilizando el metodo Guardar.\n");

        while(strcmp(cadenas[i], "\0") != 0){
            strcat(cadenas[i], "\n");
            fputs(cadenas[i], parchivo); //Escribe en archivo.

            puts(cadenas[i]); //Escribe en consola
            //rintf("%s", cadenas[i]);

            i++;
        }
    } else {
        puts("\nError al abrir el archivo, o el archivo no se encontro.");
    }

    fclose(parchivo);

}

void ArchivosDeC::agregar(char *nomArch, char (*cadenas)[25]){

    FILE *parchivo;
    int i = 0;
    if ((parchivo = fopen(nomArch, "a+t"))){ //Es una coomparación implicita con null

        printf("\n Estemamos utilizando el metodo Agregar.\n");

        while(strcmp(cadenas[i], "\0") != 0){

            fputs(cadenas[i], parchivo); //Escribe en archivo.

            puts(cadenas[i]); //Escribe en consola
            //rintf("%s", cadenas[i]);

            i++;
        }
    } else {
        puts("\nError al abrir el archivo, o el archivo no se encontro.");
    }

    fclose(parchivo);

}

