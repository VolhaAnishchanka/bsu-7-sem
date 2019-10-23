/********************************************************************************
** Form generated from reading UI file 'OrtogonalSegmentIntersection.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ORTOGONALSEGMENTINTERSECTION_H
#define UI_ORTOGONALSEGMENTINTERSECTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OrtogonalSegmentIntersectionClass
{
public:
    QWidget *centralWidget;
    QLabel *label;

    void setupUi(QMainWindow *OrtogonalSegmentIntersectionClass)
    {
        if (OrtogonalSegmentIntersectionClass->objectName().isEmpty())
            OrtogonalSegmentIntersectionClass->setObjectName(QString::fromUtf8("OrtogonalSegmentIntersectionClass"));
        OrtogonalSegmentIntersectionClass->resize(600, 400);
        centralWidget = new QWidget(OrtogonalSegmentIntersectionClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 10, 361, 31));
        OrtogonalSegmentIntersectionClass->setCentralWidget(centralWidget);

        retranslateUi(OrtogonalSegmentIntersectionClass);

        QMetaObject::connectSlotsByName(OrtogonalSegmentIntersectionClass);
    } // setupUi

    void retranslateUi(QMainWindow *OrtogonalSegmentIntersectionClass)
    {
        OrtogonalSegmentIntersectionClass->setWindowTitle(QCoreApplication::translate("OrtogonalSegmentIntersectionClass", "OrtogonalSegmentIntersection", nullptr));
        label->setText(QCoreApplication::translate("OrtogonalSegmentIntersectionClass", "Click mouse to generate points", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OrtogonalSegmentIntersectionClass: public Ui_OrtogonalSegmentIntersectionClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ORTOGONALSEGMENTINTERSECTION_H
