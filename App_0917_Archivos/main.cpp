// ejemplo1.c: Muestra un fichero dos veces.
#include <stdio.h>
#include<iostream>
using namespace std;
int main()
{
   FILE *fichero;

   fichero = fopen("C:\Users\Jesus\Downloads\BURBUJA.txt", "rt+");
   while(!feof(fichero))
       fputc(fgetc(fichero), stdout);
   rewind(fichero);

   cout<<endl;

   while(!feof(fichero))
       fputc(fgetc(fichero), stdout);
   fclose(fichero);
   //getchar();
   return 0;
}
