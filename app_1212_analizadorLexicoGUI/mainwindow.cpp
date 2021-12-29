#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>

#include "analizadorlexico.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QDir dir;
    foreach(QFileInfo var, dir.entryInfoList()){
        ui->comboBox->addItem(var.absoluteFilePath());
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    ui->textEdit_2->clear();
    string texto = ui->textEdit->toPlainText().toStdString();
    string linea, resultado;
    char caracteres[255];
    AnalizadorLexico al;

    int i = 1;
    int len = texto.length();
    size_t puntoComa = texto.find_first_of(";");

    while(puntoComa != string::npos)
    {
        linea = texto.substr(0 ,puntoComa + 1);
        strcpy(caracteres, linea.c_str());
        resultado +=  to_string(i) + ": " + al.scanner(caracteres) + "\n☼☼☼☼☼☼☼☼☼☼☼\n";
        texto = texto.substr(puntoComa + 1, len - puntoComa);
        puntoComa = texto.find_first_of(";");
        i++;
    }

    ui->textEdit_2->setText(QString::fromStdString(resultado));
}

void MainWindow::on_comboBox_activated(int index)
{
    QString pathNuevo = ui->comboBox->itemText(index);
    std::string path = pathNuevo.toStdString();
    int len = path.length();
    if(path[len-1] == 't' && path[len-2] == 'x' && path[len-3] == 't' && path[len-4] == '.'){
        ui->comboBox->addItem("YEIOOOOO");
        string linea, resultado;
        ifstream Archivo(path);
        while(getline(Archivo, linea)){
            resultado += linea;
        }
        ui->textEdit->setText(QString::fromStdString(resultado));
    }
    else{
        ui->comboBox->clear();
        QDir dir(pathNuevo);
        foreach(QFileInfo var, dir.entryInfoList()){
            ui->comboBox->addItem(var.absoluteFilePath());
        }
    }
}

