#include <iostream>

using namespace std;

#include "archivosdec.h"

//COPIAR EL METODO DE LA BURBUJA QUE ORDENA CADENAS
void BurbujaDsc(char vec[50][25], int n)
        {
            /*int comp = 0;
            int interc = 0;
            comp = interc = 0;
            */
            for (int i = 0; i < n-1; i++)
            {
                for (int j = n - 1; i < j; j--)
                {
                    //comp++;
                    //if (vec[j - 1] < vec[j])
                    if(strcmp(vec[j-1],vec[j])<0)
                    {
                        //int aux = vec[j - 1];
                        char *cadaux = new char[10];
                        //vec[j - 1] = vec[j];
                        strcpy(cadaux,vec[j-1]);
                        //vec[j] = aux;
                        strcpy(vec[j-1],vec[j]);
                       // interc++;
                        strcpy(vec[j],cadaux);
                    }
                }
            }

        }


int main()
{
    //copiar aqui el arreglo de nombres que se uso en la evaluacion
    char nombres[10][25] = {"Juan","Juana","Carlos","ALMA","ana","Jose","Luis","LUISA","BEATRIZ","SAra"};
    char apellidos[10][25]= {"PEREZ","LOPEZ","CISENA","RUIZ","RIOS","ALCALA","CASTANEDA","ESQUIVEL","RIVERA","GIL"};

    //for(int i = 0; strcmp(nombres[i],"\0") != 0 ; i++)
      //  cout<<nombres[i]<<endl;

    string nomarch, path;
    cout<<"NOMBRE DEL ARCHIVO (sin extension) : ";
   // getline(cin,nomarch,'\n');
    //cin.getline(nomarch,'\n');
    cin>>nomarch;
    nomarch += ".txt";

    //path = "/Users/martinvaldes/Desktop/";   // UNIX'LIKE

    path = "c:\\users\\mosva\\desktop\\";
    path += nomarch;

    ArchivosDeC archivo;  //OBJETO ESTATICO
    //ArchivosDeC *archivo1 = new ArchivosDeC();  // OBJETO DINAMICO

    //COMO SE CAPTURO con string hay que cambiarlo a char[]

    char narch[100];
    strncpy(narch, path.c_str() ,sizeof(narch));
    archivo.guardar(narch,nombres);


    cout<<"\n CONTENIDO DEL ARCHIVO alumnos.txt"<<endl;
    //archivo.abrir(narch);

    char nomsEnArchivo[50][25]; // PARA DEJAR EN ESTE ARREGLO LOS DATOS DEL ARCHIVO
    int cantNombres;
    archivo.abrir(narch,nomsEnArchivo,cantNombres);
    cout<<"\n\t\a\a NOMBRES EN EL ARREGLO BIDIMENSIONAL  "<<endl;
    for(int ren = 0; ren < 10 /*strcmp(nomsEnArchivo[ren],"\0") != 0*/; ren++)
        cout<<"Nombre [ "<<ren<<" ] "<<nomsEnArchivo[ren]<<endl;
 //PROBAR EL METODO AGREGAR

   // string path2 = "/Users/martinvaldes/Desktop/";
   // string path2 = "C:\\Users\\mosva\\Desktop\\";
   // path2+= "nombres.txt";

   // char narch2[100];
   // strncpy(narch2, path2.c_str() ,sizeof(narch));
    archivo.agregar(narch,apellidos);//10

    archivo.abrir(narch,nomsEnArchivo,cantNombres);
    cout<<"\n\t\a\a NOMBRES AGREGADOS EN EL ARREGLO BIDIMENSIONAL  "<<endl;
    for(int ren = 0; ren < 20/*strcmp(nomsEnArchivo[ren],"\0") != 0*/; ren++)
        cout<<"Nombre [ "<<ren<<" ] "<<nomsEnArchivo[ren]<<endl;

    //ORDENAR LOS NOMBRES DEL ARCHIVO

    BurbujaDsc(nomsEnArchivo,20);//cantNombres);
    cout<<"\a\a\a\a \tNOMBRES ORDENADOS "<<endl;
    for(int ren = 0; ren < 20 /*strcmp(nomsEnArchivo[ren],"\0") != 0*/; ren++)
        cout<<"Nombre [ "<<ren<<" ] "<<nomsEnArchivo[ren]<<endl;





    return 0;
}
