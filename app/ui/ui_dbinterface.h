/********************************************************************************
** Form generated from reading UI file 'dbinterface.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DBINTERFACE_H
#define UI_DBINTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dbinterface
{
public:
    QGridLayout *gridLayout;
    QGridLayout *lessarea;
    QLabel *l_less;
    QSpinBox *min;
    QCheckBox *checkless;
    QGridLayout *greaterarea;
    QLabel *l_greater;
    QCheckBox *checkgreater;
    QSpinBox *max;
    QFrame *line_2;
    QGridLayout *toarea;
    QLabel *l_to;
    QCheckBox *checkto;
    QDateEdit *deadline;
    QGridLayout *fromarea;
    QCheckBox *checkfrom;
    QLabel *l_from;
    QDateEdit *startdate;
    QFrame *line;
    QGridLayout *categoryarea;
    QLabel *l_category;
    QLabel *l_currs;
    QComboBox *currs;
    QComboBox *categories;
    QFrame *line_3;
    QGridLayout *outputarea;
    QLabel *l_total;
    QLineEdit *loss;
    QLabel *l_loss;
    QLabel *l_profit;
    QLineEdit *profit;
    QLineEdit *total;
    QPushButton *select;

    void setupUi(QWidget *dbinterface)
    {
        if (dbinterface->objectName().isEmpty())
            dbinterface->setObjectName("dbinterface");
        dbinterface->resize(358, 271);
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setUnderline(false);
        font.setStrikeOut(false);
        dbinterface->setFont(font);
        gridLayout = new QGridLayout(dbinterface);
        gridLayout->setObjectName("gridLayout");
        lessarea = new QGridLayout();
        lessarea->setObjectName("lessarea");
        l_less = new QLabel(dbinterface);
        l_less->setObjectName("l_less");

        lessarea->addWidget(l_less, 0, 0, 1, 1);

        min = new QSpinBox(dbinterface);
        min->setObjectName("min");

        lessarea->addWidget(min, 0, 1, 1, 1);

        checkless = new QCheckBox(dbinterface);
        checkless->setObjectName("checkless");

        lessarea->addWidget(checkless, 1, 0, 1, 1);


        gridLayout->addLayout(lessarea, 0, 0, 1, 1);

        greaterarea = new QGridLayout();
        greaterarea->setObjectName("greaterarea");
        l_greater = new QLabel(dbinterface);
        l_greater->setObjectName("l_greater");

        greaterarea->addWidget(l_greater, 0, 0, 1, 1);

        checkgreater = new QCheckBox(dbinterface);
        checkgreater->setObjectName("checkgreater");

        greaterarea->addWidget(checkgreater, 1, 0, 1, 1);

        max = new QSpinBox(dbinterface);
        max->setObjectName("max");
        max->setMinimumSize(QSize(41, 0));

        greaterarea->addWidget(max, 0, 1, 1, 1);


        gridLayout->addLayout(greaterarea, 0, 2, 1, 2);

        line_2 = new QFrame(dbinterface);
        line_2->setObjectName("line_2");
        line_2->setFrameShape(QFrame::Shape::HLine);
        line_2->setFrameShadow(QFrame::Shadow::Sunken);

        gridLayout->addWidget(line_2, 1, 0, 1, 4);

        toarea = new QGridLayout();
        toarea->setObjectName("toarea");
        l_to = new QLabel(dbinterface);
        l_to->setObjectName("l_to");

        toarea->addWidget(l_to, 0, 0, 1, 1);

        checkto = new QCheckBox(dbinterface);
        checkto->setObjectName("checkto");

        toarea->addWidget(checkto, 1, 0, 1, 1);

        deadline = new QDateEdit(dbinterface);
        deadline->setObjectName("deadline");

        toarea->addWidget(deadline, 0, 1, 1, 1);


        gridLayout->addLayout(toarea, 2, 0, 1, 1);

        fromarea = new QGridLayout();
        fromarea->setObjectName("fromarea");
        checkfrom = new QCheckBox(dbinterface);
        checkfrom->setObjectName("checkfrom");

        fromarea->addWidget(checkfrom, 1, 0, 1, 1);

        l_from = new QLabel(dbinterface);
        l_from->setObjectName("l_from");

        fromarea->addWidget(l_from, 0, 0, 1, 1);

        startdate = new QDateEdit(dbinterface);
        startdate->setObjectName("startdate");
        startdate->setMinimumSize(QSize(63, 0));

        fromarea->addWidget(startdate, 0, 1, 1, 1);


        gridLayout->addLayout(fromarea, 2, 2, 1, 2);

        line = new QFrame(dbinterface);
        line->setObjectName("line");
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);

        gridLayout->addWidget(line, 3, 0, 1, 4);

        categoryarea = new QGridLayout();
        categoryarea->setObjectName("categoryarea");
        l_category = new QLabel(dbinterface);
        l_category->setObjectName("l_category");

        categoryarea->addWidget(l_category, 0, 0, 1, 1);

        l_currs = new QLabel(dbinterface);
        l_currs->setObjectName("l_currs");

        categoryarea->addWidget(l_currs, 1, 0, 1, 1);

        currs = new QComboBox(dbinterface);
        currs->addItem(QString());
        currs->addItem(QString());
        currs->addItem(QString());
        currs->addItem(QString());
        currs->addItem(QString());
        currs->addItem(QString());
        currs->addItem(QString());
        currs->addItem(QString());
        currs->addItem(QString());
        currs->addItem(QString());
        currs->addItem(QString());
        currs->addItem(QString());
        currs->addItem(QString());
        currs->addItem(QString());
        currs->addItem(QString());
        currs->addItem(QString());
        currs->addItem(QString());
        currs->addItem(QString());
        currs->addItem(QString());
        currs->addItem(QString());
        currs->addItem(QString());
        currs->addItem(QString());
        currs->addItem(QString());
        currs->addItem(QString());
        currs->addItem(QString());
        currs->addItem(QString());
        currs->addItem(QString());
        currs->addItem(QString());
        currs->addItem(QString());
        currs->addItem(QString());
        currs->addItem(QString());
        currs->setObjectName("currs");

        categoryarea->addWidget(currs, 1, 1, 1, 1);

        categories = new QComboBox(dbinterface);
        categories->addItem(QString());
        categories->addItem(QString());
        categories->addItem(QString());
        categories->addItem(QString());
        categories->addItem(QString());
        categories->addItem(QString());
        categories->addItem(QString());
        categories->addItem(QString());
        categories->addItem(QString());
        categories->addItem(QString());
        categories->addItem(QString());
        categories->addItem(QString());
        categories->addItem(QString());
        categories->addItem(QString());
        categories->addItem(QString());
        categories->addItem(QString());
        categories->addItem(QString());
        categories->setObjectName("categories");

        categoryarea->addWidget(categories, 0, 1, 1, 1);


        gridLayout->addLayout(categoryarea, 4, 0, 1, 1);

        line_3 = new QFrame(dbinterface);
        line_3->setObjectName("line_3");
        line_3->setFrameShape(QFrame::Shape::VLine);
        line_3->setFrameShadow(QFrame::Shadow::Sunken);

        gridLayout->addWidget(line_3, 4, 1, 1, 2);

        outputarea = new QGridLayout();
        outputarea->setObjectName("outputarea");
        l_total = new QLabel(dbinterface);
        l_total->setObjectName("l_total");

        outputarea->addWidget(l_total, 2, 1, 1, 1);

        loss = new QLineEdit(dbinterface);
        loss->setObjectName("loss");

        outputarea->addWidget(loss, 1, 2, 1, 1);

        l_loss = new QLabel(dbinterface);
        l_loss->setObjectName("l_loss");

        outputarea->addWidget(l_loss, 1, 1, 1, 1);

        l_profit = new QLabel(dbinterface);
        l_profit->setObjectName("l_profit");

        outputarea->addWidget(l_profit, 0, 1, 1, 1);

        profit = new QLineEdit(dbinterface);
        profit->setObjectName("profit");

        outputarea->addWidget(profit, 0, 2, 1, 1);

        total = new QLineEdit(dbinterface);
        total->setObjectName("total");

        outputarea->addWidget(total, 2, 2, 1, 1);


        gridLayout->addLayout(outputarea, 4, 3, 1, 1);

        select = new QPushButton(dbinterface);
        select->setObjectName("select");

        gridLayout->addWidget(select, 5, 2, 1, 2);


        retranslateUi(dbinterface);

        QMetaObject::connectSlotsByName(dbinterface);
    } // setupUi

    void retranslateUi(QWidget *dbinterface)
    {
        dbinterface->setWindowTitle(QCoreApplication::translate("dbinterface", "Form", nullptr));
        l_less->setText(QCoreApplication::translate("dbinterface", "less than :", nullptr));
        checkless->setText(QString());
        l_greater->setText(QCoreApplication::translate("dbinterface", "greater than :", nullptr));
        checkgreater->setText(QString());
        l_to->setText(QCoreApplication::translate("dbinterface", "to :", nullptr));
        checkto->setText(QString());
        checkfrom->setText(QString());
        l_from->setText(QCoreApplication::translate("dbinterface", "from :", nullptr));
        l_category->setText(QCoreApplication::translate("dbinterface", "category :", nullptr));
        l_currs->setText(QCoreApplication::translate("dbinterface", "currency :", nullptr));
        currs->setItemText(0, QCoreApplication::translate("dbinterface", "USD \342\200\224 United States Dollar", nullptr));
        currs->setItemText(1, QCoreApplication::translate("dbinterface", "EUR \342\200\224 Euro", nullptr));
        currs->setItemText(2, QCoreApplication::translate("dbinterface", "GBP \342\200\224 Pound Sterling", nullptr));
        currs->setItemText(3, QCoreApplication::translate("dbinterface", "JPY \342\200\224 Japanese Yen", nullptr));
        currs->setItemText(4, QCoreApplication::translate("dbinterface", "CNY \342\200\224 Chinese Yuan Renminbi", nullptr));
        currs->setItemText(5, QCoreApplication::translate("dbinterface", "CHF \342\200\224 Swiss Franc", nullptr));
        currs->setItemText(6, QCoreApplication::translate("dbinterface", "AUD \342\200\224 Australian Dollar", nullptr));
        currs->setItemText(7, QCoreApplication::translate("dbinterface", "CAD \342\200\224 Canadian Dollar", nullptr));
        currs->setItemText(8, QCoreApplication::translate("dbinterface", "NZD \342\200\224 New Zealand Dollar", nullptr));
        currs->setItemText(9, QCoreApplication::translate("dbinterface", "SEK \342\200\224 Swedish Krona", nullptr));
        currs->setItemText(10, QCoreApplication::translate("dbinterface", "NOK \342\200\224 Norwegian Krone", nullptr));
        currs->setItemText(11, QCoreApplication::translate("dbinterface", "DKK \342\200\224 Danish Krone", nullptr));
        currs->setItemText(12, QCoreApplication::translate("dbinterface", "RUB \342\200\224 Russian Ruble", nullptr));
        currs->setItemText(13, QCoreApplication::translate("dbinterface", "PLN \342\200\224 Polish Zloty", nullptr));
        currs->setItemText(14, QCoreApplication::translate("dbinterface", "CZK \342\200\224 Czech Koruna", nullptr));
        currs->setItemText(15, QCoreApplication::translate("dbinterface", "HUF \342\200\224 Hungarian Forint", nullptr));
        currs->setItemText(16, QCoreApplication::translate("dbinterface", "TRY \342\200\224 Turkish Lira", nullptr));
        currs->setItemText(17, QCoreApplication::translate("dbinterface", "INR \342\200\224 Indian Rupee", nullptr));
        currs->setItemText(18, QCoreApplication::translate("dbinterface", "BRL \342\200\224 Brazilian Real", nullptr));
        currs->setItemText(19, QCoreApplication::translate("dbinterface", "ZAR \342\200\224 South African Rand", nullptr));
        currs->setItemText(20, QCoreApplication::translate("dbinterface", "MXN \342\200\224 Mexican Peso", nullptr));
        currs->setItemText(21, QCoreApplication::translate("dbinterface", "SGD \342\200\224 Singapore Dollar", nullptr));
        currs->setItemText(22, QCoreApplication::translate("dbinterface", "HKD \342\200\224 Hong Kong Dollar", nullptr));
        currs->setItemText(23, QCoreApplication::translate("dbinterface", "KRW \342\200\224 South Korean Won", nullptr));
        currs->setItemText(24, QCoreApplication::translate("dbinterface", "THB \342\200\224 Thai Baht", nullptr));
        currs->setItemText(25, QCoreApplication::translate("dbinterface", "MYR \342\200\224 Malaysian Ringgit", nullptr));
        currs->setItemText(26, QCoreApplication::translate("dbinterface", "IDR \342\200\224 Indonesian Rupiah", nullptr));
        currs->setItemText(27, QCoreApplication::translate("dbinterface", "VND \342\200\224 Vietnamese Dong", nullptr));
        currs->setItemText(28, QCoreApplication::translate("dbinterface", "AED \342\200\224 UAE Dirham", nullptr));
        currs->setItemText(29, QCoreApplication::translate("dbinterface", "SAR \342\200\224 Saudi Riyal", nullptr));
        currs->setItemText(30, QCoreApplication::translate("dbinterface", "EGP \342\200\224 Egyptian Pound", nullptr));

        categories->setItemText(0, QCoreApplication::translate("dbinterface", "Rent", nullptr));
        categories->setItemText(1, QCoreApplication::translate("dbinterface", "Taxes", nullptr));
        categories->setItemText(2, QCoreApplication::translate("dbinterface", "Electricity", nullptr));
        categories->setItemText(3, QCoreApplication::translate("dbinterface", "Water", nullptr));
        categories->setItemText(4, QCoreApplication::translate("dbinterface", "Gas", nullptr));
        categories->setItemText(5, QCoreApplication::translate("dbinterface", "Internet", nullptr));
        categories->setItemText(6, QCoreApplication::translate("dbinterface", "Food", nullptr));
        categories->setItemText(7, QCoreApplication::translate("dbinterface", "Transportation", nullptr));
        categories->setItemText(8, QCoreApplication::translate("dbinterface", "Health", nullptr));
        categories->setItemText(9, QCoreApplication::translate("dbinterface", "Education", nullptr));
        categories->setItemText(10, QCoreApplication::translate("dbinterface", "Entertainment", nullptr));
        categories->setItemText(11, QCoreApplication::translate("dbinterface", "Other", nullptr));
        categories->setItemText(12, QCoreApplication::translate("dbinterface", "Salary", nullptr));
        categories->setItemText(13, QCoreApplication::translate("dbinterface", "Gift", nullptr));
        categories->setItemText(14, QCoreApplication::translate("dbinterface", "Bonus", nullptr));
        categories->setItemText(15, QCoreApplication::translate("dbinterface", "Cashback", nullptr));
        categories->setItemText(16, QCoreApplication::translate("dbinterface", "Freelance", nullptr));

        l_total->setText(QCoreApplication::translate("dbinterface", "total :", nullptr));
        l_loss->setText(QCoreApplication::translate("dbinterface", "loss :", nullptr));
        l_profit->setText(QCoreApplication::translate("dbinterface", "profit :", nullptr));
        select->setText(QCoreApplication::translate("dbinterface", "select", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dbinterface: public Ui_dbinterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DBINTERFACE_H
