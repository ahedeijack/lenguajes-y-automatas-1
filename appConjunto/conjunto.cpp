#include "conjunto.h"

Conjunto::Conjunto()
{

}

Mensaje Conjunto::agregarElemento(int e)
{
    if(Pertenece(e))
        return YAEXISTE;
    if(numElementos < MAX)
    {
        elementos[numElementos++] = e;
        return OK;
    }
    return OVERFLOW;
}

/*Mensaje Conjunto::agregarElementoProp(int e)
{
   if ( elementos[MAX] != numElementos )
   {
        if ( elementos[MAX] == e ) {
            cout<<"ELEMENTO YA EXISTE, VALOR DUPLICADO."<<endl;
            return YAEXISTE;
        }
        cout<<"El elemento no se puede añadir, OVERFLOW"<<endl;
        return OVERFLOW;
   }
    elementos[MAX] = e;
   return OK;
}*/

Mensaje Conjunto::agregarElementoProp(int e)
{
    // numElementos < MAX
    if ( MAX > numElementos )
        return OVERFLOW;
    else
        for ( int elem = 0; elem < numElementos; elem++ )
            if ( e == elementos[elem] )
                return YAEXISTE;

    elementos[numElementos++] = e;
    return OK;
}



bool Conjunto::Pertenece(const int e)
{
    for(int i = 0; i < numElementos; i++)
        if(elementos[i] == e)
            return true;
    return false;
}

// BORRAR
void Conjunto::BorrarElemento(int e)
{
        for(int i = 0; i < numElementos; ++i)
            if ( elementos[i] == e ) {
                for(; i < numElementos -1; i++)
                    elementos[i] = elementos[i+1];
                --numElementos;
            }
}

void Conjunto::mostrarElementos(string set)
{
    cout<<"\a\a\t CONJUNTO "<<set<<endl;
    cout<<"{ ";
    int i;
    for( i = 0; i < numElementos - 1; i++ )
        cout<<elementos[i]<<" , ";
    if ( numElementos > 0 )
        cout<<elementos[i];
    cout<<" }"<<endl;
}

void Conjunto::copiar(Conjunto *set)
{
    for(int i = 0; i < this->numElementos; i++)
        set->elementos[i] = this->elementos[i];
    set->numElementos = numElementos;
}

bool Conjunto::Igual(Conjunto *set) const
{
    int i;
    if( numElementos == set->numElementos )
        return true;
    for ( i = 0; i < numElementos; i++ )
        if( set->Pertenece(this->elementos[i]) )
            return true;
    return false;
}

bool Conjunto::operator ==(Conjunto *set ) const
{
    if ( this->numElementos != set->numElementos )
        return false;

}

void Conjunto::Interseccion( Conjunto *setB, Conjunto *setC )
{
    int i, j;
    setC->numElementos = 0;
    for(i = 0; i < numElementos; i++)
        for ( j = 0; j < setB->numElementos; j++ )
            if( elementos[i] == setB->elementos[j] ) {
                setC->agregarElementoProp( this->elementos[i] );
                break;                                              //setC->elementos[setC->numElementos++] = this->elementos[i];
            }
}

Mensaje Conjunto::Union(Conjunto *s2, Conjunto *s3){
    s2->copiar(s3);
    for(int i = 0; i < numElementos; ++i)
        if(s3->agregarElemento(elementos[i]) == OVERFLOW)
            return OVERFLOW;
    return OK;
}




