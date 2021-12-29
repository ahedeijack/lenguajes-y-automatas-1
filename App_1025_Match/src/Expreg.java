
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author betto
 */
public class Expreg {


    public  boolean validarNumeroEntero ( String cadena ) 
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
    
       
    
    public  boolean validarNumeroEnteroNegativo ( String cadena ) 
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
    
    public  boolean validarNumeroEnteroPositivo ( String cadena ) 
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
    
    public  boolean validarNumControl(String cadena) {
        Pattern regExp = Pattern.compile("^[0-9]{8}+$");
        Matcher match = regExp.matcher(cadena);
        
        if ( match.find() )
            return true;
        else
            return false;
    }
    
    public  boolean validarNumeroControl(String cadena){
        
        Pattern regExp = Pattern.compile("^2[01]13[0-9]{4}$");
        Matcher match = regExp.matcher(cadena);
        
        if ( match.find() )
            return true;
        else
            return false;
        
    }
    
    public  boolean validarNumControl2020_2029 ( String cad )
    {
        Pattern regExp = Pattern.compile("^2[01]13[0-9]{4}$");
        Matcher match = regExp.matcher(cad);
        
        if ( match.find() )
            return true;
        else
            return false;
    }
    
    public  boolean validarNumero3formas( String cad ) 
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
    public  boolean validarNombresMayIni_SeguidoMinus__pattern( String cad ) 
    {
        Pattern regExp = Pattern.compile("^[(A-Z)]?[(a-z)].+$");
        Matcher match = regExp.matcher ( cad );
        //boolean resul = cad.matches( "[+-]?\\\\d" );
        
        if ( match.find() )
            return true;
        else
            return false;
    }
    
    
    public  boolean validarNombresMayIni_SeguidoMinus__matches( String cad ) 
    {
        // ^[(A-Z)]?[(a-z)].+$
        boolean resul = cad.matches("^[(A-Z)]?[(a-z)].+$");
        
        if ( resul )
            return true;
        else
            return false;
    }
    
    public  boolean validarCadena5a10(String cad){
        Pattern regExp = Pattern.compile("[a-zA-Z0-9_]{5,10}");
        Matcher match = regExp.matcher(cad);
        
        if ( match.find() )
            return true;
        else
            return false;
    }
    
    public  boolean validarCadenaHexa(String cad){
        Pattern regExp = Pattern.compile("0[xX][0-9a-fA-F]+");
        Matcher match = regExp.matcher(cad);
        
        if ( match.find() )
            return true;
        else
            return false;
    }
    public  boolean validarCadenaBin(String cad){
        Pattern regExp = Pattern.compile("[0-1]");
        Matcher match = regExp.matcher(cad);
        
        if ( match.find() )
            return true;
        else
            return false;
    }
    public   boolean validarClave2Letras3Numeros(String cad) {
        Pattern regExp = Pattern.compile("([aA-zZ]{2})+([0-9]{3})");
        Matcher match = regExp.matcher(cad);
        
        if ( match.find() )
            return true;
        else
            return false;
    }
    public  boolean validarRfc(String cad){
        Pattern regExp = Pattern.compile("^([aA-zZ]{4})+([0-9]{7})+([aA-zZ]+[0-1])$");
        Matcher match = regExp.matcher(cad);
        
        if ( match.find() )
            return true;
        else
            return false;
    }
    
    public  boolean validarCurp(String cad){
        Pattern regExp = Pattern.compile("^([aA-zZ])+([0-9])+([aA-zZ]+[0-1])$");
        Matcher match = regExp.matcher(cad);
        
        if ( match.find() )
            return true;
        else
            return false;
    }
    
    
    
}
