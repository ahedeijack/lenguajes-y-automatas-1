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


class pilaChar
{
  char []vec;
  //int tam;
  int tope;
  boolean vacia;
  boolean llena;
  public pilaChar(int n)
  {
      //tam = n;
      vec = new char[n];
      tope= 0;
      vacia = true;
      llena = false;  
  }
  public void push(char valor)
  {
      vacia = false;
      vec[tope++]= valor;
      if( tope == vec.length)   //tam)      
        llena = true;

  }
  public char pop()
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
}
