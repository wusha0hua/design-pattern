
#include <memory>
class Template {
public:
	virtual void execute() final {
		algothm1();
		algothm2();
		algothm3();
	}
	virtual void algothm1() = 0;
	virtual void algothm2() = 0;
	virtual void algothm3() = 0;
};

class ExecutorA: public Template {
public:
	void algothm1() override {}
	void algothm2() override {}
	void algothm3() override {}
};

class ExecutorB: public Template {
public:
	void algothm1() override {}
	void algothm2() override {}
	void algothm3() override {}
};

void client() {
	std::shared_ptr<Template> eA(new ExecutorA());
	eA->execute();
}
