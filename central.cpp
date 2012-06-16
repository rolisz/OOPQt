#include "central.h"

central::central(Sales* sales,QWidget *parent):sales(sales),QWidget(parent) {
	QGridLayout* layout = new QGridLayout();
	table = new QTableView(this);
	layout->addWidget(table,0,0);

	add = new QPushButton("Adauga");
	remove = new QPushButton("Sterge");
	dosmt = new QPushButton("Cautare");

	QVBoxLayout* vert1 = new QVBoxLayout;
	vert1->addWidget(add);
	vert1->addWidget(remove);
	vert1->addWidget(dosmt);
	vert1->addStretch();

	label1 = new QLabel("Label");
	layout->addWidget(label1,1,0);
	layout->addLayout(vert1,0,1);

	table->setModel(sales);
	connect(add, SIGNAL(clicked()), sales, SLOT(add()));

	//table->setSelectionMode(QAbstractItemView::SingleSelection);
	connect(remove, SIGNAL(clicked()),this, SLOT(removeSlot()));

	connect(dosmt,SIGNAL(clicked()),parent,SLOT(searchWin()));

	setLayout(layout);
}

 void central::removeSlot()
 {
     //get the text of the selected item
	 const QItemSelectionModel* selection = table->selectionModel();
	 if (selection->hasSelection()) {
     const QModelIndex index = selection->currentIndex();
     QString selectedText = index.data(Qt::DisplayRole).toString();
	 QString showString = QString("%1, Row %2 Col %3").arg(selectedText).arg(index.row()).arg(index.column());
     label1->setText(showString);
		sales->remove(index);
	 }
	 else {
		 sales->remove(QModelIndex());
		 label1->setText("Miaaaau");
	 }
 }
central::~central()
{
	delete sales;
}
