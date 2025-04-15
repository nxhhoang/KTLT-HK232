void mostFrequentCharacter(const char* str, char& res, int& freq) {
	int cha[26] = {0}; 
	int maxFreq = 0; 

	for (int i = 0; str[i] != '\0'; i++) {
		if (std::isalpha(str[i])) { 
			char lowercaseChar = std::tolower(str[i]); 
			cha[lowercaseChar - 'a']++; 
			maxFreq = std::max(maxFreq, cha[lowercaseChar - 'a']); 

		}
	}

	for (int i = 0; i < 26; i++) {
		if (cha[i] == maxFreq) {
			res = 'a' + i; 
			freq = maxFreq; 
			break;
		}
	}
}
