#include "convertidornumericodialogo.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QIntValidator>
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include "convertidornumerico.h"


/*
ConvertidorNumericoDialogo::ConvertidorNumericoDialogo(QObject *parent) : QObject(parent)
{

}
*/


convertidornumericodialogo::convertidornumericodialogo(){
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    QGridLayout *editLayout = new QGridLayout;
    QHBoxLayout *buttonLayout = new QHBoxLayout;

    QLabel *decLabel = new QLabel("Decimal");
    QLabel *hexLabel = new QLabel("Hexadecimal");
    QLabel *binLabel = new QLabel("Binario");

    decEdit = new QLineEdit;
    hexEdit = new QLineEdit;
    binEdit = new QLineEdit;

    editLayout->addWidget(decLabel, 0, 0);
    editLayout->addWidget(decEdit,0,1);

    editLayout->addWidget(hexLabel, 1, 0);
    editLayout->addWidget(hexEdit,1,1);

    editLayout->addWidget(binLabel, 2, 0);
    editLayout->addWidget(binEdit,2,1);

    QPushButton *botonSalir = new QPushButton("Salir");
    buttonLayout->addStretch();
    buttonLayout->addWidget(botonSalir);

    mainLayout->addLayout(editLayout);
    mainLayout->addStretch();
    mainLayout->addLayout(buttonLayout);

    botonSalir->setDefault(true);
    connect(botonSalir, SIGNAL(release()), this, SLOT(accept()));

    //De donde empieza hasta donde termina y con que formato va a trabajar
    QIntValidator *decVal = new QIntValidator(0, 2147483647, decEdit);
    decEdit->setValidator(decVal);

    //int num = 0x0F
    //Exp Regular para validar números HEXA de 2 digitos
    QRegularExpressionValidator *hexVal = new QRegularExpressionValidator(QRegularExpression("[0-9A-Fa-f]{1,8}"), hexEdit);
    hexEdit->setValidator(hexVal);

    //Exp Regular para número de 1-8 bits = 1Byte
    QRegularExpressionValidator *binVal = new QRegularExpressionValidator(QRegularExpression("[0-1]{1,31}"), binEdit);
    binEdit->setValidator(binVal);

    ConvertidorNumerico  *convertidor = new ConvertidorNumerico;

    connect(decEdit, SIGNAL(textChanged(QString)),convertidor, SLOT(setDec(QString)));

    connect(convertidor, SIGNAL(hexChanged(QString)), hexEdit, SLOT(setText(QString)));

    connect(convertidor, SIGNAL(binChanged(QString)), binEdit, SLOT(setText(QString)));

        //Agregar las conecciones necesarias para que el valor capturado en BINAIRO y HEXADECIMAL se escriba en las demás  opciones

    connect(hexEdit, SIGNAL(textChanged(QString)), convertidor, SLOT(setHex(QString)));
    connect(binEdit, SIGNAL(textChanged(QString)), convertidor, SLOT(setBin(QString)));
    connect(convertidor, SIGNAL(decChanged(QString)), decEdit, SLOT(setText(QString)));




}


