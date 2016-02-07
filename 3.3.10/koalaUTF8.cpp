#include <iostream>
#include "string.hpp"
#include <string>

int main() {
	// 🐨 has unicode codepoint U+1F428 (http://emojipedia.org/koala/)
	// according to UTF-8, we have to store 1 11110100 00101000:
	// [1111]0000 [10]011111 [10]010000 [10]101000
	// 4 bytes for koala!
	String sample1("🐨 коала emoji"); // 13 user-perceived characters (http://utf8everywhere.org/)
	std::string sample2("🐨 коала emoji");
	std::cout << sample1.size << " " << sample2.length() << '\n'; // 21 21
	size_t len = 0;
	char *s = sample1.str;
	while (*s) len += (*s++ & 0xc0) != 0x80; // UTF-8 — count all bytes that do not match 10xxxxxx
	std::cout << len << '\n'; // 13
	return 0;
}