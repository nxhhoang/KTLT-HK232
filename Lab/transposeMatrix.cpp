int** transposeMatrix(int** matrix, int r, int c) {
// TODO
	if (r== 0||c==0 ) return NULL;
	int** brr = new int*[c];
	for (int i = 0; i< c; i++) {
		brr[i] = new int[r];
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			brr[j][i] = matrix[i][j];
		}
	}
	return brr;
}
