/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package apppila_1;

/**
 *
 * @author martinvaldes
 */
//public class pilaGenerica {
//    
//}

// CLASE GENERICA O TEMPLATE
//class template<T>  // C++
public class pilaGenerica<T>
{
          //Vec es el contenedor 
          Object []vec;//UTILIZAR TIPO OBJECT EN LAS PLANTILLAS
                                        //int tam; //NO APLICA, SOLO SE DEBEN UTILIZAR OBJETOS
          int tope;
          boolean vacia;
          boolean llena;
          public pilaGenerica(int n)
          {
            vec = new Object[n];
            tope= 0;
            vacia = true;
            llena = false;  
         }
         public void push(T valor)
         {
             vacia = false;
             if (!llena)//   if(!esta_llena())
             {
                 vec[tope++] = valor;
             }
             if( tope == vec.length)
                llena = true;
         }
         
         public T pop()
         {
            if(--tope == 0)
              vacia = true;
            llena = false;
            return (T)vec[tope];
            //  Object aux = vec[tope];
            //  return (T)aux;
         }
         public boolean estaVacia()
         {
             return vacia;
         }
         public boolean estaLlena()
         {
            return llena;
         }

         public boolean getLlena()
        {
             return llena; 
        }
        public boolean getVacia()
        {
            return vacia;
        }

}
