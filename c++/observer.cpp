
#include <iostream>
#include <list>
class Stock;
class Observer {
protected:
	Stock *stock;
public:
	virtual void update(int) = 0;
	Observer(Stock* stock);
	virtual ~Observer();
};

class MonitorA: public Observer {
public:
	MonitorA(Stock *stock): Observer(stock) {}
	void display(int price) {
		std::cout << price << std::endl;
	}
	void update(int price) override {
		display(price);
	}
};

class MonitorB: public Observer {
public:
	MonitorB(Stock *stock): Observer(stock) {}
	void display(int price) {
		std::cout << price << std::endl;
	}
	void update(int price) override {
		display(price);
	}
};

class Stock {
private:
	std::list<Observer*> list;
	int price = 0;
public:
	void set_price(int price) {
		this->price = price;
		notify();
	}
	void attach(Observer *o) {
		list.push_back(o);
	}
	void detach(Observer *o) {
		list.remove(o);
	}
	void notify() {
		for(auto o: list) o->update(price);
	}
};

Observer::Observer(Stock *stock): stock(stock) {
	stock->attach(this);
}
Observer::~Observer() {
	stock->detach(this);
}

void client() {
	Stock *stock = new Stock();
	MonitorA *mA = new MonitorA(stock);
	MonitorB *mB = new MonitorB(stock);
	stock->set_price(10);
}
