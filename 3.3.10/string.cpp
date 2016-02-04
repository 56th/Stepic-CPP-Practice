// implementation of String

#include "string.hpp"

String::String(const char* s) 
	: size(strlen(s))
	, str(new char[size + 1]) { // C-style strings end w/ '\0', so we need one extra byte
	strcpy(str, s);
}

String::String(size_t n, char c) // fill string w/ symbol c
	: size(n)
	, str(new char[n + 1]) { 
	for (size_t i = 0; i < n; ++i)
		str[i] = c;
	str[n] = '\0';
}

String::~String() {
	delete [] str;
}

void String::append(String& other) {
	char* old = str;
	size_t olds = size;
	size += other.size;
	str = new char[size + 1];
	strcpy(str, old);
	strcpy(str + olds, other.str);
	delete [] old;
}