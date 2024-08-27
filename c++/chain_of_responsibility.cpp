
#include <memory>
class Bank {
protected:
	std::shared_ptr<Bank> successor = nullptr;
	int balance = 0;
public:
	Bank(int balance): balance(balance) {}
	virtual void set_next(std::shared_ptr<Bank> next) {
		successor = next;
	}
	virtual bool can_pay(int amount) {
		return balance >= amount;
	} 
	virtual bool pay(int amount) {
		if(can_pay(amount)) {
			balance -= amount;
			return true;
		} else if(successor != nullptr) {
			balance = 0;
			return successor->pay(amount - balance);
		} else {
			return false;
		}
	}
};

class BankA: public Bank {
public:
	BankA(int balance): Bank(balance) {}
};

class BankB: public Bank {
public:
	BankB(int balance): Bank(balance) {}
};

class BankC: public Bank {
public:
	BankC(int balance): Bank(balance) {}
};

void client() {
	std::shared_ptr<Bank> ba(new BankA(100));
	std::shared_ptr<Bank> bb(new BankB(200));
	std::shared_ptr<Bank> bc(new BankC(300));
	bb->set_next(bc);
	ba->set_next(bb);
	ba->pay(500);
}
