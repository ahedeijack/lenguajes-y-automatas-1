#include <iostream>
using namespace std;
int iter;
int comp;
void insercion(int arr[], int n)
{
    cout<<"Inserción";
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key )
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void imprimirArreglo(int *vec, int n){
    for(int i = 0; i<n;i++)
        cout<<vec[i]<< " , ";
    cout<<endl;

}

void BurbujaDsc(int *vec, int n)
        {
    cout<<"Burbuja Desc";
            int comp = 0;
            int interc = 0;
            for (int i = 0; i < n-1-1; i++)
            {
                for (int j = n - 1; i < j; j--)
                {
                    comp++;
                    if (vec[j - 1] < vec[j])
                    {
                        int aux = vec[j - 1];
                        vec[j - 1] = vec[j];
                        vec[j] = aux;
                        interc++;
                    }
                }
            }
            printf("\nNo. de Comparaciones : %d ",comp);
            printf("\nNo. de intercambios  : %d \n", interc);

        }

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    iter++;
    if (low < high)
    {
        comp++;
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


int main(int argc, char *argv[])
{
    int vec1[] = {6,5,3,1,8,7,2,4};
    int vec2[] = {6,5,3,1,8,7,2,4};
    int vec3[] = {6,5,3,1,8,7,2,4};



    int n1 = sizeof(vec1) / sizeof(vec1[0]);
    int n2 = sizeof(vec1) / sizeof(vec1[0]);
    int n3 = sizeof(vec1) / sizeof(vec1[0]);

    cout<<"Datos en el Arreglo: "<<endl;
    imprimirArreglo(vec1,n1);

    insercion(vec1,n1);
    imprimirArreglo(vec1,n1);

    cout<<"Datos en el Arreglo: "<<endl;
    imprimirArreglo(vec2,n1);

    BurbujaDsc(vec2,n2);
    imprimirArreglo(vec2,n2);

    cout<<"Datos en el Arreglo: "<<endl;
    imprimirArreglo(vec3,n3);

    cout<<"Quicksort" <<endl;
    quickSort(vec3,0,n3-1);
    imprimirArreglo(vec3,n3);
    cout<<"Comparaciones: "<<comp <<endl;
    cout<<"Iteraciones: "<<iter <<endl;
    return 0;

}
