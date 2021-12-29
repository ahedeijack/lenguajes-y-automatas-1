/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAbrir;
    QAction *actionGuardar;
    QAction *actionSalir;
    QAction *actionLimpiar;
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QTextEdit *textEdit_entrada;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QTextEdit *textEdit_lexico;
    QTextEdit *textEdit_sintactico;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 688);
        actionAbrir = new QAction(MainWindow);
        actionAbrir->setObjectName(QString::fromUtf8("actionAbrir"));
        actionGuardar = new QAction(MainWindow);
        actionGuardar->setObjectName(QString::fromUtf8("actionGuardar"));
        actionSalir = new QAction(MainWindow);
        actionSalir->setObjectName(QString::fromUtf8("actionSalir"));
        actionLimpiar = new QAction(MainWindow);
        actionLimpiar->setObjectName(QString::fromUtf8("actionLimpiar"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 10, 381, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("MS Reference Sans Serif")});
        font.setPointSize(20);
        label->setFont(font);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(440, 20, 281, 16));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(440, 40, 301, 16));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(440, 60, 221, 16));
        textEdit_entrada = new QTextEdit(centralwidget);
        textEdit_entrada->setObjectName(QString::fromUtf8("textEdit_entrada"));
        textEdit_entrada->setGeometry(QRect(20, 199, 741, 221));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 175, 61, 21));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 430, 71, 21));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(400, 430, 61, 16));
        textEdit_lexico = new QTextEdit(centralwidget);
        textEdit_lexico->setObjectName(QString::fromUtf8("textEdit_lexico"));
        textEdit_lexico->setGeometry(QRect(20, 450, 371, 191));
        textEdit_sintactico = new QTextEdit(centralwidget);
        textEdit_sintactico->setObjectName(QString::fromUtf8("textEdit_sintactico"));
        textEdit_sintactico->setGeometry(QRect(400, 450, 361, 191));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(170, 120, 111, 51));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(290, 120, 91, 51));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(390, 120, 91, 51));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(490, 120, 101, 51));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionAbrir->setText(QCoreApplication::translate("MainWindow", "Abrir", nullptr));
        actionGuardar->setText(QCoreApplication::translate("MainWindow", "Guardar", nullptr));
        actionSalir->setText(QCoreApplication::translate("MainWindow", "Salir", nullptr));
        actionLimpiar->setText(QCoreApplication::translate("MainWindow", "Limpiar", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Analizador Sintactico visual", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Roberto De Santiago N\303\241jera. 18131232", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Carlos Vazquez Aguirre 18131288", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "David Garcia Leon 19130911", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Entrada", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Tokens", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Sintactico", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Abrir", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Guardar", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Limpiar", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Salir", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
