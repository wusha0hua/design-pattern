#include "product.h"

class AbstrctFactory {
	virtual Phone* product_phone() = 0;
	virtual Laptop* product_laptop() = 0;
};

class FactoryA: public AbstrctFactory {
	Phone* product_phone() override {
		return new PhoneA;
	}
	Laptop* product_laptop() override {
		return new LaptopA;
	}
};

class FactoryB: public AbstrctFactory {
	Phone* product_phone() override {
		return new PhoneB;
	}
	Laptop* product_laptop() override {
		return new LaptopB;
	}
};

class FactoryC: public AbstrctFactory {
	Phone* product_phone() override {
		return new PhoneC;
	}
	Laptop* product_laptop() override {
		return new LaptopC;
	}
};

