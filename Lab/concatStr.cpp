char* concatStr(char* str1, char* str2) {
// TODO
	const int maxsize = 1000;
	char* str = new char[maxsize];
// for (int i = 0; i< 1000; i++){
// str[i] = '\0';
// }
	char* p = str1;
	int i = 0;
	while(*p) {
		str[i] = *p;
		p++;
		i++;
	}
	p = str2;
	while(*p) {
		str[i] = *p;
		p++;
		i++;
	}
	str[i]='\0';
	return str;
}
