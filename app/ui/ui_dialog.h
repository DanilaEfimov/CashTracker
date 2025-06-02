/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QGridLayout *gridLayout;
    QPushButton *browse_btn;
    QLineEdit *path_input;
    QPushButton *ok_btn;
    QLabel *l_path;
    QFrame *line;
    QSpacerItem *horizontalSpacer;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(312, 148);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Dialog->sizePolicy().hasHeightForWidth());
        Dialog->setSizePolicy(sizePolicy);
        QFont font;
        font.setBold(true);
        Dialog->setFont(font);
        gridLayout = new QGridLayout(Dialog);
        gridLayout->setObjectName("gridLayout");
        browse_btn = new QPushButton(Dialog);
        browse_btn->setObjectName("browse_btn");

        gridLayout->addWidget(browse_btn, 1, 2, 1, 1);

        path_input = new QLineEdit(Dialog);
        path_input->setObjectName("path_input");

        gridLayout->addWidget(path_input, 1, 1, 1, 1);

        ok_btn = new QPushButton(Dialog);
        ok_btn->setObjectName("ok_btn");

        gridLayout->addWidget(ok_btn, 3, 2, 1, 2);

        l_path = new QLabel(Dialog);
        l_path->setObjectName("l_path");

        gridLayout->addWidget(l_path, 1, 0, 1, 1);

        line = new QFrame(Dialog);
        line->setObjectName("line");
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);

        gridLayout->addWidget(line, 2, 0, 1, 3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 3, 0, 1, 2);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        browse_btn->setText(QCoreApplication::translate("Dialog", "browse...", nullptr));
        ok_btn->setText(QCoreApplication::translate("Dialog", "OK", nullptr));
        l_path->setText(QCoreApplication::translate("Dialog", "path :", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
