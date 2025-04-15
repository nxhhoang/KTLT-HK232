bool isPalindrome(const string& str) {
	string reversedStr = str;
	reverse(reversedStr.begin(), reversedStr.end());
	return str == reversedStr;
}
string findPalindrome(string s) {
	for (int i = 0; i < s.size(); i++) {
		int k = s.size() - i;
		int vitri = 0;
		while ((vitri + k) <= s.size()) {
			string m = s.substr(vitri, k);
			if (isPalindrome(m)) return m;
			else vitri += 1;
		}
	}
	return s;
}
