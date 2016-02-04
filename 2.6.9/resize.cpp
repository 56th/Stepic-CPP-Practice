char *resize(const char *str, unsigned size, unsigned new_size) {
	unsigned i, 
			 maxIter = new_size > size ? size : new_size;
	char* res = new char[new_size];
	for (i = 0; i < maxIter; ++i)
		res[i] = str[i];
	delete [] str;
	return res;
}

int main() {
	return 0;
}