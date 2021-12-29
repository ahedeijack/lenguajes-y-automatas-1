#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "analizador_sintactico.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <stdlib.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_textEdit_entrada_textChanged()
{
    ui->textEdit_sintactico->clear();
    ui->textEdit_lexico->clear();
    analizador_sintactico *analizador = new analizador_sintactico();
    QList<QString> sentencias = ui->textEdit_entrada->toPlainText().split(";");

    analizador->vanalisislexico();

    for(int j = 0 ; j < sentencias.length() - 1 ; j++) {
        QList<QString> lista = analizador->analizar(sentencias.at(j) + ";");
        //QList<QString> token = analizador->vmuestra();

        for(int i = 0 ; i < lista.length() ; i++) {
            ui->textEdit_sintactico->append(lista.at(i));
            //ui->lexico2->append(token[i]);
        }

         QList<QString> token = analizador->vmuestra();
          for (int i = 0; i < token.length(); i++) {
              ui->textEdit_lexico->append(token[i]);
         }
    }
    analizador->~analizador_sintactico();
}

void MainWindow::on_textEdit_sintactico_selectionChanged()
{
    ui->textEdit_sintactico->clear();
    analizador_sintactico *analizador = new analizador_sintactico();

    QList<QString> sentencias = ui->textEdit_entrada->toPlainText().split(";");

    ui->textEdit_entrada->clear();
    ui->textEdit_sintactico->clear();

    for(int j = 0 ; j < sentencias.length() - 1 ; j++) {
        QList<QString> lista = analizador->analizar(sentencias.at(j) + ";");

        if (lista.at(lista.length() - 1) == "Error de Sintaxis") {
            ui->textEdit_entrada->setTextColor(qRgb(255,0,0));
            ui->textEdit_entrada->append(sentencias.at(j) + ";");
        } else {
            ui->textEdit_entrada->setTextColor(qRgb(0,0,0));
            ui->textEdit_entrada->append(sentencias.at(j) + ";");
        }
    }


    analizador->~analizador_sintactico();
}

void MainWindow::on_pushButton_clicked()
{
    QString file = QFileDialog::getOpenFileName(this, tr("Open Image"), "C://", tr("Text Files (*.txt)"));

    QFile inputFile(file);
    if (inputFile.open(QIODevice::ReadOnly))
    {
       QTextStream in(&inputFile);
       while (!in.atEnd())
       {
          ui->textEdit_entrada->append(in.readLine());
       }
       inputFile.close();


    }
}

void MainWindow::on_pushButton_2_clicked()
{
    QString file = QFileDialog::getSaveFileName(this, tr("archivo"),"C://", tr("Text Files (*.txt)"));

    if (file != "")
    {
    QFile filetxt(QFileInfo(file).absoluteFilePath());
    if (filetxt.open(QIODevice::WriteOnly))
    {
    QTextStream out(&filetxt);
    out << ui->textEdit_entrada->toPlainText();;
    filetxt.close();
    }

    }
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->textEdit_entrada->setText("");
    ui->textEdit_lexico->setText("");
    ui->textEdit_sintactico->setText("");
}

void MainWindow::on_pushButton_4_clicked()
{
    exit(1);
}
