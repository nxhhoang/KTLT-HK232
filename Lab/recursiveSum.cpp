int recursiveSum(int arr[], int size) {
// TODO
	if (size <= 0) return 0;
	if (size == 1) return arr[0];
	return arr[0] + recursiveSum(arr + 1, size - 1);
}
int recursiveSum(int arr[], int size) {
// TODO
	if (size <= 0) return 0;
	if (size == 1) return arr[0];
	int result = arr[0];
	arr += 1; ///Ca:-p nha:-t con tra; sau khi ca;ng bia:?n arr[0]
	return result + recursiveSum(arr, size - 1);
}
