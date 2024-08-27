
#include <cassert>
#include <string>
class AbstractProduct {
public:
	virtual std::string manual() = 0;
};

class ConcreteProductA: public AbstractProduct {
public:
	std::string manual() override {
		return "A";
	}
};

class ConcreteProductB: public AbstractProduct {
public:
	std::string manual() override {
		return "B";
	}
};

class AbstractFactoryMethod {
public:
	virtual AbstractProduct* produt() = 0;
};

class ConcreteFactoryMethodA: public AbstractFactoryMethod {
public:
	ConcreteProductA* produt() override {
		return new ConcreteProductA();
	}
};

class ConcreteFactoryMethodB: public AbstractFactoryMethod {
public:
	ConcreteProductB* produt() override {
		return new ConcreteProductB();
	}
};

void client(AbstractFactoryMethod* factory, std::string type) {
	AbstractProduct *product = factory->produt();
	assert(product->manual() == type);
}

void server() {
	ConcreteFactoryMethodA *factoryA = new ConcreteFactoryMethodA();
	ConcreteFactoryMethodB *factoryB = new ConcreteFactoryMethodB();
	client(factoryA, "A");
	client(factoryB, "B");
}

