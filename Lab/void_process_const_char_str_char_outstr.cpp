void process(const char str[], char outstr[]) {
	int pos = 0;
	bool isPrevSpace = true;
	for (int i = 0; str[i] != '\0'; i++) {
		if (isalpha(str[i])) {
			if (isPrevSpace || i == 0) {
				outstr[pos++] = toupper(str[i]);
				isPrevSpace = false;
			} else {
				outstr[pos++] = tolower(str[i]);
			}
		}
		else if (isspace(str[i])) {
			if (!isPrevSpace) {
				outstr[pos++] = ' ';
				isPrevSpace = true;
			}
		}
	}
	outstr[pos] = '\0';
}
void process(const char str[], char outstr[]) {
	int len = strlen(str);
	int pos = 0;
	bool isPrevSpace = true;
	for (int i = 0; i < len; i++) {
		if (isalpha(str[i])) {
			if (isPrevSpace || i == 0) {
				outstr[pos++] = toupper(str[i]);
				isPrevSpace = false;
			} else {
				outstr[pos++] = tolower(str[i]);
			}
		} else if (isspace(str[i])) {
			if (!isPrevSpace) {
				outstr[pos++] = ' ';
				isPrevSpace = true;
			}
		} else {

			continue;
		}
	}
	outstr[pos] = '\0';
}
