int** readArray()
{
//TODO
	int** arr = new int*[10];
	for (int i = 0; i<10; i++) {
		arr[i] = new int[10];
	}
	for (int i = 0; i< 10; i++) {
		for (int j = 0; j< 10; j++) {
			arr[i][j] = 0;
		}
	}
	for (int i = 0; i< 10; i++) {
		for (int j = 0; j< 10; j++) {
			int t;
			cin >> t;
			arr[i][j] = t;
			if (arr[i][j]==0) break;
		}
	}
	return arr;
}
