#ifndef PIDATE_H
#define PIDATE_H

#include <QtGui>

namespace Ui {
    class PiDate;
}

class PiDate : public QWidget
{
    Q_OBJECT

public:
    explicit PiDate(QWidget *parent = 0);
    ~PiDate();

public slots:
    void day10inc();
    void day10dec();
    void day1inc();
    void day1dec();
    void month1inc();
    void month1dec();
    void year10inc();
    void year10dec();
    void year1inc();
    void year1dec();

    void search();
    bool search(QByteArray pattern);
    void searchall();

private:
    Ui::PiDate *ui;
    QFile file;
    int position;
};

#endif // PIDATE_H
