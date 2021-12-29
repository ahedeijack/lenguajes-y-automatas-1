#include "convertidornumerico.h"

ConvertidorNumerico::ConvertidorNumerico(QObject *parent) : QObject(parent)
{

}

void ConvertidorNumerico::setDec(const QString &cadena){
    bool ok;
    int num = cadena.toInt(&ok);

    if(ok){
        emit hexChanged(QString::number(num,16));
        emit binChanged(QString ::number(num, 2));

    } else {
        emit hexChanged("");
        emit binChanged("");
    }
}

void ConvertidorNumerico::setHex(const QString &cadena){
    bool ok;
    int num = cadena.toInt(&ok, 16);

    if(ok){
      emit decChanged(QString::number(num));
      emit binChanged(QString::number(num, 2));
    } else {
        emit decChanged("");
        emit binChanged("");
    }
}

void ConvertidorNumerico::setBin(const QString &cadena){
    bool ok;
    int num = cadena.toInt(&ok, 2);

    if(ok){
        emit decChanged(QString::number(num));
        emit hexChanged(QString::number(num,16));
    } else {
        emit decChanged("");
        emit hexChanged("");
    }
}
