int findMax(int *ptr, int n)
{
	if (n<=0) return -99999999;
	if (n==1) return *ptr;
	int result = findMax(ptr + 1, n - 1);
	return max(*ptr, result);
}
