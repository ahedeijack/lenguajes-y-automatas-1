#include "archivosdec.h"

ArchivosDeC::ArchivosDeC()
{

}

void ArchivosDeC::abrir(char *nomArch)
{
    FILE *parchivo;
    char *cadena = new char[25];

    if((parchivo = fopen(nomArch,"r"))== nullptr)//NULL
        printf("\n ERROR al abrir el archivo. \n");
    else
    {
        while(!feof(parchivo))
        {
            printf("\n LEYENDO DESDE EL METODO ABRIR (O LEER) \n");
            while(fgets(cadena,25,parchivo))
            {
                printf("%s",cadena);
            }
       }
    }

    fclose(parchivo);

}
                //leer
void ArchivosDeC::abrir(char *nomArch, char cadenas[][25], int &cant)
{
   FILE *parchivo;
   char *cadena = new char[25];
   int i = 0;
   if((parchivo = fopen(nomArch,"r"))== nullptr)//NULL
       printf("\n ERROR al abrir el archivo. \n");
   else
   {
       while(!feof(parchivo))
       {
           printf("\n LEYENDO DESDE EL METODO ABRIR (O LEER) \n");
           while(fgets(cadena,25,parchivo))
           {
               printf("%s",cadena);
              // strncpy(cadenas[i],cadena, sizeof(cadena));
               strcpy_s(cadenas[i],cadena);
               i++;
           }
      }
   }
   cant = i;
   fclose(parchivo);
}

void ArchivosDeC::guardar(char *nombArch, char cadenas[][25])
{
    FILE *parchivo;
    int i = 0;
    if((parchivo = fopen(nombArch,"w")))  // ESTA IMPLICITO LA COMP. CON NULL
    {
       printf("\n dentro del METODO GUARDAR \n");
       while(i < 10)//strcmp(cadenas[i],"\0") != 0)
       {
           //strcat(cadenas[i],"\n");
          /* fputs(cadenas[i],parchivo);
           fputs("\n",parchivo);

           //puts(cadenas[i]);
           printf("%s\n",cadenas[i]);
          */


           strcat(cadenas[i],"\n");
           fprintf(parchivo,"%s",cadenas[i]);
           printf("%s\n",cadenas[i]);
           i++;
       }
    }
    else
    {
        puts("\n ERROR AL ABRIR EL ARCHIVO o EL ARCHIVO NO SE ENCOTRO ");
    }

    fclose(parchivo);

}

void ArchivosDeC::agregar(char nombArch[], char cadenas[][25])
{
    FILE *parchivo;
    int i = 0;     // esta implicito la t :  at+,  a+t
    if((parchivo = fopen(nombArch,"at+")) != nullptr)  // EXPLICITA LA COMP. CON NULL
    {
       printf("\n dentro del METODO AGREGAR \n");
       while(i < 10)//strcmp(cadenas[i],"\0") != 0)
       {
           /*strcat(cadenas[i],"\n");
           fputs(cadenas[i],parchivo);
           //fputs("\n",parchivo);
           //puts(cadenas[i]);
           printf("%s",cadenas[i]);
           */
           strcat(cadenas[i],"\n");
           fprintf(parchivo,"%s",cadenas[i]);
           printf("%s\n",cadenas[i]);
           i++;
       }
    }
    else
    {
        puts("\n ERROR AL ABRIR EL ARCHIVO o EL ARCHIVO NO SE ENCOTRO ");
    }
    fclose(parchivo);
}
