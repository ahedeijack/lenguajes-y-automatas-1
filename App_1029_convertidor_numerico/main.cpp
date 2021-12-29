#include<QApplication>
#include"convertidornumericodialogo.h"

int main(int argc, char *argv[]){

    QApplication app(argc, argv);

    convertidornumericodialogo cNum;

    cNum.setAttribute(Qt::WA_QuitOnClose);

   cNum.show();

   return app.exec();
}
