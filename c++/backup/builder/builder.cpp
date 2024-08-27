class Server {};
class TcpServer: public Server {};
class UdpServer: public Server {};

class Builder {
	friend class Director;
public:
	Server *get_server() {
		return server;
	}
private:
	Server *server;
	virtual void set_address() = 0;
	virtual void bind() = 0;
	virtual void listen() = 0;
};

class TcpBuilder: public Builder {
private:
	void set_address() {}
	void bind() {}
	void listen() {}
};

class UdpBuilder: public Builder {
private:
	void set_address() {}
	void bind() {}
	void listen() {}
};

class Director {
public:
	void set_builder(Builder *buidler) {
		this->buidler = buidler;
	}
	Server *construct_server() {
		buidler->set_address();
		buidler->bind();
		buidler->listen();
		return buidler->get_server();
	}
private:
	Builder *buidler;
};
