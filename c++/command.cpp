
#include <iostream>
#include <memory>
class Bulb {
private:
	bool on = false;
public:
	void turn_on() {
		on = true;
		std::cout << "turn on" << std::endl;
	}
	void turn_off() {
		on = false;
		std::cout << "turn off" << std::endl;
	}
};

class Command {
protected:
	std::shared_ptr<Bulb> bulb;
	Command(std::shared_ptr<Bulb> bulb): bulb(bulb) {}
public:
	virtual void execute() = 0;
	virtual void undo() = 0;
	virtual void redo() = 0;
};

class TurnOn: public Command {
public:
	TurnOn(std::shared_ptr<Bulb> bulb): Command(bulb) {}
	void execute() override {
		bulb->turn_on();
	}
	void undo() override {
		bulb->turn_off();
	}
	void redo() override {
		execute();
	}
};

class TurnOff: public Command {
public:
	TurnOff(std::shared_ptr<Bulb> bulb): Command(bulb) {}
	void execute() override {
		bulb->turn_off();
	}
	void undo() override {
		bulb->turn_on();
	}
	void redo() override {
		execute();
	}
};

class RemoteControl {
public:
	void summit(std::shared_ptr<Command> command) {
		command->execute();
	}
};

void client() {
	std::shared_ptr<Bulb> bulb(new Bulb());
	std::shared_ptr<Command> turn_on_command(new TurnOn(bulb));
	std::shared_ptr<Command> turn_off_command(new TurnOff(bulb));
	std::shared_ptr<RemoteControl> controler(new RemoteControl());	
	controler->summit(turn_on_command);
	controler->summit(turn_off_command);
}
