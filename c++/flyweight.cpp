
#include <iostream>
#include <string>
#include <unordered_map>
class Circle {
public:
	virtual void draw() = 0;
	virtual void set_position(int, int) = 0;
};

class ConcreteCircle: public Circle {
private:
	std::string color;
	int x;
	int y;
public:
	ConcreteCircle(std::string color): color(color) {}
	void draw() override {
		std::cout << "Circle " << color << " draw" << std::endl;
	}
	void set_position(int x, int y) override {
		this->x = x;
		this->y = y;
	}
};

class ShapFactory {
private:
	std::unordered_map<std::string, Circle*> circle_map;
public:
	Circle *get_circle(std::string& color) {
		if(auto it = circle_map.find(color); it == circle_map.end()) {
			Circle *circle = new ConcreteCircle(color);
			circle_map.insert({color, circle});
			return circle;
		} else {
			return it->second;
		}
	}
};
