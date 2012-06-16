#include "poo1.h"

poo1::poo1(QWidget *parent, Qt::WFlags flags):QMainWindow(parent, flags) {
	sales = new Sales(0);
	screen1 = new central(sales,this);
	screen2 = new search(sales,this);
	stackedWidget = new QStackedWidget;
	stackedWidget->addWidget(screen1);
	stackedWidget->addWidget(screen2);
	this->setCentralWidget(stackedWidget);
}

void poo1::searchWin() {
	this->setWindowTitle("Cautare vanzari");
	stackedWidget->setCurrentIndex(1);
}

void poo1::mainWin() {
	this->setWindowTitle("Administrare vanzari");
	stackedWidget->setCurrentIndex(0);
}
poo1::~poo1()
{
	delete screen1;
}
