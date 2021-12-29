#ifndef CONVERTIDORNUMERICODIALOGO_H
#define CONVERTIDORNUMERICODIALOGO_H

//#include <QObject>
#include <QDialog>

class QLineEdit;
class convertidornumericodialogo : public QDialog
{
    Q_OBJECT
public:
    //explicit convertidornumericodialogo(QDialog *parent = nullptr);
    explicit convertidornumericodialogo();

private:
    QLineEdit *decEdit;
    QLineEdit *hexEdit;
    QLineEdit *binEdit;

};

#endif // CONVERTIDORNUMERICODIALOGO_H
