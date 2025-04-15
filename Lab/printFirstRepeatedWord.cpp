void printFirstRepeatedWord(char str[]) {
	const int MAX_WORDS = 100;
	char* words[MAX_WORDS];
	char* token = strtok(str, " ");
	int numWords = 0;
	while (token != NULL && numWords < MAX_WORDS) {
		bool repeated = false;
		for (int i = 0; i < numWords; ++i) {
			if (strcmp(token, words[i]) == 0) {
				std::cout << token;
				return;
			}
		}
		words[numWords++] = token;
		token = strtok(NULL, " ");
	}
	std::cout << "No Repetition";
}
