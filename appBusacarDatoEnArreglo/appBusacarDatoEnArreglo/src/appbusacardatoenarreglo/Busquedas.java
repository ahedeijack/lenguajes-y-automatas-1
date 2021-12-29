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
public class Busquedas {
    
    public static void SecuencialDatosNoOrdenados(int []vec, int X, Numero pos)
                                                //PARA MANEJAR LA REFERENCIA
                                                //Y TENER VARIABLE DE ENTRADA
    {
        pos.valor = -1;
        int i = 0;
        //ENCONTRAR LA PRIMER OCURRENCIA DEL DA6O A BUSCAR
        while(pos.valor == -1 && i < vec.length)
        {
            if(vec[i] == X)
            {
                pos.valor = i;
            }
            i++;
        }
        
        
        //return pos;
    }
                        //LOS DATOS LLEGAN ORDENADOS
    public static void SecuencialDatosOrdenados(int []vec, int X, Numero pos)
    {
        //int pos = -1;
        
        //return pos;
        pos.valor = -1;
        int i = 0;
        while(vec[i] < X)
            i++;
        if(vec[i] == X)
            pos.valor = i;
        
    }
    
        public static void Binaria(int [] vec, int X, Numero pos){
        pos.valor = -1;
        int LI = 0;
        int LS = vec.length -1;
        int i;
        while((LI <= LS) && (pos.valor == -1)){
            i = (LI + LS)/2;
            if (vec[i] == X) {
                pos.valor = i;
            //HACER LA PRUEBA CON break Y continue
            //Cual funciona? 
            } else if (vec[i] < X) {
                LI = i+1;
            } else {
            LS = i-1;
        }
            //TAREA: INVESTIVL METODO DE BUSQUEDABINARIA RECURSIVA.
        }
    }        
}

