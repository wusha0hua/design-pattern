

#include <iostream>
#include <memory>
#include <string>

class Cpu;
class Gpu;
class Visitor {
public:
	virtual void visit_cpu(std::shared_ptr<Cpu> cpu) = 0;
	virtual void visit_gpu(std::shared_ptr<Gpu> gpu) = 0;
};

class UpdateVisitor: public Visitor {
public:
	void visit_cpu(std::shared_ptr<Cpu> cpu) override;
	void visit_gpu(std::shared_ptr<Gpu> gpu) override;
};

class HardWare {
private:
	std::string instruct;
public:
	HardWare(std:: string instruct): instruct(instruct) {} 
	virtual void run() {
		std::cout << instruct << std::endl;
	}
	virtual void accept(std::shared_ptr<Visitor>) = 0;
	virtual void add_instruct(std::string instruct) {
		this->instruct += instruct;
	}
};

class Cpu: public HardWare {
public:
	Cpu(std::string instruct): HardWare(instruct) {}
	void accept(std::shared_ptr<Visitor> visitor) override {
		visitor->visit_cpu(std::shared_ptr<Cpu>(this));	
	}
};

class Gpu: public HardWare {
public:
	Gpu(std::string instruct): HardWare(instruct) {}
	void accept(std::shared_ptr<Visitor> visitor) override {
		visitor->visit_gpu(std::shared_ptr<Gpu>(this));
	}
};

void UpdateVisitor::visit_cpu(std::shared_ptr<Cpu> cpu) {
	cpu->add_instruct("new instruct");
}

void UpdateVisitor::visit_gpu(std::shared_ptr<Gpu> gpu) {
	gpu->add_instruct("new instruct");
}

class Computer {
private:
	std::shared_ptr<Gpu> gpu;
	std::shared_ptr<Cpu> cpu;
public:
	Computer(): cpu(std::shared_ptr<Cpu>(new Cpu("cpu instruct"))), gpu(std::shared_ptr<Gpu>(new Gpu("gpu instruct"))) {}
	void accept(std::shared_ptr<Visitor> visitor) {
		cpu->accept(visitor);
		gpu->accept(visitor);
	}
	void execute() {
		cpu->run();
		gpu->run();
	}
};

void client() {
	std::shared_ptr<Computer> computer(new Computer());
	std::shared_ptr<Visitor> update_pack(new UpdateVisitor());
	computer->accept(update_pack);
	computer->execute();
}
