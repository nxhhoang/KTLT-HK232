int findOccurrences(int nums[], int size, int element) {
// TODO:
	if (size == 0) return 0;
	if (size == 1) return (nums[0] == element);
	int result = 0;
	if (nums[0] == element) result++;
	return result + findOccurrences(nums + 1, size - 1, element);
}
