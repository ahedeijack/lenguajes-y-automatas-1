/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package appbusacardatoenarreglo;

import java.util.Arrays;
import java.util.Random;
import java.util.Scanner;

/**
 *
 * @author ivan
 */
public class AppBusacarDatoEnArreglo {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner scanner = new Scanner(System.in);
        Random random = new Random();
        
        int []vec = new int[random.nextInt(5)+5];
        
        for(int i = 0; i < vec.length; i++)
        {    
            vec[i] = i*i;
            //vec[i] = random.nextInt(90)+10;
            System.out.println("Vec[ "+i+" ] :"+ (vec[i] = random.nextInt(90)+10));
            
        }
        char resp;
       /* System.out.println("\t BUSQUEDA SEC. SOBRE DATOS DESORDENADOS \n");
        
        char resp;
        
        do
        {
            System.out.println("Dato a buscar : ");
            int dato = scanner.nextInt();
            Numero pos = new Numero();
            
            Busquedas.SecuencialDatosNoOrdenados(vec,dato,pos);
            if(pos.valor != -1)
                System.out.println("DATO : "+ dato+ "SE ENCUENTRA EN LA POSICION :"
                        +pos.valor);
                   
            else
                System.out.println("DATO NO EXISTE ");
            System.out.println("BUSCAR OTRO (s/n) : ");
            resp = scanner.next().charAt(0);
            Character.toLowerCase(resp);
        }while (resp == 's');   */
        
        
        // IMPLEMENTAR LA B. SEC. SOBRE DATOS ORDENADOS
        System.out.println("\nBUSQUEDA SEC. SOBRE DATOS ORDENADOS");
        
        do
        {
            Ordenamiento.burbuja(vec);
            for(int i = 0; i < vec.length; i++)
                System.out.println("Vec[ "+i+" ] :"+ (vec[i]));
            System.out.println("Dato a buscar : ");
            int dato = scanner.nextInt();
            Numero pos = new Numero();
            
            Busquedas.SecuencialDatosOrdenados(vec,dato,pos);
            if(pos.valor != -1)
                System.out.println("DATO : "+ dato+ "SE ENCUENTRA EN LA POSICION :"
                        +pos.valor);
                   
            else
                System.out.println("DATO NO EXISTE ");
            System.out.println("BUSCAR OTRO (s/n) : ");
            resp = scanner.next().charAt(0);
            Character.toLowerCase(resp);
        }while (resp == 's');   
    }
        
        //AGREGAR LA BUSQUEDA BINARIA
        
        
    }
    

