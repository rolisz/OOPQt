#pragma once
#include <qstring.h>
#include <QDate>
#include <qtextstream.h>
class sale {
public:
	friend QTextStream& operator<<(QTextStream& output, const sale& p);
	friend QTextStream& operator>>(QTextStream& input, sale& p);
	sale();
	sale(const sale&);
	sale & operator=(const sale &rhs);
	sale(int,QString,QString,int,int,QDate);
	void setId(int id);
	int getId();
	void setName(QString name);
	QString getName();
	void setDescr(QString descr);
	QString getDescr();
	void setPrice(int price);
	int getPrice();
	void setQuantity(int quantity);
	int getQuantity();
	void setDate(QDate date);
	void setDate(QString date);
	QDate getDate();
	~sale();
	bool isValid();
private:
	int id;
	QString name, descr;
	int price,quantity;
	QDate date;
};

