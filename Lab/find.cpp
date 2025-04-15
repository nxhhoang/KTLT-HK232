int find(char str[], char substr[]) {
    // TODO
	if (strlen(str) <= 0 || strlen(substr) <=0) return -1;
	int k = strlen(substr);
	for (int i = 0; i < strlen(str); i++) {
		for (int j = 0; j < strlen(substr); j++) {
			if (str[i+j] == substr[j]) k--;
		}
		if (
		    k
		    == 0) return i;
		k = strlen(substr);
	} 
	return -1;
}
