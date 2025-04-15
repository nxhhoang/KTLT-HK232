void addElement(int*& arr, int n, int val, int index) {
// TODO
	int* brr = new int[n+1];
	for (int i = 0, in = 0; i < n+1; i++) {
		if (i!=index) {
			brr[i] = arr[in];
			in++;
		} else {
			brr[i] = val;
		}
	}
	delete[] arr;
	arr = brr;
}
