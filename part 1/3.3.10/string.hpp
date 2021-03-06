// declaration of String
#pragma once
#include <algorithm> // std::swap
#include <cstddef> // size_t
#include <cstring> // strlen, strcpy

struct String {
	size_t size;
	char *str;
	String(char const * str = "");
	String(size_t, char);
	String(String const &); // copy constructor
	~String();
	String& operator=(String const &); // assignment operator
	void append(String const &);
	void swap(String&);
};

/*
	lesson link:
	https://stepic.org/lesson/%D0%9A%D0%BE%D0%BD%D1%81%D1%82%D1%80%D1%83%D0%BA%D1%82%D0%BE%D1%80%D1%8B-%D0%B8-%D0%B4%D0%B5%D1%81%D1%82%D1%80%D1%83%D0%BA%D1%82%D0%BE%D1%80%D1%8B-546/step/10?course=%D0%9F%D1%80%D0%BE%D0%B3%D1%80%D0%B0%D0%BC%D0%BC%D0%B8%D1%80%D0%BE%D0%B2%D0%B0%D0%BD%D0%B8%D0%B5-%D0%BD%D0%B0-%D1%8F%D0%B7%D1%8B%D0%BA%D0%B5-C%2B%2B&unit=869
*/