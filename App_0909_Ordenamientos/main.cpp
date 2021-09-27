#include <QCoreApplication>
#include <iostream>
using namespace std;



void insercion(int arr[], int n)
{
    int i, key, j;
    int com, interc;
    com = interc = 0;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        com++;
        while (j >= 0 && arr[j] > key )
        {
            arr[j + 1] = arr[j];
            j = j - 1;
            interc++;
        }
        arr[j + 1] = key;

    }
    printf("Número de cmparaciones: %d", com);
    cout<<"Número de intercambios: "<<interc <<endl;
}

void burbuja(int arr[], int n){
    float aux;

    for(int i = 0; i < n; i++) {
        for(int j = 1; i<n; i++){
            if(arr[i] > arr[j]){
                    aux = arr[i];
                    arr[i]=arr[j];
                    arr[j] = aux;
        }
        }
    }
}

void imprimirArreglo(int *vec, int n){
    for(int i =0; i<n; i++){
        cout<<vec[i]<<" , ";
    }
    cout<< endl;
}

int main()
{
    int vec[] = {6,5,3,1,8};//,7,4};

    int n = sizeof (vec) / sizeof (vec[0]);
    cout<<"Datos en el arreglo" <<endl;
    cout<<"Valor de N :"<<sizeof (vec) <<"/" <<sizeof (vec[0]) <<" = " <<n <<endl;
    imprimirArreglo(vec, n);
    //insercion(vec, n);
    burbuja(vec, n);
    cout<<"Arreglo ordenado: "<<endl;
    imprimirArreglo(vec, n);
}
