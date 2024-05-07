#include <iostream>

struct Foo {
    void say() const {
		std::cout << "Foo says: " << msg << "\n"; 
	}
protected:
    Foo(char const * msg) : msg(msg) {}
private:
    char const * msg;
};

void foo_says(Foo const & foo) { 
	foo.say(); 
}

// Вам нужно определить функцию get_foo, как описано в задании,
// чтобы компилировался и работал как ожидается следующий код:
//
// foo_says(get_foo("Hello!"));

struct FooChild : Foo {
	// FooChild(char const * msg) : msg(msg) {}
	// error C2614: 'FooChild': illegal member initialization: 'msg' is not a base or member
	FooChild(char const * msg) : Foo(msg) {}
};

FooChild get_foo(char const * msg) {
	return FooChild(msg);
}

int main() {
	int const & c = 56;
	char const * msg = "hey there!"; // a pointer to a literal
	// Foo bar(msg);
	// error C2248: 'Foo::Foo': cannot access protected member declared in class 'Foo'
	// FooChild bar(msg);
	// ok!
	foo_says(get_foo(msg)); // FooChild —> Foo
	foo_says(FooChild("C-style string"));
	return 0;
}

/*
	lesson link:
	https://stepic.org/lesson/%D0%9D%D0%B0%D1%81%D0%BB%D0%B5%D0%B4%D0%BE%D0%B2%D0%B0%D0%BD%D0%B8%D0%B5-552/step/9?unit=875
*/