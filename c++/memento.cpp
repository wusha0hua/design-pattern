
#include <cassert>
#include <memory>
#include <string>
#include <vector>

class Memento {
private:
	std::string state;
public:
	Memento(std::string state): state(state) {}
	std::string get_state() {
		return state;
	}
};

class Originator {
private:
	std::string state;
public:
	void set_state(std::string state) {
		this->state = state;
	}
	std::string get_state() {
		return state;
	}
	std::shared_ptr<Memento> create_memento() {
		return std::shared_ptr<Memento>(new Memento(state));
	}
	void restore_from_memento(std::shared_ptr<Memento> memento) {
		state = memento->get_state();
	}
};

class Caretaker {
private:
	std::vector<std::shared_ptr<Memento>> mementos;
public:
	void add_memento(std::shared_ptr<Memento> memento) {
		mementos.emplace_back(memento);
	}
	std::shared_ptr<Memento> last_memento() {
		if(mementos.empty()) return nullptr;
		auto memento = mementos.back();
		mementos.pop_back();
		return memento;
	}
};

void client() {
	std::shared_ptr<Originator> originator(new Originator());
	originator->set_state("state 1");
	std::shared_ptr<Caretaker> caretaker(new Caretaker());
	caretaker->add_memento(originator->create_memento());
	originator->set_state("state 2");
	originator->restore_from_memento(caretaker->last_memento());
	assert(originator->get_state() == "state 1");
}
