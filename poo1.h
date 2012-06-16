#ifndef POO1_H
#define POO1_H

#include <QtGui/QMainWindow>
#include "central.h"
#include "search.h"
#include <qstackedwidget.h>
class poo1 : public QMainWindow
{
	Q_OBJECT

public:
	poo1(QWidget *parent = 0, Qt::WFlags flags = 0);
	~poo1();

private:
	QWidget* screen1;
	QWidget* screen2;
	Sales* sales;
	QStackedWidget *stackedWidget;
private slots:
	void searchWin();
	void mainWin();
};

#endif // POO1_H
