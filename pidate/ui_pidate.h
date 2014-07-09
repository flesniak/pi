/********************************************************************************
** Form generated from reading UI file 'pidate.ui'
**
** Created
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PIDATE_H
#define UI_PIDATE_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDateEdit>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PiDate
{
public:
    QDateEdit *date;
    QPushButton *day10up;
    QPushButton *day1up;
    QPushButton *month1up;
    QPushButton *year10up;
    QPushButton *year1up;
    QPushButton *day10down;
    QPushButton *day1down;
    QPushButton *month1down;
    QPushButton *year10down;
    QPushButton *year1down;
    QPushButton *search;
    QLabel *output;
    QPushButton *searchall;

    void setupUi(QWidget *PiDate)
    {
        if (PiDate->objectName().isEmpty())
            PiDate->setObjectName(QString::fromUtf8("PiDate"));
        PiDate->resize(800, 600);
        date = new QDateEdit(PiDate);
        date->setObjectName(QString::fromUtf8("date"));
        date->setGeometry(QRect(10, 90, 611, 181));
        QFont font;
        font.setPointSize(116);
        font.setBold(true);
        font.setWeight(75);
        font.setKerning(false);
        date->setFont(font);
        date->setFocusPolicy(Qt::NoFocus);
        date->setReadOnly(true);
        date->setButtonSymbols(QAbstractSpinBox::NoButtons);
        date->setDate(QDate(2095, 1, 1));
        day10up = new QPushButton(PiDate);
        day10up->setObjectName(QString::fromUtf8("day10up"));
        day10up->setGeometry(QRect(20, 20, 71, 71));
        QIcon icon;
        icon.addFile(QString::fromUtf8("go-up.png"), QSize(), QIcon::Normal, QIcon::Off);
        day10up->setIcon(icon);
        day10up->setIconSize(QSize(64, 64));
        day1up = new QPushButton(PiDate);
        day1up->setObjectName(QString::fromUtf8("day1up"));
        day1up->setGeometry(QRect(100, 20, 71, 71));
        day1up->setIcon(icon);
        day1up->setIconSize(QSize(64, 64));
        month1up = new QPushButton(PiDate);
        month1up->setObjectName(QString::fromUtf8("month1up"));
        month1up->setGeometry(QRect(270, 20, 71, 71));
        month1up->setIcon(icon);
        month1up->setIconSize(QSize(64, 64));
        year10up = new QPushButton(PiDate);
        year10up->setObjectName(QString::fromUtf8("year10up"));
        year10up->setGeometry(QRect(440, 20, 71, 71));
        year10up->setIcon(icon);
        year10up->setIconSize(QSize(64, 64));
        year1up = new QPushButton(PiDate);
        year1up->setObjectName(QString::fromUtf8("year1up"));
        year1up->setGeometry(QRect(520, 20, 71, 71));
        year1up->setIcon(icon);
        year1up->setIconSize(QSize(64, 64));
        day10down = new QPushButton(PiDate);
        day10down->setObjectName(QString::fromUtf8("day10down"));
        day10down->setGeometry(QRect(20, 270, 71, 71));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("go-down.png"), QSize(), QIcon::Normal, QIcon::Off);
        day10down->setIcon(icon1);
        day10down->setIconSize(QSize(64, 64));
        day1down = new QPushButton(PiDate);
        day1down->setObjectName(QString::fromUtf8("day1down"));
        day1down->setGeometry(QRect(100, 270, 71, 71));
        day1down->setIcon(icon1);
        day1down->setIconSize(QSize(64, 64));
        month1down = new QPushButton(PiDate);
        month1down->setObjectName(QString::fromUtf8("month1down"));
        month1down->setGeometry(QRect(270, 270, 71, 71));
        month1down->setIcon(icon1);
        month1down->setIconSize(QSize(64, 64));
        year10down = new QPushButton(PiDate);
        year10down->setObjectName(QString::fromUtf8("year10down"));
        year10down->setGeometry(QRect(440, 270, 71, 71));
        year10down->setIcon(icon1);
        year10down->setIconSize(QSize(64, 64));
        year1down = new QPushButton(PiDate);
        year1down->setObjectName(QString::fromUtf8("year1down"));
        year1down->setGeometry(QRect(520, 270, 71, 71));
        year1down->setIcon(icon1);
        year1down->setIconSize(QSize(64, 64));
        search = new QPushButton(PiDate);
        search->setObjectName(QString::fromUtf8("search"));
        search->setGeometry(QRect(630, 90, 161, 181));
        QFont font1;
        font1.setPointSize(30);
        font1.setBold(true);
        font1.setWeight(75);
        search->setFont(font1);
        output = new QLabel(PiDate);
        output->setObjectName(QString::fromUtf8("output"));
        output->setGeometry(QRect(20, 350, 751, 221));
        QFont font2;
        font2.setPointSize(30);
        output->setFont(font2);
        output->setWordWrap(true);
        searchall = new QPushButton(PiDate);
        searchall->setObjectName(QString::fromUtf8("searchall"));
        searchall->setGeometry(QRect(630, 280, 161, 21));

        retranslateUi(PiDate);

        QMetaObject::connectSlotsByName(PiDate);
    } // setupUi

    void retranslateUi(QWidget *PiDate)
    {
        PiDate->setWindowTitle(QApplication::translate("PiDate", "PiDate", 0, QApplication::UnicodeUTF8));
        day10up->setText(QString());
        day1up->setText(QString());
        month1up->setText(QString());
        year10up->setText(QString());
        year1up->setText(QString());
        day10down->setText(QString());
        day1down->setText(QString());
        month1down->setText(QString());
        year10down->setText(QString());
        year1down->setText(QString());
        search->setText(QApplication::translate("PiDate", "Suchen!", 0, QApplication::UnicodeUTF8));
        output->setText(QString());
        searchall->setText(QApplication::translate("PiDate", "Alle Daten suchen...", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PiDate: public Ui_PiDate {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PIDATE_H
