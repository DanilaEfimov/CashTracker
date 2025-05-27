/********************************************************************************
** Form generated from reading UI file 'progress.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROGRESS_H
#define UI_PROGRESS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_progress
{
public:
    QGridLayout *gridLayout;
    QGraphicsView *graphic;
    QComboBox *formatval;
    QPushButton *expotrb;
    QComboBox *periodval;
    QPushButton *update;

    void setupUi(QWidget *progress)
    {
        if (progress->objectName().isEmpty())
            progress->setObjectName("progress");
        progress->resize(329, 300);
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        progress->setFont(font);
        gridLayout = new QGridLayout(progress);
        gridLayout->setObjectName("gridLayout");
        graphic = new QGraphicsView(progress);
        graphic->setObjectName("graphic");

        gridLayout->addWidget(graphic, 0, 0, 1, 4);

        formatval = new QComboBox(progress);
        formatval->addItem(QString());
        formatval->addItem(QString());
        formatval->setObjectName("formatval");

        gridLayout->addWidget(formatval, 1, 0, 1, 1);

        expotrb = new QPushButton(progress);
        expotrb->setObjectName("expotrb");

        gridLayout->addWidget(expotrb, 1, 1, 1, 1);

        periodval = new QComboBox(progress);
        periodval->addItem(QString());
        periodval->addItem(QString());
        periodval->addItem(QString());
        periodval->addItem(QString());
        periodval->setObjectName("periodval");

        gridLayout->addWidget(periodval, 1, 2, 1, 1);

        update = new QPushButton(progress);
        update->setObjectName("update");

        gridLayout->addWidget(update, 1, 3, 1, 1);


        retranslateUi(progress);

        QMetaObject::connectSlotsByName(progress);
    } // setupUi

    void retranslateUi(QWidget *progress)
    {
        progress->setWindowTitle(QCoreApplication::translate("progress", "Form", nullptr));
        formatval->setItemText(0, QCoreApplication::translate("progress", "json", nullptr));
        formatval->setItemText(1, QCoreApplication::translate("progress", "csv", nullptr));

        expotrb->setText(QCoreApplication::translate("progress", "export", nullptr));
        periodval->setItemText(0, QCoreApplication::translate("progress", "last week", nullptr));
        periodval->setItemText(1, QCoreApplication::translate("progress", "last month", nullptr));
        periodval->setItemText(2, QCoreApplication::translate("progress", "last year", nullptr));
        periodval->setItemText(3, QCoreApplication::translate("progress", "all time", nullptr));

        update->setText(QCoreApplication::translate("progress", "update", nullptr));
    } // retranslateUi

};

namespace Ui {
    class progress: public Ui_progress {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROGRESS_H
