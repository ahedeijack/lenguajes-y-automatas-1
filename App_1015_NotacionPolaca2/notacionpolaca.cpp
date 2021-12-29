#include "notacionpolaca.h"

NotacionPolaca::NotacionPolaca()
{

}

string NotacionPolaca::convertirAPosFija(string EI)
{
    //char *Epos = new char[EI.length()];
    string Epos(EI.length(), '\0');
    pilaT<int> *stack = new pilaT<int>(EI.length());
    //La pila debe ser al menos de la cantidad de operadores en la expresion
    //Por lo tanto crear un metodo donde se analice la exp. infija y se determina
    //la cantidad de operadores a utilizar en el tamaño de la pila.
    //EJ: (7+8)-6*5pow2
    //Se requieren dos variables para el recorrido, una para el analisis y otra para la insercion en pos
    int i,pos=0;
    for(i=0; i<(int)EI.length(); i++){
        char car = EI[i];
        Simbolo actual = tipoYPrecedencia(car);
        switch (actual){
            case OPERANDO:Epos[pos++]=car;
            break;
            case SUMRES: {
                while(!stack->estaVacia() && tipoYPrecedencia((char)stack->Tope()) >= actual){
                    Epos[pos++] = (char)stack->pop();
                }
                stack->push(car);
            }
            break;
            case MULTDIV: {
                while(!stack->estaVacia() && tipoYPrecedencia((char)stack->Tope()) >= actual){
                    Epos[pos++] = (char)stack->pop();
                }
                stack->push(car);
            }
            break;
            case POW: {
                while(!stack->estaVacia() && tipoYPrecedencia((char)stack->Tope()) >= actual){
                    Epos[pos++] = (char)stack->pop();
                }
                stack->push(car);
            }
            break;
            case PIZQ: stack->push(car);
            break;
            case PDER: {
                char x = (char)stack->pop();
                while(tipoYPrecedencia(x) != PIZQ) {
                    Epos[pos++] = x;
                    x = (char)stack->pop();
                }
            }
            break;
        }
    }

    while(!stack->estaVacia()){
        if(pos < (int)EI.length())
            Epos[pos++] = (char)stack->pop();
        else
            break;
    }

    delete stack;//Se agregó para evitar el warning Potential leak of memory de Stack

    Epos[pos] = '\0';
    return Epos;
}

Simbolo NotacionPolaca::tipoYPrecedencia(char s)
{
    Simbolo simbolo;
    switch(s)
    {
        case '+': //simbolo = SUMRES;
        case '-': simbolo = SUMRES;
            break;
        case '*':
        case '/': simbolo = MULTDIV;
            break;
        case '^': simbolo = POW; break;
        case '(': simbolo = PIZQ; break;
        case ')': simbolo = PDER; break;
        default: simbolo = OPERANDO; break;
    }
    return simbolo;
}

void NotacionPolaca::ajusteExpresion(string &exp, int &nope)
{
    int i=0,cont=0;
    while(exp[i] != '\0'){
        if(exp[i] == ' '){
            cont++;
            for(int j=i; j<(int)exp.length()-cont; j++){
                exp[j] = exp[j+1];
            }
            exp[(int)exp.length()-cont] = '\0';
        }
        if(tipoYPrecedencia(exp[i]) != OPERANDO){
            nope++;
        }
        i++;
    }
}
char* NotacionPolaca::ajusteExpresion2(string &exp, int &nope)
{
    char *Einf = new char[exp.length()-1];
    int i=0,pos=0;
    while(exp[i] != '\0'){
        if(exp[i] != ' '){
            Einf[pos] = exp[i];
            Einf[++pos] = '\0';

            if(tipoYPrecedencia(exp[i]) != OPERANDO)
                nope++;
        }
        i++;
    }
    return Einf;
}

float NotacionPolaca::conversion(char s)
{
    float res = s - 0x30;
    return res;
}

float NotacionPolaca::solucionPost(string EP)
{

    pilaT<float> *operandos = new pilaT<float>((int)EP.length());

    int i=0;
    float res=0,a=0,b=0;

    while(EP[i] != '\0'){
        if(EP[i] >= '0' && EP[i] <= '9' ){
            if(tipoYPrecedencia(EP[i]) == OPERANDO){
                operandos->push(conversion(EP[i]));
            }else{
                switch(EP[i]){
                case '+':{
                    b=operandos->pop();
                    a=operandos->pop();
                    res =a+b;
                }
                break;
                case '-':{
                    b=operandos->pop();
                    a=operandos->pop();
                    res = a-b;
                }
                break;
                case '*':{
                    b=operandos->pop();
                    a=operandos->pop();
                    res =a*b;
                }
                break;
                case '/':{
                    b=operandos->pop();
                    a=operandos->pop();
                    res = a/b;
                }
                break;
                case '^':{
                    b=operandos->pop();
                    a=operandos->pop();
                    res = pow(a,b);
                }
                break;
                }
                operandos->push((float)res);
            }
        i++;
        }else{
            delete operandos;
            return 0x20;
        }
    }
    res = (float)operandos->pop();
    delete operandos;
    return res;
}
