void deleteWord(string s, string s1) {
  //TO DO
	size_t pos = s.rfind(s1);
	while (pos!=string::npos) {
		s.erase(pos, s1.size());
		pos = s.rfind(s1);
	}
	cout << s;
}
