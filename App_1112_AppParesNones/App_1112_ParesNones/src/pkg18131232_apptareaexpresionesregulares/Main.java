/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pkg18131232_apptareaexpresionesregulares;

import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 *
 * @author Betito
 */
public class Main {
 
       public static boolean validarNumeroEntero ( String cadena ) 
    {
        // "/^[0-9]+$/ ";
        // "\\^[0-9](.*)+"
        
        //Pattern regExp = Pattern.compile("\\w-?[0-9]$");
        Pattern regExp = Pattern.compile("^-?[0-9]+$");
        Matcher match = regExp.matcher(cadena);
        
        if ( match.find() )
            return true;
        else
            return false;
    }
    
       
    
    public static boolean validarNumeroEnteroNegativo ( String cadena ) 
    {
        // "/^[0-9]+$/ ";
        // "\\^[0-9](.*)+"
        
        //Pattern regExp = Pattern.compile("\\w-?[0-9]$");
        Pattern regExp = Pattern.compile("^-[0-9]*$");
        Matcher match = regExp.matcher(cadena);
        
        if ( match.find() )
            return true;
        else
            return false;
        
        
    }
    
    public static boolean validarNumeroEnteroPositivo ( String cadena ) 
    {
        // "/^[0-9]+$/ ";
        // "\\^[0-9](.*)+"
        
        //Pattern regExp = Pattern.compile("\\w-?[0-9]$");
        Pattern regExp = Pattern.compile("^[0-9]*$");
        Matcher match = regExp.matcher(cadena);
        
        if ( match.find() )
            return true;
        else
            return false;
        
        
    }
    
    public static boolean validarNumControl(String cadena) {
        Pattern regExp = Pattern.compile("^[0-9]{8}+$");
        Matcher match = regExp.matcher(cadena);
        
        if ( match.find() )
            return true;
        else
            return false;
    }
    
    public static boolean validarNumeroControl(String cadena){
        
        Pattern regExp = Pattern.compile("^2[01]13[0-9]{4}$");
        Matcher match = regExp.matcher(cadena);
        
        if ( match.find() )
            return true;
        else
            return false;
        
    }
    
    public static boolean validarNumControl2020_2029 ( String cad )
    {
        Pattern regExp = Pattern.compile("^2[01]13[0-9]{4}$");
        Matcher match = regExp.matcher(cad);
        
        if ( match.find() )
            return true;
        else
            return false;
    }
    
    public static boolean validarNumero3formas( String cad ) 
    {
        //Pattern regExp = Pattern.compile("\\w-?[0-9]$");
        Pattern regExp = Pattern.compile("[+-]?\\d");
        Matcher match = regExp.matcher ( cad );
        //boolean resul = cad.matches( "[+-]?\\\\d" );
        
        if ( match.find() )
            return true;
        else
            return false;
    }
    
    // DISEÑE UN METODO PARA VALIDAR NOMBRE DE PERSONAS QUE EMPIECEN CON LETRAS MAYUSCULAS SEGUIDO DE MINUSCULAS.
    // LOS NOMBRES SERÁN A LO MÁS, DOS NOMBRES.
    public static boolean validarNombresMayIni_SeguidoMinus__pattern( String cad ) 
    {
        Pattern regExp = Pattern.compile("^[(A-Z)]?[(a-z)].+$");
        Matcher match = regExp.matcher ( cad );
        //boolean resul = cad.matches( "[+-]?\\\\d" );
        
        if ( match.find() )
            return true;
        else
            return false;
    }
    
    
    public static boolean validarNombresMayIni_SeguidoMinus__matches( String cad ) 
    {
        // ^[(A-Z)]?[(a-z)].+$
        boolean resul = cad.matches("^[(A-Z)]?[(a-z)].+$");
        
        if ( resul )
            return true;
        else
            return false;
    }
    
    public static boolean validarCadena5a10(String cad){
        Pattern regExp = Pattern.compile("[a-zA-Z0-9_]{5,10}");
        Matcher match = regExp.matcher(cad);
        
        if ( match.find() )
            return true;
        else
            return false;
    }
    
