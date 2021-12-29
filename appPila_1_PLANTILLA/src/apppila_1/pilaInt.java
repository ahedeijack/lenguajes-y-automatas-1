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

class pilaInt
{
  private int []vec;
  //int tam;
  private int tope;
  private boolean vacia;
  boolean llena;
  public pilaInt(int n)
  {
     // tam = n;
      vec = new int[n];
      tope= 0;
      vacia = true;
      llena = false;  
  }
  public void push(int valor)
  {
      vacia = false;
      vec[tope++]= valor;
      if( tope == vec.length)   //tam)      
        llena = true;
  }
  public int pop()
  {
    if(--tope == 0)
       vacia = true;
    llena = false;
    return vec[tope];
  }

    public boolean estaVacia()
    {
       return vacia;
    }
  public boolean esta_Llena()
  {
      return llena;
  } 
  public void mostrar()
  {
  
    System.out.println("\nDatos en la pila : \n"); 
    for(int i = 0; i < tope; i++)//<--
    {
        System.out.println("\n Dato[ "+i+" ] -> " + vec[i]);
    }
  }
  
}
