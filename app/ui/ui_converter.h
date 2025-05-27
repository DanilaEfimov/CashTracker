/********************************************************************************
** Form generated from reading UI file 'converter.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONVERTER_H
#define UI_CONVERTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_converter
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QComboBox *fromcur;
    QLabel *l_tempc_cut;
    QSpacerItem *verticalSpacer;
    QLabel *l_target_cur;
    QPushButton *convert_btn;
    QLabel *l_result;
    QLineEdit *amount_output;
    QSpacerItem *verticalSpacer_3;
    QLineEdit *amount_input;
    QLabel *l_amount;
    QSpacerItem *verticalSpacer_2;
    QComboBox *tocur;

    void setupUi(QWidget *converter)
    {
        if (converter->objectName().isEmpty())
            converter->setObjectName("converter");
        converter->resize(390, 326);
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        converter->setFont(font);
        gridLayout_2 = new QGridLayout(converter);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        fromcur = new QComboBox(converter);
        fromcur->addItem(QString());
        fromcur->addItem(QString());
        fromcur->addItem(QString());
        fromcur->addItem(QString());
        fromcur->addItem(QString());
        fromcur->addItem(QString());
        fromcur->addItem(QString());
        fromcur->addItem(QString());
        fromcur->addItem(QString());
        fromcur->addItem(QString());
        fromcur->addItem(QString());
        fromcur->addItem(QString());
        fromcur->addItem(QString());
        fromcur->addItem(QString());
        fromcur->addItem(QString());
        fromcur->addItem(QString());
        fromcur->addItem(QString());
        fromcur->addItem(QString());
        fromcur->addItem(QString());
        fromcur->addItem(QString());
        fromcur->addItem(QString());
        fromcur->addItem(QString());
        fromcur->addItem(QString());
        fromcur->addItem(QString());
        fromcur->addItem(QString());
        fromcur->addItem(QString());
        fromcur->addItem(QString());
        fromcur->addItem(QString());
        fromcur->addItem(QString());
        fromcur->addItem(QString());
        fromcur->addItem(QString());
        fromcur->setObjectName("fromcur");

        gridLayout->addWidget(fromcur, 1, 1, 1, 1);

        l_tempc_cut = new QLabel(converter);
        l_tempc_cut->setObjectName("l_tempc_cut");

        gridLayout->addWidget(l_tempc_cut, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 4, 1, 1, 2);

        l_target_cur = new QLabel(converter);
        l_target_cur->setObjectName("l_target_cur");

        gridLayout->addWidget(l_target_cur, 2, 0, 1, 1);

        convert_btn = new QPushButton(converter);
        convert_btn->setObjectName("convert_btn");

        gridLayout->addWidget(convert_btn, 7, 2, 1, 1);

        l_result = new QLabel(converter);
        l_result->setObjectName("l_result");

        gridLayout->addWidget(l_result, 7, 0, 1, 1);

        amount_output = new QLineEdit(converter);
        amount_output->setObjectName("amount_output");

        gridLayout->addWidget(amount_output, 7, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 0, 1, 1, 2);

        amount_input = new QLineEdit(converter);
        amount_input->setObjectName("amount_input");

        gridLayout->addWidget(amount_input, 3, 1, 1, 1);

        l_amount = new QLabel(converter);
        l_amount->setObjectName("l_amount");

        gridLayout->addWidget(l_amount, 3, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 9, 1, 1, 2);

        tocur = new QComboBox(converter);
        tocur->addItem(QString());
        tocur->addItem(QString());
        tocur->addItem(QString());
        tocur->addItem(QString());
        tocur->addItem(QString());
        tocur->addItem(QString());
        tocur->addItem(QString());
        tocur->addItem(QString());
        tocur->addItem(QString());
        tocur->addItem(QString());
        tocur->addItem(QString());
        tocur->addItem(QString());
        tocur->addItem(QString());
        tocur->addItem(QString());
        tocur->addItem(QString());
        tocur->addItem(QString());
        tocur->addItem(QString());
        tocur->addItem(QString());
        tocur->addItem(QString());
        tocur->addItem(QString());
        tocur->addItem(QString());
        tocur->addItem(QString());
        tocur->addItem(QString());
        tocur->addItem(QString());
        tocur->addItem(QString());
        tocur->addItem(QString());
        tocur->addItem(QString());
        tocur->addItem(QString());
        tocur->addItem(QString());
        tocur->addItem(QString());
        tocur->addItem(QString());
        tocur->setObjectName("tocur");

        gridLayout->addWidget(tocur, 2, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(converter);

        QMetaObject::connectSlotsByName(converter);
    } // setupUi

    void retranslateUi(QWidget *converter)
    {
        converter->setWindowTitle(QCoreApplication::translate("converter", "Form", nullptr));
        fromcur->setItemText(0, QCoreApplication::translate("converter", "USD \342\200\224 United States Dollar", nullptr));
        fromcur->setItemText(1, QCoreApplication::translate("converter", "EUR \342\200\224 Euro", nullptr));
        fromcur->setItemText(2, QCoreApplication::translate("converter", "GBP \342\200\224 Pound Sterling", nullptr));
        fromcur->setItemText(3, QCoreApplication::translate("converter", "JPY \342\200\224 Japanese Yen", nullptr));
        fromcur->setItemText(4, QCoreApplication::translate("converter", "CNY \342\200\224 Chinese Yuan Renminbi", nullptr));
        fromcur->setItemText(5, QCoreApplication::translate("converter", "CHF \342\200\224 Swiss Franc", nullptr));
        fromcur->setItemText(6, QCoreApplication::translate("converter", "AUD \342\200\224 Australian Dollar", nullptr));
        fromcur->setItemText(7, QCoreApplication::translate("converter", "CAD \342\200\224 Canadian Dollar", nullptr));
        fromcur->setItemText(8, QCoreApplication::translate("converter", "NZD \342\200\224 New Zealand Dollar", nullptr));
        fromcur->setItemText(9, QCoreApplication::translate("converter", "SEK \342\200\224 Swedish Krona", nullptr));
        fromcur->setItemText(10, QCoreApplication::translate("converter", "NOK \342\200\224 Norwegian Krone", nullptr));
        fromcur->setItemText(11, QCoreApplication::translate("converter", "DKK \342\200\224 Danish Krone", nullptr));
        fromcur->setItemText(12, QCoreApplication::translate("converter", "RUB \342\200\224 Russian Ruble", nullptr));
        fromcur->setItemText(13, QCoreApplication::translate("converter", "PLN \342\200\224 Polish Zloty", nullptr));
        fromcur->setItemText(14, QCoreApplication::translate("converter", "CZK \342\200\224 Czech Koruna", nullptr));
        fromcur->setItemText(15, QCoreApplication::translate("converter", "HUF \342\200\224 Hungarian Forint", nullptr));
        fromcur->setItemText(16, QCoreApplication::translate("converter", "TRY \342\200\224 Turkish Lira", nullptr));
        fromcur->setItemText(17, QCoreApplication::translate("converter", "INR \342\200\224 Indian Rupee", nullptr));
        fromcur->setItemText(18, QCoreApplication::translate("converter", "BRL \342\200\224 Brazilian Real", nullptr));
        fromcur->setItemText(19, QCoreApplication::translate("converter", "ZAR \342\200\224 South African Rand", nullptr));
        fromcur->setItemText(20, QCoreApplication::translate("converter", "MXN \342\200\224 Mexican Peso", nullptr));
        fromcur->setItemText(21, QCoreApplication::translate("converter", "SGD \342\200\224 Singapore Dollar", nullptr));
        fromcur->setItemText(22, QCoreApplication::translate("converter", "HKD \342\200\224 Hong Kong Dollar", nullptr));
        fromcur->setItemText(23, QCoreApplication::translate("converter", "KRW \342\200\224 South Korean Won", nullptr));
        fromcur->setItemText(24, QCoreApplication::translate("converter", "THB \342\200\224 Thai Baht", nullptr));
        fromcur->setItemText(25, QCoreApplication::translate("converter", "MYR \342\200\224 Malaysian Ringgit", nullptr));
        fromcur->setItemText(26, QCoreApplication::translate("converter", "IDR \342\200\224 Indonesian Rupiah", nullptr));
        fromcur->setItemText(27, QCoreApplication::translate("converter", "VND \342\200\224 Vietnamese Dong", nullptr));
        fromcur->setItemText(28, QCoreApplication::translate("converter", "AED \342\200\224 UAE Dirham", nullptr));
        fromcur->setItemText(29, QCoreApplication::translate("converter", "SAR \342\200\224 Saudi Riyal", nullptr));
        fromcur->setItemText(30, QCoreApplication::translate("converter", "EGP \342\200\224 Egyptian Pound", nullptr));

        l_tempc_cut->setText(QCoreApplication::translate("converter", "temp cur :", nullptr));
        l_target_cur->setText(QCoreApplication::translate("converter", "target cur :", nullptr));
        convert_btn->setText(QCoreApplication::translate("converter", "convert", nullptr));
        l_result->setText(QCoreApplication::translate("converter", "result :", nullptr));
        l_amount->setText(QCoreApplication::translate("converter", "amount :", nullptr));
        tocur->setItemText(0, QCoreApplication::translate("converter", "USD \342\200\224 United States Dollar", nullptr));
        tocur->setItemText(1, QCoreApplication::translate("converter", "EUR \342\200\224 Euro", nullptr));
        tocur->setItemText(2, QCoreApplication::translate("converter", "GBP \342\200\224 Pound Sterling", nullptr));
        tocur->setItemText(3, QCoreApplication::translate("converter", "JPY \342\200\224 Japanese Yen", nullptr));
        tocur->setItemText(4, QCoreApplication::translate("converter", "CNY \342\200\224 Chinese Yuan Renminbi", nullptr));
        tocur->setItemText(5, QCoreApplication::translate("converter", "CHF \342\200\224 Swiss Franc", nullptr));
        tocur->setItemText(6, QCoreApplication::translate("converter", "AUD \342\200\224 Australian Dollar", nullptr));
        tocur->setItemText(7, QCoreApplication::translate("converter", "CAD \342\200\224 Canadian Dollar", nullptr));
        tocur->setItemText(8, QCoreApplication::translate("converter", "NZD \342\200\224 New Zealand Dollar", nullptr));
        tocur->setItemText(9, QCoreApplication::translate("converter", "SEK \342\200\224 Swedish Krona", nullptr));
        tocur->setItemText(10, QCoreApplication::translate("converter", "NOK \342\200\224 Norwegian Krone", nullptr));
        tocur->setItemText(11, QCoreApplication::translate("converter", "DKK \342\200\224 Danish Krone", nullptr));
        tocur->setItemText(12, QCoreApplication::translate("converter", "RUB \342\200\224 Russian Ruble", nullptr));
        tocur->setItemText(13, QCoreApplication::translate("converter", "PLN \342\200\224 Polish Zloty", nullptr));
        tocur->setItemText(14, QCoreApplication::translate("converter", "CZK \342\200\224 Czech Koruna", nullptr));
        tocur->setItemText(15, QCoreApplication::translate("converter", "HUF \342\200\224 Hungarian Forint", nullptr));
        tocur->setItemText(16, QCoreApplication::translate("converter", "TRY \342\200\224 Turkish Lira", nullptr));
        tocur->setItemText(17, QCoreApplication::translate("converter", "INR \342\200\224 Indian Rupee", nullptr));
        tocur->setItemText(18, QCoreApplication::translate("converter", "BRL \342\200\224 Brazilian Real", nullptr));
        tocur->setItemText(19, QCoreApplication::translate("converter", "ZAR \342\200\224 South African Rand", nullptr));
        tocur->setItemText(20, QCoreApplication::translate("converter", "MXN \342\200\224 Mexican Peso", nullptr));
        tocur->setItemText(21, QCoreApplication::translate("converter", "SGD \342\200\224 Singapore Dollar", nullptr));
        tocur->setItemText(22, QCoreApplication::translate("converter", "HKD \342\200\224 Hong Kong Dollar", nullptr));
        tocur->setItemText(23, QCoreApplication::translate("converter", "KRW \342\200\224 South Korean Won", nullptr));
        tocur->setItemText(24, QCoreApplication::translate("converter", "THB \342\200\224 Thai Baht", nullptr));
        tocur->setItemText(25, QCoreApplication::translate("converter", "MYR \342\200\224 Malaysian Ringgit", nullptr));
        tocur->setItemText(26, QCoreApplication::translate("converter", "IDR \342\200\224 Indonesian Rupiah", nullptr));
        tocur->setItemText(27, QCoreApplication::translate("converter", "VND \342\200\224 Vietnamese Dong", nullptr));
        tocur->setItemText(28, QCoreApplication::translate("converter", "AED \342\200\224 UAE Dirham", nullptr));
        tocur->setItemText(29, QCoreApplication::translate("converter", "SAR \342\200\224 Saudi Riyal", nullptr));
        tocur->setItemText(30, QCoreApplication::translate("converter", "EGP \342\200\224 Egyptian Pound", nullptr));

    } // retranslateUi

};

namespace Ui {
    class converter: public Ui_converter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONVERTER_H
