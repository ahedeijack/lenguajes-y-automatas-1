/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package appbusacardatoenarreglo;

/**
 *
 * @author ivan
 */
public class Ordenamiento {
    
    public static void burbuja(int vec[])
     {
        for(int i = 0;i<vec.length-1;i++){
           for(int j=vec.length-1;j>i;j--){
            if(vec[j-1]>vec[j]){
                int aux  = vec[j-1];
                vec[j-1] = vec[j];
                vec[j]   = aux;
              }
           }
       }
    }
    
}
