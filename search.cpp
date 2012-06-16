#include "search.h"

search::search(Sales* sales,QWidget *parent): sales(sales),QWidget(parent) {
	QGridLayout* layout = new QGridLayout();
	id = new QLineEdit();
	id->setValidator(new QIntValidator());
	pret = new QLineEdit();
	pret->setValidator(new QIntValidator());
	cant = new QLineEdit();
	cant->setValidator(new QIntValidator());
	nume = new QLineEdit();
	QRegExp rx("[0-9]{4}-[0-9]{2}-[0-9]{2}");
	date = new QLineEdit();
	date->setValidator(new QRegExpValidator(rx));
	descr = new QTextEdit();
	pretTotal = new QLabel();
	cauta = new QPushButton("Cauta");
	save = new QPushButton("Salveaza");
	lista = new QPushButton("Inapoi");

	QVBoxLayout* parteaStanga = new QVBoxLayout();
	QVBoxLayout* parteaDreapta = new QVBoxLayout();

	parteaStanga->addWidget(id);
	parteaStanga->addWidget(cauta);
	parteaStanga->addStretch();

	parteaDreapta->addWidget(nume);
	parteaDreapta->addWidget(descr);
	parteaDreapta->addWidget(pret);
	parteaDreapta->addWidget(cant);
	parteaDreapta->addWidget(pretTotal);
	parteaDreapta->addWidget(date);

	layout->addLayout(parteaStanga,0,0,5,1);
	layout->addLayout(parteaDreapta,0,1);
	layout->addWidget(save,1,0);
	layout->addWidget(lista,1,1);
	setLayout(layout);

	connect(lista,SIGNAL(clicked()),parent,SLOT(mainWin()));
	connect(cauta,SIGNAL(clicked()),this,SLOT(searchId()));
	connect(save,SIGNAL(clicked()),parent,SLOT(saveSale()));
	connect(pret,SIGNAL(textEdited(const QString)),this,SLOT(updateTotal()));
	connect(cant,SIGNAL(textEdited(const QString)),this,SLOT(updateTotal()));
}

void search::searchId() {
	int idNr = id->text().toInt();
	sale* s = sales->searchById(idNr);
	if (s != 0) {
		pret->setText(QString::number(s->getPrice()));
		cant->setText(QString::number(s->getQuantity()));
		nume->setText(s->getName());
		date->setText(s->getDate().toString("yyyy-MM-dd"));
		descr->setText(s->getDescr());
		pretTotal->setText(QString::number(s->getPrice()*s->getQuantity()));
	}
	else {
		id->setToolTip("Idul nu a fost gasit");
	}

}

void search::updateTotal() {
	pretTotal->setText(QString::number(pret->text().toInt()*cant->text().toInt()));
}
void search::saveSale() {
	sale* s = sales->searchById(id->text().toInt());
	s->setPrice(pret->text().toInt());
	s->setQuantity(cant->text().toInt());
	s->setName(nume->text());
	s->setDescr(descr->toPlainText());
	s->setDate(QDate().fromString(date->text(),"yyyy-MM-dd"));
}
search::~search()
{

}
