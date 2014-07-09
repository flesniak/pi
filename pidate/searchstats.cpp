#include "searchstats.h"

searchstats::searchstats(QWidget *parent) : QDialog(parent)
{
    setWindowTitle(QString::fromUtf8("Pi-Daten prüfen"));
  
    label_total = new QLabel(this);
    label_found = new QLabel(this);
    label_notfound = new QLabel(this);
    label_digits = new QLabel(this);
    button_close = new QPushButton(QString::fromUtf8("Schließen"),this);

    QLabel *dummy_missing = new QLabel("Fehlende Daten:",this);
    missingdates = new QTextEdit(this);

    search = NULL;

    QFormLayout *form = new QFormLayout();
    form->addRow("Gesamt:",label_total);
    form->addRow("Gefunden:",label_found);
    form->addRow("Nicht gefunden:",label_notfound);
    form->addRow(QString::fromUtf8("Höchste Stelle:"),label_digits);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addLayout(form);
    layout->addWidget(dummy_missing);
    layout->addWidget(missingdates);
    layout->addWidget(button_close);

    connect(button_close,SIGNAL(clicked()),SLOT(close()));
}

void searchstats::missingdate(const QString &datestr)
{
missingdates->append(datestr);
}

void searchstats::show()
{
missingdates->clear();
search = new crawler(this);
if( !search->isReady() ) {
    QMessageBox::critical(this,"Fehler","pi.txt nicht gefunden!");
    close();
    }
else {
    connect(search,SIGNAL(updateValues()),SLOT(updateValues()));
    connect(search,SIGNAL(missingdate(const QString&)),SLOT(missingdate(const QString&)));
    search->start();
    }
QDialog::show();
}

searchstats::~searchstats()
{
    closeEvent();
}

void searchstats::closeEvent()
{
if( NULL != search ) {
    search->abortrun = true;
    search->wait(200);
    disconnect(search,SIGNAL(updateValues()));
    disconnect(search,SIGNAL(missingdate(const QString&)));
    usleep(500);
    delete search;
    search=NULL;
    }
}

void searchstats::updateValues()
{
label_total->setText(QString::number(search->total()));
label_found->setText(QString::number(search->found()));
label_notfound->setText(QString::number(search->notfound()));
label_digits->setText(QString::number(search->digits()));
}

crawler::crawler(QObject *parent) : QThread(parent)
{
file.close();
file.setFileName("pi.txt");
if( !file.open(QIODevice::ReadOnly) )
    ready=false;
else
    ready=true;
abortrun=false;
mtotal=mfound=mnotfound=mdigits=0;
}

crawler::~crawler()
{
    file.close();
}

void crawler::run()
{
    QDate date(1990,1,1);
    QDate finish(2001,12,31);
    while( date < finish) {
        QByteArray pattern = date.toString("ddMMyy").toUtf8();
        file.seek(1);
        quint32 position = 0;
        QByteArray buffer;
        buffer.resize(6);
        buffer = file.read(6);
        while( (buffer != pattern) & (!file.atEnd()) ) {
            position++;
            buffer.remove(0,1);
            buffer.append(file.read(1));
            if( abortrun )
                break;
            }
        if( file.atEnd() ) {
            mnotfound++;
            emit missingdate(QString(pattern));
            }
        else {
            mfound++;
            if( mdigits < position )
                mdigits = position;
            }
        if( abortrun )
            break;
        mtotal++;
        emit updateValues();
        date=date.addDays(1);
        }
}
