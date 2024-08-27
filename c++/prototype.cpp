#include <cassert>
#include <string>
class AbstractPrototype {
protected:
	std::string data;
public:
	virtual std::string get_data() = 0;
	virtual AbstractPrototype* clone() = 0;
};

class ConcretePrototype: public AbstractPrototype {
public:
	ConcretePrototype(std::string data) {
		this->data = data;
	}
	std::string get_data() {
		return data;
	}
	AbstractPrototype* clone() {
		return new ConcretePrototype(*this); 
	}
};

void client(AbstractPrototype *p) {
	AbstractPrototype *p_cloned = p->clone();
	assert(p->get_data() == p_cloned->get_data());
}

void server() {
	ConcretePrototype *p = new ConcretePrototype("original");
	client(p);
}
