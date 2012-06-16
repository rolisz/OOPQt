#ifndef CENTRAL_H
#define CENTRAL_H

#include <QWidget>
#include <qtableview.h>
#include <qgridlayout.h>
#include <qlayout.h>
#include <qlabel.h>
#include <QtGui/qpushbutton.h>
#include <sales.h>
#include <QModelIndex>
class central : public QWidget
{
	Q_OBJECT

public:
	central(Sales*,QWidget *parent = 0 );
	~central();

private:
	QTableView* table;
	QPushButton* add;
	QPushButton* remove;
	QPushButton* dosmt;
	QLabel* label1,label2;
	Sales* sales;
private slots:
	void removeSlot();
};

#endif // CENTRAL_H
