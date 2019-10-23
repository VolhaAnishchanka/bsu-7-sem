#include "BezierCurve.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	BezierCurve w;
	w.show();
	return a.exec();
}
