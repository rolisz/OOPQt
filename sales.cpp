#include "sales.h"

Sales::Sales(QObject *parent):sales(*(new QVector<sale>())),QAbstractTableModel(parent) {
	QFile fisier("sales.txt");
	
	if (!fisier.open(QIODevice::ReadOnly) ) 
		throw QString("Eroare la citirea fisierului");

	QTextStream in(&fisier);
	
	while (!in.atEnd()) {
		sale s;
		in>>s;
		if (s.isValid()) {
			if (s.getId() > newId) {
				newId = s.getId() +1;
			}
			sales.append(s);
		}
	}
}

int Sales::rowCount(const QModelIndex &parent) const {
	return sales.size();
}
int Sales::columnCount(const QModelIndex &parent) const {
	return 7;
}

QVariant Sales::data(const QModelIndex &index, int role) const {
	if (role == Qt::DisplayRole) {
		switch (index.column()) {
		case 0:
			return sales[index.row()].getId();
		case 1:
			return sales[index.row()].getName();
		case 2:
			return sales[index.row()].getDescr();
		case 3:
			return sales[index.row()].getQuantity();
		case 4:
			return sales[index.row()].getPrice();
		case 5:
			return sales[index.row()].getQuantity()*sales[index.row()].getPrice();
		case 6:
			return sales[index.row()].getDate().toString("yyyy-MM-dd");
		default:
			return QVariant();
		}
		if (role == Qt::FontRole) {
			if (index.column() == 4) //change font only for cell(0,0)
			{
				QFont boldFont;
				boldFont.setBold(true);
				return boldFont;
			}
		}
	}
	return QVariant();
}
QVariant Sales::headerData(const QModelIndex &index, Qt::Orientation orientation, int role) const {
	if (role == Qt::DisplayRole) {
		if (orientation == Qt::Horizontal) {
			switch (index.column()) {
				case 0:
					return "Product ID";
				case 1:
					return "Product Name";
				case 2:
					return "Description";
				case 3:
					return "Quantity";
				case 4:
					return "Price";
				case 5:
					return "Total Price";
				case 6:
					return "Date of Sale";
				default:
					return QVariant();
			}
		}
	}
	return QVariant();
}

bool Sales::setData(const QModelIndex &index, const QVariant &value, int role) {
	int row = index.row();
	int col = index.column();
	int pos = 0;
	QRegExp rx("[0-9]{4}-[0-9]{2}-[0-9]{2}");
	if (role == Qt::EditRole) {
		switch (col) {
				case 1:
					sales[row].setName(value.toString());
					break;
				case 2:
					sales[row].setDescr(value.toString());
					break;
				case 3:
					if (!QIntValidator().validate(value.toString(),pos)) {
						return false;
					}
					sales[row].setQuantity(value.toInt());
					break;
				case 4:
					if (!QIntValidator().validate(value.toString(),pos)) {
						return false;
					}
					sales[row].setPrice(value.toInt());
					break;
				case 6:
					pos = value.toString().length();
					if (!QRegExpValidator(rx).validate(value.toString(),pos)) {
						return false;
					}
					sales[row].setDate(value.toString());
					break;
				default:
					return false;
		}
		emit dataChanged(index,index);
	}
	return true;
}
Qt::ItemFlags Sales::flags(const QModelIndex &index) const {
	if (index.column() != 0 && index.column() != 5) {
		return Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsEnabled;
	}
	else {
		return Qt::ItemIsSelectable | Qt::ItemIsEnabled;
	}
}
Sales::~Sales() {
	QFile fisier("sales.txt");
	
	if (!fisier.open(QIODevice::WriteOnly) ) 
		throw QString("Eroare la citirea fisierului");

	QTextStream out(&fisier);
	
	for (QVector<sale>::iterator it = sales.begin(); it != sales.end(); it++) {
		out<<*it;
	}
	delete &sales;
}

void Sales::add() {
	beginInsertRows(QModelIndex(),sales.size(),sales.size());
	sale s = sale();
	s.setId(newId);
	newId++;
	sales.append(s);
	endInsertRows();
}

void Sales::remove(const QModelIndex &index) {
	if (index.isValid()) {
	beginRemoveRows(QModelIndex(),index.row(),index.row());
	sales.remove(index.row());
	}
	else {
		beginRemoveRows(QModelIndex(),sales.size()-1,sales.size()-1);
		sales.pop_back();
	}
	newId--;
	endRemoveRows();
}

sale* Sales::searchById(int id) {
	for (QVector<sale>::iterator it = sales.begin(); it != sales.end(); it++) {
		if (it->getId() == id) {
			return it;
		}
	}
	return 0;
}