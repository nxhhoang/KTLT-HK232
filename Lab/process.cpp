void process(char str[], char outstr[]) {
	memset(outstr, 0, 100);
	char *pch;
	pch = strtok(str, " ");
	while (pch != NULL) {
		strcat(outstr, pch);
		strcat(outstr, " ");
		pch = strtok(NULL, " ");
	}
}
void process(char str[], char outstr[]) {
	memset(outstr, 0, 100);
	char *pch;
	pch = strtok(str, " ");
	while (pch != NULL) {
		strcat(outstr, pch);
		pch = strtok(NULL, " ");
		if (pch != NULL) {
			strcat(outstr, " ");
		}
	}
}
