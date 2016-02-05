#include <iostream>
#include <cstddef> // size_t

struct Cls {
    Cls(char c, double d, int i);
	void print();
private:
    char c;
    double d;
    int i;
};

Cls::Cls(char c, double d, int i)
	: c(c)
	, d(d)
	, i(i) {
}

void Cls::print() {
	std::cout << c << " " << d << " " << i << '\n';
}

// Эта функция должна предоставить доступ к полю c объекта cls.
// Обратите внимание, что возвращается ссылка на char, т.е.
// доступ предоставляется на чтение и запись.
char& get_c(Cls &cls) {
	// sizeof(Cls) is 24 bytes = 8 * 3 bytes (memory alignment!)
	// [c ][1 ][2 ][3 ][4 ][5 ][6 ][7 ]
	// [d                             ]
	// [i             ][20][21][22][23]
	char* t = (char*) &cls;
	return *t;
}

double &get_d(Cls &cls) {
    double* t = (double*) &cls;
	return t[1];
}

int &get_i(Cls &cls) {
    int* t = (int*) &cls;
	return t[4];
}

int main() {
    char c;
    double d;
    int i;
	std::cin >> c >> d >> i; // values for private fields
	Cls test(c, d, i);
	std::cin >> c >> d >> i; // new values
	// magic!
	// here we are changing values of private fields using some knowledge about memory alignment
	get_c(test) = c;
	get_d(test) = d;
	get_i(test) = i;
	test.print();
	return 0;
}

/*
	lesson link:
	https://stepic.org/lesson/%D0%9C%D0%BE%D0%B4%D0%B8%D1%84%D0%B8%D0%BA%D0%B0%D1%82%D0%BE%D1%80%D1%8B-%D0%B4%D0%BE%D1%81%D1%82%D1%83%D0%BF%D0%B0-548/step/7?unit=871
*/