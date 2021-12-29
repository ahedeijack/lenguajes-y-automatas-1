/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package apppila_1;

import java.util.Scanner;

/**
 *
 * @author martinos
 */
public class Menu 
{
  public static int opciones()
  {
    Scanner scan = new Scanner(System.in);
    int op;
    System.out.println("Trabajando con una pila : "); 
    System.out.println(" Que deseas hacer : ");
    System.out.println(" 1) Insertar Dato : ");
    System.out.println(" 2) Extraer Dato : ");
    System.out.println(" 3) Salir : ");
    System.out.println("Opcion : ");
    op = scan.nextInt();
    return op;
  }
}
  
    
