#include <string>
#include <cassert>

class AbstractProduct {
protected:
	std::string data;
public:
	virtual void step_one() = 0;
	virtual void step_two() = 0;
	virtual const std::string& show() = 0;
};

class ConcreteProductA: public AbstractProduct {
public:
	void step_one() {
		data += "A finish step one\n";
	}
	void step_two() {
		data += "A finish step two\n";
	}
	const std::string& show() {
		return data;
	}
};

class ConcreteProductB: public AbstractProduct {
public:
	void step_one() {
		data += "B finish step one\n";
	}
	void step_two() {
		data += "B finish step two\n";
	}
	const std::string& show() {
		return data;
	}
};

class AbstractBuilder {
protected:
	AbstractProduct *product = nullptr;
public:
	virtual void part_one() = 0;
	virtual void part_two() = 0;
	virtual void part_three() = 0;
	virtual AbstractProduct* get() = 0;
};

class ConcreteBuilderA: public AbstractBuilder {
public:
	void part_one() {
		if(product == nullptr) {
			product = new ConcreteProductA();
		}
	}
	void part_two() {
		product->step_one();
	}
	void part_three() {
		product->step_two();
	}
	AbstractProduct* get() {
		AbstractProduct *result = product;
		product = nullptr;
		return result;
	}
};

class ConcreteBuilderB: public AbstractBuilder {
public:
	void part_one() {
		if(product == nullptr) {
			product = new ConcreteProductB();
		}
	}
	void part_two() {
		product->step_one();
	}
	void part_three() {
		product->step_two();
	}
	AbstractProduct* get() {
		AbstractProduct *result = product;
		product = nullptr;
		return result;
	}
};

class Director {
private:
	AbstractBuilder *builder;
public:
	void set_builder(AbstractBuilder *builder) {
		this->builder = builder;
	}
	void construct() {
		builder->part_one();
		builder->part_two();
		builder->part_three();
	}
};

void client(AbstractBuilder *builder, std::string result) {
	Director *director = new Director();
	director->set_builder(builder);
	director->construct();
	AbstractProduct *p = builder->get();
	assert(p->show() == result);
}

void server() {
	ConcreteBuilderA *builderA = new ConcreteBuilderA();
	ConcreteBuilderB *builderB = new ConcreteBuilderB();
	client(builderA, "A finish step one\nA finish step two\n");
	client(builderB, "B finish step one\nB finish step two\n");
}
