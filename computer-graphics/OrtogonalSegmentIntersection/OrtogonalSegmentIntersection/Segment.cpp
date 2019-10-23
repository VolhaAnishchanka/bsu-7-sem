#include <QPoint>

class Point
{
public:
	Point()
	{
	}

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

	double x() const
	{
		return x_coord;
	}

	double y() const
	{
		return y_coord;
	}

	bool operator()(const Point& lhs, const Point& rhs)
	{
		bool x_val = lhs.x() == rhs.x();
		return x_val ? lhs.y() < rhs.y() : lhs.x() < rhs.x();
	}

private:
	double x_coord;
	double y_coord;
};


class Segment
{
public:
	Segment(Point x, Point y)
	{
		a = Point(x.x(), x.y());
		b = Point(y.x(), y.y());
	}

	QPoint qstart()
	{
		return QPoint(a.x(), a.y());
	}

	QPoint qend()
	{
		return QPoint(b.x(), b.y());
	}

	Point start()
	{
		return a;
	}

	Point end()
	{
		return b;
	}

	bool isHorisontal()
	{
		return a.y() == b.y();
	}

private:
	Point a;
	Point b;
};