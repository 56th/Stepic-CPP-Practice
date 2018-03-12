#include <iostream>

char* resize(const char *str, unsigned size, unsigned new_size) {
	unsigned i, 
			 maxIter = new_size > size ? size : new_size;
	char* res = new char[new_size];
	for (i = 0; i < maxIter; ++i)
		res[i] = str[i];
	delete [] str;
	return res;
}

char* getline() {
	unsigned i = 0, s = 10;
	char c = '\0';
	char* res = new char[s];
	while(std::cin.get(c)) {
		if (c == '\n') break;
		if (i == s) {
			s *= 2;
			res = resize(res, s / 2, s);
		}
		res[i++] = c;
	}
	res[i] = '\0';
	return res;
}

int main() {
	char* str = getline();
	std::cout << str << '\n';
	return 0;
}