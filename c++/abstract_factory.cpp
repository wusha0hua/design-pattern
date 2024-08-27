#include <string>
#include <cassert>

class AbstractProductA {
public:
	virtual std::string manual() = 0;
};

class AbstractProductB {
public:
	virtual std::string manual() = 0;
};

class ConcreteProductA1: public AbstractProductA {
public:
	std::string manual() override {
		return "A1";
	}
};

class ConcreteProductA2: public AbstractProductA {
public:
	std::string manual() override {
		return "A2";
	}
};

class ConcreteProductB1: public AbstractProductB {
public:
	std::string manual() override {
		return "B1";
	}
};

class ConcreteProductB2: public AbstractProductB {
public:
	std::string manual() override {
		return "B2";
	}
};

class AbstractFactory {
public:
	virtual AbstractProductA *productA() = 0;
	virtual AbstractProductB *productB() = 0;
};

class ConcreteFactory1: public AbstractFactory {
public:
	AbstractProductA* productA() {
		return new ConcreteProductA1();
	}
	AbstractProductB* productB() {
		return new ConcreteProductB1();
	}
};

class ConcreteFactory2: public AbstractFactory {
public:
	AbstractProductA* productA() {
		return new ConcreteProductA2();
	}
	AbstractProductB* productB() {
		return new ConcreteProductB2();
	}
};

void client(AbstractFactory *factory, std::pair<std::string, std::string> products) {
	auto [pA, pB] = products;
	AbstractProductA *a = factory->productA();
	assert(pA == a->manual());
	AbstractProductB *b = factory->productB();
	assert(pB == b->manual());
}

void server() {
	AbstractFactory *f1 = new ConcreteFactory1();
	AbstractFactory *f2 = new ConcreteFactory2();
	client(f1, {"A1", "B1"});
	client(f2, {"A2", "B2"});
}
