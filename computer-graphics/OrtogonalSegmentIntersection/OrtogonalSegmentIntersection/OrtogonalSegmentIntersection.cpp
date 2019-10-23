#include "OrtogonalSegmentIntersection.h"

#include<string>
#include <algorithm>

#include <QtAlgorithms>
#include <QDateTime>
#include <QMap>
#include <QSet>
#include <QVector>
#include <QPoint>

const int width_ = 1000;
const int height_ = 900;
const int margin = 100;
const int segment_amount = 100;

OrtogonalSegments segments;

OrtogonalSegmentIntersection::OrtogonalSegmentIntersection(QWidget *parent)
	: QMainWindow(parent)
{
	setFixedSize(QSize(width_, height_));
	ui -> setupUi(this);
}

void OrtogonalSegmentIntersection::mousePressEvent(QMouseEvent* event)
{
	segments.generate_segments(segment_amount, width_, margin, height_);
	repaint();
	ui->label->setText("Press Q to find intersections");
}

void OrtogonalSegmentIntersection::keyPressEvent(QKeyEvent* event)
{
	if (event->key() == Qt::Key_Q)
	{
		int intersections_size = segments.calculate_intersections();
		std::string text = "Intersectons number : ";
		text.append(std::to_string(intersections_size));
		text.append(". Press W to clear the window");
		ui->label->setText(QString::fromStdString(text));
		repaint();
	}
	else
	{
		if (event->key() == Qt::Key_W)
		{
			segments.clear();
			repaint();
			ui->label->setText("Mouse click to generate segments");
		}
	}
}

void OrtogonalSegmentIntersection::paintEvent(QPaintEvent*)
{
	QPainter painter(this);
	painter.setPen(Qt::black);
	painter.setBrush(QBrush(Qt::black));

	auto segments_to_draw = segments.get_segments();
	auto inersection_points = segments.get_intersections();

	if (!segments_to_draw.isEmpty())
	{
		for (auto seg : segments_to_draw)
		{
			painter.drawLine(seg.qstart(), seg.qend());
		}
	}

	if (!inersection_points.isEmpty())
	{
		painter.setBrush(QBrush(Qt::blue));
		for (auto point : inersection_points)
		{
			painter.drawEllipse(point, 3, 3);
		}
	}
}

OrtogonalSegmentIntersection::~OrtogonalSegmentIntersection()
{
}
