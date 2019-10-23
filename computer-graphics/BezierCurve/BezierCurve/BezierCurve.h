#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_BezierCurve.h"

#include <QMainWindow>
#include <QMouseEvent>
#include <QPainter>


class BezierCurve : public QMainWindow
{
	Q_OBJECT

public:
	BezierCurve(QWidget *parent = Q_NULLPTR);
	~BezierCurve();

protected:
	void mousePressEvent(QMouseEvent* event) override;
	void keyPressEvent(QKeyEvent* event) override;
	void paintEvent(QPaintEvent *event);

private:
	Ui::BezierCurveClass* ui;
};
