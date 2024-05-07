#include <iostream>
#include <typeinfo>

struct Base {
	Base* b = nullptr;
	virtual ~Base() = default;
	virtual Base* clone() const = 0;
	virtual void bar() const = 0;
	void foo() const {
		auto& p = const_cast<Base&>(*this); 
		p.b = clone();
		b->bar();
		//std::cout << "call " << typeid(*this).name() << "::" << __func__ << ": ";
		//foo();
		//return *this;
	}
};

struct Derived : Base {
	int a = 0;
	Derived* clone() const override {
		return new Derived(*this);
	}
	void bar() const override {
		std::cout << a << '\n';
	}
};

int main() {
	Derived d;
	d.a = 42;
	d.foo();
	return 0;
}