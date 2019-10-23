/********************************************************************************
** Form generated from reading UI file 'BezierCurve.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BEZIERCURVE_H
#define UI_BEZIERCURVE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BezierCurveClass
{
public:
    QWidget *centralWidget;
    QLabel *label;

    void setupUi(QMainWindow *BezierCurveClass)
    {
        if (BezierCurveClass->objectName().isEmpty())
            BezierCurveClass->setObjectName(QString::fromUtf8("BezierCurveClass"));
        BezierCurveClass->resize(600, 400);
        centralWidget = new QWidget(BezierCurveClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 10, 141, 21));
        BezierCurveClass->setCentralWidget(centralWidget);

        retranslateUi(BezierCurveClass);

        QMetaObject::connectSlotsByName(BezierCurveClass);
    } // setupUi

    void retranslateUi(QMainWindow *BezierCurveClass)
    {
        BezierCurveClass->setWindowTitle(QCoreApplication::translate("BezierCurveClass", "BezierCurve", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class BezierCurveClass: public Ui_BezierCurveClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BEZIERCURVE_H
