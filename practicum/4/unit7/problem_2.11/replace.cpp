void replace(char str[], char c1, char c2) {
	for (int i = 0;; i++) {
		if (str[i] == '\0') return;
		if (str[i] == c1) str[i] = c2;
	}
}
