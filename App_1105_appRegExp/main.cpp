#include <QRegularExpression>
#include <QRegularExpressionValidator>

#include <iostream>

using namespace std;

int main(){
    QString patron1= "^[0-1]{1,8}$";

    //^ INICIO || $ FIN

    QRegularExpression rex;
    rex.setPattern(patron1);

    if(rex.isValid()){
        cout << "patron valido : " << patron1.toStdString() << endl;
    }else{
        cout << "patron no valido : " << patron1.toStdString() << endl;
    }

    QString valor = "1020";
    QRegularExpressionMatch match1 = rex.match(valor);

    bool hasMatch1 = match1.hasMatch();
    if(hasMatch1)
        cout <<"expresion valida uwu: " << valor.toStdString()<<endl;
    else
        cout<<"expresion no valida unu: "<<valor.toStdString()<<endl;


    //UTILIZANDO PUNTERO

    QRegularExpression *match2 = new QRegularExpression(patron1);

    // bool hasMatch2 = match2->match(valor).hasMatch();
    cout<<"Alternativa 2 con punteros \n6";
    if(match2->match(valor).hasMatch())
        cout <<"expresion valida uwu: " << valor.toStdString()<<endl;
    else
        cout<<"expresion no valida unu: "<<valor.toStdString()<<endl;

    //VALIDAR QUE UNA ENTRADA CUMPLA CON LA REGLA DE LOS HEXADECIMALES DE DOS BYTES

    //EJ: FFFf, 1000, ffGG, NO VALIDA

    QRegularExpression expHexa("^[0-9A-F]{2}$",QRegularExpression::CaseInsensitiveOption);

    QString valorHexa = "ff";

    cout<<"Alternativa 3, validacion hexadecimal \n6";
    if(expHexa.match(valorHexa).hasMatch())
        cout <<"expresion valida uwu: " << valorHexa.toStdString()<<endl;
    else
        cout<<"expresion no valida unu: "<<valorHexa.toStdString()<<endl;


    //VALIDAR EXPRESIÓN PENDIENTE

    QRegularExpression expRex("^[\\w-]+(\\.?[\\w-]+)@[A-Za-z0-9]+(\\.[A-Za-z0-9]+)(\\.[A-Za-z]{2,})?$");

    QString valorRexValido = "alu.1813128@itlalaguna.edu.mx";
    QString valorRexinValido = "alu.1813128@itlalaguna.com.mx";

    cout<<"Alternativa 3, validacion hexadecimal \n6";
    if(expRex.match(valorRexValido).hasMatch())
        cout <<"expresion valida uwu: " << valorRexValido.toStdString()<<endl;
    else
        cout<<"expresion no valida unu: "<<valorRexValido.toStdString()<<endl;

    cout<<"Alternativa 3, validacion hexadecimal \n6";
    if(expRex.match(valorRexinValido).hasMatch())
        cout <<"expresion valida uwu: " << valorRexinValido.toStdString()<<endl;
    else
        cout<<"expresion no valida unu: "<<valorRexinValido.toStdString()<<endl;

    QRegularExpression expTarea1("/^(?:(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.){3}(?:25[0-5]|2[0-4][0-9]|");

    QString ValorTarea1 = "73.60.124.136";

    if(expTarea1.match(ValorTarea1).hasMatch()){
        cout<<"La dirección IP es valida: " <<ValorTarea1.toStdString() <<endl;
    } else {
        cout<<ValorTarea1.toStdString() <<", es una IP invalida" <<endl;
    }

    /*
QString ValorTarea1Fail = "166.102.312.0.1";
    if(expTarea1.match(ValorTarea1Fail).hasMatch()){
        cout<<"La dirección IP es valida: " <<ValorTarea1Fail.toStdString() <<endl;
    } else {
        cout<<ValorTarea1Fail.toStdString() <<", es una IP invalida" <<endl;
    }
*/

    QRegularExpression expTarea2("^([A-Z,Ñ,&]{3,4}([0-9]{2})(0[1-9]|1[0-2])(0[1-9]|1[0-9]|2[0-9]|3[0-1])[A-Z|\\d]{3})$");

    QString ValorTarea2 = "VAAC9806024W1";

    if(expTarea2.match(ValorTarea2).hasMatch()){
        cout<<"El RFC "<<ValorTarea2.toStdString() <<", es un RFC valido. "<<endl;
    } else {
        cout<<ValorTarea2.toStdString()<<", es un RFC Invalido"<<endl;
    }

    QRegularExpression expTarea3("^d{5}(?:[-s]d{4})?$");

    QString ValorTarea3 = "35049";

    if(expTarea3.match(ValorTarea3).hasMatch()){
        cout<<"Es un codigo postal valido: " <<ValorTarea3.toStdString() <<endl;
    } else {
        cout<<ValorTarea3.toStdString() <<", Es un codigo postal invalido" <<endl;
    }

}


