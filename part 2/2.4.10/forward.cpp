#include <iostream>
#include <string>

template<typename F, typename ...Args>
auto apply(F const & f, Args&&... args) -> decltype(f(std::forward<Args>(args)...)) {
	return f(std::forward<Args>(args)...);
}

int main() {
	auto fun = [](std::string a, std::string const& b) {
		return a += b; 
	};
	std::string s("world!");
	// @s is passed via lvalue reference, and
	// a temporary object via rvalue reference 
	s = apply(fun, std::string("Hello, "), s);
	std::cout << s << '\n';
	return 0;
}