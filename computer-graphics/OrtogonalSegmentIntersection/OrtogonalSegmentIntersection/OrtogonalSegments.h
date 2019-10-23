#pragma once

#include <QVector>
#include "Segment.cpp"

class OrtogonalSegments
{
public:
	OrtogonalSegments();
	void generate_segments(int size, int max_x, int min_y, int max_y);
	int calculate_intersections();
	QVector<Segment> get_segments();
	QVector<QPoint> get_intersections();
	void clear();

private:
	QVector<Segment> segments;
	QVector<QPoint> intersections;
};