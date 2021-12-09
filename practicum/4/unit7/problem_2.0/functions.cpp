int strlen(const char str[]) {
	int size = 0;
	while (str[size] != '\0') {
		size++;
	}
	return size;
}

int strcmp(const char str1[], const char str2[]) {
	int s1Idx = 0;
	int s2Idx = 0;
	while (str1[s1Idx] != '\0'  && str1[s1Idx] == str2[s2Idx]) {
		s1Idx++;
		s2Idx++;
	}

	if (str1[s1Idx] == str2[s2Idx]) {
		return 0;
	}
	return (str1[s1Idx] > str2[s2Idx] ? 1 : -1);
}
void strcpy(char dst[], const char src[]) {
	int i = 0;
	while (src[i] != '\0') {
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

void strncpy(char dst[], const char src[], int n) {
	int i = 0;
	while (src[i] != '\0' && i < n) {
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

void strcat(char dst[], const char src[]) {
	int len1 = strlen(dst);
	int i = 0;
	while (src[i] != '\0') {
		dst[len1 + i] = src[i];
		i++;
	}
	dst[len1 + i] = '\0';
}

void strncat(char dst[], const char src[], int n) {
	int len1 = strlen(dst);
	int i = 0;
	while (src[i] != '\0' && i < n) {
		dst[len1 + i] = src[i];
		i++;
	}
	dst[len1 + i] = '\0';
}

// strchr returns a pointer to the character - we do not yet know about pointers, so return its index, or -1 if it does not exist
int strchr(const char str[], char c) {
	if (c == '\0') {
		return strlen(str);
	}
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == c) {
			return i;
		}
	}
	return -1;
}

// strstr returns a pointer, but we do not yet know about pointers - so return the index, or -1 if substr is not found within str
int strstr(const char str[], const char substr[]) {
	for (int i = 0; str[i] != '\0'; i++) {
		for (int j = 0;; j++) {
			if (substr[j] == '\0') {
				return i;
			}
			if (str[i + j] != substr[j]) {
				break;
			}
		}
	}
	return -1;

}