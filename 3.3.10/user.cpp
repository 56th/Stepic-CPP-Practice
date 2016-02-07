#include <iostream>
#include "string.hpp"
#include <string>

int main() {
	String sample1("🐨 коала emoji"); // 13 user-perceived characters (http://utf8everywhere.org/)
	std::string sample2("🐨 коала emoji");
	std::cout << sample1.size << " " << sample2.length() << '\n'; // 21 21
	size_t len = 0;
	char *s = sample1.str;
	while (*s) len += (*s++ & 0xc0) != 0x80; // UTF-8 -- count all bytes that do not match 10xxxxxx
	std::cout << len << '\n'; // 13
	return 0;
}