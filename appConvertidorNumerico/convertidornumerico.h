#ifndef CONVERTIDORNUMERICO_H
#define CONVERTIDORNUMERICO_H

#include <QObject>

class ConvertidorNumerico : public QObject
{
    Q_OBJECT
public:
    explicit ConvertidorNumerico(QObject *parent = nullptr);

signals:
    void decChanged(const QString &);
    void hexChanged(const QString &);
    void binChanged(const QString &);

public slots:
    void setDec(const QString &);
    void setHex(const QString &);
    void setBin(const QString &);

};

#endif // CONVERTIDORNUMERICO_H
