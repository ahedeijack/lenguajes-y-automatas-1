//#include <iostream>

//using namespace std;


#include "conjunto.h"



void menu(int &op) //REGRESA LA OPCION POR REFERENCIA
{
    do
    {
        cout<<"\n 1. Agregar "; //   +
        cout<<"\n 2. Borrar ";  //   -
        cout<<"\n 3. Mostrar ";
        cout<<"\n 4. Copiar ";
        cout<<"\n 5. Iguales ";//
        //if(set1.esIgual(set2) ...   if(set1 == set2)
        //USAR SOBRECARGA DE OPERADORES EN C++
        cout<<"\n 6. Interseccion ";
        cout<<"\n 7. Union ";
        cout<<"\n 8. Salir \n";
       cin>>op;
    }while(op < 1 || op > 8);
}



int main()
{
    Conjunto set1, set2, set3;
    int opc;
    set1.vacio();
    set2.vacio();
    set3.vacio();
    char resp = 's';
    while( resp == 's' || resp == 'S' )
    {
        menu(opc);
        switch(opc)
        {
          case 1:{
                   Mensaje mensaje;
                   int conj, val;
                   int cont = 0;
                   while(cont < 10)
                   {
                       cout<<"Conjunto (1,2) ? : ";
                       cin>>conj;
                       if(conj == 1)
                       {
                           cout<<"Valor : ";
                           cin>>val;
                           cout<<"VALOR PARA EL CONJUNTO "<< val <<" : "<<val<<endl;
                           mensaje = set1.agregarElemento(val);
                           //   mensaje = set1 + val; // APLICANDO SOBRECARGA
                           if(!mensaje)
                               cout<<"ESPACIO INSUFICIENTE "<<endl;
                           else if( mensaje == YAEXISTE)
                               cout<<"DATO YA EXISTE "<<val<<endl;
                           else
                               cout<<"Dato AGREGADO \n";
                       }
                       if(conj == 2)
                       {
                           cout<<"Valor : ";
                           cin>>val;
                           cout<<"VALOR PARA EL CONJUNTO "<<val<< " : "<<val<<endl;
                           mensaje = set2.agregarElemento(val);
                           //   mensaje = set2 + val; // APLICANDO SOBRECARGA
                           if(!mensaje)
                               cout<<"ESPACIO INSUFICIENTE "<<endl;
                           else if( mensaje == YAEXISTE)
                               cout<<"DATO YA EXISTE "<<val<<endl;
                           else
                               cout<<"Dato AGREGADO \n";
                       }
                       cont++;
                   }//FIN WHILE
                }
            break;
        case 2: {
            int conj, val;
            int cont = 0;
            cout<<"Elige el conjunto (1,2) ? : ";
            cin>>conj;
            if(conj == 1)
            {
                cout<<"Valor a borrar : ";
                cin>>val;
                cout<<"VALOR PARA BORRAR "<< val<<endl;
                set1.BorrarElemento(val);
                cout<<"VALOR " << val << " BORRADO"<<endl;
            }
            if(conj == 2)
            {
                cout<<"Valor a borrar : ";
                cin>>val;
                cout<<"VALOR PARA BORRAR:  "<< val<<endl;
                set1.BorrarElemento(val);
                cout<<"VALOR " << val << " BORRADO"<<endl;
            }
            cont++;
        }
            break;


        case 3: set1.mostrarElementos(" 1 ");
                set2.mostrarElementos(" 2 ");
            break;
        case 4: {
            int conj,conj2, val;
            int cont = 0;
            cout<<"Elige cual conjunto vas a copiar (1,2) ? : ";
            cin>>conj;
            cout<<"Elige a que conjunto vas a copiar (1,2) ? : ";
            cin>>conj2;
            if(conj == 1)
            {
                set1.copiar(&set2);
                cout<<"CONJUNTO"<< conj << " COPIADO AL CONJUNTO "<<conj2<<endl;
            }
            if(conj == 2)
            {
                set2.copiar(&set1);
                cout<<"CONJUNTO"<< conj << " COPIADO AL CONJUNTO "<<conj2<<endl;
            }
            cont++;
        }
            break;
        case 5: if(set1.Igual(&set2))  //  set1 == set2
                   cout<<"CONJUNTOS IGUALES "<<endl;
                else
                   cout<<"CONJUNTOS DIFERENTES "<<endl;
            break;

        case 6: {
            int conj,conj2;
            int cont = 0;
            cout<<"Elige cual conjunto (1,2) ? : ";
            cin>>conj;
            cout<<"Elige cual conjunto (1,2) ? : ";
            cin>>conj2;
            if(conj == 1)
            {
                set1.Interseccion(&set1, &set2);
                cout<<" CONJUNTO "<< &set1<<endl;
            }
            if(conj == 2)
            {
                set2.Interseccion(&set1, &set2);
                cout<<" CONJUNTO "<< &set2<<endl;
            }
            cont++;
        }
            break;

        case 7: {
            Mensaje mensaje;
            int conj, val;
            int cont = 0;
            cout<<"Conjunto (1,2) ? : ";
            cin>>conj;
            if(conj == 1)
            {
                cout<<"Valor : ";
                cin>>val;
                cout<<"VALOR PARA EL CONJUNTO "<< val<<endl;
                mensaje = set1.Union(&set2, &set3);
                if(!mensaje)
                    cout<<"ESPACIO INSUFICIENTE "<<endl;
                else if( mensaje == YAEXISTE)
                    cout<<"DATO YA EXISTE "<<val<<endl;
                else
                    cout<<" OK \n";
            }
            if(conj == 2)
            {
                cout<<"Valor : ";
                cin>>val;
                cout<<"VALOR PARA EL CONJUNTO "<<val<<endl;
                mensaje = set2.Union(&set1, &set3);
                if(!mensaje)
                    cout<<"ESPACIO INSUFICIENTE "<<endl;
                else if( mensaje == YAEXISTE)
                    cout<<"DATO YA EXISTE "<<val<<endl;
                else
                    cout<<" OK \n";
            }
            cont++;
        }
            break;

        case 8: exit(1);



        }//FIN DEL SWITCH
        cout << "Continuar (S/N) : ";
        cin>>resp;
    }//FIN DEL WHILE EXTERNO
    return 0;
}



