bool norepeat(string s) {
	int lower[26] = {0};
	int upper[26] = {0};
	for (int i = 0; i < s.size(); i++) {
		if (s[i]>='a'&&s[i]<='z') {
			lower[s[i]-'a']++;
		} else if (s[i]>='A'&&s[i]<='Z') {
			lower[s[i]-'A']++;
		}
	}
	for (int i = 0; i < 26; i++) {
		if (lower[i]>=2||upper[i]>=2) return false;
	}
	return true;
}
int longestNonRepeatSubString(string s) {
    // TO DO
	for (int i = 0; i < s.size(); i++) {
		int k = s.size() - i;
		int vitri = 0;
		while ((vitri + k) <= s.size()) {
			string m = s.substr(vitri, k);
			if (norepeat(m)) return m.size();
			else vitri += 1;
		}
	}
	return s.size();
}
