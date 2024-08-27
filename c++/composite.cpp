
#include <string>
#include <vector>
class Shape {
protected:
	std::string color;
	std::vector<Shape*> inner_shape;
public:
	virtual void set_color(std::string) = 0;
	virtual void add_shape(Shape*) = 0;
};

class Circle: public Shape {
public:
	void set_color(std::string color) override {
		this->color = color;
		for(Shape* shape: inner_shape) {
			shape->set_color(color);
		}
	}
	void add_shape(Shape *shape) override {
		inner_shape.push_back(shape);
	}
};

class Square: public Shape {
public:
	void set_color(std::string color) override {
		this->color = color;
		for(Shape* shape: inner_shape) {
			shape->set_color(color);
		}
	}
	void add_shape(Shape *shape) override {
		inner_shape.push_back(shape);
	}
};

