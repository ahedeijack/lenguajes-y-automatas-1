/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package apppila_1;

import java.util.Random;
import java.util.Scanner;
import java.util.Stack;

/**
 *
 * @author martinvaldes
 */
public class AppPila_1 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        //DISEÑAR LA APP. UTILIZANDO UN MENU  
        
          Random r = new Random();
       /*
          pilaInt pila = new pilaInt(r.nextInt(6)+5);//Construimos una Pila con 5 elementos
          //Podemos solicitar este dato al usuario
          System.out.println("\t Introduciendo datos en la pila ");
                      
          while (!pila.esta_Llena())  
          {
              int dato = r.nextInt(90)+10;
              System.out.println("Valor introducido en la pila >>> "+dato);
              pila.push(dato); //pila.push(i);
          }
          System.out.println("\n\t Extrayendo datos de la pila ");
          while (!pila.estaVacia())
          {
              int dato = pila.pop();
              System.out.println( dato + " <<< Dato extraido de la pila " );
          }
          */
          
          //DISEÑAR LA APP. UTILIZANDO EL MENU
         /*   int d,op;
            Numero numero = new Numero();
            pilaInt pila = new pilaInt(3);
            Menu menu=new Menu(); 
            Scanner scan = new Scanner(System.in);
            boolean band=true; 
            while(band)
            {
                op = menu.opciones(); 
                switch(op)
                {
                    case 1: 
                        {
                          System.out.println(" Dato : ");
                          d = scan.nextInt(); 
                          if(!pila.esta_Llena()) 
                          {
                            pila.push(d);  
                            System.out.println(" OK, DATO INSERTADO EN LA PILA ");
                            pila.mostrar();
                          } else
                          System.out.println(" Desbordamiento (Overflow) "); 
                        }
                        break; 
                    case 2: {//MAÑANA EXAMEN DE RECURSIVIDAD
                              if(!pila.estaVacia()) 
                              {
                                  d = pila.pop();// pila.pop(numero)
                                  System.out.println("\n Dato eliminado : " + d);
                                  pila.mostrar(); 
                              }
                              else
                                 System.out.println(" Pila vacia (Underflow)");
                            } 
                            break;
                    case 3: band = false;
                }
            }
              
             */
          
          
          
          
          /*
              pilaChar pilaC = new pilaChar(('Z' - 'A')+1);//Construimos una Pila con 5 elementos
              //Podemos solicitar este dato al usuario
              System.out.println("\t Introduciendo datos en la pila ");
              char letra = 'A';
              while (!pilaC.esta_Llena())  
              {
                  
                 System.out.println("Valor introducido en la pila >>> "+letra);
                  pilaC.push(letra); //pila.push(i);
                  letra++;
              }
              System.out.println("\n\t Extrayendo datos de la pila ");
              while (!pilaC.estaVacia())
              {
                  char dato = pilaC.pop();
                  System.out.println( dato + " <<< Dato extraido de la pila " );
              }
            */ 
            
             
             /*
              Random ran = new Random();
              pilaGenerica<Integer> pilaI = new pilaGenerica<Integer>(ran.nextInt(5)+5);//Construimos una Pila con 5 elementos
              //Podemos solicitar este dato al usuario
              System.out.println("\t Introduciendo datos de tipo Integer en la pila ");
               //for(int i = 0; !pila.esta_llena();i++)
              while (!pilaI.estaLlena())  // !pila.Llena
              {
                  int dato = ran.nextInt(90)+10;
                  System.out.println("Valor introducido en la pila >>> "+dato);
                  pilaI.push(dato); //pila.push(i);
              }
              System.out.println("\n\t Extrayendo datos de la pila ");
              while (!pilaI.estaVacia())
              {
                  System.out.println( pilaI.pop() + " <<< Dato extraido de la pila " );
              }
              */
//Stack pila = new Stack();
              
        
              
              /*
       
             
             pilaGenerica<Character> pilaAlfabeto = new pilaGenerica<Character>('z' - 'a' + 1);
                         //97
             for (int i = 'a'; !pilaAlfabeto.estaLlena(); i++)
              {
                  pilaAlfabeto.push((char)i);  
                  System.out.println(i+" -> Caracter Insertado : "+ (char)i);// Character.toString((char)i));//     Integer.toString(i));
              } 
              int j = 25;
              while (!pilaAlfabeto.estaVacia())      //(!stack_ascii.esta_vacia())
              {                                    //System.out.println(j+" = "+(char)stack_ascii.pop());
                  char letra = pilaAlfabeto.pop();     //stack_ascii.pop();
                  //System.out.println(j+" = "+ letra);    //stack_ascii.pop());
                  //j--;
                  System.out.println((int)letra + " = "+ letra);
              }
*/
              //CREAR UNA PILA DE CADENAS, DONDE LAS CADENAS SON
              //NOMBRES DE PERSONAS, AUTOMATICE LA CONSTRUCCION Y
              //LA INSERCION
                      
              /*
              Scanner scan = new Scanner(System.in);
              System.out.print("NOMBRE : ");
              String nombre = scan.nextLine();
              pilaGenerica<Character> pilaNombre = new pilaGenerica<Character>(nombre.length());
                //97
             for (int i = 0; !pilaNombre.estaLlena(); i++)
              {
                  pilaNombre.push(nombre.charAt(i));                     // Character.toString((char)i));//     Integer.toString(i));
              } 
              
              while (!pilaNombre.estaVacia())    //(!stack_ascii.esta_vacia())
              {                                    //System.out.println(j+" = "+(char)stack_ascii.pop());
                  char letra = pilaNombre.pop();     //stack_ascii.pop();
                  System.out.println(letra);    //stack_ascii.pop());
                  
              }
              */
              
             /* Scanner entrada = new Scanner(System.in) ;
              String nombre = entrada.nextLine();
              pilaGenerica<Character> pilaLetras = new pilaGenerica<Character>(nombre.length());
                //97
                
                
             for (int i = 0; !pilaLetras.estaLlena(); i++)
              {
                  pilaLetras.push(nombre.charAt(i));                     // Character.toString((char)i));//     Integer.toString(i));
              } 
              
              while (!pilaLetras.estaVacia())    //(!stack_ascii.esta_vacia())
              {                                    //System.out.println(j+" = "+(char)stack_ascii.pop());
                  char letra = pilaLetras.pop();     //stack_ascii.pop();
                  System.out.print(letra);    //stack_ascii.pop());
                  
              }
              System.out.println();
            */  
            
               
             String []nombres={"Ana","Alberto","Alma","Antonio","Antonia","Bertha","Benjamin","Cecilia","Jorge","Gilberto"};
             //String []nombres = {"Ana","Bertha","Alicia","Juan","Pedro"};
             pilaGenerica<String> pilaNombres = new pilaGenerica<String>(nombres.length);
             int i =0;
             while(!pilaNombres.estaLlena())
              {
                  pilaNombres.push(nombres[i++]);//     Integer.toString(i));
              }
              while (!pilaNombres.estaVacia())    //(!stack_ascii.esta_vacia())
              {
                  String nombre= pilaNombres.pop();     //stack_ascii.pop();
                  System.out.println(nombre);    //stack_ascii.pop());
              }
              
              
             
              
    }
    
}


// pilaGenerica<char> stack_ascii = new pilaGenerica<char>(256); NO APLICA, EN TIPOS GENERICOS SOLO SE ACEPTAN OBJETOS