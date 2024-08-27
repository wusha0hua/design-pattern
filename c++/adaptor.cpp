#include <string>
#include <cassert>

class Elf {
private:
	std::string header = "elf";
public:
	std::string execute() {
		return "elf running";
	}
	const std::string& get_header() {
		return header;
	}
};

class Pe {
private:
	std::string header = "pe";
public:
	std::string execute() {
		return "pe running";
	}
	const std::string& get_header() {
		return header;
	}
};

class Transformer {
public:
	virtual std::string transform() = 0;
};

class Adaptor: public Transformer {
private:
	Pe *pe = nullptr;
public:
	Adaptor(Pe *pe): pe(pe) {}
	std::string transform() {
		return pe->execute();
	}
};

void client() {
	Elf *elf = new Elf();
	elf->execute();
	Pe *pe = new Pe();
	Adaptor *adaptor = new Adaptor(pe);
	adaptor->transform();
	delete elf;
	delete pe;
	delete adaptor;
}

