#include "tabladesimbolos.h"

TablaDeSimbolos::TablaDeSimbolos(int sz){
    if(sz <= 0){
        size = 0;
        tabla = NULL;
    } else if((tabla = new Symbol*[size = sz]) != NULL) {
        for(int i = 0; i<size; i++){
            tabla[i] = NULL;
        }
    } else {
        size = 0;
    }
}

int TablaDeSimbolos::Hash(char *cadena){ //Cadena = "var1"

    int slot = 0;
    while (*cadena) {
        slot += * cadena++;
    }

    return slot % size; //¿Que regrsa el método?
}

Symbol *TablaDeSimbolos::AddSym(char *cadena, SymValue valor){
    Symbol *sym;

    //indice para el arreglo de punteros.
    int slot = Hash(cadena);

    if((sym = new Symbol) != NULL && (sym->nombre = new char[strlen(cadena)+1]) != NULL){
        //Implementar el código necesario para insrtar un symbolo en la tabla de simbolos.
        //cout<<sym<<endl;
        strcpy(sym->nombre, cadena);
        sym->valor = valor;
        sym->next = tabla[slot];
        tabla[slot] = sym;
        return sym;

    } else {
        delete sym;
        sym = NULL;

    }
    return NULL;

}

Symbol *TablaDeSimbolos::FindSym(char *cadena){

    int slot = Hash(cadena);
       Symbol *sym= tabla[slot];
       for(; sym ; sym = sym->next )
           if(strcmp(sym->nombre,cadena) == 0 )
               break;
       return sym;
}

bool TablaDeSimbolos::RemoveSymbol(char *cadena){

    int slot = Hash(cadena);
    Symbol *sym = tabla[slot];
    string aux = sym->nombre;

    if (sym && strcmp(sym->nombre, cadena) == 0){
        tabla[slot] = sym->next;
        delete sym;
        return true;
    }

    for(sym = tabla[slot]; sym->next; sym = sym->next){
        if(strcmp(sym->next->nombre, cadena) == 0){
            Symbol *temp = sym->next;
            sym->next = sym->next->next;
            delete temp;
            return true;
        }
        return false;
    }

}

void TablaDeSimbolos::ImprimirTabla(){
    for(int i = 0; i<size; i++){
        for(Symbol *sym = tabla[i]; sym ; sym = sym->next){
            cout<<sym<<setw(20)<<sym->nombre<<setw(10)<<sym->valor<<setw(15)<<"Next: "<<hex<<sym->next<<dec<<endl;
        }
        }

        }

bool TablaDeSimbolos::setValue(char *cad, SymValue val){
                  Symbol *simbolo = FindSym(cad);
                  if(simbolo = NULL){
                  return AddSym(cad, val) != NULL;
        } else {
                  simbolo->valor = val;
        }
                  return true;
}

bool TablaDeSimbolos::getValue(char *cad, SymValue *val)
{
Symbol *simbolo = FindSym(cad);
    if(simbolo != NULL){
        *val = simbolo->valor;
    }
    return simbolo != NULL;


}

