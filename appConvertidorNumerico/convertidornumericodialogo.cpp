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
#include <convertidornumerico.h>

/*convertidornumericodialogo::convertidornumericodialogo(QDialog *parent) : QDialog(parent)
{

}*/

convertidornumericodialogo::convertidornumericodialogo()
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    QGridLayout *editLayout = new QGridLayout;
    QHBoxLayout *buttonLayout = new QHBoxLayout;

    QLabel *decLabel = new QLabel("Decimal");
    QLabel *hexLabel = new QLabel("Hexadecimal");
    QLabel *binLabel = new QLabel("Binario");

    decEdit = new QLineEdit;
    hexEdit = new QLineEdit;
    binEdit = new QLineEdit;

    editLayout->addWidget(decLabel,0,0);
    editLayout->addWidget(decEdit,0,1);
    editLayout->addWidget(hexLabel,1,0);
    editLayout->addWidget(hexEdit,1,1);
    editLayout->addWidget(binLabel,2,0);
    editLayout->addWidget(binEdit,2,1);

    QPushButton *botonSalir = new QPushButton("Salir");
    buttonLayout->addStretch();
    buttonLayout->addWidget(botonSalir);

    mainLayout->addLayout(editLayout);
    mainLayout->addStretch();
    mainLayout->addLayout(buttonLayout);

    botonSalir->setDefault(true);
    connect(botonSalir, SIGNAL(released()), this, SLOT(accept()));
                //Valores de un byte: 0-255
    QIntValidator *decVal = new QIntValidator(0,255,decEdit);
    decEdit->setValidator(decVal);

    QRegularExpressionValidator *hexVal = new QRegularExpressionValidator(QRegularExpression("^[0-9A-Fa-f]{1,2}"), hexEdit);
    hexEdit->setValidator(hexVal);

    QRegularExpressionValidator *binVal = new QRegularExpressionValidator(QRegularExpression("[0-1]{1,8}"), binEdit);
    binEdit->setValidator(binVal);

    ConvertidorNumerico *convertidor = new ConvertidorNumerico;
    connect(decEdit, SIGNAL(textChanged(QString)), convertidor, SLOT(setDec(QString)));
    connect(convertidor, SIGNAL(hexChanged(QString)), hexEdit, SLOT(setText(QString)));
    connect(convertidor, SIGNAL(binChanged(QString)), binEdit, SLOT(setText(QString)));


}
