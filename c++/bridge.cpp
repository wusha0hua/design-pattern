
#include <cassert>
#include <string>
class Color {
public:
	virtual std::string paint() = 0;
};

class Red: public Color {
public:
	std::string paint() override {
		return "Red";
	}
};

class Green: public Color {
public:
	std::string paint() override {
		return "Green";
	}
};

class Shape {
protected:
	Color *color;
public:
	Shape(Color*c): color(c) {}
	virtual std::string draw() = 0;
};

class Circle: public Shape {
public:
	Circle(Color *c): Shape(c) {}
	std::string draw() override {
		return "Circle " + color->paint();
	}
};

class Square: public Shape {
public:
	Square(Color *c): Shape(c) {}
	std::string draw() override {
		return "Square " + color->paint(); 
	}
};

void client() {
	Shape *red_circle = new Circle(new Red());
	Shape *green_square = new Square(new Green());
	assert(red_circle->draw() == "Circle Red");
	assert(green_square->draw() == "Square Green");
}
