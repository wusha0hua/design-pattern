
#include <endian.h>
#include <iostream>
#include <memory>
#include <string>
class State {
public:
	virtual std::string handle() = 0;
};

class OnState: public State {
public:
	std::string handle() override {
		return "on state";
	}
};

class OffState: public State {
public:
	std::string handle() override {
		return "off state";
	}
};

class BlinkState: public State {
public:
	std::string handle() override {
		return "blink state";
	}
};

class Bulb {
private:
	std::shared_ptr<State> current_state;
public:
	Bulb(): current_state(std::shared_ptr<State>(new OffState())) {}
	void set_state(std::shared_ptr<State> state) {
		current_state = state;
	}
	std::string perform() {
		return current_state->handle();
	}
};

void client() {
	int light;
	std::shared_ptr<Bulb> bulb(new Bulb());
	if(light < 0) {
		bulb->set_state(std::shared_ptr<State>(new BlinkState()));
	} else if(light < 100) {
		bulb->set_state(std::shared_ptr<State>(new OffState()));
	} else {
		bulb->set_state(std::shared_ptr<State>(new OffState()));
	}
	std::cout << bulb->perform() << std::endl;
}
