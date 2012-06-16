#ifndef SALES_H
#define SALES_H

#include <QAbstractTableModel>
#include <qvector.h>
#include <qfile.h>
#include <qfont.h>
#include "sale.h"
#include <qvalidator.h>
class Sales : public QAbstractTableModel
{
	Q_OBJECT

public:
	Sales(QObject *parent = 0);
	~Sales();
	int rowCount(const QModelIndex &parent = QModelIndex()) const;
	int columnCount(const QModelIndex &parent = QModelIndex()) const;

	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
	QVariant headerData(const QModelIndex &index, Qt::Orientation orientation, int role) const;

	bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
	Qt::ItemFlags flags(const QModelIndex &index) const;

	sale* searchById(int);
private:
	QVector<sale> &sales;
	int newId;
private slots:
	void add();
public slots:
	void remove(const QModelIndex &index);
};

#endif // SALES_H
