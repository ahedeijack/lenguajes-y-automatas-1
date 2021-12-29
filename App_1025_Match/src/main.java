import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/*  To change this license header, choose License Headers in Project Properties.
 *  To change this template file, choose Tools | Templates and open the template
 *  in the editor.

 */

/**
 *
 * @author Ahedeijack
 */
public class main {

    // IMPLEMENTAR UN MÉTODO PARA VALIDAR CON UNA EXPRESIÓN REGULAR. SI UNA CADENA
    // QUE SE RECIBE COMO PARÁMETRO CONTIENE UN NÚMERO ENTERO. POSITIVO O NEGATIVO:
    // -10, 10, -3, 30, -987,987

    public static boolean validarNumeroEntero(String cadena) {
        // "/^[0-9]+$/ "; "\\^[0-9](.*)+" Pattern regExp =
        // Pattern.compile("\\w-?[0-9]$");
        Pattern regExp = Pattern.compile("^-?[0-9]+$");
        Matcher match = regExp.matcher(cadena);

        if (match.find()) 
            return true;
        else 
            return false;
        }
    
    public static boolean validarNumeroEnteroNegativo(String cadena) {
        // "/^[0-9]+$/ "; "\\^[0-9](.*)+" Pattern regExp =
        // Pattern.compile("\\w-?[0-9]$");
        Pattern regExp = Pattern.compile("^-[0-9]*$");
        Matcher match = regExp.matcher(cadena);

        if (match.find()) 
            return true;
        else 
            return false;

        }
    
    public static boolean validarNumControl(String cadena) {
        Pattern regExp = Pattern.compile("^[0-9]{8}+$");
        Matcher match = regExp.matcher(cadena);

        if (match.find()) 
            return true;
        else 
            return false;
        }
    
    public static boolean validarNumeroControl(String cadena) {

        Pattern regExp = Pattern.compile("^2[01]13[0-9]{4}$");
        Matcher match = regExp.matcher(cadena);

        if (match.find()) 
            return true;
        else 
            return false;

            // boolean bandera = true;        18 13 12 32        if(cadena.length() == 8){
            // for(int i = 0; i < 8; i++ )        {            if(cadena.charAt(i) == '.'){
            // bandera = false;                break;            }
            // if(cadena.charAt(i) == '-' || cadena.charAt(i) == '+'){
            // bandera = true;            }            try{                char a =
            // cadena.charAt(i);                Integer.parseInt(a + "");
            // bandera = true;            }catch(Exception ex){                bandera =
            // false;            }        }        }        else{            bandera =
            // false;        }        return bandera;
        }
    
    public static boolean validarNumControl2020_2029(String cad) {
        Pattern regExp = Pattern.compile("^2[01]13[0-9]{4}$");
        Matcher match = regExp.matcher(cad);

        if (match.find()) 
            return true;
        else 
            return false;
        }
    
    public static boolean validarNumero3formas(String cad) {
        //Pattern regExp = Pattern.compile("\\w-?[0-9]$");
        Pattern regExp = Pattern.compile("[+-]?\\d");
        Matcher match = regExp.matcher(cad);
        //boolean resul = cad.matches( "[+-]?\\\\d" );

        if (match.find()) 
            return true;
        else 
            return false;
        }
    
    // DISEÑE UN METODO PARA VALIDAR NOMBRE DE PERSONAS QUE EMPIECEN CON LETRAS
    // MAYUSCULAS SEGUIDO DE MINUSCULAS. LOS NOMBRES SERÁN A LO MÁS, DOS NOMBRES.
    public static boolean validarNombresMayIni_SeguidoMinus__pattern(String cad) {
        Pattern regExp = Pattern.compile("^[(A-Z)]?[(a-z)].+$");
        Matcher match = regExp.matcher(cad);
        //boolean resul = cad.matches( "[+-]?\\\\d" );

        if (match.find()) 
            return true;
        else 
            return false;
        }
    
    public static boolean validarNombresMayIni_SeguidoMinus__matches(String cad) {
        // ^[(A-Z)]?[(a-z)].+$
        boolean resul = cad.matches("^[(A-Z)]?[(a-z)].+$");

        if (resul) 
            return true;
        else 
            return false;
        }
    
    public static boolean min5max10(String cad) {
        // ^[(A-Z)]?[(a-z)].+$
        boolean resul = cad.matches("^[(A-Za-z0-9)]?[(4,10)].+$");

        if (resul) 
            return true;
        else 
            return false;
        }
    
    public static boolean hexadeciaml(String cad) {
        // ^[(A-Z)]?[(a-z)].+$
        boolean resul = cad.matches("^[(A-Fa-f0-9)]?[(6)].+$");

        if (resul) 
            return true;
        else 
            return false;
        }
    public static boolean binario(String cad) {
        // ^[(A-Z)]?[(a-z)].+$
        boolean resul = cad.matches("^[(01)]?[(1,8)].+$");

        if (resul) 
            return true;
        else 
            return false;
        }
    
    public static boolean CURP(String cad) {
        // ^4[(A-Z)]?[(a-z)].+$
        boolean resul = cad.matches("^4[(A-Z)]?2[(00)]?2[(30)]?2[(12)].+$");
//"^2[01]13[0-9]{4}$"
        if (resul) 
            return true;
        else 
            return false;
        }
    
