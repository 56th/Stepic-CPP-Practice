#include <cstdlib>

int ** transpose(const int * const * m, size_t rows, std::size_t cols) {
	size_t i, j;
	int** t = new int*[cols];
	*t = new int[rows * cols];
	for (i = 0; i < cols; ++i) {
		t[i] = *t + i * rows;
		for (j = 0; j < rows; ++j) 
			t[i][j] = m[j][i];
	}
    return t;
}

void swap_min(int *m[], unsigned rows, unsigned cols) {
    unsigned i, j;
	int min = **m,
		minRow = 0; 
	for (i = 0; i < rows; ++i) 
		for (j = 0; j < cols; ++j) 
			if (min > m[i][j]) {
				min = m[i][j];
				minRow = i;
			}
	int* t = *m;
	*m = m[minRow];
	m[minRow] = t;
}


int main() {
	return 0;
}