#include "OrtogonalSegments.h"
#include <QVector>
#include <cstdlib>
#include <map>

OrtogonalSegments::OrtogonalSegments()
{

}
void OrtogonalSegments::generate_segments(int size, int max_x, int min_y, int max_y)
{
	clear();
	int size_split = rand() % size;
	//horisontal
	for (int i = 0; i < size_split / 2; i++)
	{
		double x1 = rand() % (max_x);
		double x2 = rand() % (max_x);
		double y = rand() % (max_y - min_y) + min_y;

		if (x1 > x2)
		{
			std::swap(x1, x2);
		}
		segments.append(Segment(Point(x1, y), Point(x2, y)));
	}

	//vertical
	for (int i = 0; i < size - size_split; i++)
	{
		double x = rand() % (max_x);
		double y1 = rand() % (max_y - min_y) + min_y;
		double y2 = rand() % (max_y - min_y) + min_y;
		if (y1 < y2)
		{
			std::swap(y1, y2);
		}
		segments.append(Segment(Point(x, y1), Point(x, y2)));
	}
}



int OrtogonalSegments::calculate_intersections()
{
	QVector<std::pair<Point, int>> steps;

	for (int i = 0; i < segments.size(); i++)
	{
		Segment seg = segments[i];
		steps.append(std::pair<Point, int>(seg.start(), i));
		if (seg.isHorisontal()) {
			steps.append(std::pair<Point, int>(seg.end(), i));
		}
	}

	std::sort(steps.begin(), steps.end(), [](auto & lhs, auto & rhs)
	{
		bool x_val = lhs.first.x() == rhs.first.x();
		return x_val ? lhs.first.y() < rhs.first.y() : lhs.first.x() < rhs.first.x();
	});


	std::map<int, int> l;
	intersections.clear();

	for (std::pair<Point, int> kv : steps)
	{
		Point x = kv.first;
		int i = kv.second;
		Segment segment = segments[i];

		if (segment.isHorisontal())
		{
			auto key = l.find(segment.start().y());
			if (key == l.end())
			{
				l.insert(std::pair<int, int>(segment.qstart().y(), i));
			}
			else
			{
				l.erase(key);
			}
		}

		else
		{
			auto start = l.lower_bound(segment.qend().y());
			auto end = l.upper_bound(segment.qstart().y());
			
			while (start != end && start != l.end())
			{
				intersections.append(QPoint(segment.qstart().x(), start->first));
				start++;
			}
		}

	}

	return intersections.size();
}

QVector<Segment> OrtogonalSegments::get_segments()
{
	return segments;
}

QVector<QPoint> OrtogonalSegments::get_intersections()
{
	return intersections;
}

void OrtogonalSegments::clear()
{
	segments.clear();
	intersections.clear();
}