    public static boolean RFC(String cad) {
        // ^[(A-Z)]?[(a-z)].+$
        boolean resul = cad.matches("^[(A-Za-z0-9)]?[(4,10)].+$");

        if (resul) 
            return true;
        else 
            return false;
        }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System. in);

        int cont = 1;

        do {
            System
                .out
                .println("Comprobación de excepciones...");
            System
                .out
                .println("Que deseas hacer?");

            //Validar selección

            System
                .out
                .println("1.-Validar numero entero");
            System
                .out
                .println("2.-Validar numero negativo");
            System
                .out
                .println("3.-Validar numero de control");
            System
                .out
                .println("4.-Validar numero de control con formato");
            System
                .out
                .println("5.-Validar numero negativo");
            System
                .out
                .println("6.-Validar numero positivo");
            System
                .out
                .println("7.-Validar numero normal");
            System
                .out
                .println("8.-Validar nombre iniciando con mayusculas (pattern)");
            System
                .out
                .println("9.-Validar nombre iniciando con mayusculas (matches)");
            System
                .out
                .println("10.-Validar 5 minumo, maximo 10");
            System
                .out
                .println("11.-Validar Hexadecimal");
            System
                .out
                .println("12.-Validar Binario");
            System
                .out
                .println("13.-Validar CURP");
            System
                .out
                .println("14.-Validar RFC");

            //Fin de selección

            int seleccion;

            seleccion = sc.nextInt();
            boolean res;

            System
                .out
                .println("Ingresa una cadena");
            String dato = sc.next();

            switch (seleccion) {
                case 1:
                    res = validarNumeroEntero(dato);
                    System
                        .out
                        .println("Resultado" + res);
                    break;
                case 2:
                    res = validarNumeroEnteroNegativo(dato);
                    System
                        .out
                        .println("Resultado: " + res);
                    break;
                case 3:
                    res = validarNumControl(dato);
                    System
                        .out
                        .println("Resultado: " + res);
                    break;
                case 4:
                    res = validarNumeroControl(dato);
                    System
                        .out
                        .println("Resultado: " + res);
                    break;
                case 5:
                    res = validarNumero3formas(dato);
                    System
                        .out
                        .println("Resultado: " + res);
                    break;
                case 6:
                    res = validarNumero3formas(dato);
                    System
                        .out
                        .println("Resultado: " + res);
                    break;
                case 7:
                    res = validarNumero3formas(dato);
                    System
                        .out
                        .println("Resultado: " + res);
                    break;
                case 8:
                    res = validarNombresMayIni_SeguidoMinus__pattern(dato);
                    System
                        .out
                        .println(dato + ", " + res);
                    break;
                case 9:
                    res = validarNombresMayIni_SeguidoMinus__matches(dato);
                    System
                        .out
                        .println(dato + ", " + res);
                    break;
                case 10:
                    res = min5max10(dato);
                    System
                        .out
                        .println(dato + ", " + res);
                    break;
                case 11:
                    res = hexadeciaml(dato);
                    System
                        .out
                        .println(dato + ", " + res);
                    break;
                case 12:
                    res = binario(dato);
                    System
                        .out
                        .println(dato + ", " + res);
                    break;
                case 13:
                    res = CURP(dato);
                    System
                        .out
                        .println(dato + ", " + res);
                    break;
                case 14:
                    res = RFC(dato);
                    System
                        .out
                        .println(dato + ", " + res);
                    break;
                default:
                    System
                        .out
                        .println("Agregaste un valor erroneo...");
            }
            System
                .out
                .println("Quieres volver a repetir?");
            System
                .out
                .println("1.-Si. 2.-No.");

            cont = sc.nextInt();
        } while (cont == 1);

        {
            /*
        System.out.print ( "Ingresa cadena: " );
        String dato = sc.next ();

        boolean res = validarNumeroEntero ( dato );


        System.out.println ();

        System.out.print ( "Ingresa negativo: " );
        String neg = sc.next ();

        boolean res2 = validarNumeroEnteroNegativo ( neg );

        System.out.println ( "res = " +res2 );

        System.out.println ( "======================================" );
        System.out.println ();

        System.out.print ( "Ingresa numControl: " );
        String Numctrl = sc.next ();

        boolean res3 = validarNumControl ( Numctrl );
        System.out.println ();


        System.out.println ( "numControl = " + res3 );

        System.out.println ( "===============================" );
        System.out.println ();


        System.out.print ( "Ingresa tu num ctrl: " );
        String num = sc.next ();

        boolean numctrl2 = validarNumeroControl ( num );
        System.out.println ();
        System.out.println ( numctrl2 + " : Número de control VÁLIDO." );
        System.out.println ("============================================" );
        System.out.println ();

        System.out.print ( "Ingresa num con signo negativo: " );
        String numneg = sc.next ();
        System.out.print ( "Ingresa num con signo positivo: " );
        String numpos = sc.next ();
        System.out.print ( "Ingresa num sin signo: " );
        String numnormal = sc.next ();

        System.out.println ();

        boolean numneg_res = validarNumero3formas( numneg );
        boolean numpos_res = validarNumero3formas( numpos );
        boolean numnormal_res = validarNumero3formas( numnormal );


        System.out.println ( numneg_res + " : Número VÁLIDO." );
        System.out.println ( numpos_res + " : Número  VÁLIDO." );
        System.out.println ( numnormal_res + " : Número VÁLIDO." );

        System.out.println("=====================================");
        System.out.println(" CON PATTERN  ");
        System.out.print("Ingresa 2 nombres: ");
        String nombres = sc.next();

        boolean nom_res = validarNombresMayIni_SeguidoMinus__pattern( nombres );
        System.out.println(nom_res + " COINCIDE ");
        System.out.println("========================");

        System.out.println();

        System.out.println(" CON MATCHES  ");
        System.out.print("Ingresa 2 nombres: ");
        String nombs = sc.next();

        boolean nombs_res = validarNombresMayIni_SeguidoMinus__matches( nombs );
        System.out.println(nombs_res + " COINCIDE ");

        */

        }

    }
}
