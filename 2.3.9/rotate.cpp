#include <iostream>

void swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}

unsigned newIndex(unsigned i, unsigned n, unsigned s) {
	return (n + i - s) % n;
}

void rotate(int a[], unsigned size, unsigned shift) {
	shift %= size;
	if (shift == 0) return;
	unsigned init = 0,
			 i = newIndex(0, size, shift),
			 k;
	int prev = a[0];
	for (k = 0; k < size; ++k) {
		swap(a + i, &prev);
		if (i == init) { 
			prev = a[++init];
			i = newIndex(init, size, shift);
		}
		else i = newIndex(i, size, shift);
	}
}

int main() {
	unsigned n, s, i;
	std::cin >> n;
	int* a = new int[n];
	for (i = 0; i < n; ++i)
		std::cin >> a[i];
	std::cin >> s;
	rotate(a, n, s);
	for (i = 0; i < n; ++i)
		std::cout << a[i] << " ";
	return 0;
}