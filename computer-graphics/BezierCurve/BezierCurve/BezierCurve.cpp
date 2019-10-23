#include "BezierCurve.h"

#include<string>
#include <algorithm>

#include <QtAlgorithms>
#include <QDateTime>
#include <QMap>
#include <QSet>
#include <QVector>
#include <QPoint>

class Point
{
public:
	Point(double x, double y)
	{
	    x_coord = x;
		y_coord = y;
	}

	Point(QPoint point)
	{
		this->x_coord = point.x();
		this->y_coord = point.y();
	}

	double x()
	{
		return x_coord;
	}

	double y()
	{
		return y_coord;
	}

private:
	double x_coord;
	double y_coord;
};

QVector<QPoint> points;
QVector<Point> curve;

BezierCurve::BezierCurve(QWidget *parent)
	: QMainWindow(parent)
{
	setFixedSize(QSize(1280, 840));
	ui->setupUi(this);
}

void BezierCurve::mousePressEvent(QMouseEvent* event)
{
	QPoint point(event ->x(), event ->y());
	std::string text = std::string("X = ");
	text.append(std::to_string(point.x()));
	text.append(", Y = ");
	text.append(std::to_string(point.y()));

	points.append(point);
	ui->label->setText(QString::fromStdString(text));

	curve.clear();
	repaint();	
}

Point divide(Point a, Point b, double t)
{
	return Point(a.x() * (1. - t) + b.x() * t, a.y() * (1. - t) + b.y() * t);
}

Point deCasteljau(double t, int n, int m)
{
	if (n == 0) {
		return points[m];
	}

	return divide(deCasteljau(t, n - 1, m), deCasteljau(t, n - 1, m + 1), t);
}

void drawCurve()
{
	if (!points.isEmpty())
	{
		for (double i = 0; i <= 1; i += 0.001)
		{
			curve.append(deCasteljau(i, points.size() - 1, 0));
		}
		points.clear();
	}
}

void BezierCurve::keyPressEvent(QKeyEvent* event)
{
	if (event->key() == Qt::Key_Q)
	{
		drawCurve();
		repaint();
		ui -> label ->setText("Bezier Curve drawn");
	}
}

void BezierCurve::paintEvent(QPaintEvent*)
{
	QPainter painter(this);
	painter.setPen(Qt::black);
	painter.setBrush(QBrush(Qt::black));

	for (auto point : points)
	{
		painter.drawEllipse(point, 3, 3);
	}

	painter.setPen(Qt::black);
	painter.setBrush(QBrush(Qt::black));

	if (!curve.isEmpty())
	{
		QVector<QPoint> points;

		for (auto point : curve)
		{
			points.append(QPoint(point.x(), point.y()));
		}
		painter.drawPolyline(points);
	}
}

BezierCurve::~BezierCurve()
{
}