/*#include "conjunto.h"


void menu(int &op)//REGRESA LA OPCION POR REFERENCIA
{
    do
    {
        cout<<"\n 1. Agregar "; //   +
        cout<<"\n 2. Borrar ";  //   -
        cout<<"\n 3. Mostrar ";
        cout<<"\n 4. Copiar ";
        cout<<"\n 5. Iguales ";// if(set1 == set2)
        //if(set1.esIgual(set2) ...
        //USAR SOBRECARGA DE OPERADORES EN C++
        cout<<"\n 6. Union ";
        cout<<"\n 7. Interseccion ";
        cout<<"\n 8. Salir \n";
       cin>>op;
    } while(op < 1 || op > 8);
}

int main()
{

    Conjunto set1, set2, set3;
    int opc;
    set1.vacio();
    set2.vacio();
    set3.vacio();
    char resp = 's';

    while( resp == 's' )
    {
        menu(opc);
        switch (opc)
        {
            case 1: {
                Mensaje mensaje;
                int conj, val;
                int cont = 0;
                while( cont < 10 ) {
                    cout<<"Conjunto (1,2) ? : ";
                    cin>>conj;
                    if ( conj == 1 )
                    {
                        cout<<"Dame el valor: ";
                        cin>>val;
                        cout<<"VALOR ASIGNADO PARA EL CONJUNTO "<< conj << " : "<< val <<endl;
                        mensaje = set1.agregarElementoProp(val);

                        if (!mensaje)
                            cout << "ESPACIO INSUFICIENTE "<<endl;
                        else if ( mensaje == YAEXISTE )
                            cout<<"DATO YA EXISTE "<< val<<endl;
                        else
                            cout<< "DATO AGREGADO \n";
                    }

                    if ( conj == 2 )
                    {
                        cout<<"Dame el valor: ";
                        cin>>val;
                        cout<<"VALOR ASIGNADO PARA EL CONJUNTO "<< conj << " : "<<endl;
                        mensaje = set2.agregarElementoProp(val);

                        if (!mensaje)
                            cout << "ESPACIO INSUFICIENTE "<<endl;
                        else if ( mensaje == YAEXISTE )
                            cout<<"DATO YA EXISTE "<< val<<endl;
                        else
                            cout<< "DATO AGREGADO \n";
                    }
                    cont++;
                } // FIN WHILE
            } // FIN CASE
            break;
        // case 2: BORRAR ELEMENTO

        case 3: set1.mostrarElementos(" 1 ");
            set2.mostrarElementos(" 2 ");
            break;
        // case 4:

        case 5: if ( set1.Igual( &set2 ) ) // set1 == set2
                    cout << "CONJUNTOS IGUALES "<<endl;
                else
                    cout<<"CONJUNTOS DIFERENTES "<<endl;
            break;

            // AGREGAR LOS QUE FALTAN

        case 8: exit(1);

        }
        cout<<"Continuar (s/N)";
        cin>>resp;
    } // FIN WHILE EXTERNO....



    return 0;
}*/



