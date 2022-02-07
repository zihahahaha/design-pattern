#include<iostream>
using namespace std;

class  WalkStragy {
public:
	virtual void thing() = 0;
};

class TalkStragy {
public:
	virtual void thing() = 0;
};

class OkayWalk
	:public WalkStragy {
	void thing() override {
		std::cout << "normal walk\n";
	}
};

class LameWalk
	:public WalkStragy {
public:
	void thing() override {
		std::cout << "somthing wrong walk\n";
	}
};

class OkayTalk
	:public TalkStragy {
public:
	void thing() override {
		std::cout << "normal talk\n";
	}
};


class StammerTalk
	:public TalkStragy {
public:
	void thing() override {
		std::cout << "he talk with stammering\n";
	}
};

class Person {
public:
	virtual void walk() {
		__walkStragy->thing();
	}
	virtual void talk() {
		__talkStragy->thing();
	}
protected:
	WalkStragy* __walkStragy = nullptr;
	TalkStragy* __talkStragy = nullptr;
};

class HealthMan
	:public Person {
public:
	HealthMan() {
		__walkStragy = new OkayWalk;
		__talkStragy = new OkayTalk;
	}
};

class PoorMan
	:public Person {
public:
	PoorMan() {
		__walkStragy = new LameWalk;
		__talkStragy = new StammerTalk;
	}
};


void test(Person* person) {
	person->talk();
	person->walk();
}

int main() {
	HealthMan a;
	test(&a);
	PoorMan b;
	test(&b);
}

