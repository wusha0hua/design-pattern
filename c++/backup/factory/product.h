#pragma once
#include <iostream>

class Phone {
public:
	virtual void start() = 0;
};

class PhoneA: public Phone {
public:
	void start() override {
		std::cout << "phone A start" << std::endl;
	}
};

class PhoneB: public Phone {
	void start() override {
		std::cout << "phone B start" << std::endl;
	}
};

class PhoneC: public Phone {
	void start() override {
		std::cout << "phone C start" << std::endl;
	}
};

class Laptop {
public:
	virtual void start() = 0;
};

class LaptopA: public Laptop {
public:
	void start() override {
		std::cout << "laptop A start" << std::endl;
	}
};

class LaptopB: public Laptop {
	void start() override {
		std::cout << "laptop B start" << std::endl;
	}
};

class LaptopC: public Laptop {
	void start() override {
		std::cout << "laptop C start" << std::endl;
	}
};

