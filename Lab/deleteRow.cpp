bool deleteRow(int**& matrix, int r, int c, int row) {
	if (row < 0 || row >= r) {
		return false;
	}
	int newRows = r - 1;
	int** newMatrix = newRows > 0 ? new int*[newRows] : nullptr;
	for (int i = 0, k = 0; i < r; i++) {
		if (i == row) {
			continue;
		}
		newMatrix[k] = matrix[i];
		k++;
	}
	delete[] matrix[row];
	delete[] matrix;
	matrix = newMatrix;
	return true;
}
