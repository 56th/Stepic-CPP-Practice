// implementation of String

#include "string.hpp"

String::String(char const * s) 
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

String::String(String const &source) 
	: size(source.size)
	, str(new char[size + 1]) {
		strcpy(str, source.str);
}

String& String::operator=(String const & source) {
	if (this != &source) String(source).swap(*this);
	return *this;
}

String::~String() {
	delete [] str;
}

void String::append(String const & other) {
	char* old = str;
	size_t olds = size;
	size += other.size;
	str = new char[size + 1];
	strcpy(str, old);
	strcpy(str + olds, other.str);
	delete [] old;
}

void String::swap(String& s) {
	std::swap(size, s.size);
	std::swap(str, s.str);
}