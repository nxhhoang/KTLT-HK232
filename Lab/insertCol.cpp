int** insertCol(int**& matrix, int r, int c, int* colArr, int col) {
// TODO
	int** brr = new int*[r];
	for (int i = 0; i < r; i++) {
		brr[i] = new int[c];
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0, k = 0; j < c + 1; j++) {
			if (j!=col) {
				brr[i][j] = matrix[i][k];
				k++;
			} else {
				brr[i][j] = colArr[i];
			}
		}
	}
	for (int i = 0; i < r; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
	matrix = brr;
	return brr;
}
