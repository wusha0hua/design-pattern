
#include <list>
#include <memory>
#include <string>
#include <unordered_map>
class Mediator;

class User {
private:
	int id;
	std::shared_ptr<Mediator> mediator;
	std::list<std::string> messages;
public:
	User(int id, std::shared_ptr<Mediator> mediator);
	int get_id() {
		return id;
	}
	void send_message(std::string message);
	virtual void receive_message(int sender, std::string message) = 0;
protected:
	void add_receive_message(std::string message) {
		messages.push_back(message);
	}
};

class ConcreteUser: public User {
public:
	ConcreteUser(int id, std::shared_ptr<Mediator> mediator);
	void receive_message(int sender, std::string message) override;
};

class Mediator {
public:
	virtual void send_message(int sender, std::string message) = 0;
	virtual void add_user(std::shared_ptr<User> user) = 0;
};

class ConcreteMediator: Mediator {
private:
	std::unordered_map<int, std::shared_ptr<User>> users;
public:
	void send_message(int sender, std::string message) override {
		for(const auto& user: users) {
			if(user.first != sender) {
				user.second->receive_message(sender, message);
			}
		}
	}
	void add_user(std::shared_ptr<User> user) override {
		users[user->get_id()] = user;
	}
};

User::User(int id, std::shared_ptr<Mediator> mediator): id(id), mediator(mediator) {
	mediator->add_user(std::make_shared<User>(this));
} 

void User::send_message(std::string message) {
	mediator->send_message(id, message);
}

ConcreteUser::ConcreteUser(int id, std::shared_ptr<Mediator> mediator): User(id, mediator) {}

void ConcreteUser::receive_message(int sender, std::string message) {
	add_receive_message(message);	
}
