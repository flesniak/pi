#ifndef CALCULATOR_H
#define CALCULATOR_H

extern "C" {
    #include "SFMT.h"
}

#include <QThread>
#include <QString>
#include <QtCore/QDateTime>
#include <QtCore/QDebug>

#include <arprec/mp_int.h>
#include <arprec/mp_real.h>

class calculator : public QThread
{
    Q_OBJECT


public:
    calculator(QObject *parent);
    ~calculator();
    enum mode { polygon, montecarlo, montemin1, subdivide, grid, bbp, chudnovsky };
    void setPrecision(quint32 precision);
    void setParameter(quint32 parameter);
    void setMode(mode calcmode);
    QString result();
    int duration;

public slots:
    void abortCalculation();

protected:
    void run();

private:
    bool abort;
    mode mmode;
    quint32 mprec;
    quint64 mpar;
    QString mresult;
    QTime time;
    mp_int fak(quint64 value);

signals:
    void update(int percent);
};

#endif // CALCULATOR_H
