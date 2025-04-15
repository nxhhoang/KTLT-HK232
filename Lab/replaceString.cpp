void replaceString(string s, string s1, string s2) {
	if (s.size() <= 0 || s1.size() <= 0 || s.size() < s1.size()) {
		cout << s;
		return;
	}
	size_t pos = s.rfind(s1);
	if (pos == string::npos) {
		cout << s << endl;
		return;
	}
	s.replace(pos, s1.length(), s2);
	cout << s << endl;
}
