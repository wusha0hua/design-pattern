
#include <string>
#include <vector>
class Object {
private:
	int id;
	std::string name;
public:
	Object(int id, std::string name): id(id), name(name) {}
	std::string get_name() {
		return name;
	}
	int get_id() {
		return id;
	}
};

class ObjectCollection {
public:
	virtual std::vector<Object>::iterator begin() = 0;
	virtual std::vector<Object>::iterator end() = 0;
};

class ConcreateObjectCollection: public ObjectCollection {
private:
	std::vector<Object> objects;
public:
	void add(const Object& object) {
		objects.push_back(object);
	}
	std::vector<Object>::iterator begin() override {
		return objects.begin();
	}
	std::vector<Object>::iterator end() override {
		return objects.end();
	}
};
