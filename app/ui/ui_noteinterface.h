/********************************************************************************
** Form generated from reading UI file 'noteinterface.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOTEINTERFACE_H
#define UI_NOTEINTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_noteinterface
{
public:
    QGridLayout *gridLayout;
    QGridLayout *inputarea;
    QLabel *amout;
    QLineEdit *amountval;
    QLabel *categories;
    QLabel *date;
    QDateEdit *dateval;
    QComboBox *currencyval;
    QLabel *currecy;
    QComboBox *categoriesval;
    QVBoxLayout *commentarea;
    QLabel *comment;
    QTextEdit *commentedit;
    QVBoxLayout *buttonsarea;
    QSpacerItem *spacerup;
    QPushButton *maketransaction;
    QPushButton *makepurpose;
    QSpacerItem *spacerdown;

    void setupUi(QWidget *noteinterface)
    {
        if (noteinterface->objectName().isEmpty())
            noteinterface->setObjectName("noteinterface");
        noteinterface->resize(463, 350);
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        noteinterface->setFont(font);
        gridLayout = new QGridLayout(noteinterface);
        gridLayout->setObjectName("gridLayout");
        inputarea = new QGridLayout();
        inputarea->setObjectName("inputarea");
        amout = new QLabel(noteinterface);
        amout->setObjectName("amout");

        inputarea->addWidget(amout, 1, 0, 1, 1);

        amountval = new QLineEdit(noteinterface);
        amountval->setObjectName("amountval");

        inputarea->addWidget(amountval, 1, 1, 1, 1);

        categories = new QLabel(noteinterface);
        categories->setObjectName("categories");

        inputarea->addWidget(categories, 2, 0, 1, 1);

        date = new QLabel(noteinterface);
        date->setObjectName("date");

        inputarea->addWidget(date, 2, 2, 1, 1);

        dateval = new QDateEdit(noteinterface);
        dateval->setObjectName("dateval");
        dateval->setMinimumSize(QSize(91, 0));

        inputarea->addWidget(dateval, 2, 3, 1, 1);

        currencyval = new QComboBox(noteinterface);
        currencyval->addItem(QString());
        currencyval->addItem(QString());
        currencyval->addItem(QString());
        currencyval->addItem(QString());
        currencyval->addItem(QString());
        currencyval->addItem(QString());
        currencyval->addItem(QString());
        currencyval->addItem(QString());
        currencyval->addItem(QString());
        currencyval->addItem(QString());
        currencyval->addItem(QString());
        currencyval->addItem(QString());
        currencyval->addItem(QString());
        currencyval->addItem(QString());
        currencyval->addItem(QString());
        currencyval->addItem(QString());
        currencyval->addItem(QString());
        currencyval->addItem(QString());
        currencyval->addItem(QString());
        currencyval->addItem(QString());
        currencyval->addItem(QString());
        currencyval->addItem(QString());
        currencyval->addItem(QString());
        currencyval->addItem(QString());
        currencyval->addItem(QString());
        currencyval->addItem(QString());
        currencyval->addItem(QString());
        currencyval->addItem(QString());
        currencyval->addItem(QString());
        currencyval->addItem(QString());
        currencyval->addItem(QString());
        currencyval->setObjectName("currencyval");

        inputarea->addWidget(currencyval, 1, 3, 1, 1);

        currecy = new QLabel(noteinterface);
        currecy->setObjectName("currecy");

        inputarea->addWidget(currecy, 1, 2, 1, 1);

        categoriesval = new QComboBox(noteinterface);
        categoriesval->addItem(QString());
        categoriesval->addItem(QString());
        categoriesval->addItem(QString());
        categoriesval->addItem(QString());
        categoriesval->addItem(QString());
        categoriesval->addItem(QString());
        categoriesval->addItem(QString());
        categoriesval->addItem(QString());
        categoriesval->addItem(QString());
        categoriesval->addItem(QString());
        categoriesval->addItem(QString());
        categoriesval->addItem(QString());
        categoriesval->addItem(QString());
        categoriesval->addItem(QString());
        categoriesval->addItem(QString());
        categoriesval->addItem(QString());
        categoriesval->addItem(QString());
        categoriesval->setObjectName("categoriesval");

        inputarea->addWidget(categoriesval, 2, 1, 1, 1);


        gridLayout->addLayout(inputarea, 0, 0, 1, 2);

        commentarea = new QVBoxLayout();
        commentarea->setObjectName("commentarea");
        comment = new QLabel(noteinterface);
        comment->setObjectName("comment");

        commentarea->addWidget(comment);

        commentedit = new QTextEdit(noteinterface);
        commentedit->setObjectName("commentedit");

        commentarea->addWidget(commentedit);


        gridLayout->addLayout(commentarea, 1, 0, 1, 1);

        buttonsarea = new QVBoxLayout();
        buttonsarea->setObjectName("buttonsarea");
        spacerup = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        buttonsarea->addItem(spacerup);

        maketransaction = new QPushButton(noteinterface);
        maketransaction->setObjectName("maketransaction");

        buttonsarea->addWidget(maketransaction);

        makepurpose = new QPushButton(noteinterface);
        makepurpose->setObjectName("makepurpose");

        buttonsarea->addWidget(makepurpose);

        spacerdown = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        buttonsarea->addItem(spacerdown);


        gridLayout->addLayout(buttonsarea, 1, 1, 1, 1);


        retranslateUi(noteinterface);

        QMetaObject::connectSlotsByName(noteinterface);
    } // setupUi

    void retranslateUi(QWidget *noteinterface)
    {
        noteinterface->setWindowTitle(QCoreApplication::translate("noteinterface", "Form", nullptr));
        amout->setText(QCoreApplication::translate("noteinterface", "amount :", nullptr));
        categories->setText(QCoreApplication::translate("noteinterface", "category :", nullptr));
        date->setText(QCoreApplication::translate("noteinterface", "date :", nullptr));
        currencyval->setItemText(0, QCoreApplication::translate("noteinterface", "USD \342\200\224 United States Dollar", nullptr));
        currencyval->setItemText(1, QCoreApplication::translate("noteinterface", "EUR \342\200\224 Euro", nullptr));
        currencyval->setItemText(2, QCoreApplication::translate("noteinterface", "GBP \342\200\224 Pound Sterling", nullptr));
        currencyval->setItemText(3, QCoreApplication::translate("noteinterface", "JPY \342\200\224 Japanese Yen", nullptr));
        currencyval->setItemText(4, QCoreApplication::translate("noteinterface", "CNY \342\200\224 Chinese Yuan Renminbi", nullptr));
        currencyval->setItemText(5, QCoreApplication::translate("noteinterface", "CHF \342\200\224 Swiss Franc", nullptr));
        currencyval->setItemText(6, QCoreApplication::translate("noteinterface", "AUD \342\200\224 Australian Dollar", nullptr));
        currencyval->setItemText(7, QCoreApplication::translate("noteinterface", "CAD \342\200\224 Canadian Dollar", nullptr));
        currencyval->setItemText(8, QCoreApplication::translate("noteinterface", "NZD \342\200\224 New Zealand Dollar", nullptr));
        currencyval->setItemText(9, QCoreApplication::translate("noteinterface", "SEK \342\200\224 Swedish Krona", nullptr));
        currencyval->setItemText(10, QCoreApplication::translate("noteinterface", "NOK \342\200\224 Norwegian Krone", nullptr));
        currencyval->setItemText(11, QCoreApplication::translate("noteinterface", "DKK \342\200\224 Danish Krone", nullptr));
        currencyval->setItemText(12, QCoreApplication::translate("noteinterface", "RUB \342\200\224 Russian Ruble", nullptr));
        currencyval->setItemText(13, QCoreApplication::translate("noteinterface", "PLN \342\200\224 Polish Zloty", nullptr));
        currencyval->setItemText(14, QCoreApplication::translate("noteinterface", "CZK \342\200\224 Czech Koruna", nullptr));
        currencyval->setItemText(15, QCoreApplication::translate("noteinterface", "HUF \342\200\224 Hungarian Forint", nullptr));
        currencyval->setItemText(16, QCoreApplication::translate("noteinterface", "TRY \342\200\224 Turkish Lira", nullptr));
        currencyval->setItemText(17, QCoreApplication::translate("noteinterface", "INR \342\200\224 Indian Rupee", nullptr));
        currencyval->setItemText(18, QCoreApplication::translate("noteinterface", "BRL \342\200\224 Brazilian Real", nullptr));
        currencyval->setItemText(19, QCoreApplication::translate("noteinterface", "ZAR \342\200\224 South African Rand", nullptr));
        currencyval->setItemText(20, QCoreApplication::translate("noteinterface", "MXN \342\200\224 Mexican Peso", nullptr));
        currencyval->setItemText(21, QCoreApplication::translate("noteinterface", "SGD \342\200\224 Singapore Dollar", nullptr));
        currencyval->setItemText(22, QCoreApplication::translate("noteinterface", "HKD \342\200\224 Hong Kong Dollar", nullptr));
        currencyval->setItemText(23, QCoreApplication::translate("noteinterface", "KRW \342\200\224 South Korean Won", nullptr));
        currencyval->setItemText(24, QCoreApplication::translate("noteinterface", "THB \342\200\224 Thai Baht", nullptr));
        currencyval->setItemText(25, QCoreApplication::translate("noteinterface", "MYR \342\200\224 Malaysian Ringgit", nullptr));
        currencyval->setItemText(26, QCoreApplication::translate("noteinterface", "IDR \342\200\224 Indonesian Rupiah", nullptr));
        currencyval->setItemText(27, QCoreApplication::translate("noteinterface", "VND \342\200\224 Vietnamese Dong", nullptr));
        currencyval->setItemText(28, QCoreApplication::translate("noteinterface", "AED \342\200\224 UAE Dirham", nullptr));
        currencyval->setItemText(29, QCoreApplication::translate("noteinterface", "SAR \342\200\224 Saudi Riyal", nullptr));
        currencyval->setItemText(30, QCoreApplication::translate("noteinterface", "EGP \342\200\224 Egyptian Pound", nullptr));

        currecy->setText(QCoreApplication::translate("noteinterface", "currency :", nullptr));
        categoriesval->setItemText(0, QCoreApplication::translate("noteinterface", "Rent", nullptr));
        categoriesval->setItemText(1, QCoreApplication::translate("noteinterface", "Taxes", nullptr));
        categoriesval->setItemText(2, QCoreApplication::translate("noteinterface", "Electricity", nullptr));
        categoriesval->setItemText(3, QCoreApplication::translate("noteinterface", "Water", nullptr));
        categoriesval->setItemText(4, QCoreApplication::translate("noteinterface", "Gas", nullptr));
        categoriesval->setItemText(5, QCoreApplication::translate("noteinterface", "Internet", nullptr));
        categoriesval->setItemText(6, QCoreApplication::translate("noteinterface", "Food", nullptr));
        categoriesval->setItemText(7, QCoreApplication::translate("noteinterface", "Transportation", nullptr));
        categoriesval->setItemText(8, QCoreApplication::translate("noteinterface", "Health ", nullptr));
        categoriesval->setItemText(9, QCoreApplication::translate("noteinterface", "Education", nullptr));
        categoriesval->setItemText(10, QCoreApplication::translate("noteinterface", "Entertainment", nullptr));
        categoriesval->setItemText(11, QCoreApplication::translate("noteinterface", "Other ", nullptr));
        categoriesval->setItemText(12, QCoreApplication::translate("noteinterface", "Salary", nullptr));
        categoriesval->setItemText(13, QCoreApplication::translate("noteinterface", "Gift ", nullptr));
        categoriesval->setItemText(14, QCoreApplication::translate("noteinterface", "Bonus", nullptr));
        categoriesval->setItemText(15, QCoreApplication::translate("noteinterface", "Cashback", nullptr));
        categoriesval->setItemText(16, QCoreApplication::translate("noteinterface", "Freelance ", nullptr));

        comment->setText(QCoreApplication::translate("noteinterface", "comment :", nullptr));
        maketransaction->setText(QCoreApplication::translate("noteinterface", "make tarnsaction", nullptr));
        makepurpose->setText(QCoreApplication::translate("noteinterface", "make purpose", nullptr));
    } // retranslateUi

};

namespace Ui {
    class noteinterface: public Ui_noteinterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTEINTERFACE_H
