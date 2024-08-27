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

class SingletonLazy {
public:
	SingletonLazy(SingletonLazy&) = delete;
	SingletonLazy& operator=(const SingletonLazy&) = delete;
	static SingletonLazy* instance() {
		singleton = new SingletonLazy();
		return singleton;
	}
private:
	static SingletonLazy* singleton;
	SingletonLazy() {}
	~SingletonLazy() {}
};
