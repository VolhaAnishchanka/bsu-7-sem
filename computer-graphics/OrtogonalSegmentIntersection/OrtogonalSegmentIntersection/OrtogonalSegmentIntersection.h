#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_OrtogonalSegmentIntersection.h"
#include "OrtogonalSegments.h"
#include <QMainWindow>
#include <QMouseEvent>
#include <QPainter>

class OrtogonalSegmentIntersection : public QMainWindow
{
	Q_OBJECT

public:
	OrtogonalSegmentIntersection(QWidget *parent = Q_NULLPTR);
	~OrtogonalSegmentIntersection();

	void mousePressEvent(QMouseEvent* event) override;
	void keyPressEvent(QKeyEvent* event) override;
	void paintEvent(QPaintEvent *event);

private:
	Ui::OrtogonalSegmentIntersectionClass* ui;
};
