#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QString>
#include <QMainWindow>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string>
#include <cstring>
#include <QFile>
#include <QFileDialog>
using namespace std;


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButton_Abrir_clicked();

    void on_pushButton_Cerrar_clicked();

    void on_pushButton_Guardar_clicked();

    void generararch();
    void vabrirarch();
    int  bytesarch();

    void vanalisislexico();
    void vanalisis_sintactico();
    void viniedos();
    char nextchar();
    void vretract();
    int edoActesacept();
    void vmuestra();
    void falla();
    void recuperaerror();
    int esId();

    void insertapila(string elem);//(char *elem);  //(char elem[]);
    int buscaTabla(char a[], char x[]);
    void eliminapila();
    int estoken(char x[]);



    void on_tEdit_Entrada_textChanged();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
