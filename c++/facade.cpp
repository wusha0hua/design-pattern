
#include <iostream>
class SystemA {
public:
	void operation() {
		std::cout << "SystemA operation" << std::endl;
	}
};

class SystemB {
public:
	void operation() {
		std::cout << "SystemB operation" << std::endl;
	}
};

class SystemC {
public:
	void operation() {
		std::cout << "SystemC operation" << std::endl;
	}
};

class Facade {
private:
	SystemA *sa;
	SystemB *sb;
	SystemC *sc;
public:
	Facade() {
		sa = new SystemA();
		sb = new SystemB();
		sc = new SystemC();
	}
	void operation() {
		sa->operation();
		sb->operation();
		sc->operation();
	}
};

void client() {
	Facade *facade = new Facade();
	facade->operation();
}
