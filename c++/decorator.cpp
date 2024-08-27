#include <string>
#include <cassert>

class AbstractComponet {
public:
	virtual std::string build() = 0;
};

class ConcreteComponet: public AbstractComponet {
public:
	std::string build() override {
		return "base part\n";
	}
};

class AbstractDecorator {
protected:
	AbstractComponet *componet = nullptr;
public:
	AbstractDecorator(AbstractComponet *componet): componet(componet) {}
	virtual std::string build() {
		return componet->build();
	}
};

class ConcreteDecorator: public AbstractDecorator {
public:
	ConcreteDecorator(AbstractComponet *componet): AbstractDecorator(componet) {}
	std::string build() override {
		return componet->build() + "additional part\n";
	}
};

void client() {
	AbstractComponet *componet = new ConcreteComponet();
	AbstractDecorator *decorator = new ConcreteDecorator(componet);
	assert(decorator->build() == "base part\nadditional part\n");
}
