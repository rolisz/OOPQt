#include "poo1.h"
#include <QtGui/QApplication>
#include <qdesktopwidget.h>
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	poo1 w;
	w.setGeometry(
    QStyle::alignedRect(
        Qt::LeftToRight,
        Qt::AlignCenter,
        QSize(w.size().expandedTo(QSize(843,400))),
        a.desktop()->availableGeometry()
    ));
	w.show();
	return a.exec();
}