    public static boolean validarCadenaHexa(String cad){
        Pattern regExp = Pattern.compile("0[xX][0-9a-fA-F]+");
        Matcher match = regExp.matcher(cad);
        
        if ( match.find() )
            return true;
        else
            return false;
    }
    public static boolean validarCadenaBin(String cad){
        Pattern regExp = Pattern.compile("[0-1]");
        Matcher match = regExp.matcher(cad);
        
        if ( match.find() )
            return true;
        else
            return false;
    }
    public static  boolean validarClave2Letras3Numeros(String cad) {
        Pattern regExp = Pattern.compile("([aA-zZ]{2})+([0-9]{3})");
        Matcher match = regExp.matcher(cad);
        
        if ( match.find() )
            return true;
        else
            return false;
    }
    public static boolean validarRfc(String cad){
        Pattern regExp = Pattern.compile("^([aA-zZ]{4})+([0-9]{7})+([aA-zZ]+[0-1])$");
        Matcher match = regExp.matcher(cad);
        
        if ( match.find() )
            return true;
        else
            return false;
    }
    
    public static boolean validarCurp(String cad){
        Pattern regExp = Pattern.compile("^([aA-zZ])+([0-9])+([aA-zZ]+[0-1])$");
        Matcher match = regExp.matcher(cad);
        
        if ( match.find() )
            return true;
        else
            return false;
    }
    // [a-zA-Z0-9_]{5,10}
    // 0[xX][0-9a-fA-F]+ hexadecimal
    //([aA-zZ]{2})+([0-9]{3}) 2 letras y 3 numeros
    //^([aA-zZ]{4})+([0-9]{7})+([aA-zZ]+[0-1])$ curp
    
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
        Scanner kb = new Scanner(System.in);
        int opt;
        char opc;
        String cadena;
        do {
            System.out.println("\n ---------------------------------------- \n");
            System.out.println("Menu \n"
                    + "1.- numero negativo\n"
                    + "2.- numero entero negativo\n"
                    + "3.- numero de control\n"
                    + "4.- numero de control 2020 - 2021\n"
                    + "5.- nombres\n"
                    + "6.- cadenas de 5 a 10 caracteres\n"
                    + "7.- binarios\n"
                    + "8.- hexadecimales\n"
                    + "9.- claves 2 letras seguidos de 3 numeros\n"
                    + "10.- rfc\n"
                    + "11.- curp\n");

            opt = kb.nextInt();

            switch (opt) {
                case 1:
                    cadena = kb.next();
                    if(!validarNumeroEntero(cadena)){
                        System.out.println("input invalido");
                    }else{
                        System.out.println("input valido");
                    }
                    break;
                case 2:
                    cadena = kb.next();
                    if(!validarNumeroEnteroNegativo(cadena)){
                        System.out.println("input invalido");
                    }else{
                        System.out.println("input valido");
                    }
                    break;
                case 3:
                    cadena = kb.next();
                    if(!validarNumControl(cadena)){
                        System.out.println("input invalido");
                    }else{
                        System.out.println("input valido");
                    }
                    break;
                case 4:
                    cadena = kb.next();
                    if(!validarNumControl2020_2029(cadena)){
                        System.out.println("input invalido");
                    }else{
                        System.out.println("input valido");
                    }
                    break;
                case 5:
                    cadena = kb.next();
                    if(!validarNombresMayIni_SeguidoMinus__pattern(cadena)){
                        System.out.println("input invalido");
                    }else{
                        System.out.println("input valido");
                    }
                    break;
                case 6:
                    cadena = kb.next();
                    if(!validarCadena5a10(cadena)){
                        System.out.println("input invalido");
                    }else{
                        System.out.println("input valido");
                    }
                    break;
                case 7:
                    cadena = kb.next();
                    if(!validarCadenaBin(cadena)){
                        System.out.println("input invalido");
                    }else{
                        System.out.println("input valido");
                    }
                    break;
                case 8:
                    cadena = kb.next();
                    if(!validarCadenaHexa(cadena)){
                        System.out.println("input invalido");
                    }else{
                        System.out.println("input valido");
                    }
                    break;
                case 9:
                    cadena = kb.next();
                    if(!validarClave2Letras3Numeros(cadena)){
                        System.out.println("input invalido");
                    }else{
                        System.out.println("input valido");
                    }
                    break;
                case 10:
                    cadena = kb.next();
                    if(!validarRfc(cadena)){
                        System.out.println("input invalido");
                    }else{
                        System.out.println("input valido");
                    }
                    break;
                case 11:
                    cadena = kb.next();
                    if(!validarCurp(cadena)){
                        System.out.println("input invalido");
                    }else{
                        System.out.println("input valido");
                    }
                    break;
            }

            System.out.println("desea continuar? ");
            opc = kb.next().charAt(0);
        } while (opc == 'S' || opc == 's');
    }

}
