
#include <memory>
class Expression {
public:
	virtual int interpret() = 0;
};

class NumberExpression: public Expression {
private:
	int value;
public:
	int interpret() override {
		return value;
	}
};

class AddExpression: public Expression {
private:
	std::shared_ptr<Expression> left;
	std::shared_ptr<Expression> right;
public:
	AddExpression(std::shared_ptr<Expression> left, std::shared_ptr<Expression> right): left(left), right(right) {}
	int interpret() override {
		return left->interpret() + right->interpret();
	}
};
