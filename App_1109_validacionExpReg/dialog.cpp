#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    //Expresiones regulares de inicio

    ui->comboBox->addItem("^[A-Z0-9a-z.]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,4}$");
    ui->comboBox->addItem("^[\\w-]+(\\.[\\w-]+)@[A-Za-z0-9]+(\\.[A-Za-z0-9]+)(\\.[A-Za-z]{2,})$");
    ui->comboBox->addItem("^-?[0-9]+$");
    ui->comboBox->addItem("^-[0-9]*$");
    ui->comboBox->addItem("^[0-9]{8}+$");
    ui->comboBox->addItem("^2[01]13[0-9]{4}$");
    ui->comboBox->addItem("[+-]?\\d");
    ui->comboBox->addItem("^[(A-Z)]?[(a-z)].+$");
    ui->comboBox->addItem("^[(A-Za-z0-9)]?[(4,10)].+$");
    ui->comboBox->addItem("^[(A-Fa-f0-9)]?[(6)].+$");
    ui->comboBox->addItem("^[(01)]?[(1,8)].+$");
    ui->comboBox->addItem("^4[(A-Z)]?2[(00)]?2[(30)]?2[(12)].+$");
    ui->comboBox->addItem("^[(A-Za-z0-9)]?[(4,10)].+$");


}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_pushButton_clicked()
{

    QString patron = ui->comboBox->itemText(ui->comboBox->currentIndex());

    QRegularExpression regexp(patron);

    QString entrada = ui->textLineValidator->text();

    QRegularExpressionMatch match = regexp.match(entrada);

    if(match.hasMatch()){
        ui->label_2->setText("Expresión Valida");
    } else {
        ui->label_2->setText("Expresión Invalida");
    }
}

