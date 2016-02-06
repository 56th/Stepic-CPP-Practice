#include <cstddef> // size_t

int main() {
	size_t rows = 5,
		   cols = 10,
		   i;
	// create rows * cols array on heap
	// int const * const * const m = new int const * const [rows]; 
	// m is a constant pointer to a constant pointer to a constant integer value
	int const ** m = new int const *[rows]; // m is a pointer to a pointer to a constant integer value
	*m = new int const[rows * cols];
	for (i = 1; i < rows; ++i)
		m[i] = *m + i * cols;
	// m[4][2] = 42;
	// MSVC error C3892: 'm': you cannot assign to a variable that is const
	// 
	// int const i = 1;
	// int* p = 0;
	// int const ** pp = &p; 	 int** -> int const **! С++ standard forbids this. MSVV:
	//     						 error: cannot convert from 'int **' to 'const int **'
	// 							 otherwise we could change data which is constant
	// *pp = &i; 
	// *p = 2;
	delete [] *m;
	delete [] m;
	return 0;
}
/*
	lesson link:
	https://stepic.org/lesson/%D0%9A%D0%BE%D0%BD%D1%81%D1%82%D0%B0%D0%BD%D1%82%D0%BD%D0%BE%D1%81%D1%82%D1%8C-549/step/6?unit=872
*/