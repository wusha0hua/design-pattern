
#include <string>
#include <unordered_map>

enum class ProtoType {
	TYPE_1,
	TYPE_2,
};

class Prototype {
public:
	Prototype() {}
	Prototype(std::string name): name(name) {}
	virtual ~Prototype() {}
	virtual Prototype *clone() const = 0;
protected:
	std::string name;
};

class ConcreatePrototype1: public Prototype {
public:
	ConcreatePrototype1(std::string name): Prototype(name) {}
	Prototype *clone() const override {
		return new ConcreatePrototype1(*this);
	}
};

class ConcreatePrototype2: public Prototype {
public:
	ConcreatePrototype2(std::string name): Prototype(name) {}
	Prototype *clone() const override {
		return new ConcreatePrototype2(*this);
	}
};

class PrototypeFactory {
public:
	PrototypeFactory() {
		prototypes[ProtoType::TYPE_1] = new ConcreatePrototype1("type1");
		prototypes[ProtoType::TYPE_2] = new ConcreatePrototype2("type2");
	}
	~PrototypeFactory() {
		delete prototypes[ProtoType::TYPE_1];
		delete prototypes[ProtoType::TYPE_2];
	}
	Prototype *create_prototype(ProtoType type) {
		return prototypes[type]->clone();
	}
private:
	std::unordered_map<ProtoType, Prototype*> prototypes;
};
