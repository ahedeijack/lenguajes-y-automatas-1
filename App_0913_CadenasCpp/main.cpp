#include <iostream>

using namespace std;
#include<string.h>
#include<cstring>
int main()
{
    {
        /*
            char str1[12] = "Hello";
            char str2[12] = "World";
            char str3[12];
            int  len ;

            //strcpy(str3, str1);
            //printf("strcpy( str3, str1) :  %s\n", str3 );
            strncpy(str3, str1, strlen(str1));
            cout<<"strncpy(str3, str1): " <<str3 <<endl;



            strcat( str1, str2);
            printf("strcat( str1, str2):   %s\n", str1 );

            len = strlen(str1);
            printf("strlen(str1) :  %d\n", len );
            */
    }

    char texto[50];
    char opcion;
    do{
        cout<<"Escribe una cadena de Texto: ";
        //cin>>texto;
        cin.getline(texto, sizeof (texto));

        cout<<"El texto es: "<<texto <<endl;

        cout<<"Desea agregar otro texto? (S/N):  " <<endl;
        cin>>opcion;
        cin.get();

    } while (strchr("Ss", opcion));

    return 0;
}
