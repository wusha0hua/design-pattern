
#include <memory>
class Strategy {
public:
	virtual void alogithm() = 0;
};

class ConcreteStrategyA: public Strategy {
public:
	void alogithm() override {
		// todo something
	}
};

class ConcreteStrategyB: public Strategy {
public:
	void alogithm() override {
		// todo something
	}
};

class Context {
private:
	std::shared_ptr<Strategy> strategy;
public:
	Context(std::shared_ptr<Strategy> strategy): strategy(strategy) {}
	void alogithm() {
		strategy->alogithm();
	}
};
