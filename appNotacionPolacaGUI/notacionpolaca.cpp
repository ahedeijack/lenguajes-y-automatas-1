#include "notacionpolaca.h"

//#include "pilat.cpp"

NotacionPolaca::NotacionPolaca()
{

}

char *NotacionPolaca::ConvertirAPosFija(string EI)
// TAREA
//string NotacionPolaca::ConvertirAPosFija(string EI)


{
    char *Epos = new char[EI.length()];

    //LA PILA DEBE SER AL MENOS DE LA CANTIDAD DE OPERADORES EN LA EXPRESION POR LO TANTO

    pilaT<int> *stack = new pilaT<int>(EI.length());
//TAREA
    //CREAR UN METODO DONDE SE ANALICE LA EXP. INFIJA Y SE DETERMINE LA CANTIDAD DE OPERADORES
        //A UTILIZAR EN EL TAMAÑO DE LA PILA.
        //EJ: (7+8)-6*5^2  LA PILA DEBE SER DE TAMAÑO 5

        //SE REQUIEREN DOS VARIABLES PARA EL RECORRIDO, UNA PARA EL ANALISIS Y OTRA PARA LA INSERCION DE EPOS

        int i, pos = 0;
        for(i = 0; i < (int)EI.length(); i++)
        {
            char car = EI[i];
            Simbolo actual = tipoYPrecedencia(car);
            switch (actual)
            {
                case OPERANDO: Epos[pos++]=car;
                     break;
                case SUMRES:{
                  while(!stack->estaVacia() && tipoYPrecedencia((char)stack->Tope()) >= actual )
                      Epos[pos++] = (char)stack->pop();
                  stack->push(car);
                 }
                break;

                case MULTDIV:{
                   while(!stack->estaVacia() && tipoYPrecedencia((char)stack->Tope()) >= actual )
                     Epos[pos++] = (char)stack->pop();
                   stack->push(car);
                }
                break;
                case POW:{
                   while(!stack->estaVacia() && tipoYPrecedencia((char)stack->Tope()) >= actual )
                     Epos[pos++] = (char)stack->pop();
                   stack->push(car);
                }
                break;
            case PIZQ:  stack->push(car);
                break;
            case PDER:{
                    char x = (char)stack->pop();
                    while (tipoYPrecedencia(x) != PIZQ)
                    {
                        Epos[pos++] = x;
                        x = (char)stack->pop();
                    }
              }
                //break;
            }//FIN DEL SWITCH
        }// FIN DEL for
        while (!stack->estaVacia())
        {
            if(pos < (int)EI.length())
                Epos[pos++] = (char)stack->pop();
            else
                break;
        }
        Epos[pos]='\0';//LAS CADENAS DE C/C++ TERMINAN EN NULO = '\0'
        return Epos;

}

Simbolo NotacionPolaca::tipoYPrecedencia(char s)
{
    Simbolo simbolo;
    switch(s)
    {
       case '+': //simbolo = SUMRES;break;
       case '-': simbolo = SUMRES;
                 break;
       case '*':
       case '/': simbolo = MULTDIV;
                 break;
       case '^': simbolo = POW; break;
       case '(': simbolo = PIZQ; break;
       case ')': simbolo = PDER;break;

       default : simbolo = OPERANDO; break;
    }
    return simbolo;
}
//TAREA PARA EL DOMINGO
// AGREGAR EL METODO PARA RESOLVER UNA EXPRESION MATEMATICA EXPRESADA EN NOTACION POLACA




