#ifndef SEARCH_H
#define SEARCH_H

#include <QWidget>
#include <qgridlayout.h>
#include <qpushbutton.h>
#include <qlineedit.h>
#include <qtextedit.h>
#include <qlabel.h>
#include <qlayout.h>
#include <sales.h>
#include <qvalidator.h>
class search : public QWidget
{
    Q_OBJECT

public:
    search(Sales*,QWidget *parent = 0);
    ~search();

private:
	QPushButton* cauta;
	QPushButton* save;
	QPushButton* lista;
	QLineEdit* id;
	QLineEdit* nume;
	QLineEdit* pret;
	QLineEdit* cant;
	QLineEdit* date;
	QLabel* pretTotal;
	QTextEdit* descr;
	Sales* sales;
private slots:
	void searchId();
	void updateTotal();
	void saveSale();
};

#endif // SEARCH_H
