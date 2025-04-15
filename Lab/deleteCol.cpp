bool deleteCol(int**& matrix, int r, int c, int col) {
	if (col < 0 || col >= c) {
		return false; 
	}

	int newCols = c - 1;
	int** newMatrix = newCols > 0 ? new int*[r] : nullptr;

	for (int i = 0; i < r; i++) {
		if (newCols > 0) {
			newMatrix[i] = new int[newCols];
		} 
		for (int j = 0, k = 0; j < c; j++) {
			if (j == col) {
				continue; 
			}
			if (
			    newCols >
			    0) {
				newMatrix[i][k] = matrix[i][j];
				k++;
			}
		}
	}

	for (int i = 0; i < r; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;

	matrix = newMatrix;
	return true;
}
