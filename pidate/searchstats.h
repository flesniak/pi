#ifndef SEARCHSTATS_H
#define SEARCHSTATS_H

#include <QtGui>

#include "unistd.h"

class crawler : public QThread
{
    Q_OBJECT

public:
    crawler(QObject *partent = 0);
    ~crawler();
    virtual void run();
    bool isReady() { return ready; }
    quint32 total() { return mtotal; }
    quint32 found() { return mfound; }
    quint32 notfound() { return mnotfound; }
    quint32 digits() { return mdigits; }
    bool abortrun;

private:
    bool ready;
    QFile file;
    quint32 mtotal, mfound, mnotfound, mdigits;

signals:
    void updateValues();
    void missingdate(const QString& datestr);
};

class searchstats : public QDialog
{
    Q_OBJECT

public:
    explicit searchstats(QWidget *parent = 0);
    ~searchstats();

public slots:
    void updateValues();
    void show();
    void closeEvent();
    void missingdate(const QString& datestr);

private:
    QLabel *label_total, *label_found, *label_notfound, *label_digits;
    QPushButton *button_close;
    QTextEdit *missingdates;
    crawler *search;
};

#endif // SEARCHSTATS_H
