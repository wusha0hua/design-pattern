class SingletonEager {
public:
	SingletonEager(SingletonEager&) = delete;
	SingletonEager& operator=(const SingletonEager&) = delete;
	static SingletonEager* instance() {
		return singleton;
	}
private:
	static SingletonEager* singleton;
	SingletonEager() {}
	~SingletonEager() {}
};

SingletonEager* SingletonEager::singleton = new SingletonEager();

// class SingletonLazy {
// public:
// 	SingletonLazy(SingletonLazy&) = delete;
// 	SingletonLazy& operator=(const SingletonLazy&) = delete;
// 	static SingletonLazy* instance() {
// 		if(singleton == nullptr) {
// 			singleton = new SingletonLazy();
// 		}
// 		return singleton;
// 	}
// private:
// 	static SingletonLazy* singleton;
// 	SingletonLazy() {}
// 	~SingletonLazy() {}
// };

#include <cassert>
void client() {
	SingletonEager *eager1 = SingletonEager::instance();
	SingletonEager *eager2 = SingletonEager::instance();
	assert(eager1 == eager2);
	// SingletonLazy *lazy1 = SingletonLazy::instance();
	// SingletonLazy *lazy2 = SingletonLazy::instance();
	// assert(lazy1 == lazy2);
}
