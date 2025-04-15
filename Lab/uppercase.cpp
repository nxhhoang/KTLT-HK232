void uppercase(string output) {
	fstream file;
	file.open(output, ios::out );
	string str;
	cin>>str;
	for (int i = 0; i< str.size(); i++) {
		if (str[i]<='z'&&str[i]>='a') str[i]-=('z'-'Z');
	}
	file << str;
	file.close();
}
//////////////////////////////////////////
void uppercase(string output) {
	ofstream file(output);
	string str;
	cin>>str;
	for (int i = 0; i< str.size(); i++) {
		if (str[i]<='z'&&str[i]>='a') str[i]-=('z'-'Z');
	} f
	ile << str;
	file.close();
}
