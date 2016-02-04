#include <iostream>

void firstInLastOut() {
	unsigned i;
	std::cin >> i;
	if (i == 0) return;
	firstInLastOut();
	std::cout << i << " ";
}

int main() {
	firstInLastOut();
	return 0;
}