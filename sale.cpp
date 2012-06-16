#include "sale.h"


sale::sale(void): id(0),name(""),descr(""),price(0),quantity(0),date(QDate()) {
}

sale::sale(int id,QString name,QString descr,int price,int quantity,QDate date):id(id),name(name),descr(descr),price(price),quantity(quantity),date(date){
}

sale::sale(const sale& other) {
	id = other.id;
	name = other.name;
	descr = other.descr;
	price = other.price;
	quantity = other.quantity;
	date = other.date;
}
sale& sale::operator=(const sale &other) {
	if (this != &other) {
		id = other.id;
		name = other.name;
		descr = other.descr;
		price = other.price;
		quantity = other.quantity;
		date = other.date;
	}
	return *this;
}
QTextStream& operator<<(QTextStream& output, const sale& p) {
	output<<p.id<<endl<<p.name<<endl<<p.descr<<endl<<p.price<<endl<<p.quantity<<endl<<p.date.toString("yyyy-MM-dd")<<endl;
	return output;
}

QTextStream& operator>>(QTextStream& input, sale& p) {
	p.id = input.readLine().toInt();
	p.name = input.readLine();
	p.descr = input.readLine();
	p.price = input.readLine().toInt();
	p.quantity = input.readLine().toInt();
	QString date = input.readLine();
	p.date = p.date.fromString(date,"yyyy-MM-dd");
	return input;
}

void sale::setId(int id) { this->id = id; } 
int sale::getId() { return this->id; }
void sale::setName(QString name) { this->name = name; } 
QString sale::getName() { return this->name; }
void sale::setDescr(QString descr) { this->descr = descr; } 
QString sale::getDescr() { return this->descr; }
void sale::setPrice(int price) { this->price = price; } 
int sale::getPrice() { return this->price; }
void sale::setQuantity(int quantity) { this->quantity = quantity; } 
int sale::getQuantity() { return this->quantity; }
void sale::setDate(QDate date) { this->date = date; } 
void sale::setDate(QString date) { 
	this->date = QDate(date.left(4).toInt(),date.left(7).right(2).toInt(),date.right(2).toInt());
}
QDate sale::getDate() { return this->date; }

bool sale::isValid() {
	return id != 0 && date != QDate() && name != "" && price !=0 && quantity > 0;
}
sale::~sale(void)
{
}
