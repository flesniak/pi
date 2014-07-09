#ifndef MONTECARLO_H
#define MONTECARLO_H

#include <QtGui>

#include "calculator.h"

class picalc : public QWidget
{
    Q_OBJECT

public:
    picalc(QWidget *parent = 0);
    ~picalc();

private:
    QComboBox *box_mode;
    QSpinBox *spin_prec, *spin_parm;
    QLabel *label_duration, *label_prec, *label_parm;
    QTextEdit *edit_pi;
    calculator *calc;
    QPushButton *button_start;
    QPushButton *button_abort;
    QProgressBar *bar_progress;

private slots:
    void finished();
    void startCalculation();
    void modechange(int index);
};

#endif // MONTECARLO_H
