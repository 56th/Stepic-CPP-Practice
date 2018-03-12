unsigned strlen(const char *str) {
    unsigned res = 0;
	while (*str++) ++res;
	return res;
}
void strcat(char *to, const char *from) {
	while (*to) ++to;
	do {
		*to = *from++;
	} while (*to++);
}
int strstr(const char *text, const char *pattern) {
	unsigned t = strlen(text),
			 p = strlen(pattern),
			 maxIter, i, j;
	if (p > t) return -1;
	maxIter = t - p + 1;
	for (i = 0; i < maxIter; ++i) {
		for (j = 0; j < p; ++j) if (pattern[j] != text[i + j]) break;
		if (j == p) return i;
	}
	return -1;
}