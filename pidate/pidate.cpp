#include "pidate.h"
#include "ui_pidate.h"
#include "searchstats.h"

PiDate::PiDate(QWidget *parent) : QWidget(parent), ui(new Ui::PiDate)
{
    file.setFileName("pi.txt");
    if( !file.open(QIODevice::ReadOnly) ) {
        QMessageBox::critical(this,"Fehler","pi.txt nicht gefunden, Programm wird geschlossen.");
        exit(1);
    }

    ui->setupUi(this);

    connect(ui->day10up,    SIGNAL(clicked()),this,SLOT(day10inc()));
    connect(ui->day10down,  SIGNAL(clicked()),this,SLOT(day10dec()));
    connect(ui->day1up,     SIGNAL(clicked()),this,SLOT(day1inc()));
    connect(ui->day1down,   SIGNAL(clicked()),this,SLOT(day1dec()));
    connect(ui->month1up,   SIGNAL(clicked()),this,SLOT(month1inc()));
    connect(ui->month1down, SIGNAL(clicked()),this,SLOT(month1dec()));
    connect(ui->year10up,   SIGNAL(clicked()),this,SLOT(year10inc()));
    connect(ui->year10down, SIGNAL(clicked()),this,SLOT(year10dec()));
    connect(ui->year1up,    SIGNAL(clicked()),this,SLOT(year1inc()));
    connect(ui->year1down,  SIGNAL(clicked()),this,SLOT(year1dec()));

    connect(ui->search,     SIGNAL(clicked()),this,SLOT(search()));
    connect(ui->searchall,  SIGNAL(clicked()),this,SLOT(searchall()));

    //setWindowState(Qt::WindowFullScreen);
}

PiDate::~PiDate()
{
    file.close();
    delete ui;
}

void PiDate::searchall()
{
    searchstats *searcher = new searchstats(this);
    searcher->show();
}

void PiDate::search()
{
QByteArray pattern = ui->date->date().toString("ddMMyy").toUtf8();
search(pattern);
ui->output->setText("Die Ziffernfolge "+pattern+" beginnt an Stelle "+QString::number(position)+".");
}

bool PiDate::search(QByteArray pattern)
{
file.seek(1);
position = 0;
QByteArray buffer;
buffer.resize(6);
buffer = file.read(6);
while( (buffer != pattern) & (!file.atEnd()) ) {
    position++;
    buffer.remove(0,1);
    buffer.append(file.read(1));
    }
if( file.atEnd() )
    return(false);
else
    return(true);
}

void PiDate::day10inc()
{
    ui->date->setDate(ui->date->date().addDays(10));
}

void PiDate::day10dec()
{
    ui->date->setDate(ui->date->date().addDays(-10));
}

void PiDate::day1inc()
{
    ui->date->setDate(ui->date->date().addDays(1));
}

void PiDate::day1dec()
{
    ui->date->setDate(ui->date->date().addDays(-1));
}

void PiDate::month1inc()
{
    ui->date->setDate(ui->date->date().addMonths(1));
}

void PiDate::month1dec()
{
    ui->date->setDate(ui->date->date().addMonths(-1));
}

void PiDate::year10inc()
{
    ui->date->setDate(ui->date->date().addYears(10));
}

void PiDate::year10dec()
{
    ui->date->setDate(ui->date->date().addYears(-10));
}

void PiDate::year1inc()
{
    ui->date->setDate(ui->date->date().addYears(1));
}

void PiDate::year1dec()
{
    ui->date->setDate(ui->date->date().addYears(-1));
}
