int* flatten(int** matrix, int r, int c) {
//TODO
	int k = r*c;
	int* newMatrix = new int[k];
	for (int i = 0; i< r; i++) {
		for (int j = 0; j< c; j++) {
			newMatrix[i*c + j] = matrix[i][j];
		}
	}
	for (int i = 0; i < r; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
	return newMatrix;
}
