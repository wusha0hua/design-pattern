#include "product.h"

enum class PhoneType {
	A,
	B,
	C,
};

class SimpleFactory {
public:
	Phone* product(PhoneType type) {
		switch(type) {
			case PhoneType::A: 
				return new PhoneA;
			case PhoneType::B:
				return new PhoneB;
			case PhoneType::C:
				return new PhoneC;
			default:
				return nullptr;
		}	
	}
};
