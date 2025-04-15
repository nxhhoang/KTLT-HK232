
int convertToBaseM(int n, int m = 2) {
// Write your code
	int result = 0;
	int k = 1;
	while (n>0) {
		result+=((n%m)*k);
		n/=m;
		k*=10;
	}
	return result;
}
