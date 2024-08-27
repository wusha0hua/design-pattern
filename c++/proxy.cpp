
#include <cassert>
#include <string>
class Subject {
public:
	virtual std::string method() = 0;
};

class RealSubject: public Subject {
public:
	std::string method() override {
		return "real subject";
	}
};

class Proxy: public Subject {
private:
	RealSubject *real_subjuct = nullptr;
public:
	std::string method() {
		if(real_subjuct == nullptr) real_subjuct = new RealSubject();
		return real_subjuct->method();
	}
};

void client() {
	Proxy *proxy = new Proxy();
	assert(proxy->method() == "real subject");
	delete proxy;
}
