#include "product.h"

class FactoryMethor {
public:
	virtual Phone* product() = 0;
};

class FactoryMethorA: public FactoryMethor {
public:
	Phone* product() override {
		return new PhoneA;
	}
};

class FactoryMethorB: public FactoryMethor {
public:
	Phone* product() override {
		return new PhoneB;
	}
};

class FactoryMethorC: public FactoryMethor {
public:
	Phone* product() override {
		return new PhoneC;
	}
};

