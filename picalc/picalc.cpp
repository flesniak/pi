#include "picalc.h"

picalc::picalc(QWidget *parent) : QWidget(parent)
{
setWindowTitle("Pi-Berechnung");

box_mode = new QComboBox(this);
box_mode->insertItem(calculator::polygon,"n-Eck");
box_mode->insertItem(calculator::montecarlo,"Monte-Carlo-Methode");
box_mode->insertItem(calculator::montemin1,"Monte-Carlo-Methode mit n-1 Punkten");
box_mode->insertItem(calculator::subdivide,"Aufteilen in Rechtecke");
box_mode->insertItem(calculator::grid,"Raster");
box_mode->insertItem(calculator::bbp,"BBP-Formel");
box_mode->insertItem(calculator::chudnovsky,"Chudnovsky-Formel");

button_start = new QPushButton("Starten",this);
button_abort = new QPushButton("Abbrechen",this);
button_abort->setEnabled(false);

spin_prec = new QSpinBox(this);
spin_prec->setRange(3,1000);
spin_prec->setValue(3);
spin_parm = new QSpinBox(this);
spin_parm->setRange(1,1000);

bar_progress = new QProgressBar(this);
bar_progress->setRange(0,1000);

edit_pi = new QTextEdit(this);
edit_pi->setReadOnly(true);

label_duration = new QLabel(this);
label_parm = new QLabel(this);
label_prec = new QLabel(this);
label_prec->setText("Genauigkeit (Stellen)");

QHBoxLayout *settings = new QHBoxLayout;
settings->addWidget(label_parm);
settings->addWidget(spin_parm);
settings->addWidget(label_prec);
settings->addWidget(spin_prec);

QVBoxLayout *layout = new QVBoxLayout(this);
layout->addWidget(box_mode);
layout->addLayout(settings);
layout->addWidget(button_start);
layout->addWidget(button_abort);
layout->addWidget(bar_progress);
layout->addWidget(edit_pi);
layout->addWidget(label_duration);

calc = new calculator(this);

modechange(0);

connect(box_mode,SIGNAL(currentIndexChanged(int)),SLOT(modechange(int)));
connect(button_start,SIGNAL(clicked()),this,SLOT(startCalculation()));
connect(button_abort,SIGNAL(clicked()),calc,SLOT(abortCalculation()));
connect(calc,SIGNAL(update(int)),bar_progress,SLOT(setValue(int)));
connect(calc,SIGNAL(finished()),SLOT(finished()));
}

picalc::~picalc()
{
}

void picalc::finished()
{
button_abort->setEnabled(false);
button_start->setEnabled(true);
bar_progress->setValue(1000);
edit_pi->setText(calc->result());

int mins = calc->duration/60000;
int secs = (calc->duration-(mins*60*1000))/1000;
int msecs = calc->duration-(mins*60*1000)-(secs*1000);

label_duration->setText(QString("Dauer: %1 min %2 sec %3 msec").arg(mins).arg(secs).arg(msecs));
}

void picalc::startCalculation()
{
if( calc->isRunning() )
    return;
button_abort->setEnabled(true);
button_start->setEnabled(false);
bar_progress->setValue(0);
calc->setPrecision(spin_prec->value());
calc->setParameter(spin_parm->value());
calc->setMode(calculator::mode(box_mode->currentIndex()));
calc->start();
}

void picalc::modechange(int index)
{
switch(calculator::mode(index)) {
    case calculator::polygon    : label_parm->setText("Zahl der Ecken");
                                  spin_parm->setValue(72);
                                  break;
    case calculator::montemin1  : ;
    case calculator::montecarlo : label_parm->setText("Anzahl Punkte (10^)");
                                  spin_parm->setValue(6);
                                  break;
    case calculator::subdivide  : label_parm->setText("Anzahl Unterteilungen (10^)");
                                  spin_parm->setValue(6);
                                  break;
    case calculator::grid       : label_parm->setText(QString::fromUtf8("Eindimensionale Auflösung (10^)"));
                                  spin_parm->setValue(6);
                                  break;
    case calculator::bbp  :       label_parm->setText("Iterationsschritte");
                                  spin_parm->setValue(10);
                                  break;
    case calculator::chudnovsky : label_parm->setText(QString::fromUtf8("Iterationsschritte"));
                                  spin_parm->setValue(10);
                                  break;
    }
}
