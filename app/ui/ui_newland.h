/********************************************************************************
** Form generated from reading UI file 'newland.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWLAND_H
#define UI_NEWLAND_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_newland
{
public:
    QGridLayout *gridLayout;
    QTextEdit *textEdit;
    QTableWidget *tableWidget;
    QSpacerItem *verticalSpacer;
    QComboBox *formats;
    QPushButton *export_btn;
    QPushButton *update_btn;

    void setupUi(QWidget *newland)
    {
        if (newland->objectName().isEmpty())
            newland->setObjectName("newland");
        newland->resize(372, 274);
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        newland->setFont(font);
        gridLayout = new QGridLayout(newland);
        gridLayout->setObjectName("gridLayout");
        textEdit = new QTextEdit(newland);
        textEdit->setObjectName("textEdit");

        gridLayout->addWidget(textEdit, 0, 0, 1, 1);

        tableWidget = new QTableWidget(newland);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        if (tableWidget->rowCount() < 6)
            tableWidget->setRowCount(6);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(4, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(5, __qtablewidgetitem7);
        tableWidget->setObjectName("tableWidget");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy);
        tableWidget->setMinimumSize(QSize(217, 191));
        tableWidget->setFont(font);

        gridLayout->addWidget(tableWidget, 0, 1, 1, 3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 1, 1, 1);

        formats = new QComboBox(newland);
        formats->addItem(QString());
        formats->addItem(QString());
        formats->setObjectName("formats");

        gridLayout->addWidget(formats, 2, 0, 1, 1);

        export_btn = new QPushButton(newland);
        export_btn->setObjectName("export_btn");

        gridLayout->addWidget(export_btn, 2, 2, 1, 1);

        update_btn = new QPushButton(newland);
        update_btn->setObjectName("update_btn");

        gridLayout->addWidget(update_btn, 2, 3, 1, 1);


        retranslateUi(newland);

        QMetaObject::connectSlotsByName(newland);
    } // setupUi

    void retranslateUi(QWidget *newland)
    {
        newland->setWindowTitle(QCoreApplication::translate("newland", "Form", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("newland", "rate (USD)", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("newland", "rate (EUR)", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("newland", "Bitcoin", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("newland", "Ethereum", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("newland", "Tether", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("newland", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->verticalHeaderItem(4);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("newland", "Binance Coin", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->verticalHeaderItem(5);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("newland", "Ripple", nullptr));
        formats->setItemText(0, QCoreApplication::translate("newland", "json", nullptr));
        formats->setItemText(1, QCoreApplication::translate("newland", "csv", nullptr));

        export_btn->setText(QCoreApplication::translate("newland", "export", nullptr));
        update_btn->setText(QCoreApplication::translate("newland", "update", nullptr));
    } // retranslateUi

};

namespace Ui {
    class newland: public Ui_newland {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWLAND_H
